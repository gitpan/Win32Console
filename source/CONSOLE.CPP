/*
 * Console.CPP
 * 20 Jan 97 by Aldo Calpini <dada@divinf.it>
 *
 * XS interface to the Win32 Console API
 * based on Registry.CPP written by Jesse Dougherty
 *
 * Version: 0.03 07 Apr 97
 *
 */

#define  WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
// Section for the constant definitions.
#define CROAK croak

#define SETIV(index,value) sv_setiv(ST(index), value)
#define SETPV(index,string) sv_setpv(ST(index), string)
#define SETPVN(index, buffer, length) sv_setpvn(ST(index), (char*)buffer, length)

#define NEW(x,v,n,t)  (v = (t*)safemalloc((MEM_SIZE)((n) * sizeof(t))))
#define PERLSvIV(sv) (SvIOK(sv) ? SvIVX(sv) : sv_2iv(sv))
#define PERLSvPV(sv, lp) (SvPOK(sv) ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pv(sv, &lp))

#define PERLPUSHMARK(p) if (++markstack_ptr == markstack_max)   \
            markstack_grow();           \
            *markstack_ptr = (p) - stack_base

#define PERLXPUSHs(s)   do {\
        if (stack_max - sp < 1) {\
                sp = stack_grow(sp, sp, 1);\
            }\
  (*++sp = (s)); } while (0)


static CPerl* myPerl;


DWORD
constant(CPerl* pPerl,char *name, int arg)
{
    errno = 0;
    switch (*name) {
    case 'A':
        break;
    case 'B':
        if (strEQ(name, "BACKGROUND_BLUE"))
            #ifdef BACKGROUND_BLUE
                return BACKGROUND_BLUE;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "BACKGROUND_GREEN"))
            #ifdef BACKGROUND_GREEN
                return BACKGROUND_GREEN;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "BACKGROUND_INTENSITY"))
            #ifdef BACKGROUND_INTENSITY
                return BACKGROUND_INTENSITY;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "BACKGROUND_RED"))
            #ifdef BACKGROUND_RED
                return BACKGROUND_RED;
            #else
                goto not_there;
            #endif
        break;
    case 'C':
		if (strEQ(name, "CAPSLOCK_ON"))
            #ifdef CAPSLOCK_ON
                return CAPSLOCK_ON;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "CONSOLE_TEXTMODE_BUFFER"))
            #ifdef CONSOLE_TEXTMODE_BUFFER
                return CONSOLE_TEXTMODE_BUFFER;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "CTRL_BREAK_EVENT"))
            #ifdef CTRL_BREAK_EVENT
                return CTRL_BREAK_EVENT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "CTRL_C_EVENT"))
            #ifdef CTRL_C_EVENT
                return CTRL_C_EVENT;
            #else
                goto not_there;
            #endif
		break;

    case 'D':
        break;
    case 'E':
        if (strEQ(name, "ENABLE_ECHO_INPUT"))
            #ifdef ENABLE_ECHO_INPUT
                return ENABLE_ECHO_INPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENABLE_LINE_INPUT"))
            #ifdef ENABLE_LINE_INPUT
                return ENABLE_LINE_INPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENABLE_MOUSE_INPUT"))
            #ifdef ENABLE_MOUSE_INPUT
                return ENABLE_MOUSE_INPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENABLE_PROCESSED_INPUT"))
            #ifdef ENABLE_PROCESSED_INPUT
                return ENABLE_PROCESSED_INPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENABLE_PROCESSED_OUTPUT"))
            #ifdef ENABLE_PROCESSED_OUTPUT
                return ENABLE_PROCESSED_OUTPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENABLE_WINDOW_INPUT"))
            #ifdef ENABLE_WINDOW_INPUT
                return ENABLE_WINDOW_INPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENABLE_WRAP_AT_EOL_OUTPUT"))
            #ifdef ENABLE_WRAP_AT_EOL_OUTPUT
                return ENABLE_WRAP_AT_EOL_OUTPUT;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "ENHANCED_KEY"))
            #ifdef ENHANCED_KEY
                return ENHANCED_KEY;
            #else
                goto not_there;
            #endif
        break;
    case 'F':
        if (strEQ(name, "FILE_SHARE_READ"))
            #ifdef FILE_SHARE_READ
                return FILE_SHARE_READ;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "FILE_SHARE_WRITE"))
            #ifdef FILE_SHARE_WRITE
                return FILE_SHARE_WRITE;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "FOREGROUND_BLUE"))
            #ifdef FOREGROUND_BLUE
                return FOREGROUND_BLUE;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "FOREGROUND_GREEN"))
            #ifdef FOREGROUND_GREEN
                return FOREGROUND_GREEN;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "FOREGROUND_INTENSITY"))
            #ifdef FOREGROUND_INTENSITY
                return FOREGROUND_INTENSITY;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "FOREGROUND_RED"))
            #ifdef FOREGROUND_RED
                return FOREGROUND_RED;
            #else
                goto not_there;
            #endif
        break;
    case 'G':
        if (strEQ(name, "GENERIC_READ"))
            #ifdef GENERIC_READ
                return GENERIC_READ;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "GENERIC_WRITE"))
            #ifdef GENERIC_WRITE
                return GENERIC_WRITE;
            #else
                goto not_there;
            #endif
        break;
    case 'H':
        break;
    case 'I':
        break;
    case 'J':
        break;
    case 'K':
        if (strEQ(name, "KEY_EVENT"))
            #ifdef KEY_EVENT
                return KEY_EVENT;
            #else
                goto not_there;
            #endif
        break;
    case 'L':
        if (strEQ(name, "LEFT_ALT_PRESSED"))
            #ifdef LEFT_ALT_PRESSED
                return LEFT_ALT_PRESSED;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "LEFT_CTRL_PRESSED"))
            #ifdef LEFT_CTRL_PRESSED
                return LEFT_CTRL_PRESSED;
            #else
                goto not_there;
            #endif
		break;
    case 'M':
        break;
    case 'N':
        if (strEQ(name, "NUMLOCK_ON"))
            #ifdef NUMLOCK_ON
                return NUMLOCK_ON;
            #else
                goto not_there;
            #endif
        break;
    case 'O':
        break;
    case 'P':
        break;
    case 'Q':
        break;
    case 'R':
        if (strEQ(name, "RIGHT_ALT_PRESSED"))
            #ifdef RIGHT_ALT_PRESSED
                return RIGHT_ALT_PRESSED;
            #else
                goto not_there;
            #endif
        if (strEQ(name, "RIGHT_CTRL_PRESSED"))
            #ifdef RIGHT_CTRL_PRESSED
                return RIGHT_CTRL_PRESSED;
            #else
                goto not_there;
            #endif
		break;
    case 'S':
		if (strEQ(name, "SCROLLLOCK_ON"))
			#ifdef SCROLLLOCK_ON
				return SCROLLLOCK_ON;
			#else
				goto not_there;
			#endif
		if (strEQ(name, "SHIFT_PRESSED"))
			#ifdef SHIFT_PRESSED
				return SHIFT_PRESSED;
			#else
				goto not_there;
			#endif
		if (strEQ(name, "STD_ERROR_HANDLE"))
			#ifdef STD_ERROR_HANDLE
				return STD_ERROR_HANDLE;
			#else
				goto not_there;
			#endif
		if (strEQ(name, "STD_INPUT_HANDLE"))
			#ifdef STD_INPUT_HANDLE
				return STD_INPUT_HANDLE;
			#else
				goto not_there;
			#endif
		if (strEQ(name, "STD_OUTPUT_HANDLE"))
			#ifdef STD_OUTPUT_HANDLE
				return STD_OUTPUT_HANDLE;
			#else
				goto not_there;
			#endif
        break;
    case 'T':
        break;
    case 'U':
        break;
    case 'V':
        break;
    case 'W':
        break;
    case 'X':
        break;
    case 'Y':
        break;
    case 'Z':
        break;
    }
    errno = EINVAL;
    return 0;

not_there:
    errno = ENOENT;
    return 0;
}


XS(XS_Win32__Console_constant)
{
    dXSARGS;

    if (items != 2) {
        croak("Usage: Win32::Console::constant(name, arg)");
    }
    {
        char *  name = (char *)SvPV(ST(0),na);
        int arg = (int)SvIV(ST(1));
        DWORD RETVAL;

        RETVAL = constant(pPerl, name, arg);
        ST(0) = sv_newmortal();
        sv_setiv(ST(0), (IV)RETVAL);
    }
    XSRETURN(1);
}



XS(XS_Win32__Console_GetStdHandle) {

    dXSARGS;
    XSRETURN_IV((long)GetStdHandle((DWORD)PERLSvIV(ST(0))));
}


XS(XS_Win32__Console_SetStdHandle) {

    dXSARGS;

    if(SetStdHandle((DWORD)PERLSvIV(ST(0)), (HANDLE)PERLSvIV(ST(1)))) {
		XSRETURN_YES;
	} else {
		XSRETURN_NO;
	}
}


XS(XS_Win32__Console_GetNumberOfConsoleMouseButtons) {

    dXSARGS;

    DWORD buttons;
        
    if(GetNumberOfConsoleMouseButtons(&buttons)) {
		XSRETURN_IV(buttons);
	} else {
		XSRETURN_NO;
	}
}



XS(XS_Win32__Console_SetConsoleCursorPosition) {

    dXSARGS;

    COORD coords;

    coords.X=(SHORT)PERLSvIV(ST(1));
    coords.Y=(SHORT)PERLSvIV(ST(2));
        
    if(SetConsoleCursorPosition((HANDLE)PERLSvIV(ST(0)),
                               coords)) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_WriteConsoleOutputAttribute) {

    dXSARGS;
    int i;
    COORD coords;
    DWORD written;
    unsigned short buffer[80*999*sizeof(unsigned short)];
	DWORD towrite=strlen(PERLSvPV(ST(1),na));

    for(i=0; i<towrite; i++) {
        buffer[i] = (unsigned short)((char *)PERLSvPV(ST(1), na)[i]);
    }

    coords.X=(SHORT)PERLSvIV(ST(2));
    coords.Y=(SHORT)PERLSvIV(ST(3));
        
    if(WriteConsoleOutputAttribute((HANDLE)PERLSvIV(ST(0)),
                                   (const unsigned short *)&buffer,
                                   towrite,
                                   coords,
                                   &written)) {
        ST(0)=sv_2mortal(newSViv(written));
        XSRETURN(1);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_WriteConsoleOutputCharacter) {

    dXSARGS;

    COORD coords;
    DWORD written;

    coords.X=(SHORT)PERLSvIV(ST(2));
    coords.Y=(SHORT)PERLSvIV(ST(3));
        
    if(WriteConsoleOutputCharacter((HANDLE)PERLSvIV(ST(0)),
                                   (LPCTSTR)PERLSvPV(ST(1),na),
                                   (DWORD)strlen(PERLSvPV(ST(1),na)),
                                   coords,
                                   &written)) {
        XSRETURN_IV(written);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_ReadConsoleOutputCharacter) {

    dXSARGS;

    COORD coords;
    DWORD nofread;

    coords.X=(SHORT)PERLSvIV(ST(3));
    coords.Y=(SHORT)PERLSvIV(ST(4));
        
    if(ReadConsoleOutputCharacter((HANDLE)PERLSvIV(ST(0)),
                                  (char *)PERLSvPV(ST(1),na),
                                  (DWORD)PERLSvIV(ST(2)),
                                  coords,
                                  &nofread)) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_ReadConsoleOutputAttribute) {

    dXSARGS;
    int i;
    COORD coords;
    DWORD nofread;
    unsigned short abuffer[80*999*sizeof(unsigned short)];
    char cbuffer[80*999];

    coords.X=(SHORT)PERLSvIV(ST(2));
    coords.Y=(SHORT)PERLSvIV(ST(3));

    if(ReadConsoleOutputAttribute((HANDLE)PERLSvIV(ST(0)),
                                  (unsigned short *)&abuffer,
                                  (DWORD)PERLSvIV(ST(1)),
                                  coords,
                                  &nofread)) {

        for(i=0;i<nofread;i++) {
            cbuffer[i]=(char)abuffer[i];
        }
        ST(0)=sv_2mortal(newSVpv(cbuffer,nofread));
        XSRETURN(1);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_WriteConsole) {

    dXSARGS;

    DWORD written;

    if(WriteConsole((HANDLE)PERLSvIV(ST(0)),
                    (VOID *)PERLSvPV(ST(1),na),
                    (DWORD)strlen(PERLSvPV(ST(1),na)),
                    &written,
                    NULL)) {
        XSRETURN_IV(written);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_ScrollConsoleScreenBuffer) {

    dXSARGS;

    COORD dest;
    SMALL_RECT area;
    SMALL_RECT clip;
	CHAR_INFO fill;

    area.Left   = (SHORT)PERLSvIV(ST(1));
    area.Top    = (SHORT)PERLSvIV(ST(2));
    area.Right  = (SHORT)PERLSvIV(ST(3));
    area.Bottom = (SHORT)PERLSvIV(ST(4));

    dest.X=(SHORT)PERLSvIV(ST(5));
    dest.Y=(SHORT)PERLSvIV(ST(6));

	#ifdef UNICODE
		fill.Char.UnicodeChar=(WCHAR)PERLSvIV(ST(7));
	#else
		fill.Char.AsciiChar=(CHAR)PERLSvIV(ST(7));
	#endif
    fill.Attributes=(unsigned short)PERLSvIV(ST(8));

	if(items > 9) {
		clip.Left   = (SHORT)PERLSvIV(ST(9));
		clip.Top    = (SHORT)PERLSvIV(ST(10));
		clip.Right  = (SHORT)PERLSvIV(ST(11));
		clip.Bottom = (SHORT)PERLSvIV(ST(12));
	    if(ScrollConsoleScreenBuffer((HANDLE)PERLSvIV(ST(0)),
								     &area,
									 &clip,
									 dest,
									 &fill)) {
			XSRETURN_YES;
		} else {
	        XSRETURN_NO;
	    }
	} else {
	    if(ScrollConsoleScreenBuffer((HANDLE)PERLSvIV(ST(0)),
								     &area,
									 NULL,
									 dest,
									 &fill)) {
			XSRETURN_YES;
		} else {
	        XSRETURN_NO;
	    }
	}
}



XS(XS_Win32__Console_WriteConsoleOutput) {

    dXSARGS;

    COORD coords;
    COORD size;
    SMALL_RECT to;

    size.X=(SHORT)PERLSvIV(ST(2));
    size.Y=(SHORT)PERLSvIV(ST(3));

    coords.X=(SHORT)PERLSvIV(ST(4));
    coords.Y=(SHORT)PERLSvIV(ST(5));

    to.Left   = (SHORT)PERLSvIV(ST(6));
    to.Top    = (SHORT)PERLSvIV(ST(7));
    to.Right  = (SHORT)PERLSvIV(ST(8));
    to.Bottom = (SHORT)PERLSvIV(ST(9));
        
    if(WriteConsoleOutput((HANDLE)PERLSvIV(ST(0)),
                          (CHAR_INFO *)PERLSvPV(ST(1),na),
                          size,
                          coords,
                          &to)) {
        ST(0)=sv_2mortal(newSViv(to.Left));
        ST(1)=sv_2mortal(newSViv(to.Top));
        ST(2)=sv_2mortal(newSViv(to.Right));
        ST(3)=sv_2mortal(newSViv(to.Bottom));
        XSRETURN(4);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_ReadConsoleOutput) {

    dXSARGS;

    COORD coords;
    COORD size;
    SMALL_RECT from;

    size.X=(SHORT)PERLSvIV(ST(2));
    size.Y=(SHORT)PERLSvIV(ST(3));

    coords.X=(SHORT)PERLSvIV(ST(4));
    coords.Y=(SHORT)PERLSvIV(ST(5));

    from.Left   = (SHORT)PERLSvIV(ST(6));
    from.Top    = (SHORT)PERLSvIV(ST(7));
    from.Right  = (SHORT)PERLSvIV(ST(8));
    from.Bottom = (SHORT)PERLSvIV(ST(9));
        
    if(ReadConsoleOutput((HANDLE)PERLSvIV(ST(0)),
                         (CHAR_INFO *)PERLSvPV(ST(1),na),
                         size,
                         coords,
                         &from)) {
        ST(0)=sv_2mortal(newSViv(from.Left));
        ST(1)=sv_2mortal(newSViv(from.Top));
        ST(2)=sv_2mortal(newSViv(from.Right));
        ST(3)=sv_2mortal(newSViv(from.Bottom));
        XSRETURN(4);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_SetConsoleWindowInfo) {

    dXSARGS;

    SMALL_RECT newwin;

    newwin.Left   = (SHORT)PERLSvIV(ST(2));
    newwin.Top    = (SHORT)PERLSvIV(ST(3));
    newwin.Right  = (SHORT)PERLSvIV(ST(4));
    newwin.Bottom = (SHORT)PERLSvIV(ST(5));
        
    if(SetConsoleWindowInfo((HANDLE)PERLSvIV(ST(0)),
							(BOOL)PERLSvIV(ST(1)),
							&newwin)) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_GetNumberOfConsoleInputEvents) {

    dXSARGS;

    DWORD nofevents;

    if(GetNumberOfConsoleInputEvents((HANDLE)PERLSvIV(ST(0)),
									 &nofevents)) {
        XSRETURN_IV(nofevents);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_FlushConsoleInputBuffer) {

    dXSARGS;

    if(FlushConsoleInputBuffer((HANDLE)PERLSvIV(ST(0)))) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_ReadConsole) {

    dXSARGS;
	
	DWORD nofread;
	
    if(ReadConsole((HANDLE)PERLSvIV(ST(0)),
				   (void *)PERLSvPV(ST(1),na),
				   (DWORD)PERLSvIV(ST(2)),
				   &nofread,
				   NULL)) {
        XSRETURN_IV(nofread);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_ReadConsoleInput) {

    dXSARGS;
	
	DWORD nofread;
	INPUT_RECORD event;
	KEY_EVENT_RECORD * kevent;
	MOUSE_EVENT_RECORD * mevent;

    if(ReadConsoleInput((HANDLE)PERLSvIV(ST(0)),
						&event,
						1,
						&nofread)) {
		switch(event.EventType) {
		case KEY_EVENT:
			kevent=(KEY_EVENT_RECORD *)&(event.Event);
			ST(0)=sv_2mortal(newSViv(KEY_EVENT));
			ST(1)=sv_2mortal(newSViv(kevent->bKeyDown));
			ST(2)=sv_2mortal(newSViv(kevent->wRepeatCount));
			ST(3)=sv_2mortal(newSViv(kevent->wVirtualKeyCode));
			ST(4)=sv_2mortal(newSViv(kevent->wVirtualScanCode));
#ifdef UNICODE
			ST(5)=sv_2mortal(newSViv(kevent->uChar.UnicodeChar));
#else
			ST(5)=sv_2mortal(newSViv(kevent->uChar.AsciiChar));
#endif
			ST(6)=sv_2mortal(newSViv(kevent->dwControlKeyState));
			XSRETURN(7);
			break;
		case MOUSE_EVENT:
			mevent=(MOUSE_EVENT_RECORD *)&(event.Event);
			ST(0)=sv_2mortal(newSViv(MOUSE_EVENT));
			ST(1)=sv_2mortal(newSViv(mevent->dwMousePosition.X));
			ST(2)=sv_2mortal(newSViv(mevent->dwMousePosition.Y));
			ST(3)=sv_2mortal(newSViv(mevent->dwButtonState));
			ST(4)=sv_2mortal(newSViv(mevent->dwControlKeyState));
			ST(5)=sv_2mortal(newSViv(mevent->dwEventFlags));
			XSRETURN(6);
			break;
		}
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_WriteConsoleInput) {

    dXSARGS;
	
	DWORD written;
	INPUT_RECORD event;
	KEY_EVENT_RECORD * kevent;
	MOUSE_EVENT_RECORD * mevent;

	event.EventType = PERLSvIV(ST(1));
	switch(event.EventType) {
	case KEY_EVENT:
		kevent=(KEY_EVENT_RECORD *)&(event.Event);
		kevent->bKeyDown=(BOOL)PERLSvIV(ST(2));
		kevent->wRepeatCount=PERLSvIV(ST(3));
		kevent->wVirtualKeyCode=PERLSvIV(ST(4));
		kevent->wVirtualScanCode=PERLSvIV(ST(5));
#ifdef UNICODE
		kevent->uChar.UnicodeChar=PERLSvIV(ST(6));
#else
		kevent->uChar.AsciiChar=PERLSvIV(ST(7));
#endif
		break;
	case MOUSE_EVENT:
		mevent=(MOUSE_EVENT_RECORD *)&(event.Event);
		mevent->dwMousePosition.X=PERLSvIV(ST(2));
		mevent->dwMousePosition.Y=PERLSvIV(ST(3));
		mevent->dwButtonState=PERLSvIV(ST(4));
		mevent->dwControlKeyState=PERLSvIV(ST(5));
		mevent->dwEventFlags=PERLSvIV(ST(6));
		break;
	default:
		XSRETURN_NO;
		break;
	}

    if(WriteConsoleInput((HANDLE)PERLSvIV(ST(0)),
						 &event,
						 1,
						 &written)) {
		XSRETURN_YES;
	} else {
		XSRETURN_NO;
    }
}


XS(XS_Win32__Console_PeekConsoleInput) {

    dXSARGS;
	
	DWORD nofread;
	INPUT_RECORD event;
	KEY_EVENT_RECORD * kevent;
	MOUSE_EVENT_RECORD * mevent;

    if(PeekConsoleInput((HANDLE)PERLSvIV(ST(0)),
						&event,
						1,
						&nofread)) {
		switch(event.EventType) {
		case KEY_EVENT:
			kevent=(KEY_EVENT_RECORD *)&(event.Event);
			ST(0)=sv_2mortal(newSViv(KEY_EVENT));
			ST(1)=sv_2mortal(newSViv(kevent->bKeyDown));
			ST(2)=sv_2mortal(newSViv(kevent->wRepeatCount));
			ST(3)=sv_2mortal(newSViv(kevent->wVirtualKeyCode));
			ST(4)=sv_2mortal(newSViv(kevent->wVirtualScanCode));
#ifdef UNICODE
			ST(5)=sv_2mortal(newSViv(kevent->uChar.UnicodeChar));
#else
			ST(5)=sv_2mortal(newSViv(kevent->uChar.AsciiChar));
#endif
			ST(6)=sv_2mortal(newSViv(kevent->dwControlKeyState));
			XSRETURN(7);
			break;
		case MOUSE_EVENT:
			mevent=(MOUSE_EVENT_RECORD *)&(event.Event);
			ST(0)=sv_2mortal(newSViv(MOUSE_EVENT));
			ST(1)=sv_2mortal(newSViv(mevent->dwMousePosition.X));
			ST(2)=sv_2mortal(newSViv(mevent->dwMousePosition.Y));
			ST(3)=sv_2mortal(newSViv(mevent->dwButtonState));
			ST(4)=sv_2mortal(newSViv(mevent->dwControlKeyState));
			ST(5)=sv_2mortal(newSViv(mevent->dwEventFlags));
			XSRETURN(6);
			break;
		}
    } else {
        XSRETURN_NO;
    }
}



XS(XS_Win32__Console_SetConsoleMode) {

    dXSARGS;
	
    if(SetConsoleMode((HANDLE)PERLSvIV(ST(0)),
					  (DWORD)PERLSvIV(ST(1)))) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_GetConsoleMode) {

    dXSARGS;
	DWORD flags;
	
    if(GetConsoleMode((HANDLE)PERLSvIV(ST(0)),
					  &flags)) {
        XSRETURN_IV(flags);
    } else {
        XSRETURN_NO;
    }
}



XS(XS_Win32__Console_SetConsoleTextAttribute) {

    dXSARGS;

    if(SetConsoleTextAttribute((HANDLE)PERLSvIV(ST(0)),
                               PERLSvIV(ST(1)))) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}
 

XS(XS_Win32__Console_GetConsoleScreenBufferInfo) {

    dXSARGS;
    CONSOLE_SCREEN_BUFFER_INFO info;

    if(GetConsoleScreenBufferInfo((HANDLE)PERLSvIV(ST(0)),
                                  &info)) {
        ST( 0)=sv_2mortal(newSViv(info.dwSize.X));
        ST( 1)=sv_2mortal(newSViv(info.dwSize.Y));
        ST( 2)=sv_2mortal(newSViv(info.dwCursorPosition.X));
        ST( 3)=sv_2mortal(newSViv(info.dwCursorPosition.Y));
        ST( 4)=sv_2mortal(newSViv(info.wAttributes));
        ST( 5)=sv_2mortal(newSViv(info.srWindow.Left));
        ST( 6)=sv_2mortal(newSViv(info.srWindow.Top));
        ST( 7)=sv_2mortal(newSViv(info.srWindow.Right));
        ST( 8)=sv_2mortal(newSViv(info.srWindow.Bottom));
        ST( 9)=sv_2mortal(newSViv(info.dwMaximumWindowSize.X));
        ST(10)=sv_2mortal(newSViv(info.dwMaximumWindowSize.Y));
        XSRETURN(11);
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_SetConsoleScreenBufferSize) {

    dXSARGS;
    COORD size;

    size.X=(SHORT)PERLSvIV(ST(1));
    size.Y=(SHORT)PERLSvIV(ST(2));

    if(SetConsoleScreenBufferSize((HANDLE)PERLSvIV(ST(0)), size)) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_GetConsoleCursorInfo) {

    dXSARGS;
    CONSOLE_CURSOR_INFO info;

    if(GetConsoleCursorInfo((HANDLE)PERLSvIV(ST(0)),
                            &info)) {
        ST(0)=sv_2mortal(newSViv(info.dwSize));
        ST(1)=sv_2mortal(newSViv(info.bVisible));
        XSRETURN(2);
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_SetConsoleCursorInfo) {

    dXSARGS;
    CONSOLE_CURSOR_INFO info;

    info.dwSize=(DWORD)PERLSvIV(ST(1));
    info.bVisible=(BOOL)PERLSvIV(ST(2));

    if(SetConsoleCursorInfo((HANDLE)PERLSvIV(ST(0)),
                            &info)) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_FillConsoleOutputAttribute) {

    dXSARGS;

    COORD coords;
    DWORD written;

    coords.X=(SHORT)PERLSvIV(ST(3));
    coords.Y=(SHORT)PERLSvIV(ST(4));
        
    if(FillConsoleOutputAttribute((HANDLE)PERLSvIV(ST(0)),
                                  PERLSvIV(ST(1)),
                                  (DWORD)PERLSvIV(ST(2)),
                                  coords,
                                  &written)) {
        XSRETURN_IV(written);
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_FillConsoleOutputCharacter) {

    dXSARGS;

    COORD coords;
    DWORD written;

    coords.X=(SHORT)PERLSvIV(ST(3));
    coords.Y=(SHORT)PERLSvIV(ST(4));
        
    if(FillConsoleOutputCharacter((HANDLE)PERLSvIV(ST(0)),
                                  (char)PERLSvPV(ST(1),na)[0],
                                  (DWORD)PERLSvIV(ST(2)),
                                  coords,
                                  &written)) {
        XSRETURN_IV(written);
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_CreateConsoleScreenBuffer) {

    dXSARGS;

    HANDLE handle;

    handle=CreateConsoleScreenBuffer((DWORD)PERLSvIV(ST(0)),
                                     (DWORD)PERLSvIV(ST(1)),
                                     NULL,
                                     (DWORD)PERLSvIV(ST(2)),
                                     NULL);

    XSRETURN_IV((long)handle);
}

XS(XS_Win32__Console_SetConsoleActiveScreenBuffer) {

    dXSARGS;

    if(SetConsoleActiveScreenBuffer((HANDLE)PERLSvIV(ST(0)))) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_AllocConsole) {

    dXSARGS;

    if(AllocConsole()) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_FreeConsole) {

    dXSARGS;

    if(FreeConsole()) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_GetConsoleTitle) {

    dXSARGS;

    char title[1024];

    if(GetConsoleTitle((char *)&title,1024)) {
        ST(0)=sv_2mortal(newSVpv((char *)title,strlen(title)));
        XSRETURN(1);
    } else {
        XSRETURN_NO;
    }
}

XS(XS_Win32__Console_SetConsoleTitle) {

    dXSARGS;

    if(SetConsoleTitle((char *)PERLSvPV(ST(0),na))) {
        XSRETURN_YES;
    } else {
        XSRETURN_NO;
    }
}


XS(XS_Win32__Console_GetLargestConsoleWindowSize) {

    dXSARGS;
	COORD size;

	size=GetLargestConsoleWindowSize((HANDLE)PERLSvIV(ST(0)));
	ST(0)=sv_2mortal(newSViv(size.X));
	ST(1)=sv_2mortal(newSViv(size.Y));
	XSRETURN(2);
}


XS(XS_Win32__Console_GetConsoleCP) {

    dXSARGS;
	XSRETURN_IV((long)GetConsoleCP());
}


XS(XS_Win32__Console_SetConsoleCP) {

    dXSARGS;
	XSRETURN_IV((long)SetConsoleCP((UINT)PERLSvIV(ST(0))));
}

XS(XS_Win32__Console_GetConsoleOutputCP) {

    dXSARGS;
	XSRETURN_IV((long)GetConsoleOutputCP());
}

XS(XS_Win32__Console_SetConsoleOutputCP) {

    dXSARGS;
	XSRETURN_IV((long)SetConsoleOutputCP((UINT)PERLSvIV(ST(0))));
}


XS(XS_Win32__Console_CloseHandle) {

    dXSARGS;
	XSRETURN_IV((long)CloseHandle((HANDLE)PERLSvIV(ST(0))));
}


/*
BOOL HandlerRoutine(DWORD dwCtrlType) {
	CPerl *pPerl = myPerl;
	int count;
	int result;

	// printf("HandlerRoutine: CtrlType=%d\n", dwCtrlType);
	dSP;
	ENTER;
	SAVETMPS;
	PUSHMARK(sp);
	XPUSHs(sv_2mortal(newSViv(dwCtrlType)));
	PUTBACK;
	count = perl_call_pv("Win32::Console::CtrlHandler", G_EVAL|G_SCALAR);
	SPAGAIN;
    // Check the eval first
    //if (SvTRUE(GvSV(lerrgv))) {
    //    POPs ;
	//	PUTBACK ;
	//	FREETMPS ;
	//	LEAVE ;
	//	// ExitProcess(0);
	//	return(TRUE);
	//} else {
		if(count < 1) {
			result = 0;
		} else {
			result = POPi;
		}
		PUTBACK ;
		FREETMPS ;
		LEAVE ;
		printf("HandlerRoutine: result=%d\n", result);
		if(result == 0) {
			printf("HandlerRoutine: returning FALSE\n");
			return(FALSE);
		} else {
			printf("HandlerRoutine: returning TRUE\n");
			// ExitProcess(0);
			return(TRUE);
		}
	//}
}
*/


XS(XS_Win32__Console_GenerateConsoleCtrlEvent) {

	dXSARGS;
	if(GenerateConsoleCtrlEvent((DWORD)PERLSvIV(ST(0)),
		                        (DWORD)PERLSvIV(ST(1)))) {
		XSRETURN_YES;
	} else {
		XSRETURN_NO;
	}
}

/*
XS(XS_Win32__Console_SetConsoleCtrlHandler) {

	dXSARGS;
	if(SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine,
		                     (BOOL)TRUE)) {
		XSRETURN_YES;
	} else {
		XSRETURN_NO;
	}
}
*/


XS(boot_Win32__Console) {
    dXSARGS;
    char* file = __FILE__;

    newXS("Win32::Console::constant", XS_Win32__Console_constant, file);

    newXS("Win32::Console::_GetStdHandle", XS_Win32__Console_GetStdHandle, file);
    newXS("Win32::Console::_SetStdHandle", XS_Win32__Console_SetStdHandle, file);
    newXS("Win32::Console::_CloseHandle", XS_Win32__Console_CloseHandle, file);

	// newXS("Win32::Console::_AllocConsole", XS_Win32__Console_AllocConsole, file);
	// newXS("Win32::Console::_FreeConsole", XS_Win32__Console_FreeConsole, file);	
	newXS("Win32::Console::Alloc", XS_Win32__Console_AllocConsole, file);
	newXS("Win32::Console::Free", XS_Win32__Console_FreeConsole, file);

    newXS("Win32::Console::_WriteConsole", XS_Win32__Console_WriteConsole, file);
    newXS("Win32::Console::_WriteConsoleOutput", XS_Win32__Console_WriteConsoleOutput, file);
    newXS("Win32::Console::_WriteConsoleOutputCharacter", XS_Win32__Console_WriteConsoleOutputCharacter, file);
    newXS("Win32::Console::_WriteConsoleOutputAttribute", XS_Win32__Console_WriteConsoleOutputAttribute, file);

    newXS("Win32::Console::_FillConsoleOutputAttribute", XS_Win32__Console_FillConsoleOutputAttribute, file);
    newXS("Win32::Console::_FillConsoleOutputCharacter", XS_Win32__Console_FillConsoleOutputCharacter, file);

	newXS("Win32::Console::_ReadConsole", XS_Win32__Console_ReadConsole, file);
	newXS("Win32::Console::_ReadConsoleInput", XS_Win32__Console_ReadConsoleInput, file);
	newXS("Win32::Console::_PeekConsoleInput", XS_Win32__Console_PeekConsoleInput, file);
	newXS("Win32::Console::_WriteConsoleInput", XS_Win32__Console_WriteConsoleInput, file);
    newXS("Win32::Console::_ReadConsoleOutput", XS_Win32__Console_ReadConsoleOutput, file);
    newXS("Win32::Console::_ReadConsoleOutputCharacter", XS_Win32__Console_ReadConsoleOutputCharacter, file);
    newXS("Win32::Console::_ReadConsoleOutputAttribute", XS_Win32__Console_ReadConsoleOutputAttribute, file);

    newXS("Win32::Console::_SetConsoleCursorPosition", XS_Win32__Console_SetConsoleCursorPosition, file);
    newXS("Win32::Console::_SetConsoleTextAttribute", XS_Win32__Console_SetConsoleTextAttribute, file);
    newXS("Win32::Console::_GetConsoleScreenBufferInfo", XS_Win32__Console_GetConsoleScreenBufferInfo, file);
    newXS("Win32::Console::_SetConsoleScreenBufferSize", XS_Win32__Console_SetConsoleScreenBufferSize, file);
    newXS("Win32::Console::_GetConsoleCursorInfo", XS_Win32__Console_GetConsoleCursorInfo, file);
    newXS("Win32::Console::_SetConsoleCursorInfo", XS_Win32__Console_SetConsoleCursorInfo, file);
	newXS("Win32::Console::_ScrollConsoleScreenBuffer", XS_Win32__Console_ScrollConsoleScreenBuffer, file);
    newXS("Win32::Console::_CreateConsoleScreenBuffer", XS_Win32__Console_CreateConsoleScreenBuffer, file);
    newXS("Win32::Console::_SetConsoleActiveScreenBuffer", XS_Win32__Console_SetConsoleActiveScreenBuffer, file);
    newXS("Win32::Console::_SetConsoleWindowInfo", XS_Win32__Console_SetConsoleWindowInfo, file);
    newXS("Win32::Console::_GetConsoleTitle", XS_Win32__Console_GetConsoleTitle, file);
    newXS("Win32::Console::_SetConsoleTitle", XS_Win32__Console_SetConsoleTitle, file);
    newXS("Win32::Console::_GetConsoleMode", XS_Win32__Console_GetConsoleMode, file);
    newXS("Win32::Console::_SetConsoleMode", XS_Win32__Console_SetConsoleMode, file);
	// newXS("Win32::Console::_GetNumberOfConsoleMouseButtons", XS_Win32__Console_GetNumberOfConsoleMouseButtons, file);
	newXS("Win32::Console::MouseButtons", XS_Win32__Console_GetNumberOfConsoleMouseButtons, file);
	newXS("Win32::Console::_GetLargestConsoleWindowSize", XS_Win32__Console_GetLargestConsoleWindowSize, file);
	newXS("Win32::Console::_GetConsoleCP", XS_Win32__Console_GetConsoleCP, file);
	newXS("Win32::Console::_GetConsoleOutputCP", XS_Win32__Console_GetConsoleOutputCP, file);
	newXS("Win32::Console::_SetConsoleCP", XS_Win32__Console_SetConsoleCP, file);
	newXS("Win32::Console::_SetConsoleOutputCP", XS_Win32__Console_SetConsoleOutputCP, file);

	newXS("Win32::Console::_GenerateConsoleCtrlEvent", XS_Win32__Console_GenerateConsoleCtrlEvent, file);
	// newXS("Win32::SetConsoleCtrlHandler", XS_Win32__Console_SetConsoleCtrlHandler, file);

	newXS("Win32::Console::_GetNumberOfConsoleInputEvents", XS_Win32__Console_GetNumberOfConsoleInputEvents, file);
	newXS("Win32::Console::_FlushConsoleInputBuffer", XS_Win32__Console_FlushConsoleInputBuffer, file);	

	myPerl = pPerl;

	ST(0) = &sv_yes;
    XSRETURN(1);
}
