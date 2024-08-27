OUTDIR=Release
INTDIR=Release
USE_DLL=0

CPP=cl.exe
RSC=rc.exe
LINK32=link.exe

CXX_MAKE_PCH=/Yc"stdafx.h"
CXX_USE_PCH=/Yu"stdafx.h"

!IF $(USE_DLL)==1
CXX_RUNTIME=/MD /D "_AFXDLL"
RC_RUNTIME=/d "_AFXDLL"
!ELSE
CXX_RUNTIME=/MT
RC_RUNTIME=
!ENDIF

CXXFLAGS=/Zc:wchar_t /nologo /W3 /EHsc /Os /Z7 $(CXX_RUNTIME) /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_UNICODE" /Fp"$(INTDIR)\wordpad.pch" /Fo"$(INTDIR)\\" /c 
RCFLAGS=/l 0x409 /fo"$(INTDIR)\wordpad.res" /d "NDEBUG" $(RC_RUNTIME)

LDFLAGS=/nologo /entry:"wWinMainCRTStartup" /subsystem:windows /incremental:no /debug /pdb:"$(OUTDIR)\wordpad.pdb" /out:"$(OUTDIR)\wordpad.exe" 

!IF [$(CC) 2>&1 | find "x86" >NUL]==0
LDFLAGS=$(LDFLAGS) -MACHINE:X86
!ELSE
!IF [$(CC) 2>&1 | find "x64" >NUL]==0
LDFLAGS=$(LDFLAGS) -MACHINE:X64
!ELSE
!IF [$(CC) 2>&1 | find "AMD64" >NUL]==0
LDFLAGS=$(LDFLAGS) -MACHINE:AMD64
!ELSE
!IF [$(CC) 2>&1 | find "ARM64" >NUL]==0
LDFLAGS=$(LDFLAGS) -MACHINE:ARM64
!ENDIF # ARM64
!ENDIF # AMD64
!ENDIF # X64
!ENDIF # X86

ALL : "$(OUTDIR)\wordpad.exe"

CLEAN :
	-@if exist "$(INTDIR)" rmdir /s /q "$(INTDIR)"
	-@if exist "$(OUTDIR)" rmdir /s /q "$(OUTDIR)"

"$(OUTDIR)" :
    @if not exist "$(OUTDIR)" mkdir "$(OUTDIR)"

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
    @$(LINK32) $(LDFLAGS) $(LINK32_OBJS) 

$(INTDIR)\stdafx.obj: stdafx.h stdafx.cpp
    @$(CPP) $(CXXFLAGS) $(CXX_MAKE_PCH) stdafx.cpp

# YMAKE needs to build stdafx.obj first so the precompiled header exists,
# then use it.  NMAKE processes things in order one at a time, so this is
# achieved by having stdafx.obj listed as the first object.
!IFDEF _YMAKE_VER
.cpp{$(INTDIR)}.obj: "$(INTDIR)\stdafx.obj"
    @$(CPP) $(CXXFLAGS) $(CXX_USE_PCH) $< 
!ELSE
.cpp{$(INTDIR)}.obj:
    @$(CPP) $(CXXFLAGS) $(CXX_USE_PCH) $< 
!ENDIF

.rc{$(INTDIR)}.res:
    @$(RC) $(RCFLAGS) $< 

