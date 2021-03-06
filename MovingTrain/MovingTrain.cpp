
#include "stdafx.h"
#include "Program.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProgramDlg dialog



CProgramDlg::CProgramDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PROGRAM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	fg = true;

	SetWindowTextW(L"Program");

	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CProgramDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()

BOOL CProgramDlg::OnInitDialog()
{
	CDialog::OnInitDialog();


	SetIcon(m_hIcon, TRUE);		
	SetIcon(m_hIcon, FALSE);		



	return TRUE;  
}



void CProgramDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CClientDC dc(this);
		GetClientRect(&rc);

		dc.FillSolidRect(&rc, RGB(255, 255, 255));

		RH = abs(rc.left - rc.right);
		RW = abs(rc.top - rc.bottom);

		cx = RH / 2;
		cy = RW / 2;

		dx = cx / 8;
		dy = cy / 6;

		x1 = w.left = cx;
		y1 = w.top = cy - 4 * dy;
		
		for (x1 = x1 + 400; x1 >= -500; x1 -= 50)
		{
			Sleep(mtime - 150);
			dc.FillSolidRect(&rc, RGB(255, 255, 255));

			Corpus(x1, y1, dx, dy);
			Road(x1, y1, dx, dy);
		}
			
		CDialog::OnPaint();
	}
}


HCURSOR CProgramDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//train

void CProgramDlg::Corpus(int X1, int Y1, int DX, int DY)
{
	CClientDC dc(this);
	GetClientRect(&rc);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	dc.MoveTo(x1 + dx, y1);
	dc.LineTo(x1 + dx * 7, y1);
	dc.LineTo(x1 + dx * 7, y1 + dy);
	dc.LineTo(x1 + dx * 6, y1 + dy);
	dc.LineTo(x1 + dx * 6, y1 + dy * 6);
	dc.LineTo(x1 - dx * 6, y1 + dy * 6);
	dc.LineTo(x1 - dx * 6, y1 + dy * 5);
	dc.LineTo(x1 - dx * 5, y1 + dy * 5);
	dc.LineTo(x1 - dx * 5, y1 + dy * 2);
	dc.LineTo(x1 - dx * 4, y1 + dy * 2);
	dc.LineTo(x1 - dx * 4, y1 - dy);
	dc.LineTo(x1 - dx * 3, y1 - dy);
	dc.LineTo(x1 - dx * 3, y1 + dy * 2);
	dc.LineTo(x1 + dx, y1 + dy * 2);
	dc.LineTo(x1 + dx, y1);

	dc.MoveTo(x1 + dx * 2, y1 + dy);
	dc.LineTo(x1 + dx * 4, y1 + dy);
	dc.LineTo(x1 + dx * 4, y1 + dy * 3);
	dc.LineTo(x1 + dx * 2, y1 + dy * 3);
	dc.LineTo(x1 + dx * 2, y1 + dy);



}

// wheel
void CProgramDlg::Road(int X1, int Y1, int DX, int DY)
{
	CClientDC dc(this);
	GetClientRect(&rc);

	cf = RGB(0, 0, 0);
	hPenOxy = CreatePen(PS_SOLID, 3, cf);
	hOldPen = (HPEN)SelectObject(dc, hPenOxy);

	int r1 = DX * 0.9;
	int x = X1 + DX * 3;
	int y = Y1 + DY * 6.2;
	dc.Ellipse(x - r1, y - r1, x + r1, y + r1);

	x = X1;
	y = Y1 + DY * 6.2;
	dc.Ellipse(x - r1, y - r1, x + r1, y + r1);

	x = X1 - DX * 3;
	y = Y1 + DY * 6.2;
	dc.Ellipse(x - r1, y - r1, x + r1, y + r1);

	SelectObject(dc, hOldPen);
	DeleteObject(hPenOxy);

}
