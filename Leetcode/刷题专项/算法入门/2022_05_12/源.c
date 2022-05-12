#define _CRT_SECURE_NO_WARNINGS

//278. ��һ������İ汾             ͨ��
//���ֲ���
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

//35. ��������λ��                  ͨ��
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] > target)right = mid - 1;
        else if (nums[mid] < target)left = mid + 1;
        else return mid;
    }
    return left;
}

//704. ���ֲ���                     ͨ��
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] > target)right = mid - 1;
        else if (nums[mid] < target)left = mid + 1;
        else return mid;
    }
    return -1;
}