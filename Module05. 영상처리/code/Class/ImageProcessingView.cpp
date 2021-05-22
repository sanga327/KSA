﻿
// ImageProcessingView.cpp: CImageProcessingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing.h"
#endif

#include "ImageProcessingDoc.h"
#include "ImageProcessingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessingView

IMPLEMENT_DYNCREATE(CImageProcessingView, CView)

BEGIN_MESSAGE_MAP(CImageProcessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessingView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_UP_SAMPLING, &CImageProcessingView::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CImageProcessingView::OnQuantization)
	ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessingView::OnDownSampling)
	ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessingView::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessingView::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessingView::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessingView::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessingView::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessingView::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessingView::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessingView::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessingView::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CImageProcessingView::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CImageProcessingView::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessingView::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessingView::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessingView::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CImageProcessingView::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessingView::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CImageProcessingView::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessingView::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessingView::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CImageProcessingView::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CImageProcessingView::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CImageProcessingView::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CImageProcessingView::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CImageProcessingView::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CImageProcessingView::OnLaplacian)
	ON_COMMAND(ID_BILINEAR, &CImageProcessingView::OnBilinear)
	ON_COMMAND(ID_NEAREST, &CImageProcessingView::OnNearest)
	ON_COMMAND(ID_MEAN_SUB, &CImageProcessingView::OnMeanSub)
	ON_COMMAND(ID_MEDIAN_SUB, &CImageProcessingView::OnMedianSub)
	ON_COMMAND(ID_TRANSLATION, &CImageProcessingView::OnTranslation)
	ON_COMMAND(ID_MIRROR_HOR, &CImageProcessingView::OnMirrorHor)
	ON_COMMAND(ID_MIRROR_VER, &CImageProcessingView::OnMirrorVer)
	ON_COMMAND(ID_ROTATION, &CImageProcessingView::OnRotation)
	ON_COMMAND(ID_FRAME_SUM, &CImageProcessingView::OnFrameSum)
	ON_COMMAND(ID_FRAME_SUB, &CImageProcessingView::OnFrameSub)
	ON_COMMAND(ID_FRAME_MUL, &CImageProcessingView::OnFrameMul)
	ON_COMMAND(ID_FRAME_DIV, &CImageProcessingView::OnFrameDiv)
	ON_COMMAND(ID_FRAME_AND, &CImageProcessingView::OnFrameAnd)
	ON_COMMAND(ID_FRAME_OR, &CImageProcessingView::OnFrameOr)
	ON_COMMAND(ID_FRAME_COMB, &CImageProcessingView::OnFrameComb)
	ON_COMMAND(ID_BINARY_EROSION, &CImageProcessingView::OnBinaryErosion)
	ON_COMMAND(ID_BINARY_DILATION, &CImageProcessingView::OnBinaryDilation)
	ON_COMMAND(ID_GRAY_EROSION, &CImageProcessingView::OnGrayErosion)
	ON_COMMAND(ID_GRAY_DILATION, &CImageProcessingView::OnGrayDilation)
	ON_COMMAND(ID_LOW_PASS_FILTER, &CImageProcessingView::OnLowPassFilter)
	ON_COMMAND(ID_HIGH_PASS_FILTER, &CImageProcessingView::OnHighPassFilter)
	ON_COMMAND(ID_MEAN_FILTER, &CImageProcessingView::OnMeanFilter)
	ON_COMMAND(ID_MEDIAN_FILTER, &CImageProcessingView::OnMedianFilter)
	ON_COMMAND(ID_MAX_FILTER, &CImageProcessingView::OnMaxFilter)
	ON_COMMAND(ID_MIN_FILTER, &CImageProcessingView::OnMinFilter)
	ON_COMMAND(ID_FFT_2D, &CImageProcessingView::OnFft2d)
	ON_COMMAND(ID_IFFT_2D, &CImageProcessingView::OnIfft2d)
	ON_COMMAND(ID_LPF_FREQUENCY, &CImageProcessingView::OnLpfFrequency)
	ON_COMMAND(ID_HPF_FREQUENCY, &CImageProcessingView::OnHpfFrequency)
END_MESSAGE_MAP()

// CImageProcessingView 생성/소멸

CImageProcessingView::CImageProcessingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessingView::~CImageProcessingView()
{
}

BOOL CImageProcessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessingView 그리기

void CImageProcessingView::OnDraw(CDC* pDC)
{
	CImageProcessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc);
	int i, j;
	unsigned char R, G, B;

	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = G = B = pDoc->m_InputImage[i*pDoc->m_width + j];
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}
	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i*pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}
}


// CImageProcessingView 인쇄


void CImageProcessingView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProcessingView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessingView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessingView 진단

#ifdef _DEBUG
void CImageProcessingView::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}


CImageProcessingDoc* CImageProcessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessingDoc)));
	return (CImageProcessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessingView 메시지 처리기

void CImageProcessingView::OnDownSampling()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CImageProcessingView::OnUpSampling()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CImageProcessingView::OnQuantization()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CImageProcessingView::OnSumConstant()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant();

	Invalidate(TRUE);
}



void CImageProcessingView::OnSubConstant()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMulConstant()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);

}


void CImageProcessingView::OnDivConstant()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);

}


void CImageProcessingView::OnAndOperate()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);

}


void CImageProcessingView::OnOrOperate()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);

}


void CImageProcessingView::OnXorOperate()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);

}


void CImageProcessingView::OnNegaTransform()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();

	Invalidate(TRUE);

}


void CImageProcessingView::OnGammaCorrection()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);

}


void CImageProcessingView::OnBinarization()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarization();

	Invalidate(TRUE);

}


void CImageProcessingView::OnStressTransform()
{
	// TODO: Add your command handler code here
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHistoStretch()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();

	Invalidate(TRUE);

}


void CImageProcessingView::OnEndInSearch()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndInSearch();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHistogram()
{
	CImageProcessingDoc*pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistogram();
	Invalidate(TRUE);

}


void CImageProcessingView::OnHistoEqual()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEqual();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHistoSpec()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoSpec();

	Invalidate(TRUE);

}


void CImageProcessingView::OnEmbossing()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossing();

	Invalidate(TRUE);

}


void CImageProcessingView::OnBlurr()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurr();

	Invalidate(TRUE);

}


void CImageProcessingView::OnGaussianFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGaussianFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnSharpening()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpening();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHpfSharp()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfSharp();

	Invalidate(TRUE);

}


void CImageProcessingView::OnLpfSharp()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfSharp();

	Invalidate(TRUE);

}


void CImageProcessingView::OnDiffOperatorHor()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDiffOperatorHor();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHomogenOperator()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHomogenOperator();

	Invalidate(TRUE);

}


void CImageProcessingView::OnLaplacian()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian();

	Invalidate(TRUE);

}

void CImageProcessingView::OnNearest()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNearest();

	Invalidate(TRUE);

}


void CImageProcessingView::OnBilinear()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();

	Invalidate(TRUE);

}



void CImageProcessingView::OnMedianSub()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianSub();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMeanSub()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanSub();

	Invalidate(TRUE);

}


void CImageProcessingView::OnTranslation()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnTranslation();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMirrorHor()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorHor();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMirrorVer()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMirrorVer();

	Invalidate(TRUE);

}


void CImageProcessingView::OnRotation()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnRotation();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFrameSum()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameSum();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFrameSub()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameSub();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFrameMul()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameMul();

	Invalidate(TRUE);


}


void CImageProcessingView::OnFrameDiv()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameDiv();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFrameAnd()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameAnd();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFrameOr()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameOr();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFrameComb()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFrameComb();

	Invalidate(TRUE);

}


void CImageProcessingView::OnBinaryErosion()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinaryErosion();

	Invalidate(TRUE);

}


void CImageProcessingView::OnBinaryDilation()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinaryDilation();

	Invalidate(TRUE);

}


void CImageProcessingView::OnGrayErosion()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGrayErosion();

	Invalidate(TRUE);

}


void CImageProcessingView::OnGrayDilation()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGrayDilation();

	Invalidate(TRUE);

}


void CImageProcessingView::OnLowPassFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLowPassFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHighPassFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHighPassFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMeanFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMedianFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMaxFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMaxFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnMinFilter()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMinFilter();

	Invalidate(TRUE);

}


void CImageProcessingView::OnFft2d()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnFft2d();

	Invalidate(TRUE);

}


void CImageProcessingView::OnIfft2d()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnIfft2d();

	Invalidate(TRUE);

}


void CImageProcessingView::OnLpfFrequency()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfFrequency();

	Invalidate(TRUE);

}


void CImageProcessingView::OnHpfFrequency()
{
	CImageProcessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfFrequency();

	Invalidate(TRUE);

}
