#ifndef DATAFILE_H
#define DATAFILE_H

struct tDatafileIndex
{
	long offset;
	const struct GameDriver *driver;
};

extern int load_driver_history (const struct GameDriver *drv, char *buffer, int bufsize);

#ifdef KAILLERA
struct tMenuIndex
{
	long offset;
	char *menuitem;
};

extern void  init_cmdfunc(void);
extern int   load_driver_command_ex(const struct GameDriver *drv, char *buffer, int bufsize, const int menu_sel);
extern UINT8 command_sub_menu(const struct GameDriver *drv, const char *menu_item[]);
#endif /* KAILLERA */

#endif
