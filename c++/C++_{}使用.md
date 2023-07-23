# C++11知识点——{}大括号的用法

大括号是C++11功能，可以使用大括号(而不是圆括号)括起来的列表**调用构造函数**。

### Example：

```c++
std::vector<cv::Point3d> row;
row.push_back({3, 0, 0}); 
/*----------------------------------------------------------------------*/
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

class Stump
{
private:
    int roots;
    double weight;
public:
    Stump(int r, double w):roots(r), weight(w){}
	void show(){
		std::cout<<"roots: "<<roots<<", weight: "<<weight<<std::endl;
	}
};

int main(int argc, char** argv)
{
	std::vector<cv::Point3d> row;
	row.push_back({3, 0, 0}); 
	row.push_back(cv::Point3d(3, 1, 0)); 
	std::cout<<row[0]<<std::endl;
	row[0]={3,1,1}; 
	std::cout<<row[0]<<std::endl;
	std::cout<<row[1]<<std::endl;

	Stump s1(1,2.2);  	//old style
	Stump s2{4,3.2};  	//C++11
	Stump s3 = {2,3.3}; 	//C++11
	s3.show();
	return 0;
}

```

