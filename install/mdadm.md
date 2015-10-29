mdadm - linux software raid
===

## Create software raid5 with mdadm


1. prepare disk. (skip)  


2. create newe raid5 with `mdadm`
```
# mdadm -C /dev/md0 -a yes -l5 -n3 -x0 /dev/sdb /dev/sdc /dev/sdd
```

3. check state
```
# mdadm -D /dev/md0
```

4. make filesystem and mount
```
# mkfs.ext4 /dev/md0
# mount /dev/md0 /mnt
```

5. setup raid in configure files
```
# mdadm -Ds /dev/md0 >> /etc/mdadm.conf
# blkid
# vim /etc/fstab
+ /dev/md0 /mnt ext4 defaults 0 0
OR
+ UUID=xx /mnt ext4 defaults 0 0
# cat /proc/mdstat
# mdadm -D /dev/md0
```

6. simulate disk failure
```
# mdadm /dev/md0 --fail /dev/sdd
# mdadm -D /dev/md0
# mdadm /dev/md0 --remove /dev/sdd
# mdadm --zero-superblock --force /dev/sdd
# mdadm /dev/md0 --add /dev/sdd
```

7. stop an md
```
# mdadm -S /dev/md0  ## and then edit fstab, mdadm.conf
```

8. assemble md
```
# mdadm -A /dev/md0 /dev/sdx /dev/sdy /dev/sdz
```


### Ref
https://wiki.gentoo.org/wiki/Filesystem/Security  
https://wiki.archlinux.org/index.php/RAID  

