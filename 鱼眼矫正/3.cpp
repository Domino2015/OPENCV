//#include "opencv2/highgui/highgui.hpp"  
//#include "opencv2/imgproc/imgproc.hpp"  
//#include <iostream>  
//
////-----------------------------------【命名空间声明部分】--------------------------------------  
////          描述：包含程序所使用的命名空间  
////-----------------------------------------------------------------------------------------------  
//using namespace cv;
//using namespace std;
//
////-----------------------------------【全局函数声明部分】--------------------------------------  
////     描述：全局函数声明  
////-----------------------------------------------------------------------------------------------
//
////-----------------------------------【全局变量声明部分】--------------------------------------  
////     描述：全局变量声明  
////-----------------------------------------------------------------------------------------------
//int cx;//图像中心X坐标
//int cy;//图像中心y坐标
//int dr;//中心黑圆半径
//int DR;//外边界大圆半径
//double PI = 3.141592;
//int rou; //是半径
//double phi;//th是角度（弧度）
//double theta;//入射角度
//double newRou; //是半径
//double thetamax=80;
//double f;
////-----------------------------------【main( )函数】--------------------------------------------  
////          描述：控制台应用程序的入口函数，我们的程序从这里开始执行  
////-----------------------------------------------------------------------------------------------  
//int main()
//{
//	//【0】变量定义  
//	Mat srcImage, srcImage1, dstImage;
//	Mat map_x, map_y;
//
//	//【1】载入原始图  
//	srcImage = imread("1.jpg", 1);
//	srcImage1 = imread("3.jpg", 1);
//	cx = 450;
//	cy = 450;
//	rou = 100;
//	dr = 20;
//	DR = 100;
//	thetamax = thetamax*PI / 180;
//	f = DR / thetamax;
//	if (!srcImage.data) { cout << "读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"; return -1; }
//	imshow("原始图", srcImage);
//
//	//【2】创建和原始图一样的效果图，x重映射图，y重映射图  
//	dstImage.create(srcImage1.size(), srcImage.type());
//	map_x.create(srcImage1.size(), CV_32FC1);
//	map_y.create(srcImage1.size(), CV_32FC1);
//	//【3】双层循环，遍历每一个像素点，改变map_x & map_y的值  
//	for (int j = 0; j < srcImage1.rows; j++)
//	{
//		for (int i = 0; i < srcImage1.cols; i++)
//		{
//			//笛卡尔坐标转化为极坐标
//			phi = atan2(i, j);
//			rou = hypot(i, j);
//			theta = rou / f;
//			newRou = f*tan(theta);
//			//改变map_x & map_y的值.   
//			map_x.at<float>(j, i) = static_cast<float>(i - cx);
//			map_y.at<float>(j, i) = static_cast<float>(j - cy);
//		}
//	}
//
//	//【4】进行重映射操作  
//	remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//	//【5】显示效果图  
//	imshow("【程序窗口】", dstImage);
//	waitKey();
//
//	return 0;
//}
//
////double getPoint(int i,int j)
////{
////	double ii, jj;
////	//笛卡尔坐标转化为极坐标
////	phi = atan2(i, j);
////	rou = hypot(i, j);
////	theta = rou / f;
////	newRou = f*tan(theta);
////	//cout <<newRou <<" "<<theta<< endl;
////	ii = newRou*cos(theta) - cx;
////	jj = newRou*sin(theta) - cy;
////	//改变map_x & map_y的值.   
////	//map_x.at<float>(j, i) = static_cast<float>(ii);
////	//map_y.at<float>(j, i) = static_cast<float>(jj);
////}
