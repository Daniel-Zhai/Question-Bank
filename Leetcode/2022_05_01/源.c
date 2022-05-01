#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//leetcode
//第20题 有效的括号                 ——看答案通过，使用栈不一定要定义一个栈类型，数组下标加减一样可以
// 
// 自己写的
//runtime error: store to null pointer of type 'char'
typedef struct {
    char* base;
    char* top;
    int stacksize;
}Sqstack;//栈

bool isValid(char* s) {
    Sqstack S;
    S.top = S.base;
    S.stacksize = 10000;
    if (!s)return false;
    while (s != NULL && S.top >= S.base)
    {
        if ((*s == '{') || (*s == '(') || (*s == '['))
        {
            *S.top = *s;
            S.top++; s++;
        }
        else
        {
            if ((*s == ')') && (*--S.top != '('))return false;
            else s++;
            if ((*s == '}') && (*--S.top != '{'))return false;
            else s++;
            if ((*s == ']') && (*--S.top != '['))return false;
            else s++;
        }
    }
    return true;
}
//答案                 ——也是用栈
char pair(char s)      //——使用函数返回值与栈顶元素比较，甚妙！使用指针的话，指针--自动出栈，不好比较
{
    if (s == ')')return '(';
    if (s == ']')return '[';
    if (s == '}')return '{';
    return 0;
}

bool isValid(char* s)
{
    if (!s)return false;
    int n = strlen(s);
    char* stk = (char*)malloc(sizeof(char) * 10000);
    if (n % 2 == 1)return false;
    int top = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        char ch = pair(s[i]);
        if (ch)
        {
            if (top == 0 || stk[top - 1] != ch)//——ch=0时执行else，说明输入了左括号，则top++，stk数组不会越界
                return false;
            top--;             //——出栈
        }
        else
        {
            stk[top++] = s[i]; //——入栈
        }
    }
    if (top != 0)       //——循环到最后一次时top应该等于0，top从0增大，再减小到0
        return false;
    return true;
}
//第21题 合并两个有序链表   ——看答案通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//超时
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* p = list1;
    struct ListNode* q = list2;
    struct ListNode* t;
    if (p && !q)return list1;
    else if (q && !p)return list2;
    else if (p && q)
    {
        if (p->val <= q->val)//对第一个结点单独处理
        {
            t = p;
            p = p->next;
            t = t->next;
        }
        else {
            t = q;
            q = q->next;
            t = t->next;
        }
        while (p && q)
        {
            if (p->val <= q->val)
            {
                t->next = p;
                p = p->next;
                t = t->next;
            }
            else
            {
                t->next = q;
                q = q->next;
                t = t->next;
            }
        }
        if (p && !q)t->next = p;
        else if (!p && q)t->next = q;
        return list1->val <= list2->val ? list1 : list2;
    }
    return NULL;
}

//递归      神奇，多多领会
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1)return list2;
    else if (!list2)return list1;
    else if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else if (list1->val > list2->val)
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    return NULL;
}

//第94题 二叉树的中序遍历            ——通过
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
void inorder(struct TreeNode* root, int* arr, int* res)    //——不太清楚什么时候写函数，一开始直接用下面的循环了。。。
{                                                          //——如果直接用下面的函数循环的话，函数参数中没有数组，无法存储
    if (!root || !arr || !res)return;
    inorder(root->left, arr, res);
    arr[(*res)++] = root->val;
    inorder(root->right, arr, res);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    //左根右
    int* arr = (int*)malloc(sizeof(int) * 100);                    //——写成int arr[100] = { 0 };无法通过
    *returnSize = 0;
    inorder(root, arr, returnSize);
    return arr;
}

//第26题 删除有序数组中的重复项          ——看答案后通过
// 
//int removeDuplicates(int* nums, int numsSize) {
//    int i = 0;
//    numsSize = 1;
//    int sz = sizeof(nums) / sizeof(nums[0]);
//    int pos = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        for (j = i + 1; j < sz; j++)
//        {
//            if (nums[i] != nums[j])break;//直到找到不相等的数
//        }
//        if (nums[i + 1] != nums[j]) {
//            nums[pos + 1] = nums[j];
//            i = j - 1;
//            numsSize++;
//            pos++;
//        }
//    }
//    return numsSize;
//}

int removeDuplicates(int* nums, int numsSize) {           //——我使用了3个指针，搞的很乱，实际上只需要两个
    int i = 1;
    int j = 1;
    if (numsSize == 0)return 0;
    while (j < numsSize)
    {
        if (nums[j] != nums[j - 1])                       //——找到不相等的元素则将其存放到慢指针处，放一个数，慢指针++
        {
            nums[i] = nums[j];
            i++;
        }
        j++;                                              //——不管放没放，快指针++
    }
    return i;
}
//第27题 移除元素                  ——通过
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;               //上一题因为要前后比较所以从1开始，这题则是从0开始
    int j = 0;
    while (j < numsSize)
    {
        if (nums[j] != val)
        {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return i;
}

//第28题 实现strStr()              
//——看笔记写的KMP，未通过
void getnextval(char* needle, int* nextval, int szn)
{
    int i = 1;
    nextval[1] = 0;
    int j = 0;
    while (i < szn)
    {
        if (j == 0 || needle[i] == needle[j]) {
            ++i; ++j;
            if (needle[i] != needle[j])nextval[i] = j;
            else nextval[i] = nextval[j];
        }
        else j = nextval[j];
    }
}

int strStr(char* haystack, char* needle) {
    if (!needle)return 0;
    //KMP
    int* nextval = (int*)malloc(sizeof(int) * 100);
    int szn = sizeof(needle) / sizeof(needle[0]);
    int szh = sizeof(haystack) / sizeof(haystack[0]);
    getnextval(needle, nextval, szn);
    int i = 0;
    int j = 0;
    while (i < szh && j < szn)
    {
        if (j == 0 || haystack[i] == needle[j])
        {
            i++;
            j++;
        }
        else j = nextval[j];
    }
    if (j >= szn)return i - szn;
    else return 0;
}
//暴力法，未通过
int strStr(char* haystack, char* needle) {
    //暴力法
    int slow = 0;
    int fast = 0;
    int n = sizeof(needle) / sizeof(needle[0]);
    int pos = 0;
    if (!needle)return 0;
    while (slow < n)
    {
        if (haystack[fast] == needle[slow])
        {
            fast++; slow++;
        }
        else
        {
            pos++;
            slow = 0;
            fast = pos;
        }
    }
    if (slow == n - 1)return pos;
    return -1;
}
//第35题 搜索插入位置           ——通过
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    if (target > nums[right])return numsSize;
    else if (target < nums[left])return 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)left = mid + 1;
        else if (nums[mid] > target)right = mid - 1;
        else return mid;
    }
    return left;
}