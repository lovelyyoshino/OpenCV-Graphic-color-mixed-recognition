#include "water_competition.h"

SimpleShapes shapes;
int edgeThresh = 1;
int low_Threshold = 50;
const int max_lowThreshold = 100;

int main()
{
	Mat imgsrc = imread("3.png");
	namedWindow("Image Result", CV_WINDOW_AUTOSIZE);
	namedWindow("Image Canny", CV_WINDOW_AUTOSIZE);
	createTrackbar("Min Threshold:", "Image Canny", &low_Threshold, max_lowThreshold);
	while (true) {
		//Extration of simple shape (triangles/rectangles/circles) from the frame
		shapes = Water_Shape(imgsrc, low_Threshold);
		imshow("Image Result", shapes.img_dst);
		imshow("Image Canny", shapes.img_bw);
		if (waitKey(30) == 27) {
			destroyWindow("Image Traitee");
			destroyWindow("Image Canny");
			destroyAllWindows();
			cout << "esc key is pressed by user" << endl;
			return 0;
		}
	}
}