#define _CRT_SECURE_NO_WARNINGS

//53. 最大子数组和                   通过
int mymax(int a, int b) {
    return a > b ? a : b;
}

int maxSubArray(int* nums, int numsSize) {
    int dp[100001] = { 0 };
    dp[0] = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = mymax(dp[i - 1] + nums[i], nums[i]);
        max = mymax(max, dp[i]);
    }
    return max;
}

//217. 存在重复元素               通过
int cmp(int* e1, int* e2) {
    return *e1 - *e2;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, 4, cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1])return true;
    }
    return false;
}