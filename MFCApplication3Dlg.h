
// MFCApplication3Dlg.h : header file
//

#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
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

using namespace cv;
using namespace std;


// CMFCApplication3Dlg dialog
class CMFCApplication3Dlg : public CDialogEx
{
// Construction
public:

	CMFCApplication3Dlg(CWnd* pParent = NULL);	// standard constructor
	CString m_Path;
	cv::Mat dst1,dst2,dst3,dst4;
	float x0=248.5, y0=232.5;
	float u3, u4;
	std::vector<cv::Point2f>corners;
	std::vector<cv::Vec3f>circles;
	int max(float a, float b, float c)
	{
		if (b > a)
			a = b;
		if (c > a)
			a = c;

		return a;
	}


//	cv::Mat linearTransform(cv::Mat srcImage, float a, int b)
//	{
//	//	if (srcImage.empty())
//	//	{
//	//		std::cout << "No data!" << std::endl;
//	//}
//	//	const int nRows = srcImage.rows;
//	//	const int nCols = srcImage.cols;
//	//	cv:: Mat resultImage = cv::Mat::zeros(srcImage.size(), srcImage.type());
//	//   //图像元素遍历  
//	//   for (int i = 0; i < nRows; i++)
//	//   {
//	//	   for (int j = 0; j < nCols; j++)
//	//	   {
//	//		   for (int c = 0; c < 3; c++)
//	//		   {
//	//			   //矩阵at操作，检查下标防止越界  
//	//			   resultImage.at<Vec3b>(i, j)[c] = saturate_cast<uchar>(a * (srcImage.at<Vec3b>(i, j)[c]) + b);
//	//		   }
//	//	   }
//	//   }
//	//   return resultImage;
//}
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnStnClickedText1();
};
