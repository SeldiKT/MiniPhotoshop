// ----------------
// PngViewerDlg.cpp
// ----------------
/**
* @file
* @brief Re: CAboutDlg, CPngViewerDlg
* @author Achim Klein
* @version 0.6
*/


// --------
// Includes
// --------
#include "stdafx.h"
#include "PngViewer.h"
#include "PngViewerDlg.h"
#include "PngImage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// ---------------------------------
// Definition of the CAboutDlg class
// ---------------------------------
/**
 * 
 */
class CAboutDlg : public CDialog
{

public:

	CAboutDlg();

	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL


protected:

	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};


// ---------
// CAboutDlg
// ---------
/**
 * 
 */
CAboutDlg::CAboutDlg()
: CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}


// --------------
// DoDataExchange
// --------------
/**
 * 
 */
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}


// -----------------
// BEGIN_MESSAGE_MAP
// -----------------
/**
 * 
 */
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



// -------------
// CPngViewerDlg
// -------------
/**
 * The standard-constructor.
 */
CPngViewerDlg::CPngViewerDlg(CWnd* pParent)
: CDialog(CPngViewerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPngViewerDlg)
	//}}AFX_DATA_INIT

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bitmap = 0;
	m_visible = 0;
}


// --------------
// ~CPngViewerDlg
// --------------
/**
 * The destructor frees the allocated memory.
 */
CPngViewerDlg::~CPngViewerDlg()
{
	if (m_bitmap) delete m_bitmap;
	if (m_visible) delete m_visible;
}


// --------------
// DoDataExchange
// --------------
/**
 * 
 */
void CPngViewerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	//{{AFX_DATA_MAP(CPngViewerDlg)
	//}}AFX_DATA_MAP
}


// -----------------
// BEGIN_MESSAGE_MAP
// -----------------
/**
 * 
 */
BEGIN_MESSAGE_MAP(CPngViewerDlg, CDialog)
	//{{AFX_MSG_MAP(CPngViewerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_SIZE()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// ------------
// OnInitDialog
// ------------
/**
 * 
 */
BOOL CPngViewerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);

	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);

		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	return TRUE;
}


// ------------
// OnSysCommand
// ------------
/**
 * 
 */
void CPngViewerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}

	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}


// -------
// OnPaint
// -------
/**
 * 
 */
void CPngViewerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		CRect rect;
		GetClientRect(&rect);

		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}

	else
	{
		CDialog::OnPaint();

		// check pointer
		if (m_visible)
		{
			doDrawBitmap(m_visible, this);
		}
	}
}


// ------
// OnSize
// ------
/**
 * 
 */
void CPngViewerDlg::OnSize(UINT nType, int cx, int cy) 
{
	// check pointer
	if (m_bitmap && m_visible)
	{
		// check size
		if (doCheckZoom(m_visible, this))
		{
			doInvalidateBackground(m_visible, this);

			delete m_visible;

			m_visible = doZoomBitmap(m_bitmap, this);
		}
	}
}


// ---------------
// OnQueryDragIcon
// ---------------
/**
 * 
 */
HCURSOR CPngViewerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


// ----
// OnOK
// ----
/**
 * Called when ENTER is pressed.
 */
void CPngViewerDlg::OnOK()
{
	// nothing
}


// --------
// OnCancel
// --------
/**
 * Called when ESC is pressed.
 */
void CPngViewerDlg::OnCancel()
{
	// redirect
	OnFileExit();
}


// ----------
// OnFileOpen
// ----------
/**
 * 
 */
void CPngViewerDlg::OnFileOpen() 
{
	CFileDialog dlg(TRUE, "png", 0, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, "Portable Network Graphics (.png)|*.png||");

	if (dlg.DoModal() == IDCANCEL) return;

	PngImage png;

	if ( png.load(dlg.GetPathName()) )
	{
		// get size
		int width  = png.getWidth();
		int height = png.getHeight();

		// get blue, green, red and alpha
		unsigned char* data = png.getBGRA();

		// free memory first
		if (m_bitmap) delete m_bitmap;
		if (m_visible) delete m_visible;

		// create a CBitmap to display
		m_bitmap = doCreateCompatibleBitmap(width, height, data, this);

		// used to speed up OnPaint()
		m_visible = doZoomBitmap(m_bitmap, this);

		// request graphical update
		Invalidate();
		UpdateWindow();
	}
}


// ----------
// OnFileExit
// ----------
/**
 * 
 */
void CPngViewerDlg::OnFileExit() 
{
	CDialog::OnCancel();
}


// ------------------------
// doCreateCompatibleBitmap
// ------------------------
/**
 * Creates a new bitmap.
 */
CBitmap* CPngViewerDlg::doCreateCompatibleBitmap(int Width, int Height, unsigned char* BGRA, CWnd* pCompatibleWindow) const
{
	// RGB + Alpha
	int size = Width * Height * 4;

	// create bitmap
	CBitmap* bmp = new CBitmap;

	// get device context
	CDC* pDC = pCompatibleWindow->GetDC();

	// initialize
	bmp->CreateCompatibleBitmap(pDC, Width, Height);

	// set pixels
	bmp->SetBitmapBits(size, BGRA);

	// release device context
	pCompatibleWindow->ReleaseDC(pDC);

	// return object
	return bmp;
}


// ------------
// doDrawBitmap
// ------------
/**
 * Draws the passed bitmap into the specified window.
 */
void CPngViewerDlg::doDrawBitmap(CBitmap* pBitmap, CWnd* pWindow, CPoint Offset) const
{
	// get bitmap information
	BITMAP bmpInfo;
	pBitmap->GetObject(sizeof(bmpInfo), &bmpInfo);

	// get size
	CSize size;
	size.cx = bmpInfo.bmWidth;
	size.cy = bmpInfo.bmHeight;

	// get window's client device context
	CClientDC* pDC = new CClientDC(pWindow);

	// create memory device context
	CDC* memDC = new CDC; memDC->CreateCompatibleDC(pDC);

	// buffer bitmap
	CBitmap* old = memDC->SelectObject(pBitmap);

	// copy bitmap bits
	pDC->BitBlt
	(
		Offset.x,		// specifies the x-coordinate (in logical units) of the upper-left corner of the destination rectangle
		Offset.y,		// specifies the y-coordinate (in logical units) of the upper-left corner of the destination rectangle
		size.cx,		// specifies the width (in logical units) of the destination rectangle
		size.cy,		// specifies the height (in logical units) of the destination rectangle
		memDC,			// specifies the source device context
		0,				// specifies the x-coordinate (in logical units) of the upper-left corner of the source rectangle
		0,				// specifies the x-coordinate (in logical units) of the upper-left corner of the source rectangle
		SRCCOPY			// specifies the raster operation to be performed
	);

	// reselect first bitmap
	memDC->SelectObject(old);

	// delete device context and reset pointer
	delete memDC; memDC = 0;

	// delete device context and reset pointer
	delete pDC; pDC = 0;
}


// -----------
// doCheckZoom
// -----------
/**
 * Returns TRUE if the bitmap fits into the window's client rect or into the MaxSize rect.
 */
BOOL CPngViewerDlg::doCheckZoom(CBitmap* pBitmap, CWnd* pWindow, CSize MaxSize) const
{
	// get bitmap information
	BITMAP bmpInfo;
	pBitmap->GetObject(sizeof(bmpInfo), &bmpInfo);

	// get bitmap size
	CSize bmpSize;
	bmpSize.cx = bmpInfo.bmWidth;
	bmpSize.cy = bmpInfo.bmHeight;

	// get client rect
	CRect clientRect;
	pWindow->GetClientRect(&clientRect);

	// check max size
	if (MaxSize == CSize(0, 0))
	{
		// use client area
		MaxSize.cx = clientRect.Width();
		MaxSize.cy = clientRect.Height();
	}

	else
	{
		// use client area
		if (MaxSize.cx > clientRect.Width()) MaxSize.cx = clientRect.Width();
		if (MaxSize.cy > clientRect.Height()) MaxSize.cy = clientRect.Height();
	}

	// too narrow
	if (MaxSize.cx < bmpSize.cx) return TRUE;

	// too low
	if (MaxSize.cy < bmpSize.cy) return TRUE;

	// scale up bitmap
	if ((MaxSize.cx > bmpSize.cx) && (MaxSize.cy > bmpSize.cy)) return TRUE;

	// it fits
	return FALSE;
}


// ------------
// doZoomBitmap
// ------------
/**
 * Returns a new bitmap that fits proportionally into the client rect of the passed window or into the MaxSize rect.
 */
CBitmap* CPngViewerDlg::doZoomBitmap(CBitmap* pBitmap, CWnd* pCompatibleWindow, CSize MaxSize) const
{
	// get bitmap information
	BITMAP bmpInfo;
	pBitmap->GetObject(sizeof(bmpInfo), &bmpInfo);

	// get source size
	CSize srcSize;
	srcSize.cx = bmpInfo.bmWidth;
	srcSize.cy = bmpInfo.bmHeight;

	// get client rect
	CRect clientRect;
	pCompatibleWindow->GetClientRect(&clientRect);

	// check max size
	if (MaxSize == CSize(0, 0))
	{
		// use client area
		MaxSize.cx = clientRect.Width();
		MaxSize.cy = clientRect.Height();
	}

	else
	{
		// use client area
		if (MaxSize.cx > clientRect.Width()) MaxSize.cx = clientRect.Width();
		if (MaxSize.cy > clientRect.Height()) MaxSize.cy = clientRect.Height();
	}

	// calculate zoom factors
	double xfac = MaxSize.cx / static_cast<double>(srcSize.cx);
	double yfac = MaxSize.cy / static_cast<double>(srcSize.cy);

	// use smaller factor
	double zfac = (xfac < yfac) ? (xfac) : (yfac);

	// get destination size
	CSize dstSize;
	dstSize.cx = static_cast<int>(zfac * srcSize.cx + 0.5);	// round = add 0.5 first and cut off
	dstSize.cy = static_cast<int>(zfac * srcSize.cy + 0.5);	// round = add 0.5 first and cut off

	CDC* pDC = pCompatibleWindow->GetDC();

	// create memory device contexts
	CDC* memDC1 = new CDC; memDC1->CreateCompatibleDC(pDC);
	CDC* memDC2 = new CDC; memDC2->CreateCompatibleDC(pDC);

	// create zoomed bitmap
	CBitmap* zoomed = new CBitmap; zoomed->CreateCompatibleBitmap(pDC, dstSize.cx, dstSize.cy);

	// not needed anymore
	pCompatibleWindow->ReleaseDC(pDC);

	// select bitmaps
	CBitmap* old1 = memDC1->SelectObject(pBitmap);
	CBitmap* old2 = memDC2->SelectObject(zoomed);

	// stretch bitmap
	memDC2->SetStretchBltMode(HALFTONE);
	memDC2->StretchBlt
	(
		0,				// specifies the x-coordinate (in logical units) of the upper-left corner of the destination rectangle
		0,				// specifies the y-coordinate (in logical units) of the upper-left corner of the destination rectangle
		dstSize.cx,		// specifies the width (in logical units) of the destination rectangle
		dstSize.cy,		// specifies the height (in logical units) of the destination rectangle
		memDC1,			// specifies the source device context
		0,				// specifies the x-coordinate (in logical units) of the upper-left corner of the source rectangle
		0,				// specifies the x-coordinate (in logical units) of the upper-left corner of the source rectangle
		srcSize.cx,		// specifies the width (in logical units) of the source rectangle
		srcSize.cy,		// specifies the height (in logical units) of the source rectangle
		SRCCOPY			// specifies the raster operation to be performed
	);

	// reselect old bitmaps
	memDC2->SelectObject(old2);
	memDC1->SelectObject(old1);

	// delete temporary device contexts
	delete memDC2;
	delete memDC1;

	// the zoomed bitmap
	return zoomed;
}


// ----------------------
// doInvalidateBackground
// ----------------------
/**
 * Invalidates the area that is not covered by the bitmap.
 */
void CPngViewerDlg::doInvalidateBackground(CBitmap* pBitmap, CWnd* pWindow) const
{
	// get bitmap information
	BITMAP bmpInfo;
	pBitmap->GetObject(sizeof(bmpInfo), &bmpInfo);

	// get bitmap size
	CSize bmpSize;
	bmpSize.cx = bmpInfo.bmWidth;
	bmpSize.cy = bmpInfo.bmHeight;

	// get client rect
	CRect clientRect;
	pWindow->GetClientRect(&clientRect);

	// when the window was maximized and gets restored
	if ((bmpSize.cx > clientRect.Width()) && (bmpSize.cy > clientRect.Height()))
	{
		pWindow->InvalidateRect( clientRect );
	}

	else
	{
		// check right
		if (bmpSize.cx < clientRect.Width())
		{
			CRect update;
			update.top = 0;
			update.left = bmpSize.cx;
			update.right = clientRect.right;
			update.bottom = (bmpSize.cy > clientRect.bottom) ? bmpSize.cy : clientRect.bottom;

			pWindow->InvalidateRect(update);
		}

		// check bottom
		if (bmpSize.cy < clientRect.Height())
		{
			CRect update;
			update.top = bmpSize.cy;
			update.left = 0;
			update.right = (bmpSize.cx > clientRect.right) ? bmpSize.cx : clientRect.right;
			update.bottom = clientRect.bottom;

			pWindow->InvalidateRect(update);
		}
	}
}
