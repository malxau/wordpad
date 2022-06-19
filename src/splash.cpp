// splash.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "wordpad.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplashWnd dialog

BOOL CSplashWnd::Create(CWnd* pParent)
{
	//{{AFX_DATA_INIT(CSplashWnd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	if (!CDialog::Create(CSplashWnd::IDD, pParent))
	{
		TRACE0("Warning: creation of CSplashWnd dialog failed\n");
		return FALSE;
	}

	return TRUE;
}

BOOL CSplashWnd::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();

	// initialize the big icon control
	m_icon.SubclassDlgItem(IDC_BIGICON, this);
	m_icon.SizeToContent();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

