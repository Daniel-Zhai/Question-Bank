#define _CRT_SECURE_NO_WARNINGS

//19. ɾ������ĵ����� N �����           �����ͨ��
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
    if (num == n)p->next = p->next->next;//num==nʱp��ɾ���ڵ��ǰ��
    return num + 1;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //�ݹ�
    int num = traverse(head, n);
    if (num == n)return head->next;
    return head;
}

//876. ������м���             �����ͨ��

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//����ָ�뷨����ָ��һ����һ������ָ��һ������������ָ������ʱ��ָ��λ���м�
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