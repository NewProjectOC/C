// SEBankDlg.h : header file
//

#if !defined(AFX_SEBANKDLG_H__390645E1_AC45_42E5_AA8A_3A0118BA0F00__INCLUDED_)
#define AFX_SEBANKDLG_H__390645E1_AC45_42E5_AA8A_3A0118BA0F00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSEBankDlg dialog

class CSEBankDlg : public CDialog
{
// Construction
public:
	CSEBankDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSEBankDlg)
	enum { IDD = IDD_SEBANK_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSEBankDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSEBankDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEBANKDLG_H__390645E1_AC45_42E5_AA8A_3A0118BA0F00__INCLUDED_)
