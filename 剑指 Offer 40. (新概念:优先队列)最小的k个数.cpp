/*输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //用队列 最多存k个数字
        vector<int> res(k, 0);
        if(k == 0) return res;
        
        //优先队列默认是一个最大堆，每次输出的堆顶元素是此时堆中的最大元素
        priority_queue<int> my_queue;

        //先把k个放入
        for(int i = 0; i < k; i++)
        {
            my_queue.push(arr[i]);
        }

        //从k+1个开始， 如果比top元素小，就把top弹出，然后把自己排到队列里
        for(int i = k; i < arr.size(); i++)
        {
            if (arr[i] < my_queue.top())
            {
                my_queue.pop();
                my_queue.push(arr[i]);
            }
        }

        //最后把队列的数字全部给res
        for(int i = 0; i < k; i++)
        {
            res[i] = my_queue.top();
            my_queue.pop();
        }

        return res;
    }
};
