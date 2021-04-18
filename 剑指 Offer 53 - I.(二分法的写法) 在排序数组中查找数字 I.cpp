/*统计一个数字在排序数组中出现的次数。*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //二分法 找到了往两边找

        int res = 0;
        int left = 0;
        int right = nums.size()-1;

        while(left <= right)
        {
            //千万注意mid的算法！！！！！！！！！！！！！！！！！！！！！
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
            {
                res++;
                //开始往两边找
                int front = mid - 1;
                int last = mid + 1;
                while(front >= left && nums[front] == target)
                {
                    res++;
                    front--;
                }
                while(last <= right && nums[last] == target)
                {
                    res++;
                    last++;
                }
                return res;
            }
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }

        return res;

    }
};
