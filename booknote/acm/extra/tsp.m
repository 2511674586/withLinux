%!/usr/bin/octave
% solve the TSP problem, this is a demo
% Copyright 2015 Lumin <cdluminate@gmail.com>
% License: MIT

%clear;
display ('I: initializing ...');
% initialize matrix
n = 6;
w =  [ 
0 13 51 77 68 50;
13  0 60 70 67 59;
51 60  0 57 36  2;
77 70 57  0 20 55;
68 67 36 20  0 34;
50 59  2 55 34  0;
]

tmp = zeros(6,6);

pms = perms ([ 1 2 3 4 5 6]);

pmssize = size(pms)

tspdec = [];
tspsum = 0;

% set flags
if_first = 1;
if_bad = 0;
for i = 1:pmssize(1)
    % generate dicision with current pms
    for j = 1:pmssize(2)
        tmp(j,pms(i,j)) = 1;
    end
    % no i = j, or bad one
    if trace(tmp) > 0
        if_bad = 1;
    end
    % no sub cycle, or bad one
    for i = 1:6
        for j = 1:6
            if tmp(i,j) + tmp(j,i) > 1
                if_bad = 1;
            end
        end
    end
    % if is a bad decision, continue
    if if_bad
        %display (i); display ('bad pms'); 
        tmp = zeros(6);
        if_bad = 0;
        continue
    end
    % save result if this is the first time computing
    if if_first == 1
        tspdec = tmp;
        tspsum = sum(sum(w.*tmp));
        if_first = 0;
    end
    % show current
    %display ('I: current dicision');
    %display (tmp);
    %display ('I: current sumsum');
    tmpsum = sum(sum(w.*tmp));
    % if less than the result stored, update the restored result
    if tmpsum < tspsum
        tspdec = tmp;
        tspsum = tmpsum;
    end
    % clear tmp
    tmp = zeros(6,6);
end

display ('I: Best dicision'); display(tspdec);
display ('I: Minimal result'); display(tspsum);
