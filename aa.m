close all
clc

sampleRate = 1e-6;
timeRange = [0: sampleRate: 1e-3];
idealOut = 10 * sin(2*pi * 8000 * timeRange);

resPlt = subplot(2, 1, 1);
hold on
plot(timeRange, idealOut);

realOut = idealOut;
realOut(realOut > 7) = 7;
realOut(realOut < -7) = -7;

plot(timeRange, realOut);
plot(timeRange, realOut - idealOut);

legend('Ideal Response', 'Real Response', 'Error','Location', 'northoutside','Orientation', 'horizontal');
legend('boxoff');

pbaspect([4, 1, 1]);
set(gca ,'Box'	,'off'	,'TickDir'	,'out'	,'YGrid'	,'on'	,'YTick'	,[-10: 5: 10]	);

hold off


ft = fft(realOut);
len = int32(length(ft) / 2);

fundFT = ft;
fundFT(fundFT < max(ft)) = 0;
fundHarm = ifft(fundFT, 'symmetric');

harmPlt = subplot(2, 1, 2);
hold on
plot(timeRange, fundHarm);

otherFT = ft;
otherFT(otherFT >= max(ft)) = 0;
otherHarm = ifft(otherFT, 'symmetric');

plot(timeRange, otherHarm);

legend('Fundamental Harmonic', 'Higher Harmonics','Location', 'northoutside',"Orientation","horizontal");
legend('boxoff');

pbaspect([4, 1, 1]);
set(gca,'Box'	,'off'	, 'TickDir'	,'out'	, 'YGrid'	,'on'	,'YTick'	,[-10: 5: 10]	);

hold off
print('harmonics.eps', '-depsc');

fs = 1 / sampleRate;
freqRange = (-len+1: len-1) * fs / (2 * len);
freqRange = round(double(freqRange), 2, 'significant');

subplot(1, 1, 1);
ftPlt = plot(freqRange, abs( fftshift(ft) ));

freqData = zeros(len, 2);
freqData(:, 1) = abs(ft(1: len));
freqData(:, 2) = freqRange(len: end);
freqData = sortrows(freqData, 'descend');
freqData(freqData(:, 1) < freqData(4, 1), :) = [];

text(freqData(:, 2), freqData(:, 1), num2cell(freqData(:, 2)'),'VerticalAlignment','bottom');

pbaspect([2, 1, 1]);
set(gca,'Box'	,'off' , 'TickDir'	,'out' );
axis([0, freqRange(end) / 6, -500, 4500]);

print('ft.eps', '-depsc');
