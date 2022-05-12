#define _CRT_SECURE_NO_WARNINGS
//复习

//1.两数之和
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;
    int* arr = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target - nums[i] == nums[j]) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
            }
        }
    }
    return arr;
}

//2. 两数相加
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
        int sum = n1 + n2 + carry;
        if (!new) {
            new = malloc(sizeof(struct ListNode));
            new->val = sum % 10;
            new->next = NULL;
            tail = new;
        }
        else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
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

//9. 回文数                       通过
bool isPalindrome(int x) {
    int i = 1;
    int tmp = x;
    if (x < 0)return false;
    while (tmp > 9) {
        i *= 10;
        tmp /= 10;
    }
    if (x <= 9)return true;
    while (x) {
        if (x / i != x % 10)return false;
        x %= i;
        x /= 10;
        i /= 100;
    }
    return true;
}

//13. 罗马数字转整数              通过
int romanToInt(char* s) {
    int* arr = malloc(sizeof(int) * 26);
    arr['I' - 'A'] = 1;
    arr['V' - 'A'] = 5;
    arr['X' - 'A'] = 10;
    arr['L' - 'A'] = 50;
    arr['C' - 'A'] = 100;
    arr['D' - 'A'] = 500;
    arr['M' - 'A'] = 1000;
    int num = 0;
    int str = strlen(s);
    for (int i = 0; i < str - 1; i++) {
        if (arr[s[i] - 'A'] >= arr[s[i + 1] - 'A']) {
            num += arr[s[i] - 'A'];
        }
        else {
            num -= arr[s[i] - 'A'];
        }
    }
    num += arr[s[str - 1] - 'A'];
    return num;
}

//14. 最长公共前缀          通过
char* longestCommonPrefix(char** strs, int strsSize) {
    char* arr = strs[0];
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (arr[j] != '\0' && *strs[i] != '\0') {
            if (arr[j] == strs[i][j]) {
                j++;
            }
            else {
                break;
            }
        }
        arr[j] = '\0';
    }
    return arr;
}

//19. 删除链表的倒数第 N 个结点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    //找前驱
    struct ListNode* pre = malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode* tmp = NULL;
    while (1) {
        tmp = pre;
        for (int i = 0; i < n; i++) {
            tmp = tmp->next;
        }
        if (tmp->next == NULL)break;
        else pre = pre->next;
    }
    if (pre->next == head)head = head->next;
    tmp = pre->next;
    pre->next = tmp->next;
    free(tmp);
    return head;
}

//20. 有效的括号                   通过
char couple(char a) {
    if (a == ')')return '(';
    if (a == ']')return '[';
    if (a == '}')return '{';
    return 0;
}

bool isValid(char* s) {
    int str = strlen(s);
    if (str % 2 == 1)return false;
    char* arr = malloc(sizeof(char) * str);
    memset(arr, '0', str);
    int i = 0;
    int top = 0;
    for (i = 0; i < str; i++) {
        char a = couple(s[i]);
        if (!a) {
            arr[top] = s[i];
            top++;
        }
        else {
            if (top == 0 || a != arr[top - 1])return false;
            top--;
        }
    }
    if (top == 0)
        return true;
    return false;
}

//21. 合并两个有序链表               通过
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1 && !list2)return NULL;
    else if (!list1)return list2;
    else if (!list2)return list1;
    else {
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
    return NULL;
}