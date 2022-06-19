// bigicon.h : header file
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
// CBigIcon window

class CBigIcon : public CButton
{
// Attributes
public:
	CBitmap m_bitmap;
	CSize m_sizeBitmap;

// Operations
public:
	void SizeToContent();

// Implementation
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

	//{{AFX_MSG(CBigIcon)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

