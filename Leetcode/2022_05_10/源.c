#define _CRT_SECURE_NO_WARNINGS
//leetcode

//2. 两数相加              通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* new = NULL;
    struct ListNode* tail = NULL;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        if (!new) {
            new = malloc(sizeof(struct ListNode));
            new->val = (n1 + n2 + carry) % 10;
            tail = new;
            tail->next = NULL;
        }
        else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = (n1 + n2 + carry) % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = (n1 + n2 + carry) / 10;
        if (l1)l1 = l1->next;
        if (l2)l2 = l2->next;
    }
    if (carry) {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return new;
}

//112. 路径总和              通过
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root)return false;
    if (!root->left && !root->right)return targetSum == root->val;
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}

//125. 验证回文串                通过
bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    if (right == 0)return true;
    while (left < right) {
        while (!isalnum(s[left]) && (s[left] < '0' || s[left]>'9')) {
            left++;
            if (left == strlen(s))return true;
        }
        while (!isalnum(s[right]) && (s[right] < '0' || s[right]>'9')) {
            right--;
        }
        if (isupper(s[left])) {
            s[left] = tolower(s[left]);
        }
        if (isupper(s[right])) {
            s[right] = tolower(s[right]);
        }
        if (s[left] == s[right]) {
            if (left == right)return true;
            left++; right--;
        }
        else {
            return false;
        }
    }
    //if(left==right)return true;
    return true;
}