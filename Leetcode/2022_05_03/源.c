#define _CRT_SECURE_NO_WARNINGS
//leetcode
//13. ��������ת����                ����ͨ����ֻ��˵���ϣ����̫��д
int romanToInt(char* s) {
    int n = strlen(s);
    int val = 0;
    int sum = 0;
    int i = 0;
    int* table = (int*)malloc(sizeof(int) * 26);
    table['I' - 'A'] = 1;
    table['V' - 'A'] = 5;
    table['X' - 'A'] = 10;
    table['L' - 'A'] = 50;
    table['C' - 'A'] = 100;
    table['D' - 'A'] = 500;
    table['M' - 'A'] = 1000;
    for (i = 0; i < n; i++) {
        val = table[s[i] - 'A'];
        if (i < n - 1 && val < table[s[i + 1] - 'A']) {
            sum -= val;
        }
        else {
            sum += val;
        }
    }
    return sum;
}

//100. ��ͬ����     ����ͨ��
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    else if (!p || !q) {
        return false;
    }
    else if (p->val != q->val) {
        return false;
    }
    else {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//Ϊʲô�������ᱨ���ʿ�ָ��Ĵ���
    }                                                                         //����Ϊ�������Դ�NULL��
}

//121. ������Ʊ�����ʱ��
//��������ʱδͨ��
int maxProfit(int* prices, int pricesSize) {
    int Profit = 0;
    int max = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < pricesSize; i++) {
        for (j = i + 1; j < pricesSize; j++) {
            Profit = prices[j] - prices[i];
            if (max < Profit)max = Profit;
        }
    }
    return max;
}


//206. ��ת����  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
         
//����������ͨ��
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* next = head;
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
//�ݹ鷨ͨ��
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* new_head = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

//ͷ�巨ͨ��
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* new_head = NULL;
    struct ListNode* temp = NULL;
    while (head) {
        temp = head;
        head = head->next;
        temp->next = new_head;
        new_head = temp;
    }
    return new_head;
}

//�͵����÷�ͨ��
struct ListNode* reverseList(struct ListNode* head) {
    if (!head || !head->next)return head;
    struct ListNode* beg = head;
    struct ListNode* end = head->next;
    while (end) {
        beg->next = end->next;
        end->next = head;
        head = end;
        end = beg->next;
    }
    return head;
}