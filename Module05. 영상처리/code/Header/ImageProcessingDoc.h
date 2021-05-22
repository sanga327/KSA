﻿
// ImageProcessingDoc.h: CImageProcessingDoc 클래스의 인터페이스
//


#pragma once


class CImageProcessingDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CImageProcessingDoc() noexcept;
	DECLARE_DYNCREATE(CImageProcessingDoc)

// 특성입니다.
public:

// 작업입니다.
public:

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
	virtual ~CImageProcessingDoc();
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
	unsigned char* m_InputImage;
	int m_width;
	int m_height;
	int m_size;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	void OnDownSampling();
	unsigned char* m_OutputImage;
	int m_Re_width;
	int m_Re_height;
	int m_Re_size;

	double m_HIST[256];
	double m_Sum_Of_HIST[256];
	unsigned char m_Scale_HIST[256];


	void OnUpSampling();
	void OnQuantization();
	void OnSumConstant();
	void OnSubConstant();
	void OnMulConstant();
	void OnDivConstant();
	void OnAndOperate();
	void OnOrOperate(); // afx_msg 
	void OnXorOperate();
	void OnNegaTransform();
	void OnGammaCorrection();
	void OnBinarization();
	void OnStressTransform();
	void OnHistoStretch();
	void OnEndInSearch();
	void OnHistogram();
	void OnHistoEqual();
	void OnHistoSpec();
	void OnEmbossing();
	double** OnMaskProcess(unsigned char *Target, double Mask[3][3]);
	double** OnScale(double **Target, int height, int width);
	double** Image2DMem(int height, int width);
	double** m_tempImage;

	void OnBlurr();
	void OnGaussianFilter();
	void OnSharpening();
	void OnHpfSharp();
	void OnLpfSharp();
	void OnDiffOperatorHor();
	void OnHomogenOperator();
	double DoubleABS(double X);
	void OnLaplacian();
	
	void OnBilinear();
	void OnNearest();
	void OnMeanSub();
	void OnMedianSub();
	void OnBubleSort(double * A, int MAX);
	void OnSwap(double * a, double * b);
	void OnTranslation();
	void OnMirrorHor();
	void OnMirrorVer();
	void OnRotation();
	void OnFrameSum();
	void OnFrameSub();
	void OnFrameMul();
	void OnFrameDiv();
	void OnFrameAnd();
	void OnFrameOr();
	void OnFrameComb();
	void OnBinaryErosion();
	void OnBinaryDilation();
	void OnGrayErosion();
	void OnGrayDilation();

	void OnLowPassFilter();
	void OnHighPassFilter();
	void OnMeanFilter();
	void OnMedianFilter();
	void OnMaxFilter();
	void OnMinFilter();

	void OnFft2d();
	void OnIfft2d();
	void OnLpfFrequency();
	void OnHpfFrequency();


	// onfft2d에서 사용하는 complex 구조체 선언
	struct Complex {
		double Re; // 실수를 위한 변수
		double Im; // 허수를 위한 변수
	};
	Complex **m_FFT;
	Complex **m_IFFT;

	void OnFft1d(Complex * X, int N, int Log2N);
	void OnShuffle(Complex * X, int N, int Log2N);
	void OnButterfly(Complex * X, int N, int Log2N, int mode);
	int OnReverseBitOrder(int index, int Log2N);
	void OnIfft1d(Complex * X, int N, int Log2N);
};
