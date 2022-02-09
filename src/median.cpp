#include "median.hxx"
#include "optional.hpp" //c++14 does not provide std::optional...
#include <string>
#include <stdexcept>
#include <cassert>

MedianFinder::MedianFinder() {};
MedianFinder::~MedianFinder() {};
/*
    Time complexities:
    Adding elements to the heap: O(logn)
    Removing elements from the heap: O(logn)
    Finding the max/min from a max heap/ min heap: O(1)
    Getting the median: O(1)

    Keep the smaller elements in a max-heap 
    and the bigger ones - in a min-heap.
    The max size difference between the two heaps is 1.
*/

void MedianFinder::addNum(double num)
{
    //check if the heaps are equal in size
    if (maxHeap.size()==minHeap.size()) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else {
        minHeap.push(num);
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

tl::optional<double> MedianFinder::findMedian() 
{
    if (maxHeap.empty() && minHeap.empty()) {
        throw std::runtime_error(std::string("No numbers were inserted!"));
        return {};
    }
    else if (maxHeap.empty() || (minHeap.size() > maxHeap.size()))
        return minHeap.top();

    else if (minHeap.empty() || (maxHeap.size() > minHeap.size()))
        return maxHeap.top();

    return (minHeap.top() + maxHeap.top()) / 2.0;
}


// Not needed; run the unit tests :P
// $ ctest -V

/* int main() {
    MedianFinder* medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);
    assert (medianFinder->findMedian() == 1.5);
    medianFinder->addNum(3);
    assert (medianFinder->findMedian() == 2.0);

    delete medianFinder;
    //new(&medianFinder) MedianFinder();
    medianFinder = new MedianFinder();
    
    medianFinder->addNum(6);
    assert (medianFinder->findMedian() == 6.0);
    medianFinder->addNum(10);
    assert (medianFinder->findMedian() == 8.0);
    medianFinder->addNum(2);
    assert (medianFinder->findMedian() == 6.0);
    medianFinder->addNum(6);
    assert (medianFinder->findMedian() == 6.0);
    medianFinder->addNum(5);
    assert (medianFinder->findMedian() == 6.0);
    medianFinder->addNum(0);
    assert (medianFinder->findMedian() == 5.5);
    medianFinder->addNum(6);
    assert (medianFinder->findMedian() == 6.0);
    medianFinder->addNum(3);
    assert (medianFinder->findMedian() == 5.5);
    medianFinder->addNum(1);
    assert (medianFinder->findMedian() == 5.0);
    medianFinder->addNum(0);
    assert (medianFinder->findMedian() == 4.0);
    medianFinder->addNum(0);
    assert (medianFinder->findMedian() == 3.0);
    
    return 0;
 } */