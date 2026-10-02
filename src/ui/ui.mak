#####################################################################
# make SUFFIX=32

# don't create gamelist.txt
TEXTS = gamelist.txt

# remove pedantic
$(OBJ)/ui/%.o: src/ui/%.c
	@echo Compiling $<...
	$(CC) $(CDEFS) $(CFLAGS) -c $< -o $@

OBJDIRS += $(OBJ)/ui

# only OS specific output files and rules
OSOBJS += \
        $(OBJ)/ui/m32main.o \
        $(OBJ)/ui/m32util.o \
        $(OBJ)/ui/directinput.o \
        $(OBJ)/ui/dijoystick.o \
        $(OBJ)/ui/directdraw.o \
        $(OBJ)/ui/directories.o \
        $(OBJ)/ui/audit32.o \
        $(OBJ)/ui/columnedit.o \
        $(OBJ)/ui/screenshot.o \
        $(OBJ)/ui/treeview.o \
        $(OBJ)/ui/splitters.o \
        $(OBJ)/ui/bitmask.o \
        $(OBJ)/ui/datamap.o \
        $(OBJ)/ui/dxdecode.o \
        $(OBJ)/ui/win32ui.o \
        $(OBJ)/ui/properties.o \
        $(OBJ)/ui/options.o \
        $(OBJ)/ui/help.o \
	$(OBJ)/ui/layout.o \
	$(OBJ)/ui/history.o \
	$(OBJ)/ui/dialogs.o \

ifdef KAILLERA
OSOBJS += $(OBJ)/ui/chat.o
OSOBJS += $(OBJ)/ui/kcommand.o
endif

ifdef MAME_AVI
OSOBJS += $(OBJ)/ui/Avi.o
OSOBJS += $(OBJ)/ui/Wav.o
endif

# add resource file
OSOBJS += $(OBJ)/ui/mame32.res

#####################################################################
# compiler

#
# Preprocessor Definitions
#

DEFS += -DDIRECTSOUND_VERSION=0x0300 \
        -DDIRECTINPUT_VERSION=0x0500 \
        -DDIRECTDRAW_VERSION=0x0300 \
        -DWINVER=0x0400 \
        -D_WIN32_IE=0x0500 \
        -D_WIN32_WINNT=0x0400 \
        -DWIN32 \
        -UWINNT \
	-DCLIB_DECL=__cdecl \
	-DDECL_SPEC= \
        -DZEXTERN=extern \

#	-DSHOW_UNAVAILABLE_FOLDER


#####################################################################
# Resources

ifdef KAILLERA # TEST
  RC  = @brcc32
  RC2 = @windres --use-temp-file
  RCDEFS = -DNDEBUG -D_WIN32_IE=0x0400 $(KAILLERA)
  RCFLAGS = -r -I./ui
else
 RC = windres --use-temp-file
 RCDEFS = -DNDEBUG -D_WIN32_IE=0x0400 $(KAILLERA)
 RCFLAGS = -O coff --include-dir src/ui
endif

#ifdef KAILLERA
#$(OBJ)/ui/mame32k.res: src/ui/mame32k.rc
#	@echo Compiling resources $<...
#	$(RC) $(RCDEFS) $(RCFLAGS) -o $@ -i $<
#	
ifdef KAILLERA # TEST
  $(OBJ)/ui/%.res: src/ui/%.rc
	@echo Compiling resources $<...
	$(RC) $(RCDEFS) $(RCFLAGS) -Fo$(OBJ)/ui/mame32k.res $<
	$(RC2) -I res -O coff -i $(OBJ)/ui/mame32k.res -o $@	
else
$(OBJ)/ui/%.res: src/ui/%.rc
	@echo Compiling resources $<...
	$(RC) $(RCDEFS) $(RCFLAGS) -o $@ -i $<
endif

#####################################################################
# Linker

LIBS += -lkernel32 \
        -lshell32 \
        -lcomctl32 \
        -lcomdlg32 \
        -ladvapi32 \
        -lhtmlhelp

ifdef KAILLERA
LIBS += -lkailleraclient -lws2_32 -limm32
endif

ifdef MAME_AVI
LIBS += -lmsvfw32 \
		-lavifil32 \
		-lavicap32
	
endif

# use -mconsole for romcmp
LDFLAGS += -mwindows

#####################################################################

