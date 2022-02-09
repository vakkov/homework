#include "median.hxx"
#include <cassert>

MedianFinder::MedianFinder() {};
MedianFinder::~MedianFinder() {};

void MedianFinder::addNum(double num)
{
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

double MedianFinder::findMedian() 
{        
    if (maxHeap.size()==minHeap.size()) 
        return (minHeap.top() + maxHeap.top()) / 2.0;
    else
        return minHeap.top();
}


int main() {
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
}