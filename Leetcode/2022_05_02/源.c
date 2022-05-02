#define _CRT_SECURE_NO_WARNINGS

//leetcode
//第53题 最大子数组和          ——看答案通过
int maxSubArray(int* nums, int numsSize) {
    int i = 1;//子数组起始点
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

//58. 最后一个单词的长度    ——通过
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

//66. 加一                  ——取值法未通过，加一进位法通过
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //法1取值
    /*int i = 0;
    int num = 0;
    for(i=0;i<digitsSize;i++)
    {
        num += digits[i]*pow(10,digitsSize-i-1);
    }
    num+=1;
    int n = 0;//位数
    if(num/pow(10,digitsSize-1)==1)n = digitsSize;
    else n = digitsSize+1; //进位位数加1
    int* nums = (int*)malloc(sizeof(int)*n);
    for(i=n-1;i>=0;i--)
    {
        nums[i] = num%10;
        num/=10;
    }
    return nums;*/
    //法2找到最后一位加一，考虑进位
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
        int* nums = (int*)malloc(sizeof(int) * (digitsSize + 1));//新建数组
        for (i = 1; i < digitsSize + 1; i++)
        {
            nums[i] = 0;
        }
        //memset(nums,0,digitsSize+1);            for循环赋值0通过，memset未通过，为何？
        nums[0] = 1;
        return nums;
    }
    *returnSize = digitsSize;
    return digits;
}

//69. x 的平方根       ——通过
int mySqrt(int x) {
    return (int)sqrt(x);
}

//70. 爬楼梯      ——通过
int climbStairs(int n) {
    //斐波那契
    int i = 0;
    int Fib[46] = { 1,1 };
    for (i = 2; i <= n; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    return Fib[n];
}

//83. 删除排序链表中的重复元素        ——通过
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
        else {//只有不相等才挪动p
            p = p->next;
        }
    }
    q = NULL;
    return head;
}

//88. 合并两个有序数组      ——看答案后通过
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    //逆向双指针
    int p1 = m - 1;
    int p2 = n - 1;
    int i = 1;
    int cur = 0;
    while (p2 >= 0 || p1 >= 0) {//p1、p2为-1时也进入循环
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

//100. 相同的树           ——未通过
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