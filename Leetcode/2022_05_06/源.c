#define _CRT_SECURE_NO_WARNINGS

//leetcode

//160. �ཻ����             ����ͨ����˫ָ�뷨
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //˫ָ�뷨����headA��m����㣬headB��n�����
 //headA��δ�ཻ������a����㣬headB��δ�ཻ������b�����
 //�ཻ������c����㣬�� a+c=m, b+c=n
 //��pa��pbָ��ֱ����headA��headB
 //������֮��pa��ʼ����headB��pb��ʼ����pa
 //�������ߵ��ཻ���֣�pa����a+c+b(m+b)��pb����b+c+a(n+a)���������
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

//203. �Ƴ�����Ԫ��           ͨ��
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