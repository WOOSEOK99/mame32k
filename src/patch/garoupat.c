/****************************
        GAROU Patch
****************************/

#define PATCH_END (-1)

#include "driver.h"
#include "garoup1.c"
#include "garoup2.c"


#define WRITE_BYTE(a, c) (*(unsigned char *)(&RAM[a]) = (c))

static void neogeo_garou_p1_patch(void)
{
	int i = 0;
	unsigned char *RAM = memory_region(REGION_CPU1);

	while (garou_p1_address[i])
	{
		WRITE_BYTE(garou_p1_address[i], garou_p1_data[i]);
		i++;
	}
}

static void neogeo_garou_p2_patch(void)
{
	int i = 0;
	unsigned char *RAM = memory_region(REGION_CPU1) + 0x100000L;

	while (garou_p2_address[i])
	{
		WRITE_BYTE(garou_p2_address[i], garou_p2_data[i]);
		i++;
	}
}


void neogeo_garou_patch(void)
{
	neogeo_garou_p1_patch();
	neogeo_garou_p2_patch();
}
