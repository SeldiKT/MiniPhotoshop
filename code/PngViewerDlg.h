// --------------
// PngViewerDlg.h
// --------------
/**
* @file
* @brief Re: CPngViewerDlg
* @author Achim Klein
* @version 0.2
*/


// -------------------
// One-Definition-Rule
// -------------------
#ifndef PNGVIEWERDLG_H_INCLUDE_NR1
#define PNGVIEWERDLG_H_INCLUDE_NR1


// -------
// Pragmas
// -------
#if _MSC_VER > 1000
#pragma once
#endif


// -------------------------------------
// Definition of the CPngViewerDlg class
// -------------------------------------
/**
 * The application's main window.
 */
class CPngViewerDlg : public CDialog
{

public:

	// ------------
	// Construction
	// ------------

	/// standrd-constructor
	CPngViewerDlg(CWnd* pParent = NULL);

	/// virtual destructor
	virtual ~CPngViewerDlg();


	// -----------
	// Dialog Data
	// -----------
	//{{AFX_DATA(CPngViewerDlg)
	enum { IDD = IDD_PNGVIEWER_DIALOG };
	//}}AFX_DATA


	// --------------------------
	// Overloaded virtual methods
	// --------------------------
	//{{AFX_VIRTUAL(CPngViewerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_VIRTUAL


protected:

	// ----------------
	// Internal methods
	// ----------------

	/// creates a new bitmap
	CBitmap* doCreateCompatibleBitmap(int Width, int Height, unsigned char* BGRA, CWnd* pCompatibleWindow) const;

	/// draws the passed bitmap into the specified window
	void doDrawBitmap(CBitmap* pBitmap, CWnd* pWindow, CPoint Offset = CPoint(0, 0)) const;

	/// returns TRUE if the bitmap fits into the window's client rect or into the MaxSize rect
	BOOL doCheckZoom(CBitmap* pBitmap, CWnd* pWindow, CSize MaxSize = CSize(0, 0)) const;

	/// returns a new bitmap that fits proportionally into the client rect of the passed window or into the MaxSize rect
	CBitmap* doZoomBitmap(CBitmap* pBitmap, CWnd* pCompatibleWindow, CSize MaxSize = CSize(0, 0)) const;

	/// invalidates the area that is not covered by the bitmap
	void doInvalidateBackground(CBitmap* pBitmap, CWnd* pWindow) const;


	// ---------------------
	// Message map functions
	// ---------------------
	//{{AFX_MSG(CPngViewerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFileOpen();
	afx_msg void OnFileExit();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()


private:

	// ----------
	// Attributes
	// ----------

	/// the application's icon
	HICON m_hIcon;

	/// the the converted png
	CBitmap* m_bitmap;

	/// the visible (zoomed) bitmap
	CBitmap* m_visible;


	/// the bitmap's position in the client area
	CRect m_bmpRect;
};


//{{AFX_INSERT_LOCATION}}

#endif	// #ifndef PNGVIEWERDLG_H_INCLUDE_NR1
