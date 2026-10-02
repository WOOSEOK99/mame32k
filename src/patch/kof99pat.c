/****************************
        KOF'99 Patch
****************************/

#define PATCH_END (-1)

#include "driver.h"
#include "kof99p1.c"
#include "kof99p2.c"
#include "kof99s1.c"

static void neogeo_kof99_p1_patch(void)
{
	data8_t *mem8 = memory_region(REGION_CPU1);
	int i = 0;

	while (kof99_p1_address[i] != PATCH_END)
	{
		mem8[kof99_p1_address[i]] = kof99_p1_data[i];
		i++;
	}
}


static void neogeo_kof99_p2_patch(void)
{
	data8_t *mem8 = memory_region(REGION_CPU1) + 0x100000L;
	int i = 0;

	while (kof99_p2_address[i] != PATCH_END)
	{
		mem8[kof99_p2_address[i]] = kof99_p2_data[i];
		i++;
	}
}


static void neogeo_kof99_s1_patch(void)
{
	data8_t *mem8 = memory_region(REGION_GFX1);
	int i = 0;

	while (kof99_s1_address[i] != PATCH_END)
	{
		mem8[kof99_s1_address[i]] = kof99_s1_data[i];
		i++;
	}
}


#if 0
static void neogeo_kof99_m1_patch(void)
{
	data8_t *mem8 = memory_region(REGION_CPU2);

	mem8[0x19e1dL] = 0x0c;
	mem8[0x19e30L] = 0x0c;
	mem8[0x19e4aL] = 0x0c;
}
#endif


void neogeo_kof99_patch(void)
{
	neogeo_kof99_p1_patch();
	neogeo_kof99_p2_patch();
	neogeo_kof99_s1_patch();
//	neogeo_kof99_m1_patch();
}
