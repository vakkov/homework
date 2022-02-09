#ifndef __MEDIAN_HXX
#define __MEDIAN_HXX

#include <queue>
#include <vector>
#include "optional.hpp" //c++14 does not provide std::optional...

class MedianFinder {
public:
    MedianFinder();
    ~MedianFinder();
    std::priority_queue<double> maxHeap; //lower/smaller half of the numbers
    std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap; //upper half
    void addNum(double num);
    tl::optional<double> findMedian();
};

#endif // __MEDIAN_HXX
