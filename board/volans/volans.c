/*
 * (C) Copyright 2006
 * Ingenic Semiconductor, <jlwei@ingenic.cn>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <command.h>
#include <asm/mipsregs.h>
#include <asm/jz4750l.h>

static void gpio_init(void)
{
	/*
	 * Initialize SDRAM pins
	 */
#if CONFIG_NR_DRAM_BANKS == 2   /*Use Two Banks SDRAM*/
	__gpio_as_sdram_x2_16bit();
#else
	__gpio_as_sdram_16bit();
#endif

	/*
	 * Initialize UART1 pins
	 */
	__gpio_as_uart0();
}

//----------------------------------------------------------------------
// board early init routine
void board_early_init(void)
{
#if 0
#define CS2  (32*2+22)
	__gpio_as_output(CS2);
	while(1) {
		int i;
		__gpio_set_pin(CS2);
		i=480000;
		while(i--);
		__gpio_clear_pin(CS2);
		i=480000;
		while(i--);
	}
#endif
	gpio_init();
}


//----------------------------------------------------------------------
// U-Boot common routines

int checkboard (void)
{
	DECLARE_GLOBAL_DATA_PTR;

	printf("Board: Ingenic VOLANS (CPU Speed %d MHz)\n",
	       gd->cpu_clk/1000000);

	return 0; /* success */
}
