#define _CRT_SECURE_NO_WARNINGS

//1. 两数之和                   通过
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* ans = malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++) {
        int x = target - nums[i];
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == x) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    ans[0] = -1;
    ans[1] = -1;
    return ans;
}

//88. 合并两个有序数组        通过
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p = m - 1;
    int q = n - 1;
    int i = 1;
    while (p >= 0 && q >= 0) {
        if (nums1[p] <= nums2[q]) {
            nums1[nums1Size - i] = nums2[q--];
            i++;
        }
        else {
            nums1[nums1Size - i] = nums1[p--];
            i++;
        }
    }
    while (q >= 0) {
        nums1[q] = nums2[q];
        q--;
    }
}