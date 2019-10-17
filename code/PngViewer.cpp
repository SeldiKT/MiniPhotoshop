// PngViewer.cpp : Legt das Klassenverhalten für die Anwendung fest.
//

#include "stdafx.h"
#include "PngViewer.h"
#include "PngViewerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPngViewerApp

BEGIN_MESSAGE_MAP(CPngViewerApp, CWinApp)
	//{{AFX_MSG_MAP(CPngViewerApp)
	//}}AFX_MSG
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPngViewerApp Konstruktion

CPngViewerApp::CPngViewerApp()
{
}

/////////////////////////////////////////////////////////////////////////////
// Das einzige CPngViewerApp-Objekt

CPngViewerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPngViewerApp Initialisierung

BOOL CPngViewerApp::InitInstance()
{
	// Standardinitialisierung

#ifdef _AFXDLL
	Enable3dControls();			// Diese Funktion bei Verwendung von MFC in gemeinsam genutzten DLLs aufrufen
#else
	Enable3dControlsStatic();	// Diese Funktion bei statischen MFC-Anbindungen aufrufen
#endif

	CPngViewerDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
	}
	else if (nResponse == IDCANCEL)
	{
	}

	// Da das Dialogfeld geschlossen wurde, FALSE zurückliefern, so dass wir die
	//  Anwendung verlassen, anstatt das Nachrichtensystem der Anwendung zu starten.
	return FALSE;
}
