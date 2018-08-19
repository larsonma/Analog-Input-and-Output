% PLOT_REAL.M
% 
% MATLAB function to plot real 
% floating point values read from a microcontroller
% memory using Keil uvision 5.
% data should be 32-bit floating point saved in
% Intel hex format file
%
% 12/4/2017 (CJP): parsing debugger data now in function ihexread

function plot_real()

fname = input('enter filename ','s');
%% Read data from the input file specified by the user
memdata = ihexread(fname);

%% Plot
floatcount = length(memdata);
figure;
set(gcf,'numberTitle','off')
set(gcf,'name','real data read from the microcontroller memory in Keil uVision 5')
%plot(0:(floatcount-1),memdata(1:1:floatcount)/2,'LineWidth',2.0);
plot(0:(floatcount-1),memdata(1:1:floatcount),'--bo','LineWidth',2.0);
%bar(0:(floatcount-1),memdata(1:1:floatcount)/2,0.2);grid on
xlabel('n','FontSize',12,'FontName','times');
ylabel('real','FontSize',12,'FontName','times');
