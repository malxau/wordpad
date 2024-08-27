// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _UNICODE
#define VC_EXTRALEAN        // use stripped down Win32 headers
#endif

#ifdef _MSC_VER
#if _MSC_VER >= 1700
#define WINVER 0x601
#elif _MSC_VER >= 1600
#define WINVER 0x501
#elif _MSC_VER >= 1500
#define WINVER 0x500
#else
#define WINVER 0x400
#endif

#if _MSC_VER >= 1600
#pragma warning(disable: 4996) // Function declared deprecated
#endif
#endif

#define CONVERTERS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxcmn.h>
#include <afxrich.h>
#include <afxpriv.h>

#define HORZ_TEXTOFFSET 15
#define VERT_TEXTOFFSET 5

class CDisplayIC : public CDC
{
public:
	CDisplayIC() { CreateIC(_T("DISPLAY"), NULL, NULL, NULL); }
};

struct CCharFormat : public CHARFORMAT2
{
	CCharFormat() {cbSize = sizeof(CHARFORMAT2);}
	BOOL operator==(CCharFormat& cf);
};

struct CParaFormat : public PARAFORMAT2
{
	CParaFormat() {cbSize = sizeof(_paraformat);}
	BOOL operator==(PARAFORMAT2& pf);
};

#include "doctype.h"
#include "chicdial.h"
