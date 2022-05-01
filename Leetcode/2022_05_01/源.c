#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//leetcode
//��20�� ��Ч������                 ��������ͨ����ʹ��ջ��һ��Ҫ����һ��ջ���ͣ������±�Ӽ�һ������
// 
// �Լ�д��
//runtime error: store to null pointer of type 'char'
typedef struct {
    char* base;
    char* top;
    int stacksize;
}Sqstack;//ջ

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
//��                 ����Ҳ����ջ
char pair(char s)      //����ʹ�ú�������ֵ��ջ��Ԫ�رȽϣ����ʹ��ָ��Ļ���ָ��--�Զ���ջ�����ñȽ�
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
            if (top == 0 || stk[top - 1] != ch)//����ch=0ʱִ��else��˵�������������ţ���top++��stk���鲻��Խ��
                return false;
            top--;             //������ջ
        }
        else
        {
            stk[top++] = s[i]; //������ջ
        }
    }
    if (top != 0)       //����ѭ�������һ��ʱtopӦ�õ���0��top��0�����ټ�С��0
        return false;
    return true;
}
//��21�� �ϲ�������������   ��������ͨ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//��ʱ
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* p = list1;
    struct ListNode* q = list2;
    struct ListNode* t;
    if (p && !q)return list1;
    else if (q && !p)return list2;
    else if (p && q)
    {
        if (p->val <= q->val)//�Ե�һ����㵥������
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

//�ݹ�      ���棬������
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

//��94�� ���������������            ����ͨ��
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
void inorder(struct TreeNode* root, int* arr, int* res)    //������̫���ʲôʱ��д������һ��ʼֱ���������ѭ���ˡ�����
{                                                          //�������ֱ��������ĺ���ѭ���Ļ�������������û�����飬�޷��洢
    if (!root || !arr || !res)return;
    inorder(root->left, arr, res);
    arr[(*res)++] = root->val;
    inorder(root->right, arr, res);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    //�����
    int* arr = (int*)malloc(sizeof(int) * 100);                    //����д��int arr[100] = { 0 };�޷�ͨ��
    *returnSize = 0;
    inorder(root, arr, returnSize);
    return arr;
}

//��26�� ɾ�����������е��ظ���          �������𰸺�ͨ��
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
//            if (nums[i] != nums[j])break;//ֱ���ҵ�����ȵ���
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

int removeDuplicates(int* nums, int numsSize) {           //������ʹ����3��ָ�룬��ĺ��ң�ʵ����ֻ��Ҫ����
    int i = 1;
    int j = 1;
    if (numsSize == 0)return 0;
    while (j < numsSize)
    {
        if (nums[j] != nums[j - 1])                       //�����ҵ�����ȵ�Ԫ�������ŵ���ָ�봦����һ��������ָ��++
        {
            nums[i] = nums[j];
            i++;
        }
        j++;                                              //�������ܷ�û�ţ���ָ��++
    }
    return i;
}
//��27�� �Ƴ�Ԫ��                  ����ͨ��
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;               //��һ����ΪҪǰ��Ƚ����Դ�1��ʼ���������Ǵ�0��ʼ
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

//��28�� ʵ��strStr()              
//�������ʼ�д��KMP��δͨ��
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
//��������δͨ��
int strStr(char* haystack, char* needle) {
    //������
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
//��35�� ��������λ��           ����ͨ��
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