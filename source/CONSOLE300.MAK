# Microsoft Developer Studio Generated NMAKE File, Format Version 4.10
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

!IF "$(CFG)" == ""
CFG=CONSOLE - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to CONSOLE - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CONSOLE - Win32 Release" && "$(CFG)" !=\
 "CONSOLE - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Console.mak" CFG="CONSOLE - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CONSOLE - Win32 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CONSOLE - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "CONSOLE - Win32 Debug"
CPP=cl.exe
RSC=rc.exe
MTL=mktyplib.exe

!IF  "$(CFG)" == "CONSOLE - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : ".\WinRel\Console.pll"

CLEAN : 
	-@erase ".\WinRel\Console.exp"
	-@erase ".\WinRel\Console.lib"
	-@erase ".\WinRel\CONSOLE.OBJ"
	-@erase ".\WinRel\Console.pll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../../../" /I "../../../inc" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "PERL_OBJECT" /D "MSWIN32" /D "EMBED" /YX /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MT /W3 /GX /O2 /I "../../../" /I "../../../inc" /D "NDEBUG"\
 /D "WIN32" /D "_WINDOWS" /D "PERL_OBJECT" /D "MSWIN32" /D "EMBED"\
 /Fp"$(INTDIR)/Console.pch" /YX /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\WinRel/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Console.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ../../../Release/Perl300.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:0x10120000 /subsystem:windows /dll /machine:I386 /out:"WinRel\Console.pll"
LINK32_FLAGS=../../../Release/Perl300.lib kernel32.lib user32.lib gdi32.lib\
 winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib\
 uuid.lib odbc32.lib odbccp32.lib /nologo /base:0x10120000 /subsystem:windows\
 /dll /incremental:no /pdb:"$(OUTDIR)/Console.pdb" /machine:I386\
 /def:".\CONSOLE.DEF" /out:"$(OUTDIR)/Console.pll"\
 /implib:"$(OUTDIR)/Console.lib" 
DEF_FILE= \
	".\CONSOLE.DEF"
LINK32_OBJS= \
	".\WinRel\CONSOLE.OBJ"

".\WinRel\Console.pll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CONSOLE - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : ".\WinDebug\Console.pll"

CLEAN : 
	-@erase ".\WinDebug\Console.exp"
	-@erase ".\WinDebug\Console.ilk"
	-@erase ".\WinDebug\Console.lib"
	-@erase ".\WinDebug\CONSOLE.OBJ"
	-@erase ".\WinDebug\Console.pdb"
	-@erase ".\WinDebug\Console.pll"
	-@erase ".\WinDebug\vc40.idb"
	-@erase ".\WinDebug\vc40.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /MTd /w /W0 /Gm /GX /Zi /Od /I "../../../" /I "../../../inc" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "PERL_OBJECT" /D "MSWIN32" /D "EMBED" /YX /c
# SUBTRACT CPP /Fr
CPP_PROJ=/nologo /MTd /w /W0 /Gm /GX /Zi /Od /I "../../../" /I "../../../inc"\
 /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "PERL_OBJECT" /D "MSWIN32" /D "EMBED"\
 /Fp"$(INTDIR)/Console.pch" /YX /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\WinDebug/
CPP_SBRS=.\.
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Console.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 ../../../Release/Perl300.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /base:0x10120000 /subsystem:windows /dll /debug /machine:I386 /out:"WinDebug\Console.pll"
LINK32_FLAGS=../../../Release/Perl300.lib kernel32.lib user32.lib gdi32.lib\
 winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib\
 uuid.lib odbc32.lib odbccp32.lib /nologo /base:0x10120000 /subsystem:windows\
 /dll /incremental:yes /pdb:"$(OUTDIR)/Console.pdb" /debug /machine:I386\
 /def:".\CONSOLE.DEF" /out:"$(OUTDIR)/Console.pll"\
 /implib:"$(OUTDIR)/Console.lib" 
DEF_FILE= \
	".\CONSOLE.DEF"
LINK32_OBJS= \
	".\WinDebug\CONSOLE.OBJ"

".\WinDebug\Console.pll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "CONSOLE - Win32 Release"
# Name "CONSOLE - Win32 Debug"

!IF  "$(CFG)" == "CONSOLE - Win32 Release"

!ELSEIF  "$(CFG)" == "CONSOLE - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\CONSOLE.DEF

!IF  "$(CFG)" == "CONSOLE - Win32 Release"

!ELSEIF  "$(CFG)" == "CONSOLE - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\CONSOLE.CPP
DEP_CPP_CONSO=\
	"..\..\..\av.h"\
	"..\..\..\build.h"\
	"..\..\..\config.h"\
	"..\..\..\cop.h"\
	"..\..\..\cv.h"\
	"..\..\..\dosish.h"\
	"..\..\..\form.h"\
	"..\..\..\gv.h"\
	"..\..\..\handy.h"\
	"..\..\..\hv.h"\
	"..\..\..\IPerlSup.h"\
	"..\..\..\mg.h"\
	"..\..\..\nostdio.h"\
	"..\..\..\nt.h"\
	"..\..\..\NTXSub.h"\
	"..\..\..\objpp.h"\
	"..\..\..\op.h"\
	"..\..\..\opcode.h"\
	"..\..\..\perlio.h"\
	"..\..\..\perllib.h"\
	"..\..\..\perlsdio.h"\
	"..\..\..\perlsfio.h"\
	"..\..\..\perly.h"\
	"..\..\..\pp.h"\
	"..\..\..\proto.h"\
	"..\..\..\regexp.h"\
	"..\..\..\scope.h"\
	"..\..\..\sv.h"\
	"..\..\..\unixish.h"\
	"..\..\..\util.h"\
	".\../../../embed.h"\
	".\../../../EXTERN.h"\
	".\../../../inc\dirent.h"\
	".\../../../perl.h"\
	".\../../../XSUB.h"\
	{$(INCLUDE)}"\sys\STAT.H"\
	{$(INCLUDE)}"\sys\TYPES.H"\
	
NODEP_CPP_CONSO=\
	"..\..\..\os2ish.h"\
	"..\..\..\plan9\plan9ish.h"\
	"..\..\..\vmsish.h"\
	

!IF  "$(CFG)" == "CONSOLE - Win32 Release"


".\WinRel\CONSOLE.OBJ" : $(SOURCE) $(DEP_CPP_CONSO) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "CONSOLE - Win32 Debug"


".\WinDebug\CONSOLE.OBJ" : $(SOURCE) $(DEP_CPP_CONSO) "$(INTDIR)"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
