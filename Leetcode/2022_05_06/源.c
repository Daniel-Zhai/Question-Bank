#define _CRT_SECURE_NO_WARNINGS

//leetcode

//160. 相交链表             看答案通过，双指针法
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //双指针法：设headA有m个结点，headB有n个结点
 //headA中未相交部分有a个结点，headB中未相交部分有b个结点
 //相交部分有c个结点，即 a+c=m, b+c=n
 //让pa和pb指针分别遍历headA、headB
 //遍历完之后pa开始遍历headB，pb开始遍历pa
 //当二者走到相交部分，pa走了a+c+b(m+b)，pb走了b+c+a(n+a)，距离相等
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    if (!headA || !headB)return NULL;
    struct ListNode* pa = headA;
    struct ListNode* pb = headB;
    while (pa != pb) {
        pa = pa == NULL ? headB : pa->next;
        pb = pb == NULL ? headA : pb->next;
    }
    return pa;
}

//203. 移除链表元素           通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* tmp;
    if (!head)return NULL;
    while (head->val == val) {
        tmp = head;
        head = head->next;
        free(tmp);
        if (!head)return NULL;
    }
    if (!head)return NULL;
    head->next = removeElements(head->next, val);
    return head;
}