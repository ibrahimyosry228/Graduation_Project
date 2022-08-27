load NCR18650B_measurements
% soc=soc/100;
% meas.Current=-1*meas.Current;
soc=meas.soc;
ocv=meas.ocv;
parameter.R0=76e-3;
parameter.R=62e-3;
parameter.RC=exp(-1/3620);
parameter.M0=14e-3;
parameter.M=31e-3;
parameter.G=1050;
parameter.Q=3.1541;
parameter.deltat=1;
parameter.zkInd=1;
parameter.irkInd=2;
parameter.hkInd=3;
j=min(abs(ocv-meas.Voltage(1,:)))==abs(ocv-meas.Voltage(1,:));
m = soc(j);
sim_state=[m;0;1];
model_voltage=zeros(length(meas.Current),1);
model_soc=zeros(length(meas.Current),1);
model_ir=zeros(length(meas.Current),1);
model_h=zeros(length(meas.Current),1);
for k=1:length(meas.Current)
    if k>1
parameter.deltat=meas.Time(k)-meas.Time(k-1);
    end
sim_voltage=outputEqn(sim_state,meas.Current(k,1),parameter,soc,ocv);
sim_state= stateEqn(sim_state,meas.Current(k,1),parameter);
model_voltage(k,1)=sim_voltage;
model_soc(k,1)=sim_state(1,1);
model_ir(k,1)=sim_state(2,1);
model_h(k,1)=sim_state(3,1);
end

t=meas.Time;
v1=meas.Voltage;
v2=model_voltage;
rms=100*sqrt(mean(((v1-v2)).^2))/sqrt(mean((v1).^2));
figure(1); clf; plot(t/60,v1,'k',t/60,v2,'m'); hold on
title('Voltage profiles from test and from model');
xlabel('Time (min)'); ylabel('Voltage (V)');
legend('Test Voltage','Model Voltage'); ylim([0 5]); grid on
fprintf('RMS estimation error = %g%%\n',rms);
parameter.soc=flip(soc);
parameter.ocv=flip(ocv);

function xnew = stateEqn(xold,current,parameter)
RC      = parameter.RC;
G       = parameter.G;
Q       = parameter.Q;
deltat  = parameter.deltat;
zkInd   = parameter.zkInd;
irkInd  = parameter.irkInd;
hkInd   = parameter.hkInd;
Ah = exp(-abs(current*G*deltat/(3600*Q)));
%xnew = 0*xold;
xnew(irkInd,:) = RC*xold(irkInd,:) + (1-RC)*current;
xnew(hkInd,:) = Ah.*xold(hkInd,:) + (Ah-1).*sign(current);
xnew(zkInd,:) = xold(zkInd,:) - current*deltat/(3600*Q);
% xnew(hkInd,:) = min(1,max(-1,xnew(hkInd,:)));
% xnew(zkInd,:) = min(1,max(0,xnew(zkInd,:)));
end
function y = outputEqn(x,current,parameter,soc_vector,ocv_vector)
R0      = parameter.R0;
R       = parameter.R;
M0      = parameter.M0;
M       = parameter.M;
zkInd   = parameter.zkInd;
irkInd  = parameter.irkInd;
hkInd   = parameter.hkInd;
i=min(abs(soc_vector-x(zkInd,:)))==abs(soc_vector-x(zkInd,:));
y = ocv_vector(i);
y = y + M*x(hkInd,:) + M0*sign(current);
y = y - R*x(irkInd,:) - R0*current;
end