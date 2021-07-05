class MedianFinder {
public:
    priority_queue<int>maxHeap; //max heap;
    priority_queue<int ,vector<int> ,greater<int>>minHeap;
    void addNum(int num) {
        maxHeap.push(num);
         if((!minHeap.empty() && maxHeap.top()>minHeap.top()) || ((maxHeap.size()-minHeap.size())>1))
        {
        minHeap.push(maxHeap.top());
        maxHeap.pop();    
        }
        if(minHeap.size() >(maxHeap.size()+1))
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
       if((minHeap.size() + maxHeap.size())%2==1)
           return minHeap.size()>maxHeap.size()?minHeap.top():maxHeap.top();
        return (minHeap.top() + maxHeap.top())/2.0;
     
    }
};
