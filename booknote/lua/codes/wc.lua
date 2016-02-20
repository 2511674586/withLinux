#!/usr/bin/lua5.1

local BUFSIZE = 2^13 -- 8K
local f = io.input(arg[1])
local cc, lc, wc = 0, 0, 0 -- char, line, word
while true do
	local lines, rest = f:read(BUFSIZE, "*line")
	if not lines then break end
	if rest then lines = lines .. rest .. "\n" end
	cc = cc + #lines
	local _, t = string.gsub(lines, "%S+", "")
	wc = wc + t
	_, t = string.gsub(lines, "\n", "\n")
	lc = lc + t
end
print (lc, wc, cc)
