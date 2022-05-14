#define _CRT_SECURE_NO_WARNINGS

//283. 移动零             通过               在0个数少时覆盖法更优，0个数多时交换法更优
//覆盖法，数0，最后补0
void moveZeroes(int* nums, int numsSize) {
    int count = 0;
    int p = 0;
    int q = numsSize - 1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            count++;
        }
    }
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[p] = nums[i];
            p++;
        }
    }
    for (int i = numsSize - count; i < numsSize; i++) {
        nums[i] = 0;
    }
}
//覆盖法优化，数覆盖次数
void moveZeroes(int* nums, int numsSize) {
    int count = 0;
    int p = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[p] = nums[i];
            p++;
            count++;
        }
    }
    for (int i = count; i < numsSize; i++) {
        nums[i] = 0;
    }
}
//交换法
void moveZeroes(int* nums, int numsSize) {
    int p = 0;
    int q = 0;
    if (numsSize == 1)return;
    while (q != numsSize && p <= q) {
        if (nums[q] == 0) {//q要找到非0
            q++;
        }
        if (nums[p] != 0) {//p要找到0
            p++; q++;
        }
        if (q == numsSize)return;
        if (nums[p] == 0 && nums[q] != 0) {
            nums[p] = nums[q];
            nums[q] = 0;
            p++;
            q++;
        }
    }
}


//167. 两数之和 II - 输入有序数组
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    //二分查找，确定一个数，对另一个数二分查找
    *returnSize = 2;
    int* ans = malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersSize; i++) {
        int x = numbers[i];
        int left = i + 1;
        int right = numbersSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (numbers[mid] > target - x)right = mid - 1;
            else if (numbers[mid] < target - x)left = mid + 1;
            else {
                ans[0] = i + 1;
                ans[1] = mid + 1;
                return ans;
            }
        }
    }
    ans[0] = -1;
    ans[1] = -1;
    return ans;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    //双指针 头尾相加，若比target大，则右指针左移，else左指针右移
    int p = 0;
    int q = numbersSize - 1;
    while (numbers[p] + numbers[q] != target) {//因为题目说必有唯一解，所以用此循环条件
        if (numbers[p] + numbers[q] > target)q--;
        else if (numbers[p] + numbers[q] < target)p++;
    }
    *returnSize = 2;
    int* ans = malloc(sizeof(int) * 2);
    ans[0] = p + 1;
    ans[1] = q + 1;
    return ans;
}