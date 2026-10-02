/*************************************
   Wind Jammers Patch (by nose)
*************************************/

#define PATCH_END (-1)

#include "driver.h"
#include "windjs1.c"

void neogeo_wjammers_patch(void)
{
	data8_t *mem8 = memory_region(REGION_GFX1);
	int i = 0;

	while (wjammers_s1_address[i] != PATCH_END)
	{
		mem8[wjammers_s1_address[i]] = wjammers_s1_data[i];
		i++;
	}
}
