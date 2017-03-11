/*
 * Copyright (C) 2001 MontaVista Software Inc.
 * Author: Jun Sun, jsun@mvista.com or jsun@junsun.net
 *
 * This program is free software; you can redistribute  it and/or modify it
 * under  the terms of  the GNU General  Public License as published by the
 * Free Software Foundation;  either version 2 of the  License, or (at your
 * option) any later version.
 *
 */

#include <printf.h>
#include <pmap.h>

int main()
{
	printf("main.c:\tmain is start ...\n");
	/*printf("Characters: %c %c \n",'a',65);
	printf("Decimals %d %ld\n",1977,650000L);
	printf("Blanks %10d\n",1977);
	printf("Blanks %-10d\n",1977);
	printf("Blanks %010d\n",1977);
	printf("Radices:%d %x %o %b\n",100,100,100,100);
	printf("%s\n","A string");
	*/

	mips_init();
	panic("main is over is error!");

	return 0;
}
