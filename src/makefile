OUTDIR=Release
INTDIR=Release
USE_DLL=0

CPP=cl.exe
RSC=rc.exe

ALL : "$(OUTDIR)\wordpad.exe"


CLEAN :
	-@if exist "$(INTDIR)" rmdir /s /q "$(INTDIR)"
	-@if exist "$(OUTDIR)" rmdir /s /q "$(OUTDIR)"

"$(OUTDIR)" :
    @if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"


CPP_MAKE_PCH=/Yc"stdafx.h"
CPP_USE_PCH=/Yu"stdafx.h"

!IF $(USE_DLL)==1
CPP_RUNTIME=/MD /D "_AFXDLL"
RSC_RUNTIME=/d "_AFXDLL"
!ELSE
CPP_RUNTIME=/MT
RSC_RUNTIME=
!ENDIF

CPP_PROJ=/Zc:wchar_t /nologo /W3 /EHsc /Os /Z7 $(CPP_RUNTIME) /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_UNICODE" /D WINVER=0x500 /Fp"$(INTDIR)\wordpad.pch" /Fo"$(INTDIR)\\" /c 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\wordpad.res" /d "NDEBUG" $(RSC_RUNTIME)

LINK32=link.exe
LINK32_FLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /debug /pdb:"$(OUTDIR)\wordpad.pdb" /machine:I386 /out:"$(OUTDIR)\wordpad.exe" 
LINK32_OBJS= \
	"$(INTDIR)\stdafx.obj" \
	"$(INTDIR)\about.obj" \
	"$(INTDIR)\bigicon.obj" \
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

