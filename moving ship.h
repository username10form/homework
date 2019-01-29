
#pragma once
#define mtime 298
#define PI 3.1415926535897932384626433832795

class CMFCApplication3Dlg : public CDialog
{

public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// standard constructor
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROGRAM_DIALOG };
#endif
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	afx_msg void CorpusShip(int X1, int Y1, int X2, int Y2, int DX, int DY);
	afx_msg void ElluminateShip(int X1, int Y1, int DX, int DY);
	afx_msg void Ship(int X1, int Y1, int X2, int Y2, int DX, int DY);

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
private:

	COLORREF cf, c[25];
	HFONT hold, hNew, hbk;
	HPEN hPenOxy, hOldPen, pen;
	HBRUSH m, oldm, brush;
	CPen d, oldd;
	CBitmap pic;
	CRect rc, w, kw[30];

	CString ms, t, z;

	int Matrix[50][50];
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int RH, RW, k, i, j, p, x, y, cx, cy, dx, dy;
	bool fg;
	DECLARE_MESSAGE_MAP()
};