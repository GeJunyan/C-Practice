/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。*/

/*这题可以用首尾指针
我采用了记录第一个偶数出现的位置的方法*/

class Solution {
public:

    void swap(vector<int>& nums, int i, int j)
    {
        int temp;
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    vector<int> exchange(vector<int>& nums) {

        int first_even = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++)
        {
            //遇到了偶数，记录位置
            if(nums[i]%2 == 0)
            {
                if(i < first_even)
                    first_even = i;
            }
            else if(nums[i]%2 !=0 && first_even != INT_MAX)
            {
                swap(nums, i, first_even);
                first_even++;
            }
            else 
                continue;
        }
        
        return nums;
    }
};
