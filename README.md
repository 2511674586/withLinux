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
2. [Basic tools](./basic_tools)  
  1. [netcat ... some usages](./basic_tools/netcat.txt)  
  2. [bash ... some tricks](./basic_tools/bash_tricks.txt)  
  3. [(OT) funny commands](./basic_tools/funny_commands.txt)  
3. [Internet](./internet)  
  1. [iceweasel ... cache config, of iceweasel (firefox)](./internet/iceweasel-cache.txt)  
  2. [vpn ... set up on debian](./internet/vpn.txt)  
  3. [ping ... no reply to icmp ping](./internet/ping.txt)  
4. [Graphical(Xorg)](./x)  
  1. [Gnome3 (gnome-shell)](./x/gnome)  
    1. [the height of top bar ... modify](./x/gnome/topbar.txt)  
    2. [alacarte empties gnome menu ... wheezy](./x/gnome/alacarte.txt)  
5. [System management](./config)  
  1. [tzdata ... change the system time zone](./config/time_zone_change.txt)  
  2. [grub ... where is its config files](./config/grub_config_file_location.txt)  
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
6. [Setup server](./server)  
  1. [vsftpd ... a simple setup](./server/BriefVsftpd.tex)  
  2. [dnsmasq ... name server](./server/dnsmasq.txt)  
  3. [apache2 ... simple setup](./server/apache2.txt)  
7. [Programming](./lang)  
  1. [tex](./lang/tex)  
    1. [use opentype font in tex](./lang/tex/tex-opentype-font.txt)  
  2. [the c programming language](./lang/c/)  
    1. [printf ... colourful text in terminal](./lang/c/printf_colour.c)  
    2. [crack a C program ... simple example](./lang/c/hexed/simple-hex-edit-binaries.txt)[(foo.c)](./lang/c/hexed/foo.c)[foo2.c](./lang/c/hexed/foo2.c)  
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
  
### Appendix A : External links
1. [Need help ? the anwser may be here](https://google.com)[ or here](http://173.194.72.31)  
  1. [Wikipedia ... looking up basic concept](http://wikipedia.org)  
  2. [Debian wiki ... you know](https://wiki.debian.org)  
  3. [Arch wiki ... powerful](https://wiki.archlinux.org)  
  4. [Gentoo wiki ... you know](https://wiki.gentoo.org/wiki/Main_Page)  
  5. [series of stackoverflow](http://stackoverflow.com)  
2. [Lots of docs out there](https://google.com)  
  1. [kernel doc ... OR kernel.tar.xz:/doc](https://www.kernel.org/doc)  
  2. [Gentoo doc ...](http://www.gentoo.org/doc)  
  3. [FreeBSD doc ... sometimes also helps a lot](https://www.freebsd.org/docs.html)  
3. [External Manuals Tutorials](https://google.com)  
  1. [vbird.org ... detailed, complete linux guide](http://linux.vbird.org)  
4. [Reference](http://wikipedia.org)  
  1. [list of DNS record types ... useful with dig(1)](http://en.wikipedia.org/wiki/List_of_DNS_record_types)  
  2. [comparison of DNS server software](http://http://en.wikipedia.org/wiki/Comparison_of_DNS_server_software)  
5. HTTP status code reference  
  1. rfc2616  
  2. [list of http status codes ... wikipedia](http://en.wikipedia.org/wiki/List_of_HTTP_status_codes)  
  
  
### Appendix B : Topics
1. [git ... content tracker](http://www.git-scm.com/)  
  1. [set up git ... github help](https://help.github.com/articles/set-up-git)  
  2. [a git tutor ... git immersion](http://gitimmersion.com/)  
2. Ways of file sharing (via network)  
  1. nc, as said above.  
  2. scp, ssh.  
  3. samba server.  
  4. http server, like apache2.  
  5. ftp server, like vsftpd.  
3. Log Analysis  
  1. awk programming language  
  2. apt-get search visitors  
  3. ?  
  
## LICENSE
The MIT LICENSE.  
  
---
千里之行，始于足下。  
This repo was started on 2014/06/28 by cdluminate.  
