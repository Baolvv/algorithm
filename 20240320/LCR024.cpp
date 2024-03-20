/*
 * LCR 024. 反转链表
 * 1、构造三个ListNode指针，pre指向已倒序的头，cur指向当前位置（一开始是head，随循环不停向后移动），nex保存当前位置后面的节点（以免改变指向后消失）
 * 循环体内：
 * 2、先将当前节点的next保存到nex中
 * 3、将前面循环中倒序好的pre指向cur的next
 * 4、把倒序好的cur给pre
 * 5、把后续节点nex给cur进入下一次循环体
 * 结束返回倒序好的pre
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nex = nullptr;
        while(cur)
        {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};

int main()
{
    /*
     * 测试用例：{1,2,3}
     * 输出：{3,2,1}
     */
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    p1->next = p2;
    head->next = p1;

    Solution* solution = new Solution();
    ListNode* pre = solution->reverseList(head);
    while(head)
    {
        std::cout<<head->val;
        head=head->next;
    }
    std::cout<<std::endl;
    while(pre)
    {
        std::cout<<pre->val;
        pre=pre->next;
    }
    std::cout<<std::endl;
    return 0;
}