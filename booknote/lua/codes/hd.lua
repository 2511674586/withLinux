#!/usr/bin/lua5.1

local f = assert(io.open(arg[1], "rb"))
local block = 16
while true do
	local bytes = f:read(block)
	if not bytes then break end
	for _, b in ipairs{string.byte(bytes, 1, -1)} do
		io.write(string.format("%02X ", b))
	end
	io.write(string.rep("   ", block - string.len(bytes)))
	io.write(" ", string.gsub(bytes, "%c", "."), "\n")
end
