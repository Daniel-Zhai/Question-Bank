#define _CRT_SECURE_NO_WARNINGS

//19. 删除链表的倒数第 N 个结点           看题解通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int traverse(struct ListNode* p, int n) {
    if (!p)return 0;
    int num = traverse(p->next, n);
    if (num == n)p->next = p->next->next;//num==n时p是删除节点的前驱
    return num + 1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //递归
    int num = traverse(head, n);
    if (num == n)return head->next;
    return head;
}

//876. 链表的中间结点             看题解通过

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//快慢指针法，慢指针一次走一步，快指针一次走两步，快指针走完时慢指针位于中间
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        for (int i = 0; i < 2; i++) {
            if (fast->next) {
                fast = fast->next;
            }
        }
    }
    return slow;
}