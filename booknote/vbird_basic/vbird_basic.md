# vbird's linux manual

```
this is a series of droped text from vbird's linux.  

 Type : plain text  
 Author :  cdluminate  
 last modified : 23 / 03 / 2014  
```


1.计算机概论
---
```
risc cisc
参考书目：计算机组成与设计：硬件/软件接口，机械工业出版社
```

2.什么是linux
---
GPL

3.如何学习
---
...

4.主机规划与磁盘分区
---
```
设备命名参考资料：kernel.org/pub/linux/docs/device-list/devices.list
BIOS开机流程：BIOS， MBR， Boot Loader， Kernel ?? POST
UEFI开机流程：
NAT
SAMBA Server
Mail Server
Web Server
DHCP Server
Proxy Server
FTP Server
分区规划：分析未来用途。大容量目录，读写频率高的目录分离出来--挽救起来比较容易
addition：幸运的用户可以用fsck解决磁盘问题
/boot:大硬盘+BIOS可以将其独立
磁盘第一个扇区：446byte MBR， 64byte 分区表
```

5.安装与多重引导
---
```
BIOS
UEFI
languages, locales
keymap
partitioning
LVM
SWAP
RAID
网络
IPv4
IPv6
MAC
时区
UTC
GMT
账户和密码
软件选择
基本系统设置
```

6.登陆和帮助
---
```
window manager
session
切换tty和X
```

6.1 基础命令
---
```
大小写敏感
$LANG
echo回显
date日期时间
cal日历
bc计算器：scale=N设置小数位数为N
tab
ctrl+c
ctrl+d
man
info
whatis
apropos
nano/vi：editor
who
netstat -a
ps -aux
shutdown
reboot
halt
poweroff
sync
init（not the same as systemd）
passwd
```

6.2 man的section
---
```
       1   Executable programs or shell commands
       2   System calls (functions provided by the kernel)
       3   Library calls (functions within program libraries)
       4   Special files (usually found in /dev)
       5   File formats and conventions eg /etc/passwd
       6   Games
       7   Miscellaneous  (including  macro  packages  and  conventions), e.g.
           man(7), groff(7)
       8   System administration commands (usually only for root)
       9   Kernel routines [Non standard]
```

6.3忘记root密码
---
```
内核参数single
内核参数1
```

7.文件权限与目录配置
---
```
root
owner
others
Permission denied
ls -al的输出数据：
权限 连接数 所有者 用户组 文件容量 修改日期 文件名
chgrp
chown
chmod
addition：cp会复制执行者的属性和权限
r：4, w：2, x：1
touch
cd
su - 
特殊字符与文件系统
linux目录配置标准FHS
/usr ： UNIX Software Resource
绝对路径与相对路径
uname -r 可以查看内核版本
lsb_release -a 可以查看发行版
.* 隐藏文件
```

8.文件与目录管理
---
```
目录与路径
绝对路径和相对路径
目录操作：. .. - ~ ~ACCOUNT(ACCOUNT用户的home)
cd
pwd print working directory
mkdir
rmdir
$PATH 可以添加'.'
ls -a all -d dir -h human -i inode -l list --color --full-time
cp -a(pdr) -f force -i interactive -l hardlink -r recursive -s symbollink
rm -f force -i interactive -r recursive(dangerous!)
mv
rename
cat
tac
nl
more
less
head
tail
od
touch
umask umask -S 第一组是特殊权限 umask的数字为补齐，不是直接的权限
chattr lsattr，extN（N>1） only：： S.Sync a.append-only i：immutable
特殊权限 SetUID SetGID see man chmod
file
（magic）
which
type
whereis
locate，updatedb
mtime ctime atime 
find : -xtime N : N: n-前n天 +n-n天前 -n-n天内
	-user -group -name -size -type -perm(ission)
adduser useradd
id
su
```

9.磁盘与文件系统
---
```
ext2/3/4
硬盘组成（由外圈往内写入）
主轴电机
CHS 柱面磁头扇区
LBA
MBR
ext2：super block, inode, block
dumpe2fs:dump ext2 file system information
df
du
Linux VFS
ln   hard link, symbol link
addtional: another method to link : mount --bind
partitioning: fdisk, cfdisk, gdisk(GPT), GNU parted
mkfs, mkfs.*
mke2fs(mkfs.ext2)
fsck
badblocks
mount/umount
mknod
reference:kernel.org/pub/linux/docs/device-list/devices.txt
hdparm
fsck
SATA
开机挂载：/etc/fstab /etc/mtab
reference : mount parameters
dd
partprobe : re-read the partition table
mkswap
swapon/swapoff
free
additinal : in order to improve performance, the linux file system caches many files in RAM.
```

10.file & compressing & make package
---
```
RFC1952
.z
.gz gzip,zcat 
.bz2 bzip2, bzcat
.tar tar -J/j c/x v :: tar.xz tar -Jcv -f FILE ARCH :: de-tar.xz tar -Jxv -C DEST -f FILE
.xz
dump,restore
mkisofs
(xorriso : in jessie)
cdrecord(not exist in jessie source)
dd : see man dd. TODO : citation of sector-level operation.
cpio : 
  cpio -ovcB > FILE|DEVICE : backup
  cpio -ivcdu < FILE|DEVICE : restore
  cpio -ivct < FILE|DEVICE : view
  find / | cpio -ovcB > /dev/st0
  cpio -idvc < /dev/st0
```

11.vi/vim text editor
---
```
see vimtutor
see man vim
:N1,N2s/WORD1/WORD2/g 替换
:N1,N2s/WORD1/WORD2/gc 替换，确认
:%s/WORD1/WORD2/g
~/.vimrc
~/.viminfo
:set nu
:set nonu
:set [no]autoindent
:set backup
:set ruler
:set showmode
:set
:syntax on/off
LANG
dos2unix, unix2dos
```

12.recognize bash
---
```
recognize hardware, kernel, and shell
/etc/shells
sh,bash,ksh,tcsh,csh,zsh
type 内置命令
varibles : 
  echo, unset
  env, export
  set, declare
PS1 : 命令提示
PS2 ： 换行后的提示符
see man bash
$ ? 1 2
locale
(dpkg --reconfigure locales -> this is a debian package managing the locales)
var reading from keyboard : read ( a bash buildin ) , type read, see bash$ help read
array var : how to set : $ VAR[N] = content
ulimit : type ulimit, see bash$ help ulimit
editing vars
... ...
[un]alias
history, ~/.bash_history
ctrl+R : shortcut his search
!!, !NUMBER
/etc/issue : welcome message in booting and before login
/etc/motd : welcome message while login-ing
configure files: ~/.bashrc /etc/profile ~/.bash_login||~/.profile /etc/inputrc(hot keys, sounds) ~/sysconfig/i18n(LANG) ~/.bash_logout
source : type ~, read conf, builtin, source CONF-FILE
ctrl+C : interupt
ctrl+D : EOF, end typing, it can also be for logout
ctrl+M : Enter
ctrl+S : Stop screen , somewhat freeze the screen
ctrl+Q : continue the screen output
ctrl+W : delete a world forwards
ctrl+U : delete a whole command
ctrl+Z : pause current ? or throw it to background
通配符wildcard :
 * 0-infinite chars
 ? 1 certain char
 [] must included in [], e.g [abcd] means there must be one among "a,b,c,d". [a-d]. [^abc] ^ means not included.
except for wildcards there are still bunch of special symbols :
 # comment
 \ 转义
 | pipe
 ; divide
 ~ current user's home
 $ var前导
 & job contorl, draw to background
 ! logical not
 / dir
 > >> < << redirection
 ' ' no var replacing
 " " with var replacing
 ` CMD ` run CMD first, also works as $()
 () : 中间为子shell的起始和结束
 {} ： 中间为命令块组合
Stream redirection
 standard input : stdin,0
 stdout,1
 stderr,2
  --see man stdin
 > < >> << 
 1>[>] 2>[>]
 stdout与stderr: 
  1. COMMAND &> OutputFILE
  2. COMMAND > FILE 2>&1
   experiment material : /bin/cat
, && ||
cmd && cmd || cmd
cmd || cmd && cmd
pipe : |
  toys for pipe:
   echo $PATH | cut -d ':' -f 2
   echo $PATH | cut -d ':' -f 2,3,4,6
   export | cut -c 12-
   export | cut -c 12-20
   grep : -a incl binary files, -c count lines, -i ignore case, -n number, -v 反向选择, --color=auto
     detail see man grep
sort
  seq 1 20 | sort -R | sort | sort -n
  cat /etc/passwd | sort -t ':' -k 3
wc
uniq
  last | cut -d ' ' -f 1 | uniq -c
  last | cut -d ' ' -f 1 | sort | uniq -c
double redirection : tee(1)
commands about string : 
 tr : translate or delete characters
 col : translate special characters, see also cat -A
 join : see man, join to relative file together, not head-to-tail joining.
 paste : compare to 'join', directly join 2 text together.
 expand : transform [tab] to [space]
 split : split file into pieces
 xargs : compare '` `', an amount of utils don't support pipe
 - : with pipe
  e.g. $ tar -cvf - /home | tar -xvf -
```
 
13.正则表达式(Regular expression)，文件格式化处理 
---

13.1 base RE
---
```
 grep:
 LANG influences it
 LANG=C 01234...ABC..abc..z
 LANG=zh_CN 01234..aAbBcC...zZ
 POSIX
 ::see man grep
 [:alnum:] all num alphabet
 [:alpha:] all alphabets
 [:blank:] tabs and spaces
 [:cntrl:] controling chars, CR LF tab del etc..
 [:digit:] as it is
 [:graph:] keys except for tab & space
 [:lower:]
 [:upper:]
 [:print:] printable
 [:punct:] punctuations
 [:space:] CR space tab
 [:xdigit:] hex digits, 0-9 a-e/f? A-E/F?
 grep [-A] [-B] [--color=auto] 'Search_Pattern' filename
 行尾 ^$ : grep '^the' -> 'the' is not at head of line
           grep '^[a-z]' -> line is not begined with [a-z]
 转义字符\
 here the point '.' -> any char
                '*' -> repeat char
 repeat range limitation : {}
     grep 'o\{2\}' : repeat twice , because {} is special to bash
 base RE characters
	^word : pattern at head of line
	word$ : pattern at tail of line
	.     : any one chars
	\     : escape 转义
	*     : repeat 0-Inf the char before
	[list]: pick one from the list,, among them 
	[n1-n2]: in charset from n1 to n2, afected by LANG
	[^list]: not included in list
	\{n,m\} : '{}' should be escaped, \{n\} continuosly n same chars , 'n,' n to Inf, ',n' 0 to n
sed -e --expression -n -i
	actions : [n1[,n2]]function :: n1,n2 is line number, line n1 to n2
	function : a-append, c-change, d-delete, i-insert, p-print, s-substitude 's/OldPattern/NewPattern/g'
	CMD | head -n n2 | tail -n n1 :: sed -n 'N,Mp'
extended RE
	+ : repeat the char before : go+d, god, good, goood ...
	? : 0|1 RE-char before : go?d
	| : or
	() : group : searching glad/good 'g(la|oo)d'
	()+ : repeat group
	P.S. '!' and '>' is not special char
printf : see man : see c.function -> printf()
awk 'if_1{do} if_2{do} ...'
	most used : e.g. : last | awk '{print $1 "\t" $3}' : colomn 1 and 3, process line by line, $0 is the whole line
	inside variables :
		NF : colomns each line ($0)
		NR : current processing line number
		FS : current divider, default is ' '
	awk also has
		> < >= <= == != =
	declare var : e.g. total = $1 + $2
	awk 'BEGIN {FS=":"} ...'
diff From-File To-File : line by line
cmp - compare two files byte by byte
pr convert text files for printing
```

14.shell script
---
```
 从上到下，从左到右执行
 读取到CR符号开始执行
 \可以转义Enter
 # comment
<sample>:
#!/bin/bash
# Program's function or purpose
# History
# ISSUE
# $date $username
PATH=...
export PATH
echo .
exit 0
<end sample>.
脚本应该包含
 功能
 版本
 作者 联系
 版权
 历史
 特殊命令用绝对路径
 设置环境变量
simple script:
 1. interactive script
	read -P "Please input ..." var #prompt #this is a bash-builtin, see man bash /SHELL BUILTIN
calculating
 var = $(( expression ))
test
[ : man [
$0 : itself
$1, $2 ... : args
$# : argc
$@ : $1, $2 ...
$* : $1 $2 $3 ...
shift : 参数变量号码偏移
if [ expr ]; then
	do
fi
if [ expr ]; then
	do
else
	do
fi
if [ expr ]; then
	do
elif [ expr ]; then
	do
else
	do
fi

case $var in
	"content")
		do
		;;
	*)  # wildcard, like default
		do
		;;
esac

function FNAME() # function should be placed at the head of a script
{
	sth
}
函数也拥有内置变量$0 $1 $2


while [ condition ]
do
	paragraph
done

until [ condition ]
do
	paragraph
done

for VAR in con1 con2 con3
do
	paragraph
done
first time $var = con1
second time $var = con2
third time $var = con3

seq : see man seq

for ( ( init_value; limit; step ) )
do 
	para
done

注意空格，空格可能导致不必要的问题和错误
sh [-nvx] script , bash -x script : line by line run
```

15.account manage & ACL
---
```
	UID/GID
	user account
	/etc/passwd
		"account:password:UID:GID:info:HOME:shell"
		UID range: 0 :root
			1-499 system account
			500-65535+ login-able accounts
	/etc/shadow
		"account:passwordhash:lastmodify:lock(unchangable)time:needchangeafter:deadlinewarn:deadlinepass:accountavail:reserve"
	date --date
	/etc/group
		"group:grouppassword:GID:member"
		有效用户组，初始用户组
		usermod
		groups
		newgrp:change effective group
	/etc/gshadow
		"group:password:admin_account:owner"
	account management
		useradd
		adduser
		groupadd
		addgroup
		passwd
		/etc/pam.d/passwd
		/etc/login.defs
		change:detailed passwd manage
		usermod
		userdel
		groupmod
		groupdel
		gpasswd
		chgrp
	user
		finger USER
			plan: ~/.plan
		chfn : change finger
		chsh : change shell
		id USER
	ACL
		individually permission control
		mount -o remount,acl : to activate it.
		setting acl
			getfacl
			setfacl
			"u:USER:PERMISSION"
	change user id
		su - : login-shell env file
		su   : non-login shell
		sudo 
			adduser sudo
			visudo, /etc/sudoers
			%wheel ALL=(ALL) NOPASSWD: ALL
			myuser1 ALL=(root) !/usr/bin/passwd [A-Za-z]*, /usr/xxx
	/sbin/nologin
	PAM
		/etc/pam.d
		/lib/security/
		/etc/security/
		/usr/share/doc/pam
		limits.conf
	w,who,last,lastlog
	write,mesg,wall
	mail

	some tool
		pwck
		pwconv
		pwuconv
```

16.Quota & Disk management
---
```
	文件系统支持userquota,grpquota
	新建配置文件quotacheck
	quotaon：启动 quotaoff
	edquota：编辑配置
	quota：报表
	repquota：针对文件系统作报表
	warnquota
	setquota

	SOftware RAID
	mdadm
	partprobe：更新内核的分区表

	LVM
		PV physical volume
		VG volume group
		PE physical extend
		LV logical volume
		
		1.fdisk
		2.pvcreate,pvscan
		3.vgcreate,vgdisplay
		4.lvcreate,lvdisplay
		5.mkfs,mount

		linear write/triped write
```

17. crontab
---
```
	at : atd
	crontab : crond
	常见的例行性工作
		log rotate
		logwatch
		updatedb(locate)
		whatis database
		RPM software log creation
		delete temporary files
		analyse work related to network services
	at
		/etc/init.d/atd restart
		/var/spool/at/ : task list
		at.allow: if exist,users in this file can use at, if not, then the user can't use at. 
		at.deny
		* if at.allow and at.deny are not exist, only root can use at.
		e.g. $ at now + 5 minutes
		> echo at
		then there would be no output on your screen, but when you see your mailbox.
		atq : at query
		atrm : delete at
		batch : run when system is idle (avgload < 0.8 )
		batch : managed by atd.
	cron
		/etc/cron.allow
		/etc/cron.deny
		/var/spool/cron
		crontab : see man crontab
		/etc/crontab : system-wide crontab
	anacron
		/etc/anacrontab
		anacron : 执行关机期间的cron
```

18. program manage, selinux
---
```
进程和程序process,program
子进程与父进程
	如何判断某个进程的父进程：PPID Parent PID ：ps -l：ps xl
fork and exec：过程调用的流程
系统或网络服务，常驻内存的进程
linux的多用户，多任务
	多用户环境
	多任务行为
	多重登录环境的7个基本终端窗口
	特殊的进程管理行为
	工作管理job control ： &
	系统资源分配
工作管理
	/etc/security/limits.conf 可设置用户的同时登录数
	foreground
	background
	&
	暂停工作：ctrl Z
	jobs：查看工作状态
	fg %jobnumber
	bg 暂停变为运行中
	kill %N
	kill -SIGTERM 与 -15一样
	-9信号通常用于删除一个不正常进程
	man kill
	man 7 signal
	at
	nohup 脱机或注销之后继续运行工作
进程管理
	查看进程：ps， pstree， top
	ps aux
	ps -l : only list processes that are related to this session of bash
	ps signs:
		Flags
			4:root
			1:fork but not exec
		Stat
			Running
			Sleep(Idle)
			D unawakenable
			sTop
			Zombie
	UID/PID/PPID
	SIGHUP 1
	SIGINT 2 - ctrl^C
	SIGKILL 9
	SIGTERM 15
	SIGSTOP 17 ctrl^Z
	Priority : PRI
	Nice :NI
	free
	uname
	uptime
	netstat -tlnp
	dmesg
	vmstat
SUID/SGID
	SUID
		仅对binary有效，需要x权限，权限仅限执行过程，执行者具有持有者权限
		find . -perm 6000
/proc/*
	cmdline
	cpuinfo
	devices
	filesystems
	interrupts
	....
inspect opened files or files opened by binary.
	fuser
	lsof
	pidof
Look into SELinux
	传统文件权限与帐号的关系：自主访问控制，DAC
	策略规则特定程序特定文件：委托访问控制，MAC
SELinux的运行模式
	主体：进程
	目标：主体能否访问目标资源
	策略：targeted/strict
	安全上下文security contest：Identify，Role，Type

	启动关闭与查看
	getenforce ：enforcing，permissive，disabled
	setstatus ： list selinux policy
	/etc/selinux/config
	内核参数selinux=0
	chcon:调整selinux 安全上下文
	ls -Z
	restorecon
	setroubleshoot
	sealert
	sesearch
	getsebool
	semanage
```

19. daemons
---
```
what is daemon / service
service : 常驻在内存中的进程，并提供一些系统/网络功能
classification of daemons
1.stand_alone
2.superdaemon
多线程和单线程
daemon工作状态类型
1.signal control
2.interval control
service, port, /etc/services
/etc/init.d/ :  service/daemon initialization scripts
/etc/sysconfig/ : (CentOS) configure file of services
/etc/xinetd.conf, /etc/xinetd.d/ : superdaemon configure file
/etc
/var/run : PID
/var/lib : databases
xinetd .. not installed as debian default
add : firewall, ufw, gufw, iptables
/etc/hosts.deny
<service(program name)> : <IP, domain, hostname> : <action>
rsync : 127.0.0.1 : deny
ALL, e.g. "ALL:ALL:deny"
LOCAL, e.g. "ALL:LOCAL:deny"
UNKNOWN: 未知的IP或者domain
KNOWN：可解析的IP或domain
/etc/hosts.allow
TCP Wrapper
To find out what services is running on this machine
	netstat -tulp
To find out all the services that is listening 
	netsta -lnp
service status
	service --status-all
/etc/init.d/
/etc/rc?.d/
chkconfig : not in debian repository
telnet
```

20. analysing log
---
```
cd /var/log
	cron : crontab
	dmesg : info when kernel is checking
	lastlog : login
	maillog OR /mail/ 
	messages : **important file**
	secure : 
	wtmp : login correctly ones
	faillog : login wrongly ones
	...services ...etc.
daemon related to it:
	syslogd <- centos 5
	rsyslogd <- debian jessie/sid
	klogd <- centos 5
	logrotate
log format
	DATE HOST SRV[PID] : VIA_WHAT_MODULE : MESSAGE
被编辑过的log文件不能继续记录，根据syslogd的规则。这一点可能会在用vim浏览后以：wq退出的情况下发生。restart the log service to solve this problem.
/etc/logrotate.conf , see man logrotate
```

21.启动流程，模块管理，loader
---
```
启动流程一览
	加载BIOS的硬件信息，自我测试，根据设置取得第一个可以启动的设备
	读取并执行第一个设备内MBR的boot loader（grub， lilo， spfdisk等）
	根据boot loader的设置，加载kernen，然后kernel开始检测硬件，加载驱动程序
	硬件驱动成功后，kernel主动调用init进程，init取得run-level信息
	init执行/etc/rc.d/rc.sysinit 文件来准备操作环境，比如网络，时区等
	init执行run-level对应的各个服务启动（script方式）
	init执行/etc/rc.d/rc.local 文件
	init执行终端模拟程序mingetty来启动login进程，最后等待用户登录
pstree
BIOS( basic input output system),CMOS,plug and play(PnP, 即插即用设备),IRQ
POST(Power-On self test)
BIOS通过硬件的INT 13中断功能来读取MBR。
------------------------------/boot---------------------------------
/boot/vmlinuz -> kernel file
/boot/initrd -> virtual filesystem file
/boot/system.map 内核功能放置到内存地址的对应表
/boot/config -> kernel compile-config file
-----------------------------------------------------------------------
内核模块放置在/lib/modules/
initrd -> initial ram disk :: man initrd
是否没有initrd就不能顺利启动？当启动时无法挂载根目录的情况下就需要initrd，比如根目录在 USB SATA SCSI 设备，或者LVM，RAID之类。IDE就可以不用
内核完整加载后，运行的第一个程序/sbin/init
init及配置文件/etc/inittab 与runlevel
init处理系统初始化流程 (/etc/rc.d/rc.sysinit )不同distro不同，他大致有这几项
	1.获取网络环境和主机类型 /etc/sysconfig/network
	2.测试和挂载内存设备/proc以及USB设备/sys
	3.决定是否启动selinux
	4.启动系统的随机数生成器
	5.设置终端机字体（console）
	6.设置启动过程中的欢迎界面 textbanner
	7.设置系统时间 clock，和时区设置
	8.接口设备的检测与PnP参数测试
	9.用户自定义的模块加载 /etc/sysconfig/modules/*.modules
	10.加载内核的相关设置/etc/sysctl.conf
	11.设置主机名，初始化电源管理模块acpi
	12.初始化软件磁盘阵列/etc/mdadm.conf
	13.初始化LVM的文件系统功能
	14.fsck
	15.进行磁盘配额quota的转换（非必要）
	16.以rw重新挂载系统磁盘
	17.启动quota功能
	18.启动伪随机数生成器pseudo-random
	19.清除启动过程中产生的临时文件
	20.将信息添加到/var/log/dmesg
启动系统服务和相关配置文件
	/etc/rc.d
	Sxx Kxx, number xx determines the sequence when they start.
用户自定义开机启动程序
	/etc/rc.d/rc.local
根据/etc/inittab的设置加载终端机或者X windows界面
启动过程中会用到的主要配置文件
	‘1 关于内核模块 /etc/modprobe.conf ： see man
	'2 /etc/sysconfig/*:authconfig, clock, i18n, keyboard, mouse, network, network-script
RunLevel的切换
	可以到/etc/inittab里设置每次开机默认进入的runlevel
	暂时修改可以直接 init N
内核与内核模块
	内核的存放位置/boot/vmlinuz, OR /boot/vmlinuz-version/
	/boot/initrd
	/lib/modules/version/kernel
	/usr/src/
	/proc/version
	/proc/sys/kernel
内核模块与依赖性
	in /lib/modules/$(uname -r)/kernel
	arch : relative to hardware platform
	crypto : encryption techs that kernel supports
	drivers : hardware drivers
	fs : file systems
	lib : function lib
	net : procotol, firewall, etc
	sound :..

	依赖性检查/modules.dep文件，"depmod -a
	lsmod, modinfo
	modprobe, insmod, rmmod
	modprobe.conf && IRQ
BootLoader : Grub
	stage1 : run main program of boot loader
	stage2 : main program load its config file
	'the config file of grub, grub.cfg(grub2), menu.lst(grub)
	mkinitrd
	grub-install
	vga=773"1024*768 8bit
	BIOS无法读取大硬盘的问题
	忘记密码 grub的kernel参数后加single或1
	init配置错误 kernel参数 init=/bin/bash
	device.map
	linux rescue
```

22. System configuration tools
---
```
	network: IP, netmask, gateway, DNS
	DHCP
	ppp0, pppoe, adsl
	firewall, selinux
	/etc/X11/xorg.conf
	/var/log/xorg.log
	CUPS : printer

	hardware info collecting
	lm_sensors
	/proc/cpuinfo
	/proc/partitions
	/proc/interrupts
	fdisk
	hdparm
	dmesg
	vmstat
	lspci
	lsusb
	iostat
	USB : EHCI enhanced host controller
	USB磁盘使用SCSI设备的代号，所以需要用U盘就得支持SCSI
	mknod
	udev&hal
	pstree
	/etc/udev/rules.d/
```

23. Software installing : source code & tarball
---
```
	make, configure
	tarball *.tar.xz *.tar.gz
	INSTALL README

	gcc hello.c
	gcc -c hello.c -> hello.o
	gcc -c f1.c f2.c -> f1.o f2.o
	gcc -o f f1.o f2.o
	gcc -O -c f1.c f2.c
	gcc -Wall -c f1.c f2.c
	add additional lib link when compiling
		gcc sin.c -lm -L/lib -L/usr/lib
			-l : add lib
			m : libm.so
			-L : lib path
			-I : include path
	
	gcc parameteres
		gcc -c a.c -> generate .o file rather than a excutable
		gcc -O a.c -c -> generete and optimize优化
		
	using make
	A make sample
# makefile
main: main.o [name1_name] name1.o
	gcc -o main [name1_name] name1.o -lm
#
	makefile.gramma.basic
# gramma
target : targetfile1 targetfile2
<tab> gcc -o PROG_NAME targetfile1 targetfile2
#
# Another makefile sample
LIBS = -lm
OBJS = main.o name.o
main: $(OBJS)
	gcc -o main $(OBJS) $(LIBS)
clean:
	rm ...
#
	env var : CFLAGS="-Wall"

	diff
	patch
		patch -pNUM < patch_file
	函数库管理
		静态函数库 .a
		动态函数库 .so
	ldconfig
	/etc/ld.so.conf
	ldd
	md5sum, XXXsum, etc.
```

24. RPM SRPM YUM
---
```
passed because i am apt user.
```

25. X Window
---
```
主要组件
	XServer：硬件管理，屏幕绘制，字体
	XClient：事件处理
	XWindowManager：特殊的XClient，负责管理所有XClient软件
	DisplayManager：提供登录需求

	从tty启动X：startx
	hostname:0	tty7	port 6000
	hostname:1	tty8	port 6001

X start experiment
	$ X :1 &  // this would start a Xorg at :1 i.e. tty8
	$ xterm -display :1 &//..
	$ xclock -display :1 &
	$ xeyes -display :1 &
	$ twm -display :1 &
	$ kill %1 ; kill %2 ...etc

X server configuration
	/usr/share/X11/fonts
	/usr/lib/xorg/modules/drivers
	/etc/X11/xorg.conf
	"vesa" is default driver.
	X Font server
		/etc/X11/fs/config
	gtf : changing resolution
```

26. Backup linux
---
```
key points towards it
	what to backup
	devices for backup
		/dev/cdrom
		/dev/st0(SCSI Tape)
		/dev/ht0(IDE Tape)
		/dev/fdX floppy
		hdX
		sdX
		lp printer
	complete backup
		dd
		cpio
	dump
	rsync
	differential/incremental backup
```

27. Compiling the kernel
---
```
	kernel
	kernel modules
	compiling
	driver : is it the duty of kernel or vendor ?

	the purpose you compile a kernel

	kernel.org
	kernel.tar.xz
		arch : hardware platform, architecture
		block : block devices
		crypto : cryption
		Doc
		drivers
		firmware
		fs : file system
		include
		init
		ipc : interprocess communication
		kernel : kernel
		lib
		mm : memory
		net
		security
		sound
		virt : virtualization

	Before compiling
		inspect hardwares
		make mrproper
		make help
		make clean

		make XXconfig
	Configure
	
	Single module compile
		as $ make fs/ntfs/
		$ cp XXX xXXX
		$ depmod -a
```

## EOF
