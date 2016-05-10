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
//double newRange;//归一化后r
//double PI = 3.14;
//string name = "后置摄像头";
//
//
//
////得到像素点距离原点的距离
//double getRange(double x, double y)
//{
//	double i = sqrt(x*x + y*y);
//	return i;
//}
//
//int main()
//{
//	VideoCapture capture; //声明视频读入类  
//	capture.open(0); //从摄像头读入视频 0表示从摄像头读入  
//
//	if (!capture.isOpened()) //先判断是否打开摄像头  
//	{
//		cout << "can not open";
//		cin.get();
//		return -1;
//	}
//
//	namedWindow(name);
//
//	while (1) {
//		Mat srcImg; //定义一个Mat变量，用于存储每一帧的图像  
//		capture >> srcImg; //读取当前帧  
//		if (!srcImg.data) { cout << "读取图片错误，请确定目录下是否有imread函数指定的图片存在~！ \n"; return -1; }
//		imshow("原始图", srcImg);
//		//设置图片中心为原点
//		oy = srcImg.cols / 2;
//		ox = srcImg.rows / 2;
//		//创建和原始图一样的效果图，x重映射图，y重映射图
//		srcImg.create(srcImg.size(), srcImg.type());
//		map_x.create(srcImg.size(), CV_32FC1);
//		map_y.create(srcImg.size(), CV_32FC1);
//
//		//双层循环，遍历每一个像素点，改变map_x & map_y的值
//		for (int j = 0; j < srcImg.rows; j++)
//		{
//			for (int i = 0; i < srcImg.cols; i++)
//			{
//				double newX = i - ox;
//				double newY = j - oy;
//				theta = atan2(newY, newX);
//				range = hypot(newX, newY);
//				rangeMax = 100;
//				newRange = range / rangeMax;
//				newRange = pow(newRange, 0.7);
//				newRange = newRange*rangeMax;
//				//改变map_x & map_y的值. 
//				map_x.at<float>(j, i) = static_cast<float>(newRange*cos(theta) + ox);
//				map_y.at<float>(j, i) = static_cast<float>(newRange*sin(theta) + oy);
//			}
//		}
//		//进行重映射操作
//		remap(srcImg, outImg, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//		//显示效果图
//		if (!srcImg.empty()) //判断当前帧是否捕捉成功 **这步很重要  
//			imshow(name, outImg); //若当前帧捕捉成功，显示  
//		else
//			cout << "can not ";
//		waitKey(30); //延时30毫秒  
//	}
//
//	waitKey();
//}



