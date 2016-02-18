#!/bin/bash

# files under /sys/devices/system/cpu/cpu${I}/cpufreq/
# 	may offer you some info.
#	where $I is a number.
# works on kernel 3.14.
# c.d.luminate

set_powersave () {
	for I in $(seq 0 3); do
		echo powersave > /sys/devices/system/cpu/cpu$I/cpufreq/scaling_governor
	done
}

dump_state () {
	for I in $(seq 0 3); do
		cat /sys/devices/system/cpu/cpu$I/cpufreq/scaling_governor
	done
}

case $1 in
"dump")
	dump_state
	;;
"powersave")
	set_powersave
	;;
*)
	echo "unrecogonized action"
	;;
esac
