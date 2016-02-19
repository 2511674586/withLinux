/* from Linux kernel hacks, hack 49, controling the LED of keyboard. */

#include <stdio.h>
#include <sys/io.h>

#define KBD_CMD_PORT	0x60
#define OBD_STS_PORT	0x64

#define OBS_FULL	0x1
#define SEND_LED	0xED

#define SCROLL_LOCK	(1<<0)
#define NUM_LOCK	(1<<1)
#define CAPS_LOCK	(1<<2)

void
send_cmd (cmd, port)
{
	char sts;
	do {
		sts = inb (OBD_STS_PORT);
	} while (sts & OBS_FULL);
	outb (cmd, port);
	usleep (100000);
}

int
main (void)
{
	ioperm (KBD_CMD_PORT, 1, 1);
	ioperm (OBD_STS_PORT, 1, 1);

	/* turn on a LED of CAPS_LOCK */
	send_cmd (SEND_LED, KBD_CMD_PORT);
	send_cmd (CAPS_LOCK, KBD_CMD_PORT);

	/* turn on a LED of NUM_LOCK */
	send_cmd (SEND_LED, KBD_CMD_PORT);
	send_cmd (NUM_LOCK, KBD_CMD_PORT);
	
	/* turn on a Scroll lock LED */
	send_cmd (SEND_LED, KBD_CMD_PORT);
	send_cmd (SCROLL_LOCK, KBD_CMD_PORT);

	/* turn off all LEDs */
	send_cmd (SEND_LED, KBD_CMD_PORT);
	send_cmd (0, KBD_CMD_PORT);

	ioperm (KBD_CMD_PORT, 1, 0);
	ioperm (OBD_STS_PORT, 1, 0);

	return 0;
}
