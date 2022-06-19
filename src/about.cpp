// about.cpp : implementation file
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
// CAboutDialog dialog

CAboutDialog::CAboutDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAboutDialog)
	//}}AFX_DATA_INIT
}

BOOL CAboutDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();

	// initialize the big icon control
	m_icon.SubclassDlgItem(IDC_BIGICON, this);
	m_icon.SizeToContent();

	HINSTANCE hInst = AfxGetInstanceHandle();

	HRSRC hRsrc = ::FindResource(hInst, MAKEINTRESOURCE(IDR_LICENSE_TEXT), RT_RCDATA);
	if (hRsrc == NULL)
		return FALSE;

	HGLOBAL hLoadedRsrc = ::LoadResource(hInst, hRsrc);
	if (hLoadedRsrc == NULL)
		return FALSE;

	DWORD ResourceSize = ::SizeofResource(hInst, hRsrc);

	LPCSTR LicenseTextPtr = (LPCSTR)::LockResource(hLoadedRsrc);

	if (LicenseTextPtr == NULL)
		return FALSE;

	CString LicenseText(LicenseTextPtr, ResourceSize);

	CEdit* pEditBox = (CEdit*)GetDlgItem(IDC_LICENSE_TEXT);
	pEditBox->SetWindowText(LicenseText);

	return FALSE;  // return TRUE  unless you set the focus to a control
}

