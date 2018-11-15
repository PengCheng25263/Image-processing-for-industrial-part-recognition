
// MFCApplication3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include "cvvimage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include"Resource.h"
#include"math.h"
#include"stdio.h"

using namespace cv;
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

	
END_MESSAGE_MAP()


// CMFCApplication3Dlg dialog



CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication3Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication3Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication3Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication3Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication3Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication3Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication3Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication3Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication3Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication3Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCApplication3Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCApplication3Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCApplication3Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCApplication3Dlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCApplication3Dlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCApplication3Dlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCApplication3Dlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCApplication3Dlg::OnBnClickedButton17)
	ON_STN_CLICKED(IDC_TEXT1, &CMFCApplication3Dlg::OnStnClickedText1)
END_MESSAGE_MAP()


// CMFCApplication3Dlg message handlers

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication3Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}





void CMFCApplication3Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CMFCApplication3Dlg::OnBnClickedButton1()
{
	//�ļ���ȡ
	CFileDialog dlg(TRUE, _T("*.bmp"), NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY,
		_T("image files(*.bmp;*.jpg)|*.bmp;*.jpg|ALL Files(*.*)|*.*||"), NULL);
	dlg.m_ofn.lpstrTitle = _T("open image");
	if (dlg.DoModal() != IDOK)
	{
		return;
	}
	m_Path = dlg.GetPathName();
	//CString file_path = m_Path;
	//const char* filename = m_Path.GetBuffer(sizeof(m_Path));
	m_Path.Replace(_T("//"), _T("////"));
	IplImage* m_pic = cvLoadImage((CT2CA)m_Path);
	if (!m_pic)
	{
		return;
	}
	CDC* pDC = GetDlgItem(IDC_PICTURE1)->GetDC();
	HDC hDC = pDC->GetSafeHdc();
	CvvImage pic1;
	pic1.CopyOf(m_pic);
	CRect rect;
	GetDlgItem(IDC_PICTURE1)->GetClientRect(&rect);
	pic1.DrawToHDC(hDC, &rect);
	ReleaseDC(pDC);
	cvReleaseImage(&m_pic);
	
}




void CMFCApplication3Dlg::OnBnClickedButton2()
{
	// ��Ȩֵ���ҶȻ�����
	m_Path.Replace(_T("//"), _T("////"));
	IplImage* m_pic = cvLoadImage((CT2CA)m_Path);
	Mat src = cvarrToMat(m_pic);
	Mat src0(src.rows, src.cols, CV_8UC1);
	if (!src.data)
	{
		return;
	}
	//cvtColor(src, dst1,COLOR_RGB2GRAY);
	float R, G, B;
	for (int y = 0; y < src.rows; y++)
	{
		uchar* data = src0.ptr<uchar>(y);
		for (int x = 0; x < src.cols; x++)
		{
			B = src.at<Vec3b>(y, x)[0];
			G = src.at<Vec3b>(y, x)[1];
			R = src.at<Vec3b>(y, x)[2];
			data[x] = (int)(R * 0.299 + G * 0.587 + B * 0.114);//���ù�ʽ����Ҷ�ֵ����Ȩƽ������
	
		}
	}
	dst1 = src0;
	imshow("Ȩֵ���Ҷ�ͼ", src0);
	waitKey(0);
	destroyWindow("Ȩֵ���Ҷ�ͼ");
	//namedWindow("�ҶȻ�����", WINDOW_AUTOSIZE);
	//HWND hWnd = (HWND)cvGetWindowHandle("�ҶȻ�����");
	//HWND hParent = ::GetParent(hWnd);
	//::SetParent(hWnd, GetDlgItem(IDC_PICTURE1)->m_hWnd);
	//::ShowWindow(hParent, SW_HIDE);
	//namedWindow("�ҶȻ�");
	//waitKey(0);
}

void CMFCApplication3Dlg::OnBnClickedButton4()
{
	// ƽ��ֵ���ҶȻ�
	m_Path.Replace(_T("//"), _T("////"));
	IplImage* m_pic = cvLoadImage((CT2CA)m_Path);
	Mat src = cvarrToMat(m_pic);
	Mat src0(src.rows, src.cols, CV_8UC1);
	if (!src.data)
	{
		return;
	}
	float R, G, B;
	for (int y = 0; y < src.rows; y++)
	{
		uchar* data = src0.ptr<uchar>(y);
		for (int x = 0; x < src.cols; x++)
		{
			B = src.at<Vec3b>(y, x)[0];
			G = src.at<Vec3b>(y, x)[1];
			R = src.at<Vec3b>(y, x)[2];
			data[x] = (int)(R + G + B)/3;//���ù�ʽ����Ҷ�ֵ����Ȩƽ������
		}
	}
	dst1 = src0;
	imshow("��ֵ���Ҷ�ͼ", src0);
	waitKey(0);
	destroyWindow("��ֵ���Ҷ�ͼ");
}

void CMFCApplication3Dlg::OnBnClickedButton5()
{
	// ֱ��ͼ���⻯
	if (!dst1.data)
	{
		return;
	}
	cv::equalizeHist(dst1, dst2);
	imshow("ֱ��ͼ���⻯", dst2);
	waitKey(0);
	destroyWindow("ֱ��ͼ���⻯");
}


void CMFCApplication3Dlg::OnBnClickedButton3()
{
	// ��ֵ�˲�
	if (!dst2.data)
	{
		return;
	}
	cv::medianBlur(dst2, dst3,3);
	imshow("��ֵ�˲�", dst3);
	waitKey(0);
	destroyWindow("��ֵ�˲�");
}


void CMFCApplication3Dlg::OnBnClickedButton6()
{
	// ���ֵ���ҶȻ�
	m_Path.Replace(_T("//"), _T("////"));
	IplImage* m_pic = cvLoadImage((CT2CA)m_Path);
	Mat src = cvarrToMat(m_pic);
	Mat src0(src.rows, src.cols, CV_8UC1);
	if (!src.data)
	{
		return;
	}
	float R, G, B;
	for (int y = 0; y < src.rows; y++)
	{
		uchar* data = src0.ptr<uchar>(y);
		for (int x = 0; x < src.cols; x++)
		{
			B = src.at<Vec3b>(y, x)[0];
			G = src.at<Vec3b>(y, x)[1];
			R = src.at<Vec3b>(y, x)[2];
			data[x] = max(R , G , B);//���ù�ʽ����Ҷ�ֵ����Ȩƽ������
		}
	}
	dst1 = src0;
	imshow("���ֵ��", src0);
	cvReleaseImage(&m_pic);
	waitKey(0);
	destroyWindow("���ֵ��");
}


void CMFCApplication3Dlg::OnBnClickedButton7()
{
	// ��˹�˲�
	if (!dst2.data)
	{
		return;
	}
	GaussianBlur(dst2, dst3, Size(5, 5), 0, 0);
	imshow("��˹�˲�", dst3);
	waitKey(0);
	destroyWindow("��˹�˲�");
}


void CMFCApplication3Dlg::OnBnClickedButton8()
{
	// ��ֵ�˲�
	if (!dst2.data)
	{
		return;
	}
	blur(dst2, dst3, Size(5, 5));
	imshow("��ֵ�˲�", dst3);
	waitKey(0);
	destroyWindow("��ֵ�˲�");
}



void CMFCApplication3Dlg::OnBnClickedButton9()
{
	// ˫���˲�
	if (!dst2.data)
	{
		return;
	}
	bilateralFilter(dst2, dst3, 25, 25 * 2, 25 / 2);
	imshow("˫���˲�Ч��ͼ", dst3);
	waitKey(0);
	destroyWindow("˫���˲�Ч��ͼ");
}



void CMFCApplication3Dlg::OnBnClickedButton10()
{
	// ���Ա任
	if (!dst1.data)
	{
		return;
	}
	dst1.convertTo(dst2, CV_8U, 1.3,60);
	imshow("���Ա任",dst2);
	waitKey(0);
	destroyWindow("���Ա任");
}


void CMFCApplication3Dlg::OnBnClickedButton11()
{
	// sobel���ӵ�ģ
	Mat sobelX, sobelY;
	Sobel(dst3, sobelX, CV_16S, 1, 0, 3, 0.4, 128);
	Sobel(dst3, sobelY, CV_16S, 1, 0, 3, 0.4, 128);
	Mat sobel;
	sobel = abs(sobelX) + abs(sobelY);
	//����
	double sobmin, sobmax;
	cv::minMaxLoc(sobel, &sobmin, &sobmax);
	Mat sobelImage;
	sobel.convertTo(sobelImage, CV_8U, -255./ sobmax, 255);
	//��ֵ��
	Mat sobelthresholded;
	cv::threshold(sobelImage, sobelthresholded, 125, 255, cv::THRESH_BINARY);
	dst4 = sobelthresholded;
	imshow("Sobel����",sobelthresholded);
	waitKey(0);
	destroyWindow("Sobel����");
}


void CMFCApplication3Dlg::OnBnClickedButton12()
{
	// Canny����
	if (!dst3.data)
	{
		return;
	}
	cv::Canny(dst3, dst4, 125, 350);
	imshow("Canny����", dst4);
	waitKey(0);
	destroyWindow("Canny����");
}


void CMFCApplication3Dlg::OnBnClickedButton13()
{
	// ����任
	//std::vector<cv::Vec3f>circles;
	//cv::HoughCircles(dst3, circles, CV_HOUGH_GRADIENT, 1, 50, 200, 100, 0, 0);
	//AllocConsole();
	//freopen("CONOUT$", "a +", stdout);
	//std::cout << "x          y          r" << std::endl;
	//for (size_t i = 0; i < circles.size(); i++)
	//{
	//	Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
	//	int radius = cvRound(circles[i][2]);
	//	// circle center
	//	circle(dst3, center, 3, Scalar(0, 255, 0), -1, 8, 0);
	//	// circle outline
	//	circle(dst3, center, radius, Scalar(0, 0, 255), 3, 8, 0);
	//	x0 = circles[i][0];
	//	y0 = circles[i][1];
	//	cout << cvRound(circles[i][0]) << "\t" << cvRound(circles[i][1]) << "\t"
	//		<< cvRound(circles[i][2]) << endl;//�ڿ���̨���Բ������Ͱ뾶  
	//	//cout << x0 << "\t" <<y0  << endl;//�ڿ���̨���Բ������Ͱ뾶  

	//}
	//��ͼ�ϻ���Բ
	std::vector<cv::Vec3f>::
		const_iterator itc = circles.begin();
	while (itc != circles.end()) 
	{
		cv::circle(dst3, 
			cv::Point((*itc)[0], (*itc)[1]), //Բ��
			(*itc)[2], //�뾶
			cv::Scalar(0,0,255), //��ɫ
			2);//���

		cv::circle(dst3,
			cv::Point((*itc)[0], (*itc)[1]), //Բ��
			3, //�뾶
			cv::Scalar(0,255,0), //��ɫ         
			-1,
			8,
			0);//���
		++itc;
	}
	imshow("����任", dst3);
	waitKey(0);
	destroyWindow("����任");
}

void CMFCApplication3Dlg::OnBnClickedButton14()
{
	// �ǵ���
	//std::vector<cv::Point2f>corners;
	cv::goodFeaturesToTrack(dst4,//����ͼ��
		corners,//�ǵ�ͼ��
		500,//���ؽǵ���������
		0.10,//�����ȼ�
		30);//�ǵ�֮���������̾���
	AllocConsole();
	freopen("CONOUT$", "a +", stdout);
	std::cout << "x       y" << std::endl;
	std::vector<cv::Point2f>::
		const_iterator itc = corners.begin(); 
	while (itc != corners.end())
	{
		cv::circle(dst4,
			*itc, //Բ��
			10, //�뾶
			cv::Scalar(255), //��ɫ
			2);//���
		/*cout << *itc << endl;*/
		++itc;
	}
	for (size_t i = 0; i < corners.size(); i++)
	{
		int u1 = corners[i].x;
		int u2 = corners[i].y;
		cout << u1 << "\t" << u2<<"\n"<< endl;//�ڿ���̨���Բ������Ͱ뾶  
	}
	imshow("�ǵ���", dst4);
}

void CMFCApplication3Dlg::OnBnClickedButton15()
{
	 //�򿪿���̨
	AllocConsole();
	freopen("CONOUT$","a +", stdout);
	std::cout << "x          y          r" << std::endl;

	//CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	//SMALL_RECT srctWindow;//console����ṹf'd
	//AllocConsole();//����һ��console����

	//HANDLE hdlWrite = GetStdHandle(STD_OUTPUT_HANDLE);//��ȡconsole���
	//GetConsoleScreenBufferInfo(hdlWrite, &csbiInfo);


	//SMALL_RECT rc = { 0,0, 60, 5 }; // ���ô���λ�úʹ�С
	//BOOL bset = SetConsoleWindowInfo(hdlWrite, TRUE, &rc);//���ý����С

	////SetConsoleTitle(123);//����Title
	//freopen("CONOUT$", "w", stdout);//֧��������ʾ
	//printf("salary:%d\n", 50000);

	//FreeConsole();//�ͷ�Console
}


void CMFCApplication3Dlg::OnBnClickedButton16()
{
	// Բ���������
	//std::vector<cv::Vec3f>circles;
	cv::HoughCircles(dst3, circles, CV_HOUGH_GRADIENT, 1, 50, 200, 100, 0, 0);
	AllocConsole();
	freopen("CONOUT$", "a +", stdout);
	std::cout << "x       y" << std::endl;
	for (size_t i = 0; i < circles.size(); i++)
	{
		Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
		int radius = cvRound(circles[i][2]);
		// circle center
		circle(dst3, center, 3, Scalar(0, 255, 0), -1, 8, 0);
		// circle outline
		circle(dst3, center, radius, Scalar(0, 0, 255), 3, 8, 0);
		u3 = circles[i][0];
		u4 = circles[i][1];
		float x = circles[i][0]-x0;
		float y = circles[i][1]-y0;
		cout << x << "\t" << y << endl;//�ڿ���̨���Բ������Ͱ뾶  
	}
	imshow("Բ�ļ��", dst3);
	waitKey(0);
	destroyWindow("Բ�ļ��");
}


void CMFCApplication3Dlg::OnBnClickedButton17()
{
	// ƫת�Ǽ���	
	AllocConsole();
	freopen("CONOUT$", "a +", stdout);
	//std::cout << "L" << std::endl;
	float a[2], b[2];
	int j = 0;
	for (size_t i = 0; i < corners.size(); i++)
	{
		int u1 = corners[i].x;
		int u2 = corners[i].y;
		int L = (u1 - u3) *(u1 - u3) + (u2 - u4)* (u2 - u4);
		//cout << L<< endl;//�ڿ���̨���Բ������Ͱ뾶 
		if (L > 5000 && L < 15000)
		{
			a[j] = corners[i].x;
			b[j] = corners[i].y;
			//cout << "x" << a[j] << "\t" << "y" << b[j]<< endl;
			j++;
		}
	}
	float x = 0.5*(a[0] + a[1]);
	float y = 0.5*(b[0] + b[1]);
	float theta;
	//cout << "x"<< x << "\t" << "u3" << "\t" << u3 << "\t" << "y"<< y << "\t" <<"u4" << "\t" <<u4<< endl;
	float m = x - u3;
	float n = y - u4;
	if (m > 0 && n <= 0)
	{
		theta = atan(n / m) * 180 / 3.1415 - 90;
	}
	if (m <= 0 && n <= 0)
	{
		theta = atan(n / m) * 180 / 3.1415 + 90;
	}
	if (m <= 0 && n > 0)
	{
		theta = atan(n / m) * 180 / 3.1415 + 90;
	}
	if (m > 0 && n > 0)
	{
		theta = atan(n / m) * 180 / 3.1415 - 90;
	}
	std::cout << "theta" << std::endl;
	std::cout << theta << endl;//�ڿ���̨���Բ������Ͱ뾶 
}


void CMFCApplication3Dlg::OnStnClickedText1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
