# With Linux - Brief HOWTO?

Linux tricks, hints, etc, most of which are in the style of keyword-expanding.  
  
They are based on [Debian](https://www.debian.org). Some may work on Ubuntu, Mint etc.  
  
Issue me if encountered any problem. keep updating.  
  
## Index : contents
1. [Installing Linux](./install)  
  1. [USB stick ... How can I install linux into it](./install/install-linux-into-usb-stick.txt)  
  2. [Drivers and firmware](./install/dri)  
    1. [Graphic card](./install/dri/graphic_card_driver.txt)  
    2. [Wireless network card](./install/dri/wireless.txt)  
  3. [Turn off graphic card](./install/turn-off-gpu.txt)  
  4. [Solid State Drive ... tips](./install/ssd.txt)  
  5. [efi ... some pkgs related](./install/efi.txt)  
2. [Basic tools](./basic)  
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
3. [Internet](./internet)  
  1. [iceweasel ... cache config, of iceweasel (firefox)](./internet/iceweasel-cache.txt)  
  2. [vpn ... set up on debian](./internet/vpn.txt)  
  3. [ping ... no reply to icmp ping](./internet/ping.txt)  
  4. [port ... what is running on a port](./internet/port.txt)  
  5. ifup and ifdown setting ... see interfaces(5)
  6. [share the network with other machine ... one of cases](./internet/share-network-between-linux.txt)  
  7. [share-ipv4-with-ipv6-tunnel ...](./internet/share-ipv4-with-ipv6-tunnel.txt)  
4. [Graphical(Xorg)](./x)  
  1. [Gnome3 (gnome-shell)](./x/gnome)  
    1. [the height of top bar ... modify](./x/gnome/topbar.txt)  
    2. [alacarte empties gnome menu ... wheezy](./x/gnome/alacarte.txt)  
    3. X11 default display manager ... /etc/X11/default-display-manager  
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
6. [Setup server](./server)  
  1. [vsftpd ... a simple setup](./server/BriefVsftpd.tex)  
  2. [dnsmasq ... local cache name server](./server/dnsmasq.txt)  
  3. [apache2 ... simple setup](./server/apache2.txt)  
  4. [bind9 (debian)... DNS (cache) - config file](./server/named.conf.options)  
  5. hostapd ... [external link](http://www.ibm.com/developerworks/cn/linux/l-wifiencrypthostapd/index.html)  
7. [Programming](./lang)  
  1. [tex](./lang/tex)  
    1. [use opentype font in tex](./lang/tex/tex-opentype-font.txt)  
    2. [xelatex ... chinese support, xeCJK](./lang/tex/xelatex.cjk.tex)  
    3. [pdflatex ... eng chs mixed sample tex](./lang/tex/eng_chs_mixed_sample.tex)  
  2. [the c programming language](./lang/c/)  
    1. [printf ... colourful text in terminal](./lang/c/printf_colour.c)  
    2. [crack a C program ... simple example](./lang/c/hexed/simple-hex-edit-binaries.txt)[(foo.c)](./lang/c/hexed/foo.c)[foo2.c](./lang/c/hexed/foo2.c)  
  3. [A hello world html sample](./lang/sample.html)  
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
12. [kali](./kali)  
  1. [some tools](./kali/tools.txt)  
  
### Appendix A : Topics
1. [Need help ? do some search first](http://173.194.72.31)  
  1. [Wikipedia ... looking up basic concept](http://wikipedia.org)  
  2. [Debian wiki ... ](https://wiki.debian.org)  
  3. [Arch wiki ... ](https://wiki.archlinux.org)  
  4. [Gentoo wiki ... ](https://wiki.gentoo.org/wiki/Main_Page)  
  5. [series of stackoverflow](http://stackoverflow.com)  
2. Docs out there  
  1. [kernel doc ... OR kernel.tar.xz:/doc](https://www.kernel.org/doc)  
  2. [Gentoo doc ...](http://www.gentoo.org/doc)  
  3. [FreeBSD doc ... sometimes helps](https://www.freebsd.org/docs.html)  
3. Manuals & Tutorials  
  1. [vbird.org ... detailed, complete linux guide](http://linux.vbird.org)  
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
  
## LICENSE
The MIT LICENSE.  
  
---
千里之行，始于足下。  
Started on 2014/06/28 by C.D.Luminate  
