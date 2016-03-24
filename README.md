## With Linux - Brief Hacks
> KISS: Keep It Simple, Stupid  

Linux tricks, hints, hacks and many others based on my personal experience with
[Debian GNU/Linux](https://www.debian.org). This project is a personal knowledge
base, and some of the hints and hacks there are just recored by keywords.  

One way to use this project is to clone it to your machine,
and lookup keywords within it with the perl utility `ack`.  
  
Items marked with `(-)` are still in progress.  
Items marked with `(el)` means external link.  
  
Installing Linux  
---
1. [Install linux into an USB drive](./install/install-linux-into-usb-stick.txt)  
2. [Tips about Drivers and firmware](./install/dri)  
  1. [Graphic card](./install/dri/graphic_card_driver.txt)  
  2. [Wireless network card](./install/dri/wireless.txt)  
3. [Turning off graphic card](./install/turn-off-gpu.txt)  
4. [Tips about Solid State Drive (SSD)](./install/ssd.md)  
  1. [Gentoo wiki/SSD (el) ](https://wiki.gentoo.org/wiki/SSD)  
5. [Some packages related to EFI/UEFI](./install/efi.txt)  
6. [My old installation log for a HP server](./install/hpserver)  
7. [Bootstrap minimal/stage3 Debian system](./install/bootstrap)    
8. [Simple ArchLinux install note](./install/arch)  
9. [mdadm note for creating software md5](./install/mdadm.md)  
10. [Trying Gentoo is worthwhile (-) ](./install/gentoo)  
1. [Gentoo: Sakaki's EFI Install Guide (el) ](https://wiki.gentoo.org/wiki/Sakaki%27s_EFI_Install_Guide)  
1. [Gentoo Prefix (el) ](https://wiki.gentoo.org/wiki/Project:Prefix)  
1. [ArchLinux's application list (el) ](https://wiki.archlinux.org/index.php/List_of_applications)  

Utilities / Miscellaneous  
---
1. [Example usage of netcat](./util/netcat.txt)  
2. [bash tricks](./util/bash_tricks.txt)  
3. [Commands for fun](./util/funny_commands.txt)  
5. [conky, a system monitor, example rc file](./util/conkyrc.txt)[ another one](./util/conkyrc2.txt)    
6. [GPG short note](./util/short_gpg.txt)  
7. [Data recovery tools](./util/data-recover.txt)  
8. [Remove data safely](./util/remove-data-safely.txt)  
9. [Encrypting disk with LUKS](./util/disk-crypt.txt)  
10. [Example usage of avconv, an alternative to ffmpeg](./util/avconv.txt)  
12. [Using vim, convert code into html](./util/vim_html.txt)  
13. [ffmpeg, resize picture and video](./util/ffmpeg_resize_picture.txt)  
14. [imagemagick, resize, trans-format, rotate picture](./util/imagemagick.txt)  
15. [xset, change keyboard input delay/rate under X](./util/keyrate)  
16. [ssh-agent, let it memorize your ssh password](./util/ssh-agent.txt)  
17. [Busybox, all-in-one software, developer works](http://www.ibm.com/developerworks/cn/linux/l-busybox/index.html)  
18. [JPEG integrity check](./util/jpeg-int.md)  
19. Wine  
  1. [(el) Arch: wine](https://wiki.archlinux.org/index.php/Wine)  
  1. [Terraria with Wine32, on Linux](./util/terraria.md)  
  1. [(el) Deepin's wined cajviewer](http://packages.linuxdeepin.com/deepin/pool/main/d/deepinwine-cajviewer/)  
  1. [(el) Deepin: wine QQ](http://wiki.deepin.org/index.php?title=QQ)  
20. [Git ... content tracker](http://www.git-scm.com/)  
  1. [set up git ... github help](https://help.github.com/articles/set-up-git)  
  2. [a git tutor ... git immersion](http://gitimmersion.com/)  
  3. [git ... merge 2 repos into 1](./util/git_merge_repo.txt)  
1. [iceweasel and chromium ... cache config, of iceweasel (firefox)](./util/iceweasel-cache.txt)  
23. Log Analysis  
  1. awk programming language  
  2. apt-get search {visitors,awstat}  
24. [A long list of Linux utilities](util/util_list.md)  
1. [GPG best practices (el) ](https://help.riseup.net/en/security/message-security/openpgp/best-practices#self-signatures-should-not-use-sha1)  

Graphical Interface Stuff (Xorg)  
---
1. Gnome3 (gnome-shell)  
  1. [change the height of top bar ... modify](./x/topbar.md)  
  2. [against BUG: alacarte empties gnome menu ... wheezy](./x/alacarte.txt)  
  3. X11 default display manager ... /etc/X11/default-display-manager  
2. LXDE  
  1. [set shortcut keys under LXDE](./x/lxde-shortcut)  
3. Desktop Managers, X11 login program  
  1. [gdm3] and [kdm], too heavy  
  2. [sddm] for plasma5  
  3. [lightdm] and [slim] are light and small  
  4. [jwm], [cwm], [twm], [i3-wm]  
5. Graphical Virtual terminals  
  1. [gnome-terminal], [guake], [uxterm], [lilyterm]  

Internet Specific  
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
1. IPv6
  1. [miredo note ... IPv6 Net with Teredo](./internet/miredo.md)
  1. [isatap ... IPv6 with ISATAP](./internet/isatap.txt)
  1. [(el) microsoft: teredo](https://technet.microsoft.com/en-us/library/bb457042.aspx)  
13. [script for listing available wifi SSIDs](./internet/wifilist)  
14. HTTP status code reference  
  1. RFC2616  
  2. [list of http status codes ... wikipedia](http://en.wikipedia.org/wiki/List_of_HTTP_status_codes)  
15. Sharing files through network  
  1. [nc](./util/netcat.txt)  
  2. scp, ssh, rsync.  
  3. samba server.  
  4. http server, like apache2. OR [python](internet/python.txt)   
  5. ftp server, like vsftpd.  
  6. NFS  
16. Dynamic Name Service   
  1. [list of DNS record types ... useful with dig(1)](http://en.wikipedia.org/wiki/List_of_DNS_record_types)  
  2. [comparison of DNS server software](http://http://en.wikipedia.org/wiki/Comparison_of_DNS_server_software)  

System Management / Server  
---
1. [APT/DPKG](./admin/apt-dpkg.md)    
1. [tzdata ... change the system time zone](./admin/time_zone_change.txt)  
2. [grub2 ... location of config files](./admin/grub_config_file_location.txt)  
3. [Config runlevels (sysvinit) ...](./admin/runlevel.txt)  
4. [Font in tty ...](./admin/tty-font.txt)  
5. [Networkmanager ... can't change network settings?](./admin/networkmanager.txt)  
6. [bashrc ...](./admin/bashrc.txt)  
7. [Google earth ... install on amd64](./admin/gearth.txt)  
8. [grub ... boot with kali iso image](./admin/grub_kali_iso.txt)  
9. [time ... hardware time](./admin/hardwaretime.txt)  
10. [Silence ... no beep from machine](./admin/silent_beep.txt)  
11. [Smart ... smart attributes](./admin/smart.txt)  
12. [Steam ... install steam on amd64](./admin/steam.txt)  
13. [Sudo ...](./admin/sudo.txt)  
14. [Wine ... on amd64](./admin/wine.txt)  
16. [font ... install font](./admin/font.txt)  
  1. [some open source fonts](./admin/font_list.txt)  
17. [systemd ... some reference link](./admin/systemd_link.txt)  
20. [sshd security ... sshguard](./admin/sshguard.txt)  
21. [sshd SFTP chroot ... ](./admin/ssh.txt)  
22. [Ext2/Ext3/Ext4 on Windows](http://blog.csdn.net/hansel/article/details/7557033)  
  1. [ext2Fsd](http://www.ext2fsd.com/)  
  2. [Ext2Read](http://sourceforge.net/projects/ext2read/)  
  3. [Ext2IFS](http://www.fs-driver.org/)  
  4. [DiskInternals Linux Reader for Windows](http://www.diskinternals.com/linux-reader)  
1. [vsftpd ... a simple setup](./admin/BriefVsftpd.tex)  
2. [dnsmasq ... local cache name server](./admin/dnsmasq.txt)  
3. [apache2 (2.2.22) ... simple setup](./admin/apache2.txt)  
4. [bind9 (debian)... DNS (cache) - config file](./admin/named.conf.options)  
5. [hostapd ... dev work](http://www.ibm.com/developerworks/cn/linux/l-wifiencrypthostapd/index.html)  
6. [udhcpd from busybox]
7. [gitlab ... official deb setup](./admin/gitlab.md)  
1. [multiple ssh connection at the same time](admin/multiple-ssh.txt)  
1. [(el) WorldPress in Debian](https://wiki.debian.org/WordPress)  
1. [prevent `resolv.conf` from being changed](admin/static_resolv_conf.md)  

Linux Kernel Hacks / Operating System / Embedding  
---
4. [linux frozen ... handle with SysRq](./kernel/sysrq.txt)  
1. [Compile linux kernel... ](./kernel/compile.txt)  
2. [MIT Xv6 Original](https://pdos.csail.mit.edu/6.828/2011/xv6.html)  
4. [Cook a minimum bootable linux / initramfs ](./minisys/main.pdf)  
1. [hard disk link power manage ... sample hack](./kernel/hddpower.sh)  
2. [cpu freqency tweak ... sample hack](./kernel/cpufreq.sh)  
3. [backlight](./kernel/backlight.txt)  
1. [my OK6410 installation log](kernel/ok6410/main.pdf)  
1. [OpenPOWER fundation](http://openpowerfoundation.org/)  

Virtualization  
---
1. Docker.io, the linux container  
  1. [install docker.io on debian](./virt/docker.install.txt)  
  2. [sample run](./virt/dockerizing.txt)  
  3. [make a docker image via bootstrap](./virt/docker.make.image.txt)  
4. X86 dosbox emulator, (dosbox)  
1. QEMU/KVM  
1. Fake Virtualizations  
  1. traditional chroots  
  1. schroot: [Archwiki:schroot](https://wiki.archlinux.org/index.php/Install_bundled_32-bit_system_in_64-bit_system)[ Debianwiki:Schroot](https://wiki.debian.org/Schroot)    

Cluster / HighPerf  
---
1. [storm local setup ... apache inqubator, storm](./cluster/setup-local-storm.txt)  
2. [PBS - Cluster Job Management](./cluster/pbs)  
3. [parallel computing note](./cluster/parallel.intro.txt)  

Kali / Security / Penetration  
---
1. [kali tools short list](./kali/tools.txt)  
2. [nmap note](./kali/nmap.txt)  
3. [nping note](./kali/nping.txt)  
4. [preventing buffer overflow](http://www.ibm.com/developerworks/cn/linux/l-sp/part4/index.html)  
5. [External resources](./kali/resource.md) 
6. [ARP spoof](kali/arpspoof.txt)  
7. [AirCrack](kali/aircrack.txt)  
8. [aircrack-ng](kali/aircrack-ng.txt)  
1. Disk Encryption  
  1. [(el) Gentoo: dm-crypt](https://wiki.gentoo.org/wiki/Dm-crypt)  
  1. [(el) Gentoo: dm-crypt LUKS](https://wiki.gentoo.org/wiki/DM-Crypt_LUKS)  
  1. [(el) Arch: dm-crypt](https://wiki.archlinux.org/index.php/Dm-crypt/System_configuration)  
  1. [(el) Debian: encrypt setup](http://madduck.net/docs/cryptdisk/)  
1. http://wooyun.org/

[Debian GNU/Linux Specific](https://www.debian.org/)  
---
1. [setup unofficial debian archive](./debian/unofficial_archive.txt)  
2. [setup debian mirror (el) ](https://www.debian.org/mirror/ftpmirror)  
1. Packaging and Policy  
  1. [Debian Policy Manual]
  1. [(el) Debian Science Policy Manual](http://debian-science.alioth.debian.org/debian-science-policy.html)  
  1. [(el) Debian Lua Package Policy Manual](http://pkg-lua.alioth.debian.org/policy.html)  
  1. [Debian Developer Reference]
  1. [Debian New Maintainer's Guide]
  1. [Mentors FAQ](https://wiki.debian.org/DebianMentorsFaq)  
  1. [python library style guide](https://wiki.debian.org/Python/LibraryStyleGuide)  
  1. [rpath issue](https://wiki.debian.org/RpathIssue)  
  1. [library packaging guide](https://www.netfort.gr.jp/~dancer/column/libpkg-guide/libpkg-guide.html)  
1. [Computer language benchmark Game (el)](http://benchmarksgame.alioth.debian.org/)[ its conclusion](http://benchmarksgame.alioth.debian.org/dont-jump-to-conclusions.html)    

[Looking For Help](http://google.com)  
---
wiki, doc, tutorial.

1. [Wikipedia](http://wikipedia.org)  
8. [Linux kernel document](https://www.kernel.org/doc), also shiped within kernel.tar.xz:/doc  
3. [Arch wiki](https://wiki.archlinux.org)  
2. [Debian wiki](https://wiki.debian.org)  
4. [Gentoo wiki](https://wiki.gentoo.org/wiki/Main_Page)  
9. [Gentoo doc](http://www.gentoo.org/doc)  
6. [Funtoo wiki](https://wiki.funtoo.org)  
5. [stackoverflow](http://stackoverflow.com)  
7. [IBM Developer works](https://www.ibm.com/developerworks/cn/linux/)  
10. [FreeBSD doc ... sometimes helps](https://www.freebsd.org/docs.html)  
11. [OpenBSD docs]
12. [vbird.org ... detailed, complete linux guide](http://linux.vbird.org)  
13. [from windows to Linux, beginner ... IBM developer works](http://www.ibm.com/developerworks/cn/linux/l-roadmap/index.html)  
14. Search Engines  
  1. google  
  2. shodan  
  3. [Baidu Yun Search](http://www.zhihu.com/question/24263185#answer-7880704)  
1. [Awesome List](https://github.com/sindresorhus/awesome)  

Open Source Licenses
---
1. [gpl-faq](http://www.gnu.org/licenses/gpl-faq.html#NoticeInSourceFile)  

Programming under Linux  
---
1. Overview  
  1. [Osamu Aoki's Fun to Program](https://people.debian.org/~osamu/fun2prog.html)  
1. Compilation Tool Chain, GCC, Make, CMake, etc
  5. [GNU Make](http://www.gnu.org/software/make/manual/make.html)  
  6. [CMake](http://www.cmake.org/cmake-tutorial/)  
2. C Programming Language  
  1. [printf ... colourful text in terminal](./lang/c/printf_colour.c)  
  2. [crack a C program ... simple example](./lang/c/hexed/simple-hex-edit-binaries.txt)[(foo.c)](./lang/c/hexed/foo.c)[foo2.c](./lang/c/hexed/foo2.c)  
  3. [print source file name and source line number](./lang/c/file_line_.c)  
  4. [berkely db simple demo ... ](./lang/c/db.c) and [makefile](./lang/c/Makefile)  
  1. [libarchive example (el) ](https://github.com/libarchive/libarchive/wiki/Examples)  
3. C++  
  1. [glog demo program](./lang/cpp/glog.cpp) and its [makefile](./lang/cpp/glog.mk)  
  2. [print source file name and source line number](./lang/cpp/file_line_.cpp)  
  3. [a BLAS demo in cpp](./lang/cpp/blas.cpp) and [its makefile](./lang/cpp/Makefile)  
  4. [template demo](./lang/cpp/template.cpp) and [its makefile](./lang/cpp/Makefile)  
  5. [stl demo](./lang/cpp/stl.cpp)  
  6. [Qt helloworld](./lang/cpp_qt/)  
    1. [Qt blog (el) ](http://blog.51cto.com/zt/20/1/)  
  1. [Very brilliant reference site (el)](http://www.cplusplus.com/)  
1. tex/LaTeX  
  1. [use opentype font in tex](./lang/tex/tex-opentype-font.txt)  
  2. [xelatex ... chinese support, xeCJK](./lang/tex/xelatex.cjk.tex)  
  3. [pdflatex ... eng chs mixed sample tex](./lang/tex/eng_chs_mixed_sample.tex)  
  4. [finding the right font](http://www.tug.dk/FontCatalogue/)  
  5. [insert svg picture in latex](lang/tex/tex_svg.md)  
  1. [(el) NASA: latex help](http://www.giss.nasa.gov/tools/latex/)  
1. [Python3](./lang/py3)  
  1. [convert list into string](./lang/py3/list2str.md)  
  1. [my logging example in py3](lang/py3/logging_example.py)  
  1. [HDF5 in python3: h5py demo](lang/py3/hdf5.py)  
  1. [Scipy/Numpy](./lang/py3/numpy.md)  
1. [Octave/Matlab](./lang/oct)  
1. [Lua](http://www.lua.org/)  
  1. [learn lua in 15 minutes](http://tylerneylon.com/a/learn-lua/)  
  1. [My lua logging module](./lang/lua/logging/lumin_log.lua)[demo](./lang/lua/logging/demo.lua)  
  1. [Torch7 interface note](./lang/lua/torch/main.md)  
  1. [lua embedding (el) ](http://www.ibm.com/developerworks/cn/linux/l-lua.html)  
1. Light weigt languages
  1. [Sed/Ed]  
  1. [AWK](./lang/awk/)  
  1. [GNU BC/DC]     
1. [Doxygen ... Automatic document generation for C++ code](./lang/doxygen/)  
1. [Java]
  7. [java helloworld on linux](./lang/java)  
1. [Maxima]  
1. [Go](./lang/go)  
1. Rust  
  1. [Learn RUST by example](http://rustbyexample.com/)  
1. [Julia]  
1. [C#/Mono]  
  1. [C# hello world](lang/csharp/hello.cs)  
1. [HTML/CSS/JS]
  1. [hello world html sample](./lang/sample.html)  
1. [GNU Plot]
  1. [visualizing data with gnu plot (el) ](http://www.ibm.com/developerworks/cn/linux/l-gnuplot/index.html)  
1. [IBM CPlex]
1. Online judges
  1. http://poj.org/  
  1. https://leetcode.com  

My Personal Booknotes  
---
In alphabet order.

3. [ACM Reference: several books in one (-) ](./booknote/acm/main.md)  
7. [ANN in Matlab](./booknote/ann_matlab/)  
4. [APUE (placeholder) ]
1. [Big Talk Design Pattern (-)](./booknote/btdp/main.md)  
1. [Beauty of math](./booknote/beautyofmath/main.md)  
3. [BOP (-) ](./booknote/bop/main.md)  
4. [Byte of Python (placeholder) ]
3. [Building High Availability Linux Servers](./booknote/BuildHighAvailabilityLinuxServers/)  
1. [C Primer Plus](./booknote/cprimerplus/cprimerplus.md)  
4. [Computer Organization and Design (placeholder) ]
2. [C++ Primer Plus (-)](./booknote/cppprimerplus/cppprimerplus.md)  
1. [Computer Security (index only)](./booknote/ComputerSecurity/)  
4. [CSAPP (placeholder) ]
8. [CTAN: lshort](./booknote/lshort/)  
1. [CTAN: texbook (el) (-) ](http://www.ctan.org/pkg/texbook)  
1. [Computer Vision](./booknote/ComputerVision/)  
1. [Debug Hacks](./booknote/DebugHacks/)  
4. [Deep Learning Book, bengio (placeholder) ]
1. [Denial Of Service Attack](./booknote/DenialOfServiceAttack/)  
3. [DevOps Troubleshooting](./booknote/DevOpsTroubleshooting/)  
2. [EE - from a EE open course](./booknote/EE.txt)  
1. [Fundamentals Of Multimedia](./booknote/FundamentalsOfMultimedia/)  
2. [Gray Hat Hacking](./booknote/GrayHatHacking/)  
2. [Game Theory non-technical](./booknote/GameTheory_non-technical/)  
4. [Game Theory (in progress) ]
1. [Hacker Debugging Uncovered](./booknote/HackerDebuggingUncovered/)  
3. [High Performance Linux Server Programming](./booknote/HighPerfLinuxServerProg/)  
3. [Intel Micro Processor (x) ](./booknote/IntelMicroProc/)  
3. [Image Processing](./booknote/ImageProcessing/)  
2. [Information Security Introduction](./booknote/InfoSecIntro/)  
4. [Intel64-ia-32-architectures-software-developer-manual (placeholder) ]
3. [K&R C (placeholder) ](./booknote/kr_c/)  
4. [LFS: Linux From Scratch (placeholder) ]
2. [Linux Kernel Hack](./booknote/LinuxKernelHack/)  
2. [Linux Networking Cookbook](./booknote/LinuxNetworkingCookbook/)  
1. [Linux System Programming (Rober Love) (-) ](./booknote/LinuxSysProg/)   
2. [Metasploit](./booknote/Metasploit/)  
3. [Math.describing.nature](./booknote/Math.describing.nature/)  
3. [MATH PHYS GAME PROGRAMMING](./booknote/MATH-PHYS-GAME-PROGRAMMING/)  
9. [Network Countermeasure](./booknote/NetworkCountermeasure/)  
1. [Parallel Computing and Implementation](./booknote/parallel/main.md)  
6. [Programming in Lua](./booknote/lua/main.md)  
2. [Play with data structure](./booknote/Playwithdatastructure/)  
2. [RHEL](./booknote/rhel/)  
4. [Scientific Computing with Python (placeholder) ]
4. [Stanford opencourse: CS229, Machine learning (-) ](./booknote/stanford_cs229_ml/main.md)  
3. [TAOCP Knuth (-) ](./booknote/taocp/main.md)  
2. [Thinking Python](./booknote/ThinkingPython/)  
1. [TLPI - Volume 1](./booknote/LinuxProgrammingInterface/TLPI.txt)  
1. [TLPI - Volume 2](./booknote/LinuxProgrammingInterface/TLPI2.txt)  
1. [UEFI: Principles and Programming](./booknote/uefi/main.md)  
1. [Understanding Computation (-)](./booknote/understandcomp/main.md)  
1. [UNP-I](./booknote/UNP-I/)  
4. [Vbird Basic](./booknote/vbird_basic/vbird_basic.md)  
5. [Vbird Server](./booknote/vbird_server/main.md)  

Artificial Intelegence / Mathematics  
---
1. Mathematics  
  1. [Wikipedia: Embedding (el) ](https://en.wikipedia.org/wiki/Embedding)  
1. Machine Learning  
  1. [stanford:Ng's opencourse (el) ](http://openclassroom.stanford.edu/MainFolder/CoursePage.php?course=MachineLearning)  
1. Deep Learning Frameworks  
  1. [theano (python)](http://deeplearning.net/software/theano/)  
    1. [my theano note](ai/theano/main.md)  
  1. [caffe (cxx, python, matlab)](https://github.com/BVLC/caffe)  
  1. [torch7 (lua)](https://github.com/torch/distro)  
    1. [torch cheatsheet](https://github.com/torch/torch7/wiki/Cheatsheet)  
  1. [mxnet (cxx, julia)](https://github.com/dmlc/mxnet)  
  1. [tensorflow (python)](https://github.com/tensorflow/tensorflow)  
  1. [leaf (rust)](https://github.com/autumnai/leaf)  
    1. [Deep learning frameworks benchmark by leaf](http://autumnai.com/deep-learning-benchmarks)  
1. Datasets  
  1. [MS COCO](https://github.com/CDLuminate/cocofetch)  
  1. [Imagenet](http://image-net.org/index)  
1. [WikiCFP](http://www.wikicfp.com/cfp/)  
  
## LICENSE
```
MIT LICENSE.
COPYRIGHT (C) 2014,2015,2016 Lumin
```  
---
Started on 2014/06/28 by Lumin Zhou  
  
Seek for UNIX, look into UNIX, follow the UNIX, play with UNIX, work with UNIX, learn from UNIX,
but neither becoming an UNIX, nor marrying UNIX. -- lumin  
