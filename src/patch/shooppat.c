/*****************************
     Street Hoops Patch
*****************************/

#define PATCH_END (-1)

#include "driver.h"
#include "shoops1.c"

void neogeo_strhoop_patch(void)
{
	data8_t *mem8 = memory_region(REGION_GFX1);
	int i = 0;

	while (strhoop_s1_address[i] != PATCH_END)
	{
		mem8[strhoop_s1_address[i]] = strhoop_s1_data[i];
		i++;
	}
}
