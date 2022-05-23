#define _CRT_SECURE_NO_WARNINGS


//1337. 矩阵中战斗力最弱的 K 行         未通过示例[[1,1,1,1,1,1],[1,1,1,1,1,1],[1,1,1,1,1,1]] 1   heap buffer overflow
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    //对每行进行二分
    int arr[100] = { 0 };
    for (int i = 0; i < matSize; i++) {
        int l = 0;
        int r = *matColSize - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (mat[i][mid] == 1)l = mid + 1;
            else r = mid - 1;
        }
        arr[i] = l;
    }
    *returnSize = k;
    int* ans = malloc(sizeof(int) * k);
    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < k; i++) {
        ans[i] = 0;
        int min = arr[0];
        for (int j = 1; j < matSize; j++) {
            if (arr[j] < min) {
                min = arr[j];
                ans[i] = j;
            }
        }
        arr[ans[i]] = 101;
    }
    return ans;
}


//1346. 检查整数及其两倍数是否存在       未通过
int cmp(int* e1, int* e2) {
    return *e1 - *e2;
}

bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, 4, cmp);
    if (arr[0] >= 0) {
        for (int i = 0; i < arrSize - 1; i++) {
            int l = i + 1;
            int r = arrSize - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[i] * 2 < arr[mid])r = mid - 1;
                else if (arr[i] * 2 > arr[mid])l = mid + 1;
                else return true;
            }
        }
    }
    else {//存在负数，需要分别判断
        int l = 0;
        int r = arrSize - 1;
        int pos = arrSize;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= 0) {
                pos = mid;//pos是第一个正数的下标，arr有pos个负数，arrsize-pos个正数
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        //然后分别判断正数和负数部分
        for (int i = pos - 1; i >= 1; i--) {//负数部分
            l = 0;
            r = i - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[i] * 2 < arr[mid])l = mid + 1;
                else if (arr[i] * 2 > arr[mid])r = mid - 1;
                else return true;
            }
        }
        if (pos == arrSize)return false;
        for (int i = pos; i < arrSize - 1; i++) {//正数部分
            l = i + 1;
            r = arrSize - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[i] * 2 < arr[mid])r = mid - 1;
                else if (arr[i] * 2 > arr[mid])l = mid + 1;
                else return true;
            }
        }
    }
    return false;
}