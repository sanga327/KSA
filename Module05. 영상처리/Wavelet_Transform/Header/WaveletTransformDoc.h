﻿
// WaveletTransformDoc.h: CWaveletTransformDoc 클래스의 인터페이스
//


#pragma once


#if !defined(AFX_WAVELETTRANSFORMDOC_H__4A38BAEB_E3CB_44C9_B2CB_057CD4D9FF0A__INCLUDED_)
#define AFX_WAVELETTRANSFORMDOC_H__4A38BAEB_E3CB_44C9_B2CB_057CD4D9FF0A__INCLUDED_
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CWaveletTransformDlg.h"  // 대화상자 헤더 선언


class CWaveletTransformDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CWaveletTransformDoc(); // noexcept;
	DECLARE_DYNCREATE(CWaveletTransformDoc)

// 특성입니다.
public:

// 작업입니다.
public:
	CWaveletTransformDlg *pDlg;

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CWaveletTransformDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	unsigned char *m_InputImage;  // 입력 영상 버퍼
	unsigned char *m_OutputImage;  // 출력 영상 버퍼
	unsigned char **m_ArrangeImage;  // 변환 정렬 영상 버퍼
	int m_Height;  // 영상의 세로축 크기
	int m_Width;  // 영상의 가로축 크기
	int m_Size;  //영상의 전체 크기
	void OnWaveletTransform();
	void OnWaveletEncode();
	double **m_tempInput;
	double **m_tempOutput;
	int m_Level;
	int m_FilterTap;
	double *m_FilterH0;
	double *m_FilterH1;
	double *m_FilterG0;
	double *m_FilterG1;
	
	void OnFilterTapGen(); // 필터 탭 생성 함수
	void OnFilterGen(double * m_H0, double * m_H1, double * m_G0, double * m_G1);  // 필터 생성 함수
	double * OnDownSampling(double * m_Target, int size);  // 다운 샘플링 함수
	double * OnConvolution(double * m_Target, double * m_Filter, int size, int mode);  // 1차원 컨벌루션 함수
	unsigned char ** OnMem2DAllocUnsigned(int height, int width);  // 2차원 메모리 할당
	double ** OnMem2DAllocDouble(int height, int width);  // 2차원 메모리 할당
	double ** OnScale(double ** m_Target, int height, int width);  // 정규화 함수
	
	unsigned char **m_tempImage;  // 입력 영상 버퍼						 
	int Height; // 영상의 세로축 크기
	int Width; // 영상의 가로축 크기
	void OnWaveletDecode();
	// 업 샘플링 함수
	double * OnUpSampling(double * m_Target, int size);
	// 신호 대 잡음비
	void OnSNR();

	double * m_Recon;
};



