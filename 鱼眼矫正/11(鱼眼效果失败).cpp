//#include<opencv2\opencv.hpp>
//#include<iostream>
//#include<math.h>
//
//using namespace std;
//using namespace cv;
//
//Mat srcImg;//原图片
//Mat srcImagROI;//选取感兴趣区域
//Mat outImg;//最终效果图
//Mat map_x, map_y;
//int ox, oy;//图像中心
//double theta;
//double range;
//double rangeMax;
//double dr=20;//中心黑圆半径
//double DR=200;//外边界大圆半径
//double newRange;//归一化后r
//int f;//焦距
//double PI = 3.14;
//double newTheta;
//int maxTheta;//最大角度
//
//static void ContrastAndBright(int, void *);
//
//
//int main()
//{
//	//载入原始图
//	srcImg = imread("4.jpg");
//	if (!srcImg.data) { cout << "读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"; return -1; }
//	imshow("原始图", srcImg);
//	//设置图片中心为原点
//	oy = srcImg.cols / 2;
//	ox = srcImg.rows / 2;
//	//创建和原始图一样的效果图，x重映射图，y重映射图
//	srcImg.create(srcImg.size(), srcImg.type());
//	map_x.create(srcImg.size(), CV_32FC1);
//	map_y.create(srcImg.size(), CV_32FC1);
//
//	//设定对比度和亮度的初值  
//	f = 100;
//	maxTheta = 80;
//
//	//创建窗口  
//	namedWindow("【程序窗口】", 1);
//
//	//创建轨迹条  
//	createTrackbar("焦       距：", "【程序窗口】", &f, 1000, ContrastAndBright);
//
//	//调用回调函数  
//	ContrastAndBright(f, 0);
//
//
//	//显示效果图
//	imshow("【程序窗口】", outImg);
//	waitKey();
//}
//static void ContrastAndBright(int, void *)
//{
//
//	//双层循环，遍历每一个像素点，改变map_x & map_y的值
//	for (int j = 0; j < srcImg.rows; j++)
//	{
//		for (int i = 0; i < srcImg.cols; i++)
//		{
//			double newX = i - ox;
//			double newY = j - oy;
//			theta = atan2(newY, newX);
//			range = hypot(newX, newY);
//			//maxTheta = maxTheta*PI / 180;
//			//f = DR / maxTheta;
//			newTheta = range / f;
//			newRange = f*tan(newTheta);
//			//改变map_x & map_y的值. 
//			map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//			map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//		}
//	}
//	//进行重映射操作
//	remap(srcImg, outImg, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//	//显示效果图
//	imshow("【程序窗口】", outImg);
//}