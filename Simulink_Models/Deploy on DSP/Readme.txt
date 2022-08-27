- You must first load the parameters file
write this in command window if you want the NCR18650B parameters:
load NCR18650B_parameters_edited
write this in command window if you want the NCR18650PF parameters:
load parameter
- You must then write these lines in command window to convert matlab structure into bus:
parameter_info=Simulink.Bus.createObject(parameter);
parameter_bus=evalin('base',parameter_info.busName);