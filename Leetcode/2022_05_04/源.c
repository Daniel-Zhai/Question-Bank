#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//3. ���ظ��ַ�����Ӵ�         δͨ��
int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
    int l = 0;
    int r = 1;
    int i = 0;
    int maxsize = 0;
    //������
    if (!s)return 0;
    if (len == 1)return 1;
    while (r < len) {
        for (i = l; i < r - l; i++) {
            if (s[r] == s[i]) {
                maxsize = r - l;
                l++;
                r = l + 1;
                break;
            }
        }
        if (i == r - l) {
            maxsize++;
            r++;
        }
    }
    if (len == 2 && s[0] != s[1])return 2;
    return maxsize;
}

//125. ��֤���Ĵ�         δͨ������  "0P"
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    if (right == 0)return true;
    while (left <= right) {
        while (!isupper(s[left]) && !islower(s[left]) && left <= right) {
            left++;
            if (left == strlen(s))return true;
        }
        while (!isupper(s[right]) && !islower(s[right]) && left <= right) {
            right--;
        }
        if (isupper(s[left])) {
            s[left] = tolower(s[left]);
        }
        if (isupper(s[right])) {
            s[right] = tolower(s[right]);
        }
        if (s[left] == s[right]) {
            left++; right--;
        }
        else if (s[left] != s[right]) {
            return false;
        }
    }
    return true;
}

//136. ֻ����һ�ε�����         ͨ��
int singleNumber(int* nums, int numsSize) {
    //a^a = 0;   a^0 = a;
    //�����ҳ����������ε�Ԫ�أ�����ֻ�г���һ�������ιʿ���ʹ��
    int i = 0;
    int num = 0;
    for (i = 0; i < numsSize; i++) {
        num = num ^ nums[i];
    }
    return num;
}

//144. ��������ǰ�����      ����ͨ��
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
void preorder(struct TreeNode* root, int* arr, int* arrsize) {
    if (!root)return;
    arr[(*arrsize)++] = root->val;//��������
    preorder(root->left, arr, arrsize);
    preorder(root->right, arr, arrsize);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 2000);
    *returnSize = 0;
    if (!root)return NULL;
    preorder(root, arr, returnSize);
    return arr;
}

//145. �������ĺ������            ͨ��
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

void postorder(struct TreeNode* root, int* arr, int* arrsize) {
    if (!root)return;
    postorder(root->left, arr, arrsize);
    postorder(root->right, arr, arrsize);
    arr[(*arrsize)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;
    if (!root)return NULL;
    postorder(root, arr, returnSize);
    return arr;
}

//169. ����Ԫ��          ͨ��
int cmp(const int* e1, const int* e2) {
    return *(e1)-*(e2);
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, 4, cmp);
    return nums[numsSize / 2];
}
