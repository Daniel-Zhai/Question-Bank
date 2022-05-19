#define _CRT_SECURE_NO_WARNINGS

//167. 两数之和 II - 输入有序数组           通过
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    //二分
    *returnSize = 2;
    int* ans = malloc(sizeof(int) * 2);

    for (int i = 0; i < numbersSize; i++) {
        int x = numbers[i];
        int l = i + 1;
        int r = numbersSize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (numbers[mid] > target - x)r = mid - 1;
            else if (numbers[mid] < target - x)l = mid + 1;
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

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    //双指针
    int p = 0;
    int q = numbersSize - 1;
    while (numbers[p] + numbers[q] != target) {
        if (numbers[p] + numbers[q] > target) {
            q--;
        }
        else if (numbers[p] + numbers[q] < target) {
            p++;
        }
    }
    *returnSize = 2;
    int* ans = malloc(sizeof(int) * 2);
    ans[0] = p + 1;
    ans[1] = q + 1;
    return ans;
}

//1608. 特殊数组的特征值                通过
int cmp(int* e1, int* e2) {
    return *e1 - *e2;
}

int specialArray(int* nums, int numsSize) {//暴力法
    qsort(nums, numsSize, 4, cmp);
    int x = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= x) {
            if (i > 0 && nums[i - 1] >= x)x--;
            else return x;
        }
        else {
            x--;
        }
    }
    return -1;
}
