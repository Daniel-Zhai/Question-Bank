#define _CRT_SECURE_NO_WARNINGS
//leetcode

//374. �����ִ�С          ͨ��         
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n) {
    int ret = 0;
    int mid = 0;
    int left = 1;
    int right = n;
    while (left <= right) {
        mid = left + (right - left) / 2;//ע��(left+right)/2�ᵼ��mid���
        ret = guess(mid);
        if (ret == -1) {//�´���
            right = mid - 1;
        }
        else if (ret == 1) {//��С��
            left = mid + 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

//704. ���ֲ���         ͨ��
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] > target)right = mid - 1;
        else if (nums[mid] < target)left = mid + 1;
        else return mid;
    }
    return -1;
}