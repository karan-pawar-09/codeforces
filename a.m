clc; 
clear all; 
close all; 

N = 128 ;  
k = (0:N-1)' ; 
n = k ;  
x = tripuls((n-8)/8) ; 
X = 8*diric((2*pi*k)/N,8).^2.*exp(-1i*16*pi*k/N) ;  
H = exp(1i*2*pi*k/N)./(exp(1i*2*pi*k/N)- 0.7) ;  
h = 0.7.^n.*heaviside(n) ;   
Y = H.*X ;   
y = real(ifft(Y)) ; 
n = k ;  

n = n(1:30) ; x = x(1:30) ; h = h(1:30) ; y = y(1:30) ; 
subplot(3,1,1) ; 
ptr = stem(n,x,'k','filled') ;  
grid on ; 
set(ptr,'LineWidth',2,'MarkerSize',4) ;  
xlabel('\itn','FontSize',8,'FontName','Times') ; 
ylabel('x[{\itn}]','FontSize',8,'FontName','Times') ; 
title('Excitation','FontSize',8,'FontName','Times') ; 
set(gca,'FontSize',8,'FontName','Times') ; 
subplot(3,1,2) ; 
ptr = stem(n,h,'k','filled') ; 
grid on ; 
set(ptr,'LineWidth',2,'MarkerSize',4) ; 
xlabel('\itn','FontSize',8,'FontName','Times') ; 
ylabel('h[{\itn}]','FontSize',8,'FontName','Times') ; 
title('Impulse Response','FontSize',8,'FontName','Times') ; 
set(gca,'FontSize',8,'FontName','Times') ; 
subplot(3,1,3) ; 
ptr=stem(n,y,'k','filled') ; grid on ; 
set(ptr,'LineWidth',2,'MarkerSize',4) ;
xlabel('\itn','FontSize',8,'FontName','Times') ; 
ylabel('y[{\itn}]','FontSize',8,'FontName','Times') ; 
title('System Response','FontSize',8,'FontName','Times') ; 
set(gca,'FontSize',8,'FontName','Times') ; 
