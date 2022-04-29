#define _CRT_SECURE_NO_WARNINGS
//leetcode刷题
//第1题 两数之和
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//暴力法，还可以用哈希表
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        int j = 0;
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == target - nums[i])
            {
                *returnSize = 2;
                int* num = (int*)malloc(sizeof(int) * 2);
                num[0] = i;
                num[1] = j;
                return num;          //——返回多个值时用数组返回
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

//第2题  两数相加
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//尝试取值相加再取模
//long long int 长度不够   失败
 /*
 struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
     //struct ListNode* l3;      ——leetcode新建空链表时会出错，故尝试用得到的值覆盖l1，可行
     struct ListNode* p = l1;
     struct ListNode* q = l2;
     //struct ListNode* t = l3;
     int i = 0;
     long long int m = 0;        ——int不够
     long long int n = 0;        ——int不够
     int a = 0;
     long long int sum = 0;      ——int不够
     while(p)
     {
         m += (p->val)*pow(10,i);
         i++;
         p = p->next;            ——开始时用p++，愚蠢！
     }
     i = 0;
     while(q)
     {
         n += (q->val)*pow(10,i);
         i++;
         q = q->next;
     }
     sum = m + n;
     p = l1;                 
     while(sum)
     {
         if(!a)
         {
             p->val = sum%10;
             sum/=10;
             a = 1;
         }
         if(sum)
         {
             struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode)) ;  ——不要忘记开辟空间，直接定义指针没有用
             p->next = new;
             new->val = sum%10;
             new->next = NULL;
             p = new;
             sum/=10;
         }
     }
     return l1;
 }                        ——如果对链表长度有限制，long long int 不溢出的话这个方法可行
 */
//尝试两个链表同步相加，指针后移，但是进位！      死活通不过一个用例：只剩一个链表时的进位
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //int flag = 1;
    int tmp = 0;
    int a = 0;
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    while (p && q)
    {
        tmp = p->val + q->val;
        p->val = tmp % 10;
        p = p->next;
        q = q->next;
        if (tmp / 10 != 0)
        {
            if (p && q)
            {
                p->val += 1;
            }
        }
    }
    if (tmp / 10 != 0)
    {
        if (p && !q)
        {
            p->val += 1;
            while (p)
            {
                if ((p->val) / 10)
                {
                    p->val = (p->val) % 10;
                    p = p->next;
                    if (p)
                    {
                        p->val += 1;
                        tmp = p->val;
                    }
                    //else if(!p) a = 1;
                }
                else break;
            }
            if (tmp >= 10)
            {
                struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
                p = new;
                new->val = 1;
                new->next = NULL;
            }
        }
        else if (!p && q)
        {
            p = q;
            while (q)
            {
                q->val += 1;
                if ((q->val) / 10)
                {
                    q->val = (q->val) % 10;
                    q = q->next;
                }
                else break;
            }
            if (!q)
            {
                struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
                q = new;
                q->val = 1;
                q->next = NULL;
            }
        }
        else
        {
            struct ListNode* new = (struct ListNode*)malloc(sizeof(struct ListNode));
            p = new;
            p->val = 1;
            p->next = NULL;
        }

    }
    return l1;
}