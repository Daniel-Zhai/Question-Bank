#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//leetcode

//14. �����ǰ׺     ͨ��
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

//19. ɾ������ĵ����� N �����      ͨ��
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


//28. ʵ�� strStr()           ͨ��
int strStr(char* haystack, char* needle) {
    //������
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

//67. ���������               ����ͨ��      �
void reverse(char* c) {//��ת      ����ת�Ļ��̵�ǰ�油0���Ӹ�λ��ӣ����λ��λ����ת�Ļ��ӵ�λ��ӣ����λ��λ
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
    int n = max(len_a, len_b);//�ϳ�����ĳ���
    reverse(a);//��ת
    reverse(b);
    char* c = malloc(sizeof(char) * (n + 2));//�п��ܽ�λ���������Ҫ\0��������n+2
    int carry = 0;//��λ
    int len = 0;//��������λ��
    int i = 0;
    for (i = 0; i < n; i++) {//ѭ���ϳ�����ĸ�����
        carry += i < len_a ? (a[i] == '1') : 0;//������i < len_a���ж����������������Ҫ�̵Ĳ�0
        carry += i < len_b ? (b[i] == '1') : 0;//��˼��û�������鳤�ȵ�ʱ���������������'1'����carry+=1
        c[len++] = carry % 2 + '0';//����������%2
        carry /= 2;//��һλ������һλ��
    }
    if (carry) {//��ѭ��n�κ�carry��Ϊ0��˵�������λ
        c[len++] = '1';
    }
    c[len] = '\0';//����ַ���������־
    reverse(c);//��ת
    return c;
}

//101. �Գƶ�����         
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//δͨ��
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
    //���Գƣ������Һ͸�������������ͬ
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
// ���Դ�
bool check(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q)return true;
    if (!p || !q)return false;
    return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);//return ���еݹ��ɧ����һ��Ҫѧ��
}
bool isSymmetric(struct TreeNode* root) {
    return check(root, root);
}

//104. ��������������            ����ͨ��
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
    //�ݹ�
    if (!root)return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

//108. ����������ת��Ϊ����������              ����ͨ��
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