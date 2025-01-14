class MedianFinder {
public:
    priority_queue<int> left_max_heap;
    priority_queue<int,vector<int>, greater<int>> right_min_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max_heap.empty() || left_max_heap.top()>num ){
            left_max_heap.push(num);
        }
        else{
            right_min_heap.push(num);
        }
        if (left_max_heap.size() > right_min_heap.size() + 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if (right_min_heap.size() > left_max_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
        return;
        
    }
    
    double findMedian() {
        int size_of_heap=left_max_heap.size()+right_min_heap.size();
        if(size_of_heap%2==0){
            return (double) (left_max_heap.top()+right_min_heap.top())/2;
        }else{
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */