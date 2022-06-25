// chicdial.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CCSDialog dialog

class CCSDialog : public CDialog
{
// Construction
public:
	CCSDialog();
	CCSDialog(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
	CCSDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCSDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CCSPropertyPage : public CPropertyPage
{
// Construction
public:
	CCSPropertyPage(UINT nIDTemplate, UINT nIDCaption = 0);
	CCSPropertyPage(LPCTSTR lpszTemplateName, UINT nIDCaption = 0);

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCSPropertyPage)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

class CCSPropertySheet : public CPropertySheet
{
// Construction
public:
	CCSPropertySheet(UINT nIDCaption, CWnd *pParentWnd = NULL,
		UINT iSelectPage = 0);
	CCSPropertySheet(LPCTSTR pszCaption, CWnd *pParentWnd = NULL,
		UINT iSelectPage = 0);
// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCSPropertySheet)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
