#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//189. 轮转数组                   通过
//O(1)
//1 2 3 4 5 6 7      K=3
//7 6 5 4 3 2 1
//5 6 7 1 2 3 4
int* Reverse(int* nums, int left, int right) {
    while (left <= right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
    return nums;
}

void rotate(int* nums, int numsSize, int k) {
    int tmp = 0;
    int i = 0;
    if (k % numsSize == 0)return nums;
    nums = Reverse(nums, 0, numsSize - 1);
    nums = Reverse(nums, 0, (k - 1) % numsSize);
    nums = Reverse(nums, k % numsSize, numsSize - 1);
    return nums;
}

//977. 有序数组的平方            通过
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(int* e1, int* e2) {
    return *e1 - *e2;
}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        nums[i] = pow(nums[i], 2);
    }
    qsort(nums, numsSize, 4, cmp);
    *returnSize = numsSize;
    return nums;
}

//优化 到O(n)
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* arr = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int i = 0;
    int j = numsSize - 1;
    int pos = numsSize - 1;
    while (i <= j) {
        if (nums[i] * nums[i] > nums[j] * nums[j]) {
            arr[pos] = nums[i] * nums[i];
            i++;
        }
        else {
            arr[pos] = nums[j] * nums[j];
            j--;
        }
        pos--;
    }
    return arr;
}