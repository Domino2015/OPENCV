//函数原型：void cartToPolar(const Mat& x, const Mat& y, Mat& magnitude, Mat& angle, bool angleInDegrees = false)
//笛卡尔转极坐标
//#include "opencv2/opencv.hpp"
//
//int main(int argc, const char* argv[])
//{
//	std::vector<cv::Point2f> sides;
//	sides.push_back(cv::Point2f(3, 4));
//	sides.push_back(cv::Point2f(6, 8));
//	sides.push_back(cv::Point2f(1, 1));
//
//	cv::Mat xpts(sides.size(), 1, CV_32F, &sides[0].x, 2 * sizeof(float));
//	cv::Mat ypts(sides.size(), 1, CV_32F, &sides[0].y, 2 * sizeof(float));
//
//	std::cout << "x: " << xpts.t() << std::endl;
//	std::cout << "y: " << ypts.t() << std::endl;
//
//	cv::Mat magnitude, angle;
//	cv::cartToPolar(xpts, ypts, magnitude, angle);
//
//	std::cout << "\nmagnitude: " << magnitude.t();
//	std::cout << "\nangle: " << angle.t() *180. / CV_PI << std::endl;
//	return 0;
//}