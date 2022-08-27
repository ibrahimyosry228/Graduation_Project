% parameter_info=Simulink.Bus.createObject(parameter);
% parameter_bus=evalin('base',parameter_info.busName);
% spkfData_info=Simulink.Bus.createObject(spkfData);
% spkfData_bus=evalin('base',spkfData_info.busName);
load 18650_charge1
load parameter 
meas.Current=-1*meas.Current;
realsoc=zeros(169,1);
t=meas.Time(:);
parameter.deltat = t(2)-t(1);
current = meas.Current(:);
voltage = meas.Voltage(:);
sochat = zeros(size(realsoc));
socbound = zeros(size(realsoc));
SigmaX0 = diag([1e-6 1e-8 2e-4]);
SigmaV = 2e-1;
SigmaW = 2e-1;
spkfData = initSPKF(voltage(1),SigmaX0,SigmaV,SigmaW,parameter);
for k = 1:length(voltage)
  if k>1
  parameter.deltat=t(k)-t(k-1);
  end
  vk = voltage(k);
  ik = current(k);
  [sochat(k),socbound(k),spkfData] = iterSPKF(vk,ik,spkfData);
  realsoc(k,1)=spkfData.soc0+meas.Ah(k)/parameter.Q; 
end
figure(1); clf; plot(t/60,100*realsoc,'k',t/60,100*sochat,'m'); hold on
plot([t/60; NaN; t/60],[100*(sochat+socbound); NaN; 100*(sochat-socbound)],'r');
title('SOC estimation using SPKF');
xlabel('Time (min)'); ylabel('SOC (%)');
legend('Truth','Estimate','Bounds'); ylim([0 200]); grid on
fprintf('RMS SOC estimation error = %g%%\n',sqrt(mean((100*(realsoc-sochat)).^2)));
figure(2); clf; plot(t/60,100*(realsoc-sochat),'m'); hold on
h = plot([t/60; NaN; t/60],[100*socbound; NaN; -100*socbound],'r');
title('SOC estimation errors using SPKF');
xlabel('Time (min)'); ylabel('SOC error (%)'); ylim([-10 10]); 
legend('Error','Bounds','location','northwest');
grid on
ind = find(abs(realsoc-sochat)>socbound);
fprintf('Percent of time error outside bounds = %g%%\n',length(ind)/length(realsoc)*100);
function spkfData = initSPKF(v0,SigmaX0,SigmaV,SigmaW,parameter)
irk0 = 0;
hk0 = 0;
spkfData.zkInd = 1;
spkfData.irkInd = 2;
spkfData.hkInd = 3;
ocv=parameter.ocv;
soc=parameter.soc;
j1=find(min(abs(ocv-v0))==abs(ocv-v0));
j=j1(1,:);
SOC0 = soc(j);
spkfData.soc0=SOC0;
spkfData.xhat = [SOC0;irk0;hk0];
spkfData.SigmaX = SigmaX0;
spkfData.SigmaV = SigmaV;
spkfData.SigmaW = SigmaW;
spkfData.Snoise = chol(blkdiag(SigmaW,SigmaV),'lower');
% spkfData.SXbump = 5;
Nx = length(spkfData.xhat); spkfData.Nx = Nx;
Ny = 1; spkfData.Ny = Ny;
Nu = 1; spkfData.Nu = Nu;
Nw = 1; spkfData.Nw = Nw;
Nv = 1; spkfData.Nv = Nv;
Na = Nx+Nw+Nv; spkfData.Na = Na;
h = sqrt(3); spkfData.h = h;
alpha1 = (h*h-Na)/(h*h);
alpha2 = 1/(2*h*h);
spkfData.alpham = [alpha1; alpha2*ones(2*Na,1)];
spkfData.alphac = spkfData.alpham;
spkfData.priorI = 0;
spkfData.signIk = 0;
spkfData.parameter = parameter;
end
function [zk,zkbnd,spkfData] = iterSPKF(vk,ik,spkfData)
parameter=spkfData.parameter;
RC      = parameter.RC;
G       = parameter.G;
Q       = parameter.Q;
deltat  = parameter.deltat;
R0      = parameter.R0;
R       = parameter.R;
M0      = parameter.M0;
M       = parameter.M;
eta     = 1;
if ik<0 
ik=ik*eta;
end
zkInd   = parameter.zkInd;
irkInd  = parameter.irkInd;
hkInd   = parameter.hkInd;
xhat    = spkfData.xhat;
SigmaX  = spkfData.SigmaX;
Snoise  = spkfData.Snoise;
Nx      = spkfData.Nx;
Nw      = spkfData.Nw;
Nv      = spkfData.Nv;
Na      = spkfData.Na;
alpham  = spkfData.alpham;
alphac  = spkfData.alphac;
I       = spkfData.priorI;
if abs(ik)>Q/100
spkfData.signIk = sign(ik);
end
signIk = spkfData.signIk;
xhata = [xhat; zeros([Nw+Nv 1])];
sigmaXa = chol(SigmaX,'lower');
sigmaXa= blkdiag(sigmaXa,Snoise);
Xa = xhata(:,ones([1 2*Na+1])) + spkfData.h*[zeros([Na 1]),sigmaXa,-sigmaXa];
Xx = stateEqn(Xa(1:Nx,:),I,Xa(Nx+1:Nx+Nw,:),parameter);
xhat = Xx*alpham;
Xs = Xx - xhat(:,ones([1 2*Na+1]));
SigmaX = Xs*diag(alphac)*Xs';
I = ik;
yk = vk;
Y = outputEqn(Xx,I,Xa(5,:),spkfData);
yhat = Y*alpham;
Ys = Y - yhat(:,ones([1 2*Na+1]));
SigmaXY = Xs*diag(alphac)*Ys';
SigmaY = Ys*diag(alphac)*Ys';
L = SigmaXY/SigmaY;
ytelda = yk - yhat;
xhat = xhat + L*ytelda;
xhat(hkInd) = min(0.99,max(-1,xhat(hkInd)));
SigmaX = SigmaX - L*SigmaY*L';
spkfData.priorI = ik;
spkfData.SigmaX = SigmaX;
spkfData.xhat = xhat;
zk = xhat(zkInd);
zkbnd = 3*sqrt(SigmaX(zkInd,zkInd));
function xnew = stateEqn(xold,current,xnoise,parameter)
current = current + xnoise;
RC      = parameter.RC;
G       = parameter.G;
Q       = parameter.Q;
deltat  = parameter.deltat;
zkInd   = parameter.zkInd;
irkInd  = parameter.irkInd;
hkInd   = parameter.hkInd;
Ah = exp(-abs(current*G*deltat/(3600*Q)));
xnew = 0*xold;
xnew(irkInd,:) = RC*xold(irkInd,:) + (1-RC)*current;
xnew(hkInd,:) = Ah.*xold(hkInd,:) + (Ah-1).*sign(current);
xnew(zkInd,:) = xold(zkInd,:) - current*deltat/(3600*Q);
end
function y = outputEqn(x,current,ynoise,spkfData) 
parameter=spkfData.parameter;
soc     = parameter.soc;
ocv     = parameter.ocv;
R0      = parameter.R0;
R       = parameter.R;
M0      = parameter.M0;
M       = parameter.M;
zkInd   = parameter.zkInd;
irkInd  = parameter.irkInd;
hkInd   = parameter.hkInd;
signIk = spkfData.signIk;
i=find(min(abs(soc-x(zkInd,:)))==abs(soc-x(zkInd,:)));
i = i'-length(soc)*(0:1:10);
y = ocv(i)' - R * x(irkInd,:) - R0 * current + M * x(hkInd,:) + M0 * signIk + ynoise;
end
end