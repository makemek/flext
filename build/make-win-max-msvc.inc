DEFS=$(DEFS) /DFLEXT_SYS=1
CFLAGS=$(CFLAGS) /Zp2 

INCPATH=$(INCPATH) /I$(MAXSDKPATH)\max-includes /I$(MAXSDKPATH)\msp-includes
LIBPATH=$(LIBPATH) /LIBPATH:$(MAXSDKPATH)\max-includes /LIBPATH:$(MAXSDKPATH)\msp-includes

# these are both in MAXSDKPATH
LIBS=$(LIBS) maxapi.lib maxaudio.lib

EXT=mxe

#########################################

!ifdef FLEXT_SHARED
# --- shared ---

!elseifdef FLEXT_THREADED
# --- static multi-threaded ---

!ifdef _DEBUG
LIBS=$(LIBS) flext_td-maxwin.lib 
!else
LIBS=$(LIBS) flext_t-maxwin.lib 
!endif

!else 
# --- static single-threaded ---

!ifdef _DEBUG
LIBS=$(LIBS) flext_d-maxwin.lib 
!else
LIBS=$(LIBS) flext-maxwin.lib 
!endif

!endif