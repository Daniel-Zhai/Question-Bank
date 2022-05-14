#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//367. 有效的完全平方数               通过          
bool isPerfectSquare(int num) {
    long long int left = 1;//int会溢出
    long long int right = num / 2;
    if (num == 1)return true;
    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        if (mid * mid < num)left = mid + 1;
        else if (mid * mid > num)right = mid - 1;
        else return true;
    }
    return false;
}


//1385. 两个数组间的距离值                    通过
//暴力
int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    int sub = 0;
    int j = 0;
    int count = 0;
    for (int i = 0; i < arr1Size; i++) {
        for (j = 0; j < arr2Size; j++) {
            sub = arr1[i] - arr2[j];
            if (sub < 0)sub = -sub;
            if (sub <= d)break;
        }
        if (j == arr2Size)count++;
    }
    return count;
}
//二分
int cmp(int* e1, int* e2) {
    return *e1 - *e2;
}

int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
    qsort(arr2, arr2Size, 4, cmp);
    int count = 0;
    for (int i = 0; i < arr1Size; i++) {
        int left = 0;
        int right = arr2Size - 1;
        if (arr1[i] < arr2[0]) {
            if (arr2[0] - arr1[i] > d) {
                count++;
                continue;
            }
        }
        if (arr1[i] > arr2[arr2Size - 1]) {
            if (arr1[i] - arr2[arr2Size - 1] > d) {
                count++;
                continue;
            }
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr1[i] < arr2[mid])right = mid - 1;
            else if (arr1[i] > arr2[mid])left = mid + 1;
            else break;
        }
        if (left > right && left < arr2Size && right >= 0) {
            if (arr1[i] - arr2[right] > d && arr2[left] - arr1[i] > d)count++;
        }
    }
    return count;
}