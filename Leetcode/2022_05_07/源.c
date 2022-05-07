#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>

//19. 删除链表的倒数第 N 个结点          未通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i = 0;
    struct ListNode* tmp;
    struct ListNode* p = head;
    struct ListNode* q;
    if (!head)return NULL;
    while (p) {
        tmp = p;
        for (i = 0; i < n; i++) {
            if (!tmp)return NULL;
            tmp = tmp->next;
        }
        if (!tmp)return NULL;
        if (!tmp->next) {
            q = p->next;
            p->next = q->next;
            q = NULL;
            break;
        }
        p = p->next;
    }
    return head;
}

//92. 反转链表 II          未通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* p = head;
    struct ListNode* q = head;
    struct ListNode* tmp1;//left的前驱
    struct ListNode* tmp2;//left的后继
    int i = 0;
    for (i = 0; i < left - 1; i++) {
        if (i == left - 2)tmp1 = p;
        p = p->next;
    }
    for (i = 0; i < right; i++) {
        q = q->next;
    }
    for (i = 0; i < right - left + 1; i++) {//一次移一个结点
        tmp2 = p->next;
        p->next = q->next;
        q->next = p;
        tmp1->next = tmp2;
    }
    return head;
}

//234. 回文链表                 通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head) {
    struct ListNode* newhead = malloc(sizeof(struct ListNode));
    struct ListNode* q = head;
    struct ListNode* p;
    while (q) {
        p = malloc(sizeof(struct ListNode));
        p->val = q->val;
        p->next = newhead->next;
        newhead->next = p;
        q = q->next;
    }
    p = newhead->next; q = head;
    while (p && q) {
        if (p->val != q->val)return false;
        p = p->next;
        q = q->next;
    }
    return true;
}


//237. 删除链表中的节点               通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    //从后向前覆盖，释放最后一个结点
    while (node->next) {
        node->val = node->next->val;
        if (!node->next->next) {
            node->next = NULL;
            break;
        }
        node = node->next;
    }
}


//876. 链表的中间结点                通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* node = head;
    struct ListNode* tmp;
    if (!head->next)return head;
    int n = 0;
    int i = 0;
    while (node) {
        n++;
        tmp = node;
        for (i = 0; i < n; i++) {
            tmp = tmp->next;
            if (!tmp)return node;
        }
        node = node->next;
    }
    return NULL;
}