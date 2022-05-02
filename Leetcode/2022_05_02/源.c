#define _CRT_SECURE_NO_WARNINGS

//leetcode
//��53�� ����������          ��������ͨ��
int maxSubArray(int* nums, int numsSize) {
    int i = 1;//��������ʼ��
    int dp[100001] = { 0 };
    dp[0] = nums[0];
    int maxval = nums[0];
    for (i = 1; i < numsSize; i++)//
    {
        dp[i] = dp[i - 1] + nums[i] > nums[i] ? dp[i - 1] + nums[i] : nums[i];
        maxval = maxval > dp[i] ? maxval : dp[i];
    }
    return maxval;
}

//58. ���һ�����ʵĳ���    ����ͨ��
int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int i = 0;
    int count = 0;
    for (i = len - 1; i >= 0; i--) {
        if (s[i] != ' ')count++;
        if (count != 0 && s[i] == ' ')break;
    }
    return count;
}

//66. ��һ                  ����ȡֵ��δͨ������һ��λ��ͨ��
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //��1ȡֵ
    /*int i = 0;
    int num = 0;
    for(i=0;i<digitsSize;i++)
    {
        num += digits[i]*pow(10,digitsSize-i-1);
    }
    num+=1;
    int n = 0;//λ��
    if(num/pow(10,digitsSize-1)==1)n = digitsSize;
    else n = digitsSize+1; //��λλ����1
    int* nums = (int*)malloc(sizeof(int)*n);
    for(i=n-1;i>=0;i--)
    {
        nums[i] = num%10;
        num/=10;
    }
    return nums;*/
    //��2�ҵ����һλ��һ�����ǽ�λ
    int i = 0;
    digits[digitsSize - 1] += 1;
    for (i = 1; i < digitsSize; i++)
    {
        if (digits[digitsSize - i] == 10) {
            digits[digitsSize - i] = 0;
            digits[digitsSize - 1 - i] += 1;
        }
        else {
            break;
        }
    }
    if (digits[0] == 10)
    {
        *returnSize = digitsSize + 1;
        int* nums = (int*)malloc(sizeof(int) * (digitsSize + 1));//�½�����
        for (i = 1; i < digitsSize + 1; i++)
        {
            nums[i] = 0;
        }
        //memset(nums,0,digitsSize+1);            forѭ����ֵ0ͨ����memsetδͨ����Ϊ�Σ�
        nums[0] = 1;
        return nums;
    }
    *returnSize = digitsSize;
    return digits;
}

//69. x ��ƽ����       ����ͨ��
int mySqrt(int x) {
    return (int)sqrt(x);
}

//70. ��¥��      ����ͨ��
int climbStairs(int n) {
    //쳲�����
    int i = 0;
    int Fib[46] = { 1,1 };
    for (i = 2; i <= n; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    return Fib[n];
}

//83. ɾ�����������е��ظ�Ԫ��        ����ͨ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head)return NULL;
    struct ListNode* p = head;
    struct ListNode* q = p;

    while (p && p->next) {
        if (p->val == p->next->val) {
            q = p->next;
            p->next = p->next->next;
            free(q);
        }
        else {//ֻ�в���Ȳ�Ų��p
            p = p->next;
        }
    }
    q = NULL;
    return head;
}

//88. �ϲ�������������      �������𰸺�ͨ��
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //����˫ָ��
    int p1 = m - 1;
    int p2 = n - 1;
    int i = 1;
    int cur = 0;
    while (p2 >= 0 || p1 >= 0) {//p1��p2Ϊ-1ʱҲ����ѭ��
        if (p1 == -1) {
            cur = nums2[p2--];
        }
        else if (p2 == -1) {
            cur = nums1[p1--];
        }
        else if (nums1[p1] <= nums2[p2]) {
            cur = nums2[p2--];
        }
        else {
            cur = nums1[p1--];
        }
        nums1[m + n - i] = cur;
        i++;
    }
}

//100. ��ͬ����           ����δͨ��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int isSame(struct TreeNode* p, struct TreeNode* q) {
    if (!p && q || p && !q)return 0;
    if (p && q && p->val != q->val)return 0;
    if (p->left || q->left) {
        return isSame(p->left, q->left);
    }
    if (p->right || q->right) {
        return isSame(p->right, q->right);
    }
    return 1;
}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    int ans = isSame(p, q);
    if (ans == 1)return true;
    return false;
}