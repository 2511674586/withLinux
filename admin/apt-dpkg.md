Backup and restore package selections with apt/dpkg  
---

Backup package list:
```shell
# dpkg --get-selections > pkg.list
```
Restore:
```shell
# dpkg --set-selections < pkg.list
# apt-get -u dselect-upgrade # this will pull and install all missing packages
```
see dpkg(1)

Sources.list  
---
```shell
# To add an CD-ROM, use apt-cdrom

deb file:///debian jessie main contrib non-free

deb http://ftp.cn.debian.org/debian jessie main contrib non-free
deb http://ftp.cn.debian.org/debian jessie-backports main contrib non-free
deb http://ftp.cn.debian.org/debian jessie-proposed-updates main contrib non-free
deb http://ftp.cn.debian.org/debian-security jessie/updates main contrib
deb http://ftp.cn.debian.org/debian unstable main contrib non-free
deb http://ftp.cn.debian.org/debian experimental main contrib non-free

deb-src http://ftp.cn.debian.org/debian jessie main contrib non-free
deb-src http://ftp.cn.debian.org/debian unstable main contrib non-free

deb http://ftp.cn.debian.org/debian jessie main contrib non-free
deb-src http://ftp.cn.debian.org/debian jessie main
```

APT preferences  
---
see `apt_preferences (5)`

List and Search package contents  
---
```shell
$ dpkg -S pkg  # to search installed package content
$ dpkg -L pkg  # to list installed package content
$ apt-file sesarch file  # search file among both installed and uninstalled packages
```

Package dependency
---
```shell
$ apt-cache depends pkg
$ apt-cache rdepends pkg

# aptitude can resolve some tough dependency situation
$ aptitude install pkg-with-dependency-trouble
```
