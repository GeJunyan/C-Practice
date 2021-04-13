/*请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) return nullptr;

        Node *cur = head;
        map<Node*, Node*> map;
        
        //复制各个节点 建立  给的节点 ---> 新的节点之间的映射关系
        while(cur != nullptr) 
        {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        
        cur = head;//把cur置回头
        //构建新的表 next 和 random的指向
        while(cur != nullptr)
        {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }

        return map[head];
    }
};
