\begin{verbatim}
% 2015

% clean env
clc;
clear all;
close all;

% general configure
samplenum = 20;
testsamplenum = 20;
forcastnum = 2;
hiddenunitnum = 8;
inputdimension = 3;
outputdimension = 2;

% original data
in1 = [...];
in2 = [...];
in3 = [...];
out1 = [...];
out2 = [...];

% construction data
input = [ in1; in2; in3 ];
output = [ out1; out2 ];

% initialize original sample
[samin, minin, maxin, samout, minout, maxout] = premnmx(input, output);

% introduce noise, avoiding overfitting!
rand('state', sum(100*clock));
NoiseVar = 0.01;
Noise = NoiseVar * randn(2, samplenum);
SamOut = samout + Noise;
SamIn = samin;

% generate test sample
testsamin = samin;
testsamout = samout;

% network configure
MaxEpochs = 50000;
lr = 0.01;
E0 = 0.5E-3;

% initialize weight
W1 = 0.5 * rand(hiddenunitnum, inputdimension) - 0.1;
B1 = 0.5 * rand(hiddenunitnum, 1) - 0.1;
W2 = 0.5 * rand(outputdimension, hiddenunitnum) - 0.1;
B2 = 0.5 * rand(outputdimension, 1) - 0.1;
ErrHistory = [];

% begin
for i = 1:MaxEpochs
 
    hiddentout = logsig(W1 * SamIn + repmat(B1, 1, samplenum));
    netout = W2 * hiddenout * repmat(B2, 1, samplenum));
    Error = SamOut - netout;
    SSE = sumsqr(Error);
 
    ErrHistory = [ ErrHistory, SSE ];
    if SSE < 0
    	break
    end
    
    % core part of BP : 6 lines following
    delta2 = Error;
    delta1 = W2' * delta2 .* hiddenout .* (1 - hiddenout);
 
    dW2 = delta2 * hiddenout';
    dB2 = delta2 * ones(samplenum,1);
 
    dW1 = delta1 * SamIn';
    dB1 = delta1 * ones(samplenum,1);
 
    % weight correction
    W2 = W2 + lr*dW2;
    B2 = B2 + lr*dB2;
    W1 = W1 + lr*dW1;
    B1 = B1 + lr*dB1;
 
end

hiddenout = logsig(W1 * SamIn + repmat(B1, 1, testsamnum);
netout = W2 * hiddenout + repmat(B2, 1, testsamnum);
regression = postmnmx(netout, minout, maxout);


% predict
pin = [...];
pIn = tramnmx(pin, minin, maxin);
hiddenout = logsig(W1 * pIn + repmat(B1, 1, forcastnum));
pOut = W2 * hiddenout + repmat(B2, 1, forcastnum);
pout = postmnmx(pOut, minout, maxout);

%EOF
\end{verbatim}
