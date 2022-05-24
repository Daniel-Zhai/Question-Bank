#define _CRT_SECURE_NO_WARNINGS


//21. 合并两个有序链表                通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//循环
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* list3 = NULL;
    struct ListNode* t = list3;
    struct ListNode* p = list1;
    struct ListNode* q = list2;
    while (p || q) {
        if (!list3) {
            list3 = malloc(sizeof(struct ListNode));
            if (!p) {
                list3 = q;
                break;
            }
            if (!q) {
                list3 = p;
                break;
            }
            t = list3;
            if (p->val <= q->val) {
                list3->val = p->val;
                p = p->next;
            }
            else {
                list3->val = q->val;
                q = q->next;
            }
            list3->next = NULL;
        }
        else {
            t->next = malloc(sizeof(struct ListNode));
            if (!p) {
                t->next = q;
                break;
            }
            if (!q) {
                t->next = p;
                break;
            }
            t = t->next;
            if (p->val <= q->val) {
                t->val = p->val;
                p = p->next;
            }
            else {
                t->val = q->val;
                q = q->next;
            }
            t->next = NULL;
        }
    }
    return list3;
}
//递归
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1 && !list2)return NULL;
    if (!list1)return list2;
    if (!list2)return list1;
    if (list1->val <= list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    return NULL;
}

//206. 反转链表         
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//迭代
struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->next)return head;
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
//递归
struct ListNode* reverseList(struct ListNode* head) {
    //递归
    if (!head || !head->next)return head;
    struct ListNode* newhead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
//头插法
struct ListNode* reverseList(struct ListNode* head) {
    //新建链表头插法
    if (!head || !head->next)return head;
    struct ListNode* newhead = NULL;
    struct ListNode* temp = NULL;
    while (head) {
        temp = head;
        head = head->next;
        temp->next = newhead;
        newhead = temp;
    }
    return newhead;
}
//就地逆置法
struct ListNode* reverseList(struct ListNode* head) {
    //就地逆置法
    if (!head || !head->next)return head;
    struct ListNode* begin = head;
    struct ListNode* end = head->next;
    while (end) {
        begin->next = end->next;
        end->next = head;
        head = end;
        end = begin->next;
    }
    return head;
}