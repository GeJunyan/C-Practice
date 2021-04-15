/*如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

*/
class MedianFinder {
public:
    /** initialize your data structure here. */

    //注意写法！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    priority_queue<int> small;//普通的优先级队列，按从大到小排序
    priority_queue<int, vector<int>, greater<int>> big;//从小到大的优先级队列，可将greater改为less，即为从大到小
    
    int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(small.empty()){small.push(num);n++;return;}
        if(num<=small.top()){small.push(num);n++;}
        else {big.push(num);n++;}
        if(small.size()-big.size()==2){big.push(small.top());small.pop();}
        if(big.size()-small.size()==2){small.push(big.top());big.pop();}
    }
    
    double findMedian() {
        if(n%2){
            if(small.size()>big.size())return small.top();
            return big.top();
        }
        else{
            return ((long long)small.top() + big.top()) * 0.5;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
