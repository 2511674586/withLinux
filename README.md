# With Linux - Brief Hacks


Linux tricks, hints, hacks, based on my personal experience with
[Debian GNU/Linux](https://www.debian.org). It may work on Ubuntu, Mint etc.  
Most of these hints and hacks are in the style of keyword-expanding.  
  
keep updating.  
  
FIXME: re-arrange sections.  
  
## Index : contents
1. [Installing Linux](./install)  
  1. [USB stick ... How can I install linux into it](./install/install-linux-into-usb-stick.txt)  
  2. [Drivers and firmware](./install/dri)  
    1. [Graphic card](./install/dri/graphic_card_driver.txt)  
    2. [Wireless network card](./install/dri/wireless.txt)  
  3. [Turn off graphic card](./install/turn-off-gpu.txt)  
  4. [Solid State Drive ... tips](./install/ssd.txt)  
  5. [efi ... some pkgs related](./install/efi.txt)  
  6. [server ... hp server installation](./install/hpserver)  
  7. [bootstrap minimal/stage3 Debian system](./install/bootstrap)    
  8. [simple ArchLinux install note](./install/arch)  
  9. [mdadm ... simple note on creating software md5](./install/mdadm.md)  
2. [Utilities](./basic)  
  1. [netcat ... some usages](./basic/netcat.txt)  
  2. [bash ... some tricks](./basic/bash_tricks.txt)  
  3. [(OT) funny commands](./basic/funny_commands.txt)  
  4. [linux frozen ... handle with SysRq](./basic/sysrq.txt)  
  5. [conky ... system monitor, sample rc file](./basic/conkyrc.txt)  
  6. [gpg ... short use](./basic/short_gpg.txt)  
  7. [data recovery ... tools](./basic/data-recover.txt)  
  8. [remove data safely ... tools](./basic/remove-data-safely.txt)  
  9. [encrypt disk ... luks basic use](./basic/disk-crypt.txt)  
  10. [avconv ... basic use](./basic/avconv.txt)  
  11. [git ... merge 2 repos into 1](./basic/git_merge_repo.txt)  
  12. [vim ... convert code into html](./basic/vim_html.txt)  
  13. [ffmpeg ... resize picture and video](./basic/ffmpeg_resize_picture.txt)  
  14. [imagemagick ... resize, trans-format, rotate picture](./basic/imagemagick.txt)  
  15. [xset ... change keyboard input delay/rate under X](./basic/keyrate)  
  16. [ssh-agent ... let it memorize your password](./basic/ssh-agent.txt)  
  17. [Busybox ... developer works](http://www.ibm.com/developerworks/cn/linux/l-busybox/index.html)  
3. [Internet](./internet)  
  1. [iceweasel ... cache config, of iceweasel (firefox)](./internet/iceweasel-cache.txt)  
  2. [chromium ... cache directory config](./internet/iceweasel-cache.txt)  
  2. [vpn ... set up on debian](./internet/vpn.txt)  
  3. [ping ... no reply to icmp ping](./internet/ping.txt)  
  4. [port ... what is running on a port](./internet/port.txt)  
  5. ifup and ifdown setting ... see interfaces(5)
  6. [share the network with other machine ... one of cases](./internet/share-network-between-linux.txt)  
  7. [share-ipv4-with-ipv6-tunnel ...](./internet/share-ipv4-with-ipv6-tunnel.txt)  
  8. [openvpn ... simple utilization](./internet/openvpn.txt)  
  9. [802.1X auth ... ref link](./internet/802auth)  
  10. [iptables howto ... ubuntu help](https://help.ubuntu.com/community/IptablesHowTo)  
  11. [miredo note ... IPv6 Net with Teredo](./internet/miredo.md)
  12. [isatap ... IPv6 with ISATAP](./internet/isatap.txt)
4. [Graphical(Xorg)](./x)  
  1. [Gnome3 (gnome-shell)](./x/gnome)  
    1. [the height of top bar ... modify](./x/gnome/topbar.md)  
    2. [alacarte empties gnome menu ... wheezy](./x/gnome/alacarte.txt)  
    3. X11 default display manager ... /etc/X11/default-display-manager  
  2. [LXDE](./x)  
    1. [set shortcut keys under LXDE](./x/lxde-shortcut)  
  3. Desktop Managers ... in fact X11 login program  
    1. gdm, gdm3 and kdm are too heavy  
    2. sddm for plasma5 is heavy too  
    3. lightdm and slim are light and small
  4. jwm / cwm / twm / i3-wm  
  5. Graphical Virtual terminals  
    1. Gnome-terminal
    2. guake terminal  
    3. lilyterm is light and fast
5. [System management](./config)  
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
6. [Setup server](./server)  
  1. [vsftpd ... a simple setup](./server/BriefVsftpd.tex)  
  2. [dnsmasq ... local cache name server](./server/dnsmasq.txt)  
  3. [apache2 (2.2.22) ... simple setup](./server/apache2.txt)  
  4. [bind9 (debian)... DNS (cache) - config file](./server/named.conf.options)  
  5. [hostapd ... dev work](http://www.ibm.com/developerworks/cn/linux/l-wifiencrypthostapd/index.html)  
  6. [udhcpd from dropbox]
  7. [gitlab ... official deb setup](./server/gitlab.md)  
7. [Programming](./lang)  
  1. [tex](./lang/tex)  
    1. [use opentype font in tex](./lang/tex/tex-opentype-font.txt)  
    2. [xelatex ... chinese support, xeCJK](./lang/tex/xelatex.cjk.tex)  
    3. [pdflatex ... eng chs mixed sample tex](./lang/tex/eng_chs_mixed_sample.tex)  
    4. [finding the right font](http://www.tug.dk/FontCatalogue/)  
  2. [c ](./lang/c/)  
    1. [printf ... colourful text in terminal](./lang/c/printf_colour.c)  
    2. [crack a C program ... simple example](./lang/c/hexed/simple-hex-edit-binaries.txt)[(foo.c)](./lang/c/hexed/foo.c)[foo2.c](./lang/c/hexed/foo2.c)  
    3. [print source file name and source line number](./lang/c/file_line_.c)  
    4. [berkely db simple demo ... ](./lang/c/db.c) and [makefile](./lang/c/Makefile)  
  3. [c++](./lang/cpp)  
    1. [glog demo program](./lang/cpp/glog.cpp) and its [makefile](./lang/cpp/glog.mk)  
    2. [print source file name and source line number](./lang/cpp/file_line_.cpp)  
    3. [a BLAS demo in cpp](./lang/cpp/blas.cpp) and [its makefile](./lang/cpp/Makefile)  
    4. [template demo](./lang/cpp/template.cpp) and [its makefile](./lang/cpp/Makefile)  
    5. [stl demo](./lang/cpp/stl.cpp)  
  3. [A hello world html sample](./lang/sample.html)  
  4. [Octave](./lang/oct)  
  5. [GNU Make](http://www.gnu.org/software/make/manual/make.html)  
  6. [CMake](http://www.cmake.org/cmake-tutorial/)  
  7. [java helloworld on linux](./lang/java)  
  8. [AWK](./)  
  9. [Sed](./)  
  10. [GNU BC](./)     
  11. [Maxima](./)  
  12. [Python3](./lang/py3)  
    1. [convert list into string](./lang/py3/list2str.md)  
8. [Linux Hacks](./hack)  
  1. [hard disk link power manage ... sample hack](./hack/hddpower.sh)  
  2. [cpu freqency tweak ... sample hack](./hack/cpufreq.sh)  
  3. [backlight](./hack/backlight.txt)  
9. [Virtualization](./virt)  
  1. [docker.io ... linux container](./virt/docker/)  
    1. [install docker.io on debian](./virt/docker/docker.install.txt)  
    2. [sample run](./virt/docker/dockerizing.txt)  
    3. [make a docker image via bootstrap](./virt/docker/docker.make.image.txt)  
10. [Linux Kernel](./kernel)  
  1. [Compile ... ](./kernel/compile.txt)  
11. [Cluster use](./cluster)  
  1. [storm local setup ... apache inqubator, storm](./cluster/setup-local-storm.txt)  
  2. [PBS - Cluster Job Management](./cluster/pbs)  
12. [kali/security](./kali)  
  1. [tools list](./kali/tools.txt)  
  2. [nmap note](./kali/nmap.txt)  
  3. [nping note](./kali/nping.txt)  
  4. [preventing buffer overflow](http://www.ibm.com/developerworks/cn/linux/l-sp/part4/index.html)  
  5. [resource](./kali/resource.md) 
13. [Debian](https://www.debian.org/)  
  1. [setup unofficial debian archive](./debian/unofficial_archive.txt)  
  2. [setup debian mirror](https://www.debian.org/mirror/ftpmirror)  
14. Booknotes  
  1. [C Primer Plus](./booknote/cprimerplus/cprimerplus.md)  
  2. [C++ Primer Plus](./booknote/cppprimerplus/cppprimerplus.md)  
  3. [K&R C](./booknote/kr_c/)  
  4. [Vbird Basic](./booknote/vbird_basic/vbird_basic.md)  
  5. [Vbird Server](./booknote/vbird_server/main.md)  
  
### Appendix A : Topics
1. [Need help ? do some search first](http://173.194.72.31)  
  1. [Wikipedia ... looking up basic concept](http://wikipedia.org)  
  2. [Debian wiki ... ](https://wiki.debian.org)  
  3. [Arch wiki ... ](https://wiki.archlinux.org)  
  4. [Gentoo wiki ... ](https://wiki.gentoo.org/wiki/Main_Page)  
  5. [stackoverflow](http://stackoverflow.com)  
  6. [Funtoo wiki](https://wiki.funtoo.org)  
  7. [IBM Developer works](https://www.ibm.com/developerworks/cn/linux/)  
2. Docs out there  
  1. [kernel doc ... OR kernel.tar.xz:/doc](https://www.kernel.org/doc)  
  2. [Gentoo doc ...](http://www.gentoo.org/doc)  
  3. [FreeBSD doc ... sometimes helps](https://www.freebsd.org/docs.html)  
  4. [OpenBSD docs]
3. Manuals & Tutorials  
  1. [vbird.org ... detailed, complete linux guide](http://linux.vbird.org)  
  2. [from windows to Linux, beginner ... IBM developer works](http://www.ibm.com/developerworks/cn/linux/l-roadmap/index.html)  
4. DNS   
  1. [list of DNS record types ... useful with dig(1)](http://en.wikipedia.org/wiki/List_of_DNS_record_types)  
  2. [comparison of DNS server software](http://http://en.wikipedia.org/wiki/Comparison_of_DNS_server_software)  
5. HTTP status code reference  
  1. rfc2616  
  2. [list of http status codes ... wikipedia](http://en.wikipedia.org/wiki/List_of_HTTP_status_codes)  
6. [git ... content tracker](http://www.git-scm.com/)  
  1. [set up git ... github help](https://help.github.com/articles/set-up-git)  
  2. [a git tutor ... git immersion](http://gitimmersion.com/)  
7. Ways of file sharing (via network)  
  1. [nc](./basic/netcat.txt)  
  2. scp, ssh.  
  3. samba server.  
  4. http server, like apache2. OR [python](./topic/python.txt)   
  5. ftp server, like vsftpd.  
  6. nfs  
8. Log Analysis  
  1. awk programming language  
  2. apt-get search {visitors,awstat}  
9. Search engine
  1. google  
  2. shodan  
10. [Cook a minimum bootable linux / initramfs ](./minisys/main.pdf)  
11. Open source Licenses
  1. [gpl-faq](http://www.gnu.org/licenses/gpl-faq.html#NoticeInSourceFile)  
12. Games on Linux  
  1. [Terraria on Wine32](./topic/terraria.md)  
  
## LICENSE
The MIT LICENSE.  
  
---
Started on 2014/06/28 by Lumin Zhou  
  
Seek for UNIX, look into UNIX, follow the UNIX, play with UNIX, work with UNIX, learn from UNIX,
but neither becoming an UNIX, nor marrying UNIX. -- lumin  
