//#include<opencv2\opencv.hpp>
//#include<iostream>
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
//double PI = 3.14;
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
//	//载入原始图
//	srcImg = imread("10.jpg");
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
//	//双层循环，遍历每一个像素点，改变map_x & map_y的值
//	for (int j = 0; j < srcImg.rows; j++)
//	{
//		for (int i = 0; i < srcImg.cols; i++)
//		{
//			double newX = i - ox;
//			double newY = j - oy;
//			theta = atan2(newY, newX);
//			range = hypot(newX, newY);
//			
//			//改变map_x & map_y的值. 
//			map_x.at<float>(j, i) = static_cast<float>(range*cos(theta) + ox);
//			map_y.at<float>(j, i) = static_cast<float>(range*sin(theta) + oy);
//		}
//	}
//	//进行重映射操作
//	remap(srcImg, outImg, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));
//
//	//显示效果图
//	imshow("【程序窗口】", outImg);
//	waitKey();
//}