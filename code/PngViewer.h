// PngViewer.h : Haupt-Header-Datei f�r die Anwendung PNGVIEWER
//

#if !defined(AFX_PNGVIEWER_H__78756B6F_C5ED_4EBD_8215_FBBF749F0A90__INCLUDED_)
#define AFX_PNGVIEWER_H__78756B6F_C5ED_4EBD_8215_FBBF749F0A90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole

/////////////////////////////////////////////////////////////////////////////
// CPngViewerApp:
// Siehe PngViewer.cpp f�r die Implementierung dieser Klasse
//

class CPngViewerApp : public CWinApp
{
public:
	CPngViewerApp();

// �berladungen
	// Vom Klassenassistenten generierte �berladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CPngViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementierung

	//{{AFX_MSG(CPngViewerApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ f�gt unmittelbar vor der vorhergehenden Zeile zus�tzliche Deklarationen ein.

#endif // !defined(AFX_PNGVIEWER_H__78756B6F_C5ED_4EBD_8215_FBBF749F0A90__INCLUDED_)
