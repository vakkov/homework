#ifndef __MEDIAN_HXX
#define __MEDIAN_HXX

#include <queue>
#include <vector>

class MedianFinder {
public:
    MedianFinder();
    ~MedianFinder();
    std::priority_queue<double> maxHeap; //lower half of the numbers
    std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap; //upper half
    void addNum(double num);
    double findMedian();
};

#endif // __MEDIAN_HXX
