/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        //借助一个辅助栈  
        stack<int> my_stack;

        //需要注意的是：根据最后辅助栈是不是空决定返回值

        int j = 0;
        for(int i = 0; i < pushed.size(); i++)
        {
            my_stack.push(pushed[i]);

            //如果辅助栈顶和pop[j]一样，就马上弹出
            //注意：!my_stack.empty()条件
            while(!my_stack.empty() && my_stack.top() == popped[j])
            {
                my_stack.pop();
                j++;
            }
        }
        return my_stack.empty();

    }
};
