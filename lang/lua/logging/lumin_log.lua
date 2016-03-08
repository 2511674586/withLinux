#!/usr/bin/lua
-- Lumin's lua Logging facility module
-- COPYRIGHT (C) 2016 Lumin Zhou
-- MIT LICENSE

local LOG = {}
function LOG.__CORE (level, dt, di, message)
	io.write(string.format('%s%02d%02d %02d:%02d:%02d %s:%d] %s',
		level, dt.month, dt.day, dt.hour, dt.min, dt.sec,
		di.short_src, di.currentline, message))
end
function LOG._CORE (level, message, ending)
	ending = ending or '\n'
	local di = debug.getinfo(3, 'Sl')
	if di == nil then return end
	local dt = os.date('*t', os.time())
	if dt == nil then return end
	LOG.__CORE (level, dt, di, message .. ending)
	return
end
function LOG.DEBUG (message)
	io.write ('\x1b[36;1m')
	LOG._CORE ('D', message)
	io.write ('\x1b[m')
end
function LOG.INFO (message)
	io.write ('\x1b[32;1m')
	LOG._CORE ('I', message)
	io.write ('\x1b[m')
end
function LOG.WARN (message)
	io.write ('\x1b[33;1m')
	LOG._CORE ('W', message)
	io.write ('\x1b[m')
end
function LOG.ERROR (message)
	io.write ('\x1b[31;1m')
	LOG._CORE ('E', message)
	io.write ('\x1b[m')
end
return LOG
