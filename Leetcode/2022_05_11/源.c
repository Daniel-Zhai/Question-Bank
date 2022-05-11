#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//119. 杨辉三角 II          使用一个数组，注意从后向前加，避免覆盖
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* num = malloc(sizeof(int) * (*returnSize));
    memset(num, 0, sizeof(int) * (*returnSize));
    num[0] = 1;
    for (int i = 1; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            num[j] = num[j - 1] + num[j];
        }
    }
    return num;
}

//121. 买卖股票的最佳时机              未通过    
int maxProfit(int* prices, int pricesSize) {
    int buy = 0;
    int sell = pricesSize - 1;
    int max = 0;
    while (buy < sell) {
        if (buy + 1 == pricesSize || sell - 1 == -1)break;
        buy = prices[buy + 1] <= prices[buy] ? buy + 1 : buy;
        sell = prices[sell - 1] >= prices[sell] ? sell - 1 : sell;
        if (prices[sell] - prices[buy] > max && sell > buy)max = prices[sell] - prices[buy];
        if (buy + 1 == pricesSize || sell - 1 == -1)break;
        if (prices[buy + 1] > prices[buy] && prices[sell - 1] < prices[sell]) {
            if ((prices[buy + 1] - prices[buy]) > (prices[sell] - prices[sell - 1])) {
                sell = sell - 1;
            }
            else {
                buy = buy + 1;
            }
        }
    }
    return max;
}

//217. 存在重复元素                    通过
int cmp(const int* e1, const int* e2)
{
    return *e1 - *e2;
}
bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int i = 0;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1])return true;
    }
    return false;
}

//2264. 字符串中最大的 3 位相同数字
char* largestGoodInteger(char* num) {
    char a[1000] = { 0 };
    char max = 0;
    int n = strlen(num);
    int i = 0;
    int j = 0;
    if (n < 3)return "";
    for (i = 0; i <= n - 3; i++) {
        if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
            a[j++] = num[i];
            i += 2;
        }
    }
    max = a[0];
    i = 1;
    while (a[i]) {
        if (a[i] - '0' > max - '0')max = a[i];
        i++;
    }
    for (i = 0; i < 3; i++) {
        a[i] = max;
    }
    a[3] = '\0';
    return a;
}

int main()
{
    char* num = "6777133339";
    char* n = largestGoodInteger(num);
    printf("%s", n);
    return 0;
}

