change scheduler, cfq is designed for rotational disks  
---
`/sys/block/sda/queue/scheduler` set to deadline or noop

use tmpfs to reduce ssd write   
---
vim fstab
```
tmpfs /tmp tmpfs rw,noatime,nosuid 0 0
```

mount  
---
for ssd partitions
```
UUID=... / ext4 defaults,discard,noatime,commit=300 0 0
```
where 'commit' is just optional,
'discard' is useful.
'noatime' reduces write activated by atime record.

Redirect write  
---
Deal with directories e.g. 
```
$ rm -r .cache
$ ln -s /dev/shm .cache
```

Use fstrim
---
```
$ sudo fstrim /
```

reference 
---
https://wiki.archlinux.org/index.php/Solid_State_Drives
https://wiki.debian.org/SSDOptimization

hint
---
to identify SSDs, 
```
find /sys | grep rotational
```
then
```
find /sys | grep rotational | xargs cat
```
and
```
if rotational = 0 then
	it is ssd
else if rotational = 1 then
	it is not ssd, but a hard disk
fi
```
