#include "apilib.h"

void HariMain(void)
{
	int win;
	char buf[170 * 70];
	win = api_openwin(buf, 170, 70, -1, "关于");
	api_boxfilwin(win,  8, 36, 141, 43, 3);
	api_putstrwin(win, 28, 28, 0, 14, "HELO OS 中文版");
	for (;;) {
		if (api_getkey(1) == 0x0a) {
			break; /* Enter break; */
		}
	}
	api_end();
}
