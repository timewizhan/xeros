
// XerosDlg.h : header file
//

#pragma once

#include <vector>
#include <string>

#include "Common\Common.h"
#include "MainOperation\Operation.h"
#include "Browser\Browser.h"

// CXerosDlg dialog
class CXerosDlg : public CDialog
{
	BOOL bTrayActive;
	BOOL bDialogShow;

	BOOL m_bStartState;
	BOOL m_bServiceStart;
	BOOL m_bGetURLs;

	/*
		Main Operation
	*/
	COperation *m_pOperation;
	CBrowser	*m_pBrowser;

// Construction
public:
	CXerosDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_XEROSAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnMessageFromTrayIcon(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedHistory();
	afx_msg void OnBnClickedUrls();
	afx_msg void OnBnClickedConfiguration();
	afx_msg void OnBnClickedAbout();
	afx_msg void OnEnChangeDlgText();
	afx_msg void OnXerosXerosopen();
	afx_msg void OnXerosUrls();
	afx_msg void OnXerosStart();
	afx_msg void OnXerosAbout();
	afx_msg void OnXerosConfiguration();
	afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnXerosClose();
	afx_msg void OnUpdateXerosStart(CCmdUI *pCmdUI);
};
