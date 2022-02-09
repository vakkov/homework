#include "gtest/gtest.h"
#include "median.hxx"
#include <stdexcept>


TEST(MedianTest, Equality) 
{
  MedianFinder medianFinder;
  medianFinder.addNum(1);
  medianFinder.addNum(2);
  ASSERT_EQ(medianFinder.findMedian(), 1.5);
  medianFinder.addNum(3);
  ASSERT_EQ(medianFinder.findMedian(), 2);
}

TEST(MedianTest, EqualityTwo)
{
  MedianFinder medianFinder;
  medianFinder.addNum(6);
  ASSERT_EQ(medianFinder.findMedian(), 6.0);
  medianFinder.addNum(10);
  ASSERT_EQ(medianFinder.findMedian(), 8.0);
  medianFinder.addNum(2);
  ASSERT_EQ(medianFinder.findMedian(), 6.0);
  medianFinder.addNum(6);
  ASSERT_EQ(medianFinder.findMedian(), 6.0);
  medianFinder.addNum(5);
  ASSERT_EQ(medianFinder.findMedian(), 6.0);
  medianFinder.addNum(0);
  ASSERT_EQ(medianFinder.findMedian(), 5.5);
  medianFinder.addNum(6);
  ASSERT_EQ(medianFinder.findMedian(), 6.0);
  medianFinder.addNum(3);
  ASSERT_EQ(medianFinder.findMedian(), 5.5);
  medianFinder.addNum(1);
  ASSERT_EQ(medianFinder.findMedian(), 5.0);
  medianFinder.addNum(0);
  ASSERT_EQ(medianFinder.findMedian(), 4.0);
  medianFinder.addNum(0);
  ASSERT_EQ(medianFinder.findMedian(), 3.0);
}

//!!!!!!! add edge cases
TEST(MedianTest, Exception) 
{
    MedianFinder medianFinder;
    EXPECT_THROW(medianFinder.findMedian(), std::runtime_error);
}
