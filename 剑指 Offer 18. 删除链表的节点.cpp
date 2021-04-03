/*给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        
        /*注意哨兵节点的写法*/
        ListNode * solider = new ListNode(0);
        solider->next = head;
        ListNode * pre = solider;

        while(pre->next != NULL)
        {
            //如果是要删除的
            if(pre->next->val == val)
            {
                pre->next = pre->next->next;
            }
            else 
            //不要删的就往后挪一位
                pre = pre->next;

        }
        return solider->next;
    }
};
