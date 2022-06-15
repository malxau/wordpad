NULL=
CPP=cl.exe
RSC=rc.exe

OUTDIR=Release
INTDIR=Release

ALL : "$(OUTDIR)\wordpad.exe"


CLEAN :
	-@erase "$(INTDIR)\buttondi.obj"
	-@erase "$(INTDIR)\chicdial.obj"
	-@erase "$(INTDIR)\cntritem.obj"
	-@erase "$(INTDIR)\colorlis.obj"
	-@erase "$(INTDIR)\datedial.obj"
	-@erase "$(INTDIR)\ddxm.obj"
	-@erase "$(INTDIR)\docopt.obj"
	-@erase "$(INTDIR)\doctype.obj"
	-@erase "$(INTDIR)\filenewd.obj"
	-@erase "$(INTDIR)\formatba.obj"
	-@erase "$(INTDIR)\formatpa.obj"
	-@erase "$(INTDIR)\formatta.obj"
	-@erase "$(INTDIR)\ipframe.obj"
	-@erase "$(INTDIR)\key.obj"
	-@erase "$(INTDIR)\listdlg.obj"
	-@erase "$(INTDIR)\mainfrm.obj"
	-@erase "$(INTDIR)\multconv.obj"
	-@erase "$(INTDIR)\options.obj"
	-@erase "$(INTDIR)\optionsh.obj"
	-@erase "$(INTDIR)\pageset.obj"
	-@erase "$(INTDIR)\ruler.obj"
	-@erase "$(INTDIR)\splash.obj"
	-@erase "$(INTDIR)\srvritem.obj"
	-@erase "$(INTDIR)\stdafx.obj"
	-@erase "$(INTDIR)\strings.obj"
	-@erase "$(INTDIR)\unitspag.obj"
	-@erase "$(INTDIR)\wordpad.obj"
	-@erase "$(INTDIR)\wordpad.res"
	-@erase "$(INTDIR)\wordpdoc.obj"
	-@erase "$(INTDIR)\wordpvw.obj"
	-@erase "$(OUTDIR)\wordpad.exe"

"$(OUTDIR)" :
    @if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_MAKE_PCH=/Yc"stdafx.h"
CPP_USE_PCH=/Yu"stdafx.h"

CPP_PROJ=/Zc:wchar_t /nologo /MD /W3 /EHsc /Os /Z7 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /D "_UNICODE" /D WINVER=0x500 /Fp"$(INTDIR)\wordpad.pch" /Fo"$(INTDIR)\\" /c 
RSC_PROJ=/nologo /l 0x409 /fo"$(INTDIR)\wordpad.res" /d "NDEBUG" /d "_AFXDLL" 

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /debug /pdb:"$(OUTDIR)\wordpad.pdb" /machine:I386 /out:"$(OUTDIR)\wordpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\buttondi.obj" \
	"$(INTDIR)\chicdial.obj" \
	"$(INTDIR)\cntritem.obj" \
	"$(INTDIR)\colorlis.obj" \
	"$(INTDIR)\datedial.obj" \
	"$(INTDIR)\ddxm.obj" \
	"$(INTDIR)\docopt.obj" \
	"$(INTDIR)\doctype.obj" \
	"$(INTDIR)\filenewd.obj" \
	"$(INTDIR)\formatba.obj" \
	"$(INTDIR)\formatpa.obj" \
	"$(INTDIR)\formatta.obj" \
	"$(INTDIR)\ipframe.obj" \
	"$(INTDIR)\key.obj" \
	"$(INTDIR)\listdlg.obj" \
	"$(INTDIR)\mainfrm.obj" \
	"$(INTDIR)\multconv.obj" \
	"$(INTDIR)\options.obj" \
	"$(INTDIR)\optionsh.obj" \
	"$(INTDIR)\pageset.obj" \
	"$(INTDIR)\ruler.obj" \
	"$(INTDIR)\splash.obj" \
	"$(INTDIR)\srvritem.obj" \
	"$(INTDIR)\strings.obj" \
	"$(INTDIR)\unitspag.obj" \
	"$(INTDIR)\wordpad.obj" \
	"$(INTDIR)\wordpdoc.obj" \
	"$(INTDIR)\wordpvw.obj" \
	"$(INTDIR)\wordpad.res"

"$(OUTDIR)\wordpad.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
	@echo $@
    @$(LINK32) $(LINK32_FLAGS) $(LINK32_OBJS) 

$(INTDIR)\stdafx.obj: stdafx.h stdafx.cpp
    @$(CPP) $(CPP_PROJ) $(CPP_MAKE_PCH) stdafx.cpp

# YMAKE needs to build stdafx.obj first so the precompiled header exists,
# then use it.  NMAKE processes things in order one at a time, so this is
# achieved by having stdafx.obj listed as the first object.
!IFDEF _YMAKE_VER
.cpp{$(INTDIR)}.obj: "$(INTDIR)\stdafx.obj"
    @$(CPP) $(CPP_PROJ) $(CPP_USE_PCH) $< 
!ELSE
.cpp{$(INTDIR)}.obj:
    @$(CPP) $(CPP_PROJ) $(CPP_USE_PCH) $< 
!ENDIF

.rc{$(INTDIR)}.res:
    @$(RC) $(RSC_PROJ) $< 

