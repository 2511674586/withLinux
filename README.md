## With Linux - Brief Hacks

Linux tricks, hints, hacks and many others based on my personal experience with
[Debian GNU/Linux](https://www.debian.org). This project is a personal knowledge
base, and some of the hints and hacks there are just recored by keywords.  

One way to use this project is to clone it to your machine,
and lookup keywords within it with the perl utility `ack`.  
  
Items marked with `(-)` are still in progress.  
  
[Installing Linux](./install)  
---
1. [Install linux into an USB drive](./install/install-linux-into-usb-stick.txt)  
2. [Tips about Drivers and firmware](./install/dri)  
  1. [Graphic card](./install/dri/graphic_card_driver.txt)  
  2. [Wireless network card](./install/dri/wireless.txt)  
3. [Turning off graphic card](./install/turn-off-gpu.txt)  
4. [Tips about Solid State Drive (SSD)](./install/ssd.txt)  
5. [Some packages related to EFI/UEFI](./install/efi.txt)  
6. [My old installation log for a HP server](./install/hpserver)  
7. [Bootstrap minimal/stage3 Debian system](./install/bootstrap)    
8. [Simple ArchLinux install note](./install/arch)  
9. [mdadm note for creating software md5](./install/mdadm.md)  
10. [(-) Trying Gentoo is worthwhile](./install/gentoo)  

[Utilities / Miscellaneous](./basic)  
---
1. [Example usage of netcat](./basic/netcat.txt)  
2. [bash tricks](./basic/bash_tricks.txt)  
3. [Commands for fun](./basic/funny_commands.txt)  
5. [conky, a system monitor, example rc file](./basic/conkyrc.txt)  
6. [GPG short note](./basic/short_gpg.txt)  
7. [Data recovery tools](./basic/data-recover.txt)  
8. [Remove data safely](./basic/remove-data-safely.txt)  
9. [Encrypting disk with LUKS](./basic/disk-crypt.txt)  
10. [Example usage of avconv, an alternative to ffmpeg](./basic/avconv.txt)  
12. [Using vim, convert code into html](./basic/vim_html.txt)  
13. [ffmpeg, resize picture and video](./basic/ffmpeg_resize_picture.txt)  
14. [imagemagick, resize, trans-format, rotate picture](./basic/imagemagick.txt)  
15. [xset, change keyboard input delay/rate under X](./basic/keyrate)  
16. [ssh-agent, let it memorize your ssh password](./basic/ssh-agent.txt)  
17. [Busybox, all-in-one software, developer works](http://www.ibm.com/developerworks/cn/linux/l-busybox/index.html)  
18. [JPEG integrity check](./topic/jpeg-int.md)  
19. Games on Linux  
  1. [Terraria with Wine32, on Linux](./topic/terraria.md)  
20. [Git ... content tracker](http://www.git-scm.com/)  
  1. [set up git ... github help](https://help.github.com/articles/set-up-git)  
  2. [a git tutor ... git immersion](http://gitimmersion.com/)  
  3. [git ... merge 2 repos into 1](./basic/git_merge_repo.txt)  
1. [iceweasel ... cache config, of iceweasel (firefox)](./internet/iceweasel-cache.txt)  
2. [chromium ... cache directory config](./internet/iceweasel-cache.txt)  
23. Log Analysis  
  1. awk programming language  
  2. apt-get search {visitors,awstat}  
24. [A long list of Linux utilities](basic/util_list.md)  

[Graphical Interface Stuff (Xorg)](./x)  
---
1. [Gnome3 (gnome-shell)](./x/gnome)  
  1. [change the height of top bar ... modify](./x/gnome/topbar.md)  
  2. [against BUG: alacarte empties gnome menu ... wheezy](./x/gnome/alacarte.txt)  
  3. X11 default display manager ... /etc/X11/default-display-manager  
2. [LXDE](./x)  
  1. [set shortcut keys under LXDE](./x/lxde-shortcut)  
3. Desktop Managers, X11 login program  
  1. [gdm3] and [kdm], too heavy  
  2. [sddm] for plasma5  
  3. [lightdm] and [slim] are light and small  
  4. [jwm], [cwm], [twm], [i3-wm]  
5. Graphical Virtual terminals  
  1. [gnome-terminal], [guake], [uxterm], [lilyterm]  

[Internet Specific](./internet)  
---
5. ifup and ifdown setting ... see interfaces(5)
2. [vpn ... set up on debian](./internet/vpn.txt)  
3. [ping ... no reply to icmp ping](./internet/ping.txt)  
4. [port ... what is running on a port](./internet/port.txt)  
6. [share the network with other machine ... one of cases](./internet/share-network-between-linux.txt)  
7. [share-ipv4-with-ipv6-tunnel ...](./internet/share-ipv4-with-ipv6-tunnel.txt)  
8. [openvpn ... simple utilization](./internet/openvpn.txt)  
9. [802.1X auth ... ref link](./internet/802auth)  
10. [iptables howto ... ubuntu help](https://help.ubuntu.com/community/IptablesHowTo)  
11. [miredo note ... IPv6 Net with Teredo](./internet/miredo.md)
12. [isatap ... IPv6 with ISATAP](./internet/isatap.txt)
13. [script for listing available wifi SSIDs](./internet/wifilist)  
14. HTTP status code reference  
  1. RFC2616  
  2. [list of http status codes ... wikipedia](http://en.wikipedia.org/wiki/List_of_HTTP_status_codes)  
15. Sharing files through network  
  1. [nc](./basic/netcat.txt)  
  2. scp, ssh, rsync.  
  3. samba server.  
  4. http server, like apache2. OR [python](./topic/python.txt)   
  5. ftp server, like vsftpd.  
  6. NFS  
16. Dynamic Name Service   
  1. [list of DNS record types ... useful with dig(1)](http://en.wikipedia.org/wiki/List_of_DNS_record_types)  
  2. [comparison of DNS server software](http://http://en.wikipedia.org/wiki/Comparison_of_DNS_server_software)  

[System Management / Server](./config)  
---
1. [tzdata ... change the system time zone](./config/time_zone_change.txt)  
2. [grub2 ... location of config files](./config/grub_config_file_location.txt)  
3. [Config runlevels (sysvinit) ...](./config/runlevel.txt)  
4. [Font in tty ...](./config/tty-font.txt)  
5. [Networkmanager ... can't change network settings?](./config/networkmanager.txt)  
6. [bashrc ...](./config/bashrc.txt)  
7. [Google earth ... install on amd64](./config/gearth.txt)  
8. [grub ... boot with kali iso image](./config/grub_kali_iso.txt)  
9. [time ... hardware time](./config/hardwaretime.txt)  
10. [Silence ... no beep from machine](./config/silent_beep.txt)  
11. [Smart ... smart attributes](./config/smart.txt)  
12. [Steam ... install steam on amd64](./config/steam.txt)  
13. [Sudo ...](./config/sudo.txt)  
14. [Wine ... on amd64](./config/wine.txt)  
15. [dpkg ... backup and restore package list](./config/pkglist.txt)  
16. [font ... install font](./config/font.txt)  
  1. [some open source fonts](./config/font_list.txt)  
17. [systemd ... some reference link](./config/systemd_link.txt)  
18. [source.list ... example](./config/sources.list)  
19. [apt preference control file for APT](./config/apt_preference.txt)  
20. [sshd security ... sshguard](./config/sshguard.txt)  
21. [sshd SFTP chroot ... ](./config/ssh.txt)  
22. [Ext2/Ext3/Ext4 on Windows](http://blog.csdn.net/hansel/article/details/7557033)  
  1. [ext2Fsd](http://www.ext2fsd.com/)  
  2. [Ext2Read](http://sourceforge.net/projects/ext2read/)  
  3. [Ext2IFS](http://www.fs-driver.org/)  
  4. [DiskInternals Linux Reader for Windows](http://www.diskinternals.com/linux-reader)  
1. [vsftpd ... a simple setup](./server/BriefVsftpd.tex)  
2. [dnsmasq ... local cache name server](./server/dnsmasq.txt)  
3. [apache2 (2.2.22) ... simple setup](./server/apache2.txt)  
4. [bind9 (debian)... DNS (cache) - config file](./server/named.conf.options)  
5. [hostapd ... dev work](http://www.ibm.com/developerworks/cn/linux/l-wifiencrypthostapd/index.html)  
6. [udhcpd from busybox]
7. [gitlab ... official deb setup](./server/gitlab.md)  

[Programming under Linux](./lang)  
---
1. [tex](./lang/tex)  
  1. [use opentype font in tex](./lang/tex/tex-opentype-font.txt)  
  2. [xelatex ... chinese support, xeCJK](./lang/tex/xelatex.cjk.tex)  
  3. [pdflatex ... eng chs mixed sample tex](./lang/tex/eng_chs_mixed_sample.tex)  
  4. [finding the right font](http://www.tug.dk/FontCatalogue/)  
2. [C ](./lang/c/)  
  1. [printf ... colourful text in terminal](./lang/c/printf_colour.c)  
  2. [crack a C program ... simple example](./lang/c/hexed/simple-hex-edit-binaries.txt)[(foo.c)](./lang/c/hexed/foo.c)[foo2.c](./lang/c/hexed/foo2.c)  
  3. [print source file name and source line number](./lang/c/file_line_.c)  
  4. [berkely db simple demo ... ](./lang/c/db.c) and [makefile](./lang/c/Makefile)  
3. [C++](./lang/cpp)  
  1. [glog demo program](./lang/cpp/glog.cpp) and its [makefile](./lang/cpp/glog.mk)  
  2. [print source file name and source line number](./lang/cpp/file_line_.cpp)  
  3. [a BLAS demo in cpp](./lang/cpp/blas.cpp) and [its makefile](./lang/cpp/Makefile)  
  4. [template demo](./lang/cpp/template.cpp) and [its makefile](./lang/cpp/Makefile)  
  5. [stl demo](./lang/cpp/stl.cpp)  
  6. [Qt helloworld](./lang/cpp_qt/)  
3. [HTML: hello world html sample](./lang/sample.html)  
4. [Octave](./lang/oct)  
5. [GNU Make](http://www.gnu.org/software/make/manual/make.html)  
6. [CMake](http://www.cmake.org/cmake-tutorial/)  
7. [java helloworld on linux](./lang/java)  
8. [AWK](./lang/awk/)  
9. [Sed](./)  
10. [GNU BC](./)     
11. [Maxima](./)  
12. [Python3](./lang/py3)  
  1. [convert list into string](./lang/py3/list2str.md)  
13. [learn lua in 15 minutes](http://tylerneylon.com/a/learn-lua/)  
14. [Go](./lang/go)  
15. [Torch7 interface note](./lang/lua/torch/main.md)  
16. [C# hello world](lang/csharp/hello.cs)  

[Linux Kernel Hacks / Operating System](./kernel)  
---
4. [linux frozen ... handle with SysRq](./basic/sysrq.txt)  
1. [Compile linux kernel... ](./kernel/compile.txt)  
2. [MIT Xv6](https://pdos.csail.mit.edu/6.828/2011/xv6.html)  
3. [xv6-rev6](./kernel/xv6-rev6/)  
4. [Cook a minimum bootable linux / initramfs ](./minisys/main.pdf)  
1. [hard disk link power manage ... sample hack](./hack/hddpower.sh)  
2. [cpu freqency tweak ... sample hack](./hack/cpufreq.sh)  
3. [backlight](./hack/backlight.txt)  

[Virtualization](./virt)  
---
1. [docker.io ... linux container](./virt/docker/)  
  1. [install docker.io on debian](./virt/docker/docker.install.txt)  
  2. [sample run](./virt/docker/dockerizing.txt)  
  3. [make a docker image via bootstrap](./virt/docker/docker.make.image.txt)  
4. X86 dosbox emulator, (dosbox)  

[Cluster / HighPerf](./cluster)  
---
1. [storm local setup ... apache inqubator, storm](./cluster/setup-local-storm.txt)  
2. [PBS - Cluster Job Management](./cluster/pbs)  
3. [parallel computing note](./cluster/parallel.intro.txt)  

[Kali / Security / Penetration](./kali)  
---
1. [tools list](./kali/tools.txt)  
2. [nmap note](./kali/nmap.txt)  
3. [nping note](./kali/nping.txt)  
4. [preventing buffer overflow](http://www.ibm.com/developerworks/cn/linux/l-sp/part4/index.html)  
5. [External resources](./kali/resource.md) 
6. [ARP spoof](kali/arpspoof.txt)  
7. [AirCrack](kali/aircrack.txt)  
8. [aircrack-ng](kali/aircrack-ng.txt)  

[Debian GNU/Linux Specific](https://www.debian.org/)  
---
1. [setup unofficial debian archive](./debian/unofficial_archive.txt)  
2. [setup debian mirror](https://www.debian.org/mirror/ftpmirror)  

[My Personal Booknotes](booknote/)    
---
1. [C Primer Plus](./booknote/cprimerplus/cprimerplus.md)  
2. [(in progress) C++ Primer Plus](./booknote/cppprimerplus/cppprimerplus.md)  
3. [K&R C](./booknote/kr_c/)  
4. [Vbird Basic](./booknote/vbird_basic/vbird_basic.md)  
5. [Vbird Server](./booknote/vbird_server/main.md)  
6. [(in progress) Programming in Lua](./booknote/lua/main.md)  
7. [ANN in Matlab](./booknote/ann_matlab/)  
8. [lshort](./booknote/lshort/)  
9. [Network Countermeasure](./booknote/NetworkCountermeasure/)  
10. [UNP-I](./booknote/UNP-I/)  
11. [Beauty of math](./booknote/beautyofmath/main.md)  
12. [TLPI - Volume 1](./booknote/LinuxProgrammingInterface/TLPI.txt)  
12. [TLPI - Volume 2](./booknote/LinuxProgrammingInterface/TLPI2.txt)  
13. [Hacker Debugging Uncovered](./booknote/HackerDebuggingUncovered/)  
14. [(in progress) Linux System Programming (Rober Love)](./booknote/LinuxSysProg/)   
15. [Computer Security (index only)](./booknote/ComputerSecurity/)  
16. [Computer Vision](./booknote/ComputerVision/)  
17. [Debug Hacks](./booknote/DebugHacks/)  
18. [Denial Of Service Attack](./booknote/DenialOfServiceAttack/)  
19. [Fundamentals Of Multimedia](./booknote/FundamentalsOfMultimedia/)  
20. [Gray Hat Hacking](./booknote/GrayHatHacking/)  
21. [Game Theory non-technical](./booknote/GameTheory_non-technical/)  
22. [Metasploit](./booknote/Metasploit/)  
23. [RHEL](./booknote/rhel/)  
24. [Linux Kernel Hack](./booknote/LinuxKernelHack/)  
25. [Linux Networking Cookbook](./booknote/LinuxNetworkingCookbook/)  
26. [Play with data structure](./booknote/Playwithdatastructure/)  
27. [EE - from a EE open course](./booknote/EE.txt)  
28. [Thinking Python](./booknote/ThinkingPython/)  
29. [Information Security Introduction](./booknote/InfoSecIntro/)  
30. [MATH PHYS GAME PROGRAMMING](./booknote/MATH-PHYS-GAME-PROGRAMMING/)  
31. [High Performance Linux Server Programming](./booknote/HighPerfLinuxServerProg/)  
32. [Building High Availability Linux Servers](./booknote/BuildHighAvailabilityLinuxServers/)  
33. [Image Processing](./booknote/ImageProcessing/)  
34. [DevOps Troubleshooting](./booknote/DevOpsTroubleshooting/)  
35. [Intel Micro Processor](./booknote/IntelMicroProc/)  
36. [Math.describing.nature](./booknote/Math.describing.nature/)  
37. [TAOCP Knuth](./booknote/taocp/main.md)  
38. [(in progress) BOP](./booknote/bop/main.md)  
39. [(in progress) ACM Reference](./booknote/acm/main.md)  

[looking for help?](http://173.194.72.31)  
---
wiki, doc, tutorial

1. [Wikipedia ... looking up basic concept](http://wikipedia.org)  
2. [Debian wiki ... ](https://wiki.debian.org)  
3. [Arch wiki ... ](https://wiki.archlinux.org)  
4. [Gentoo wiki ... ](https://wiki.gentoo.org/wiki/Main_Page)  
5. [stackoverflow](http://stackoverflow.com)  
6. [Funtoo wiki](https://wiki.funtoo.org)  
7. [IBM Developer works](https://www.ibm.com/developerworks/cn/linux/)  
8. [Linux kernel document](https://www.kernel.org/doc), also shiped within kernel.tar.xz:/doc  
9. [Gentoo doc ...](http://www.gentoo.org/doc)  
10. [FreeBSD doc ... sometimes helps](https://www.freebsd.org/docs.html)  
11. [OpenBSD docs]
12. [vbird.org ... detailed, complete linux guide](http://linux.vbird.org)  
13. [from windows to Linux, beginner ... IBM developer works](http://www.ibm.com/developerworks/cn/linux/l-roadmap/index.html)  
14. Search Engines
  1. google  
  2. shodan  
  3. wangpansousuo

Open Source Licenses
---
1. [gpl-faq](http://www.gnu.org/licenses/gpl-faq.html#NoticeInSourceFile)  
  
## LICENSE
```
MIT LICENSE.
COPYRIGHT (C) 2014,2015,2016 Lumin
```  
---
Started on 2014/06/28 by Lumin Zhou  
  
Seek for UNIX, look into UNIX, follow the UNIX, play with UNIX, work with UNIX, learn from UNIX,
but neither becoming an UNIX, nor marrying UNIX. -- lumin  
