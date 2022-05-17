#define _CRT_SECURE_NO_WARNINGS

//441. 排列硬币             通过
int arrangeCoins(int n) {
    //x*(1+x)/2<=n的最大x
    int l = 1;
    int r = n;
    int ans;
    while (l <= r) {
        long long int mid = l + (r - l) / 2;
        if (mid * (mid + 1) / 2 <= n) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

//1539. 第 k 个缺失的正整数       
// 来自评论区的大佬题解
//1.缺失的正整数一定 >= k
//2.数组中每出现一个 <= k 的数字, 意味着少了一个缺失的数字, 此时k+1
int findKthPositive(int* arr, int arrSize, int k) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= k)k++;
    }
    return k;
}
//二分法搞不懂
