#define _CRT_SECURE_NO_WARNINGS

//67. 二进制求和               通过
void reverse(char* c) {
    int p = 0;
    int q = strlen(c) - 1;
    while (p < q) {
        char tmp = c[p];
        c[p] = c[q];
        c[q] = tmp;
        p++; q--;
    }
}
char* addBinary(char* a, char* b) {
    reverse(a);
    reverse(b);
    int carry = 0;
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i = 0;
    int len = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
    char* c = malloc(sizeof(char) * (len + 2));
    for (i = 0; i < len; i++) {
        carry += i < len_a ? (a[i] == '1') : 0;
        carry += i < len_b ? (b[i] == '1') : 0;
        c[i] = carry % 2 + '0';
        carry /= 2;
    }
    if (carry)c[i++] = carry + '0';
    c[i] = '\0';
    reverse(c);
    return c;
}

//69. x 的平方根                     通过
int mySqrt(int x) {
    //二分
    int left = 1;
    int right = x / 2;
    if (x == 1)return 1;
    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        if (mid * mid > x)right = mid - 1;
        else if (mid * mid < x)left = mid + 1;
        else return mid;
    }
    return right;
}

//70. 爬楼梯              通过
int climbStairs(int n) {
    if (n == 1)return 1;
    if (n == 2)return 2;
    int* ans = malloc(sizeof(int) * 45);
    ans[0] = 1;
    ans[1] = 2;
    int i = 0;
    for (int i = 2; i < n; i++) {
        ans[i] = ans[i - 1] + ans[i - 2];
    }
    return ans[n - 1];
}

//83. 删除排序链表中的重复元素
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
        else {
            p = p->next;
        }
    }
    q = NULL;
    return head;
}