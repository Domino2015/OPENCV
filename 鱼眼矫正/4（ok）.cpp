//#include <iostream>
//#include <opencv2/opencv.hpp>
//using namespace cv;
//
//
//Mat fish;//原图片
//Mat fishROI;//选取感兴趣区域
//Mat nor;//最终效果图
//Mat mx, my;
//int ox, oy;//图像中心
//
//double dr, DR; //外边界大圆半径，内部小圆半径
//double thetaMax;//最大角度
//double f;//焦距
//
////设置图片中心为原点
//void setO(Mat& m)
//{
//	ox = m.cols / 2;
//	oy = m.rows / 2;
//}
////得到像素点距离原点的距离
//double getRange(double x, double y)
//{
//	double i = sqrt((x - ox)*(x - ox) + (y - oy)*(y - oy));
//	return i;
//}
//
//void on_trackbar(int th)
//{
//	f = th;
//	for (int j = 0; j < nor.rows; j++)
//	{
//		for (int i = 0; i < nor.cols; i++)
//		{
//			double range = getRange(i, j);
//			mx.at<float>(j, i) = static_cast<float>((ox + ((i - ox) / ((range / f) / atan(range / f)))) - 300);//fish.cols-(ox+((ox-i-100)/((range/f)/atan(range/f))))
//			my.at<float>(j, i) = static_cast<float>((oy + ((j - oy) / ((range / f) / atan(range / f)))) - 300);//fish.rows-(oy+((oy-j-100)/((range/f)/atan(range/f))))
//		}
//	}
//	remap(fishROI, nor, mx, my, CV_INTER_LINEAR);
//	imshow("2", nor);
//}
//
//int main()
//{
//	//初始值的传入,由于没有值传入，这里暂时赋值为1
//	dr = 1;
//	DR = 1;
//	thetaMax = 1;
//
//	//图片的初始化相关
//	fish = imread("4.jpg", 1);
//
//	imshow("1", fish);
//	//创建和原始图一样的效果图，x重映射图，y重映射图  
//	nor.create(fish.rows * 2, fish.cols * 2, fish.type());
//	mx.create(fish.rows * 2, fish.cols * 2, CV_32FC1);
//	my.create(fish.rows * 2, fish.cols * 2, CV_32FC1);
//
//
//	f = DR / thetaMax;
//	//不生成网格，使用原本的坐标系
//
//	//设置图片中心为原点
//	setO(fish);
//
//	//设置感兴趣区域
//	//fish(Rect(400,100,1200,400)).copyTo(fishROI);
//	fish(Rect(1, 1, 300, 300)).copyTo(fishROI);
//	imshow("3", fishROI);
//
//	ox = ox + 300;
//	oy = oy + 300;
//
//	//求解theta+变换模型
//	imshow("2", nor);
//	int num = 1;//焦距初始值
//	cvCreateTrackbar("f", "2", &num, 1000, on_trackbar);
//
//	cvWaitKey();
//}