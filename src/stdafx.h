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

#define _CRT_NON_CONFORMING_SWPRINTFS 1
#define _CRT_SECURE_NO_WARNINGS 1

#define _UNICODE 1
#define UNICODE 1

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

#if !defined(_WIN64) && defined(_MSC_VER) && _MSC_VER < 1300
typedef INT WP_INT_PTR;
typedef LONG LONG_PTR;
typedef DWORD DWORD_PTR;
#else
typedef INT_PTR WP_INT_PTR;
#endif

#if _MFC_VER >= 0x700
typedef CHARFORMAT2 WP_CHARFORMAT;
typedef PARAFORMAT2 WP_PARAFORMAT;
typedef ULONGLONG WP_FILE_SIZE;
#else
typedef CHARFORMAT WP_CHARFORMAT;
typedef PARAFORMAT WP_PARAFORMAT;
typedef DWORD WP_FILE_SIZE;
#endif

#ifndef ENSURE
#define ENSURE(x) if (!(x)) ::AfxThrowMemoryException()
#endif

class CDisplayIC : public CDC
{
public:
	CDisplayIC() { CreateIC(_T("DISPLAY"), NULL, NULL, NULL); }
};

struct CCharFormat : public WP_CHARFORMAT
{
	CCharFormat() {cbSize = sizeof(WP_CHARFORMAT);}
	BOOL operator==(CCharFormat& cf);
};

struct CParaFormat : public WP_PARAFORMAT
{
	CParaFormat() {cbSize = sizeof(_paraformat);}
	BOOL operator==(WP_PARAFORMAT& pf);
};

#include "doctype.h"
#include "chicdial.h"
