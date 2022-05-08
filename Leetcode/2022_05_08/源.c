#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//leetcode

//14. 最长公共前缀     通过
char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strs)return NULL;
    char* arr = strs[0];
    int n = 1;
    int i = 0;
    for (i = 1; i < strsSize; i++) {
        int j = 0;
        while (*strs[i] && arr[j]) {
            if (*strs[i] == arr[j]) {
                j++;
                *strs[i]++;
            }
            else {
                break;
            }
        }
        arr[j] = '\0';
    }
    return arr;
}

//19. 删除链表的倒数第 N 个结点      通过
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
            if (!tmp)return p->next;
            tmp = tmp->next;
        }
        if (!tmp)return p->next;
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


//28. 实现 strStr()           通过
int strStr(char* haystack, char* needle) {
    //暴力法
    int slow = 0;
    int fast = 0;
    int nn = strlen(needle);
    int nh = strlen(haystack);
    int pos = 0;
    if (!needle)return 0;
    while (pos <= nh - nn && slow < nn)
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
    if (slow == nn)return pos;
    return -1;
}

//67. 二进制求和               看答案通过      妙啊
void reverse(char* c) {//反转      不反转的话短的前面补0，从高位相加，向低位进位；反转的话从低位相加，向高位进位
    int len = strlen(c);
    int i = 0;
    for (i = 0; i < len / 2; i++) {
        int tmp = c[i];
        c[i] = c[len - 1 - i];
        c[len - 1 - i] = tmp;
    }
}
int max(int a, int b) {
    return a > b ? a : b;
}
char* addBinary(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int n = max(len_a, len_b);//较长数组的长度
    reverse(a);//反转
    reverse(b);
    char* c = malloc(sizeof(char) * (n + 2));//有可能进位，而且最后要\0，所以是n+2
    int carry = 0;//进位
    int len = 0;//新数组中位置
    int i = 0;
    for (i = 0; i < n; i++) {//循环较长数组的个数次
        carry += i < len_a ? (a[i] == '1') : 0;//这里用i < len_a作判断条件甚妙，甚至不需要短的补0
        carry += i < len_b ? (b[i] == '1') : 0;//意思是没超出数组长度的时候正常处理，如果是'1'，则carry+=1
        c[len++] = carry % 2 + '0';//二进制所以%2
        carry /= 2;//这一位进给下一位的
    }
    if (carry) {//若循环n次后carry不为0，说明还需进位
        c[len++] = '1';
    }
    c[len] = '\0';//最后补字符串结束标志
    reverse(c);//反转
    return c;
}

//101. 对称二叉树         
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//未通过
int* traverseLR(struct TreeNode* root, int* arr1, int n) {
    if (!root) {
        arr1[n++] = 0;
        return arr1;
    }
    arr1[n++] = root->val;
    traverseLR(root->left, arr1, n);
    traverseLR(root->right, arr1, n);
    return arr1;
}

int* traverseRL(struct TreeNode* root, int* arr2, int n) {
    if (!root) {
        arr2[n++] = 0;
        return arr2;
    }
    arr2[n++] = root->val;
    traverseRL(root->right, arr2, n);
    traverseRL(root->left, arr2, n);
    return arr2;
}

bool isSymmetric(struct TreeNode* root) {
    //若对称，根左右和根右左遍历结果相同
    int* arr1 = malloc(sizeof(int) * 1000);
    int* arr2 = malloc(sizeof(int) * 1000);
    traverseLR(root, arr1, 0);
    traverseRL(root, arr2, 0);
    int i = 0;
    while (arr1 && arr2) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
        i++;
    }
    return true;
}
// 来自答案
bool check(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)return true;
    if (!p || !q)return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);//return 进行递归的骚操作一定要学会
}
bool isSymmetric(struct TreeNode* root) {
    return check(root, root);
}

//104. 二叉树的最大深度            看答案通过
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth(struct TreeNode* root) {
    //递归
    if (!root)return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//108. 将有序数组转换为二叉搜索树              看答案通过
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* Turntotree(int* nums, int left, int right) {
    if (left > right)return NULL;
    int mid = (left + right) / 2;
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = Turntotree(nums, left, mid - 1);
    root->right = Turntotree(nums, mid + 1, right);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return Turntotree(nums, 0, numsSize - 1);
}