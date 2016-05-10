#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  
#include <iostream>  

//-----------------------------------【命名空间声明部分】--------------------------------------  
//          描述：包含程序所使用的命名空间  
//-----------------------------------------------------------------------------------------------  
using namespace cv;
using namespace std;

//-----------------------------------【全局函数声明部分】--------------------------------------  
//     描述：全局函数声明  
//-----------------------------------------------------------------------------------------------
//int cx;//图像中心x坐标
//int cy;//图像中心y坐标
//int dr;//中心黑圆半径
//int DR;//外边界大圆半径
//double PI = 3.141592;
//int rou; //是半径
//double phi;//th是角度（弧度）
//double theta;//入射角度
//double newRou; //是半径
//-----------------------------------【main( )函数】--------------------------------------------  
//          描述：控制台应用程序的入口函数，我们的程序从这里开始执行  
//-----------------------------------------------------------------------------------------------  
//int main()
//{
	//变量定义  
	//Mat srcImage, srcImage1, dstImage;
	//Mat map_x, map_y;

	//载入原始图  
	//srcImage = imread("1.jpg", 1);
	//srcImage1 = imread("2.jpg", 1);
	//if (!srcImage.data) { cout<<"读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"; return -1; }
	//imshow("原始图", srcImage);

	//初始化变量
	//cx = srcImage1.rows/2;
	//cy = srcImage1.cols/2;
	//dr = 60;
	//DR = 375;
	//double thetamax = 4 * PI / 9;
	//double f = DR / thetamax;
	// 选取一个ROI图像区域 ，并储存
	//Rect rect(100, 220, 150, 150);
	//srcImage(rect).copyTo(srcImage);
	//imshow("roi", srcImage);
	////创建和原始图一样的效果图，x重映射图，y重映射图  
	//dstImage.create(srcImage1.size(), srcImage1.type());
	//map_x.create(srcImage1.size(), CV_32FC1);
	//map_y.create(srcImage1.size(), CV_32FC1);
	////双层循环，遍历每一个像素点，改变map_x & map_y的值  
	//for (int j = 0; <j <srcImage1.rows; j++)
	//{
	//	for (int i = 0; <i < srcImage.cols; i++)
	//	{
	//		i = i - cx;
	//		j = j - cy;
	//		double ii, jj;
	//		//改变map_x & map_y的值.   
	//		//map_x.at<float>(j, i) = static_cast<float>(i);
	//		//map_y.at<float>(j, i) = static_cast<float>(j);
	//		//笛卡尔坐标转化为极坐标
	//		phi = atan2(i, j);
	//		rou = hypot(i, j);
	//		theta = rou / f;
	//		newRou = f*tan(theta);
	//		//cout <<newRou <<" "<<theta<< endl;
	//		ii = (int)newRou*cos(theta);
	//		jj = (int)newRou*sin(theta);
	//		//cout << ii << "  " << jj << endl;
	//		map_x.at<float>(j, i) = static_cast<float>(i-ii);
	//		map_y.at<float>(j, i) = static_cast<float>(j-jj);
	//	}
	//}


	////进行重映射操作  
	//remap(srcImage, dstImage, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));

	////显示效果图  
	//imshow("【效果图】", dstImage);

	//waitKey();

	//return 0;
//}

//调用cvLogPolar函数,笛卡尔坐标到极坐标变换
//Mat translateToPolar(Mat image, int centerx, int centery, int m)
//{
//	if (image.empty())
//		return image;
//	cv::Mat pImage = cv::Mat::zeros(image.size(), CV_8UC1);
//	IplImage ipl_a = image, ipl_pa = pImage;
//	cvLogPolar(&ipl_a, &ipl_pa, cvPoint2D32f(centerx, centery), m);
//	return pImage;
//}
