/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  */
class Solution {
public:
    int minArray(vector<int>& numbers) {
    
    //有序数组使用二分法
    int left = 0;
    int right = numbers.size()-1;

    while(left < right)
    {
        int mid = left + (right - left) / 2;

        //1.如果最右边大于中间 那么最小值一定在左边部分
        if (numbers[right] > numbers[mid])
        {
            right = mid;
        }

        //2.如果最右边小于中间 那么最小值一定在右边部分
        else if(numbers[right] < numbers[mid])
        {
            left = mid + 1;
        }

        //3.如果最右边等于中间 那么忽略右端点
        else
        {
            right-=1;
        }
    }
        return numbers[left];

    }
};
