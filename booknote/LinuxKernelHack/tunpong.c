/* This is a sample program from linux kernel hack, 机械工业出版社.
 * 
 * only process icmp echo. */

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int tun_open (void)
{
	struct ifreq ifr;
	int fd;
	char dev[IFNAMSIZ];
	char buf[512];
	/* 打开用来操作TUN/TAP设备的文件*/
	fd = open ("/dev/net/tun", O_RDWR);

	/* 生成TUN设备tun0 */
	memset (&ifr, 0, sizeof(ifr) );
	ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
	strncpy (ifr.ifr_name, "tun%d", IFNAMSIZ);
	ioctl (fd, TUNSETIFF, &ifr);

	strncpy (dev, ifr.ifr_name, IFNAMSIZ);
	/* 使用ifconfig添加ip地址 */
	sprintf (buf, "ifconfig %s 192.168.1.1 pointopoint 192.168.1.2", dev);
	system (buf);
	
	return fd;
}

void dump_pkt (unsigned char *pkt, int len)
{
	int i;

	for (i = 0; i < len; i++)
		printf ("%02x ", pkt[i]);
	printf ("\n");
}

void pingpong (int fd)
{
	fd_set fds;
	int len;
	unsigned char pkt[512];
	
	FD_ZERO (&fds);
	FD_SET (fd, &fds);

	select (fd+1, &fds, NULL, NULL, NULL);
	if (FD_ISSET (fd, &fds)) {
		len = read (fd, pkt, 512);
		dump_pkt (pkt, len);
		/* the head of icmp is 0x08 (echo request) */
		if (pkt[20] != 0x08)
			return;

		/* 将IP头的src设为192.168.1.2, dst 192.168.1.1 */
		pkt[15] = 0x02;
		pkt[19] = 0x01;
		pkt[20] = 0x00;  /* echo reply */
		write (fd, pkt, len);
	}
}

int main (int argc, char **argv)
{
	int fd;
	/* you need to be root to run this program */

	fd = tun_open();
	for (;;)
		pingpong (fd);

	return 0;
}

/*
 * 使用gcc编译后，用root权限运行程序。
 * 用ifconfig 或 ip确认tun0设备。
 * 接下来执行ping， 将ICMP ECHO REQUEST 发送到192.168.1.2
 * 程序tunpong 通过tun0设备接受数据包。
 * 最后可以ifconfig查看rx和tx
 */

