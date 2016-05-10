//#include "opencv2/highgui/highgui.hpp"  
//#include "opencv2/imgproc/imgproc.hpp"  
//#include <iostream>  
//
////-----------------------------------【命名空间声明部分】--------------------------------------  
//using namespace cv;
//using namespace std;
////-----------------------------------【全局函数声明部分】--------------------------------------  
////     描述：全局函数声明  
////-----------------------------------------------------------------------------------------------
//static void ContrastAndBright(int, void *);
//
//int dr;//中心黑圆半径
//double PI = 3.141592;
//int rou; //是半径
//double phi;//th是角度（弧度）
//double theta;//入射角度
//double newRou; //是半径
//double f;
//int g_nDRValue; //最大半径值  
//int g_nThetamaxValue;  //最大角度值 
////变量定义  
//Mat srcImage, dstImage, dstImage2;
//Mat map_x, map_y;
//int main()
//{
//	
//	//初始化变量
//	dr = 174;
//	//设定最大半径值  和最大角度值的初值  
//	g_nDRValue = 800; //外边界大圆半径
//	g_nThetamaxValue = 80;  //最大角度值
//
//
//	//载入原始图  
//	srcImage = imread("1.jpg", 1);
//	if (!srcImage.data) { cout<<"读取图片错误!\n"; return -1; }
//	imshow("原始图", srcImage);
//	//选取ROI
//	dstImage = srcImage(Rect(250, 55, 300, 300)); // Cloud region
//	imshow("hehe", dstImage);
//	////焦距计算
//	//double thetamax = g_nThetamaxValue * PI / 180;
//	//double f = g_nDRValue / thetamax;
//	////创建和原始图一样的效果图，x重映射图，y重映射图  
//	//dstImage.create(dstImage.size(), dstImage.type());
//	//map_x.create(srcImage.size(), CV_32FC1);
//	//map_y.create(srcImage.size(), CV_32FC1);
//
//	////【3】双层循环，遍历每一个像素点，改变map_x & map_y的值  
//	//for (int j = 0;j < srcImage.rows; j++)
//	//{
//	//	for (int i = 0; i < srcImage.cols; i++)
//	//	{
//	//		
//	//		//笛卡尔坐标转化为极坐标
//	//		phi = atan2(i, j);
//	//		rou = hypot(i, j);
//	//		theta = rou / f;
//	//		newRou = f*tan(theta);
//	//		//改变map_x & map_y的值. 
//	//		map_x.at<float>(j, i) = static_cast<float>(i - newRou*cos(theta));
//	//		map_y.at<float>(j, i) = static_cast<float>(j - newRou*sin(theta));
//	//	}
//	//}
//
//	////进行重映射操作  
//	//remap(dstImage, dstImage2, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//	//创建窗口  
//	namedWindow("【程序窗口】", 1);
//
//	//创建轨迹条  
//	createTrackbar("焦距：", "【程序窗口】", &g_nDRValue, 2000, ContrastAndBright);
//	createTrackbar("thetamax：", "【程序窗口】", &g_nThetamaxValue, 360, ContrastAndBright);
//	//调用回调函数  
//	ContrastAndBright(g_nDRValue, 0);
//	ContrastAndBright(g_nThetamaxValue, 0);
//	//显示效果图  
//	imshow("【程序窗口】", dstImage2);
//	waitKey();
//
//	return 0;
//}
//static void ContrastAndBright(int, void *)
//{
//
//	//焦距计算
//	double thetamax = g_nThetamaxValue * PI / 180;
//	double f = g_nDRValue / thetamax;
//	//创建和原始图一样的效果图，x重映射图，y重映射图  
//	dstImage.create(dstImage.size(), dstImage.type());
//	map_x.create(srcImage.size(), CV_32FC1);
//	map_y.create(srcImage.size(), CV_32FC1);
//
//	//双层循环，遍历每一个像素点，改变map_x & map_y的值  
//	for (int j = 0; j < srcImage.rows; j++)
//	{
//		for (int i = 0; i < srcImage.cols; i++)
//		{
//
//			//笛卡尔坐标转化为极坐标
//			phi = atan2(i, j);
//			rou = hypot(i, j);
//			theta = rou / f;
//			newRou = f*tan(theta);
//			//改变map_x & map_y的值. 
//			map_x.at<float>(j, i) = static_cast<float>(i - newRou*cos(theta));
//			map_y.at<float>(j, i) = static_cast<float>(j - newRou*sin(theta));
//		}
//	}
//
//	//进行重映射操作  
//	remap(dstImage, dstImage2, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//	//显示效果图  
//	imshow("【程序窗口】", dstImage2);
//}
