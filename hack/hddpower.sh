#!/bin/bash

# hddpower - a shortcut to control hard disk power mode.
# Usage : $0 (max|min)
# author : C.D.Luminate
# date : 29/04/2014
# version : 0.1

# FIXME : fixed path.
LINKPMP="/sys/class/scsi_host/host0/link_power_management_policy"
# cat it and see what it is.
# and files under /sys/class/scsi_host/host${N}/ may infers you,
# 	where N is a number. ( 0 - ? )


if [ -e $LINKPMP ]; then
	echo "[ $0 ] Operation target file accessable." > /dev/stderr
else
	echo "[ $0 ] File not exists, operation failed." > /dev/stderr
fi

case $1 in
	"max")
		echo max_performance > $LINKPMP
		echo "[ $0 ] turned <HDD> to max_performance power mode."
		;;
	"min")
		echo min_power > $LINKPMP
		echo "[ $0 ] turned <HDD> to min_power power mode."
		;;
	*)
		echo "[ $0 ] No action."
		;;
esac
