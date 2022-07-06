!IFDEF _YMAKE_VER

set VERSION=

ARCH=win32

!IF [$(CC) -? 2>&1 | findstr /C:"x64" >NUL 2>&1]==0
ARCH=amd64
!ELSE
!IF [$(CC) -? 2>&1 | findstr /C:"AMD64" >NUL 2>&1]==0
ARCH=amd64
!ELSE
!IF [$(CC) -? 2>&1 | findstr /C:"ARM64" >NUL 2>&1]==0
ARCH=arm64
!ELSE
!IF [$(CC) -? 2>&1 | findstr /C:"ARM" >NUL 2>&1]==0
ARCH=arm
!ELSE
!IF [$(CC) -? 2>&1 | findstr /C:"Itanium" >NUL 2>&1]==0
ARCH=ia64
!ELSE
!IF [$(CC) -? 2>&1 | findstr /C:"MIPS" >NUL 2>&1]==0
ARCH=mips
!ENDIF # MIPS
!ENDIF # Itanium
!ENDIF # ARM (32)
!ENDIF # ARM64
!ENDIF # AMD64
!ENDIF # x64

URLROOT=http://www.malsmith.net/download/?obj=wordpad/latest-stable

ARCHPKGS=out\wordpad-$(ARCH).cab      \
		 out\wordpad-pdb-$(ARCH).cab

NOARCHPKGS=out\wordpad-source.cab

all: $(ARCHPKGS) $(NOARCHPKGS)

out:
	@echo $(@F)
	@mkdir out

out\wordpad-$(ARCH).cab: out wordpad.lst
	@echo $(@F)
	@ypm -c out\wordpad-$(ARCH).cab wordpad $(VERSION) $(ARCH) -filelist wordpad.lst -minimumosbuild 1381 -upgradepath $(URLROOT)/wordpad-$(ARCH).cab -symbolpath $(URLROOT)/wordpad-pdb-$(ARCH).cab -sourcepath $(URLROOT)/wordpad-source.cab

out\wordpad-pdb-$(ARCH).cab: out wordpad-pdb.lst
	@echo $(@F)
	@ypm -c out\wordpad-pdb-$(ARCH).cab wordpad-pdb $(VERSION) $(ARCH) -filelist wordpad-pdb.lst -upgradepath $(URLROOT)/wordpad-pdb-$(ARCH).cab -sourcepath $(URLROOT)/wordpad-source.cab

out\wordpad-source.cab:
	@echo $(@F)
	@ypm -cs out\wordpad-source.cab wordpad-source $(VERSION) -filepath ..

!ENDIF
