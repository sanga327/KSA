#pragma once


// CArrangeDlg 대화 상자

class CArrangeDlg : public CDialog
{
	DECLARE_DYNAMIC(CArrangeDlg)

public:
	CArrangeDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CArrangeDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();

	int Height;
	int Width;
	unsigned char ** m_tempImage;
};
