/* ---------------------------------

	HELO OS 系统专用源程序

----------------------------------- */
/* copyright(C) 2019 PZK . */

#include "bootpack.h"
#include <stdio.h>

void init_pic(void)
{
	io_out8(PIC0_IMR,  0xff  ); /* 慡偰偺妱傝崬傒傪庴偗晅偗側偄 */
	io_out8(PIC1_IMR,  0xff  ); /* 慡偰偺妱傝崬傒傪庴偗晅偗側偄 */

	io_out8(PIC0_ICW1, 0x11  ); /* 僄僢僕僩儕僈儌乕僪 */
	io_out8(PIC0_ICW2, 0x20  ); /* IRQ0-7偼丄INT20-27偱庴偗傞 */
	io_out8(PIC0_ICW3, 1 << 2); /* PIC1偼IRQ2偵偰愙懕 */
	io_out8(PIC0_ICW4, 0x01  ); /* 僲儞僶僢僼傽儌乕僪 */

	io_out8(PIC1_ICW1, 0x11  ); /* 僄僢僕僩儕僈儌乕僪 */
	io_out8(PIC1_ICW2, 0x28  ); /* IRQ8-15偼丄INT28-2f偱庴偗傞 */
	io_out8(PIC1_ICW3, 2     ); /* PIC1偼IRQ2偵偰愙懕 */
	io_out8(PIC1_ICW4, 0x01  ); /* 僲儞僶僢僼傽儌乕僪 */

	io_out8(PIC0_IMR,  0xfb  ); /* 11111011 PIC1埲奜偼慡偰嬛巭 */
	io_out8(PIC1_IMR,  0xff  ); /* 11111111 慡偰偺妱傝崬傒傪庴偗晅偗側偄 */

	return;
}
