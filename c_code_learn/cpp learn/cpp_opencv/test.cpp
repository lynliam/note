#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace cv;
using namespace std;

int main() {

    Mat image;
    image = imread("./22.png", IMREAD_COLOR); // Read the file

    namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.

    if (!image.data) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
    } else {        // Image is good!

        imshow("Display window", image); // Show our image inside it.
    }

    waitKey(0);
    return 0;
}