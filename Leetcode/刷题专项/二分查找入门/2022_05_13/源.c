#define _CRT_SECURE_NO_WARNINGS

//35. 搜索插入位置          通过
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    return left;
}

//852. 山脉数组的峰顶索引           通过
int peakIndexInMountainArray(int* arr, int arrSize) {
    int left = 0;
    int right = arrSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}