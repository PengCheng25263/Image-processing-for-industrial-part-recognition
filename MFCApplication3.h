
// MFCApplication3.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApplication3App:
// See MFCApplication3.cpp for the implementation of this class
//

class CMFCApplication3App : public CWinApp
{
public:
	CMFCApplication3App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication3App theApp;