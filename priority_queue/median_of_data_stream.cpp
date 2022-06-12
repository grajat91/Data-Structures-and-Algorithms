/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0*/

class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>, greater<int>> minheap;
    
    void addNum(int num) {
        if (maxheap.size() == 0 && minheap.size() == 0)  maxheap.push(num);
        else {
            if (maxheap.size() > minheap.size()) {
                if (num >= maxheap.top()) {
                    minheap.push(num);
                } else {
                    minheap.push(maxheap.top());
                    maxheap.pop();
                    maxheap.push(num);
                }
            } else {
                if (num >= maxheap.top()) {
                    minheap.push(num);
                    maxheap.push(minheap.top());
                    minheap.pop();
                } else {
                    maxheap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        double median;
        if ((maxheap.size() + minheap.size())%2 == 0) {
            //cout<<"Even elements: "<<maxheap.top()<<" "<<minheap.top()<<endl;
            median = (maxheap.top() + minheap.top())/2.000;
            //cout<<"Median is: "<<median<<endl;
            
        }
        else median = maxheap.top();
        return median;
    }
};
