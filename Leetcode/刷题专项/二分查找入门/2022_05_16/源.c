#define _CRT_SECURE_NO_WARNINGS

//278. 第一个错误的版本              通过
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (isBadVersion(mid))right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

//34. 在排序数组中查找元素的第一个和最后一个位置            通过
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int search(int* nums, int numsSize, int target) {//search是一个查找大于等于x的最小下标的函数
    int left = 0;
    int right = numsSize - 1;
    int ret = numsSize;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            ret = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return ret;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = malloc(sizeof(int) * 2);
    int ret = search(nums, numsSize, target);
    *returnSize = 2;
    if (ret != numsSize && nums[ret] == target) {
        ans[0] = ret;
        int ret1 = search(nums, numsSize, target + 1);
        ans[1] = ret1 - 1;
        if (ret1 == 0)ans[1] = 0;
    }
    else {
        ans[0] = ans[1] = -1;
    }
    return ans;
}