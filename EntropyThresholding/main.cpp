#include "entropy_thresholding.h"

int main(void) {
	cv::Mat src, dst;
	src = cv::imread(R"(test.png)", cv::IMREAD_GRAYSCALE);

	if (!src.data) {
		std::cout << "Error: the image wasn't correctly loaded." << std::endl;
		return -1;
	}

	auto start = std::chrono::system_clock::now();
	EntropyBasedThreshold entropy_based_threshold(src);
	int t = entropy_based_threshold.Process();
	auto end = std::chrono::system_clock::now();
	cv::threshold(src, dst, t, DYNAMICRANGE - 1, 0);

	cv::imshow("result", dst);
	cv::waitKey(0);

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "total time consume: " << elapsed_seconds.count() << std::endl;
	return 0;
}