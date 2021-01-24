#include "entropy_thresholding.h"

static void displayImage(const cv::Mat& image, const char* name, bool mag) {
	cv::Mat Out;
	if (mag) {
		cv::resize(image, Out, cv::Size(image.cols / 4, image.rows / 4), 5, 5);
	}
	else {
		image.copyTo(Out);
	}
	namedWindow(name, cv::WINDOW_AUTOSIZE);
	cv::imshow(name, Out);
	cv::waitKey(0);
}

int main(void) {
	cv::Mat src, dst;
	src = cv::imread(R"(test.png)", cv::IMREAD_GRAYSCALE);

	if (!src.data) {
		std::cout << "Error: the image wasn't correctly loaded." << std::endl;
		return -1;
	}

	displayImage(src, "image", false);

	/*******************************************************/
	auto start = std::chrono::system_clock::now();
	EntropyBasedThreshold entropy_based_threshold(src);
	entropy_based_threshold.Process();
	auto end = std::chrono::system_clock::now();
	cv::threshold(src, dst, entropy_based_threshold.Process(), DYNAMICRANGE - 1, 0);

	// time
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "total time consume: " << elapsed_seconds.count() << std::endl;
	/*******************************************************/

	displayImage(dst, "output", false);

	return 0;
}