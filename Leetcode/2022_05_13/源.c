#define _CRT_SECURE_NO_WARNINGS
//leetcode

//26. ɾ�����������е��ظ���              ͨ��
int removeDuplicates(int* nums, int numsSize) {
    int left = 1;
    int right = 1;
    int i = 0;
    if (numsSize == 0)return 0;
    while (right < numsSize) {
        if (nums[right] != nums[right - 1]) {//���Լ���ǰһλ��
            nums[left] = nums[right];
            left++;
        }
        right++;
    }
    return left;
}

int removeDuplicates(int* nums, int numsSize) {
    int left = 0;
    int right = 1;
    while (right < numsSize) {
        if (nums[right] != nums[left]) {//��left��
            nums[++left] = nums[right];
        }
        right++;
    }
    return left + 1;
}

//27. �Ƴ�Ԫ��                ͨ��
int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize;
    if (numsSize == 0)return 0;
    while (left < right) {
        if (nums[left] == val) {
            //������Ԫ���ù���
            nums[left] = nums[right - 1];
            right--;
        }
        else {
            left++;
        }
    }
    return left;
}

//28. ʵ�� strStr()               ͨ��
int strStr(char* haystack, char* needle) {
    if (!needle)return 0;
    int haystr = strlen(haystack);
    int neestr = strlen(needle);
    int pos = 0;
    int hayptr = 0;
    int neeptr = 0;
    while (neeptr < neestr && pos <= haystr - neestr) {
        if (haystack[hayptr] == needle[neeptr]) {
            hayptr++;
            neeptr++;
        }
        else {
            neeptr = 0;
            pos++;
            hayptr = pos;
        }
    }
    if (neeptr == neestr) {
        return pos;
    }
    return -1;
}

//35. ��������λ��              ͨ��
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

//53. ����������             ͨ��   ��̬�滮
int maxSubArray(int* nums, int numsSize) {
    int sum = nums[0];
    int dp[100001] = { 0 };//dp[i]��ʾ�Ե�i��������β���������е����ֵ
    dp[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        dp[i] = dp[i - 1] + nums[i] >= nums[i] ? dp[i - 1] + nums[i] : nums[i];
        sum = sum > dp[i] ? sum : dp[i];
    }
    return sum;
}

//58. ���һ�����ʵĳ���
int lengthOfLastWord(char* s) {
    int last = strlen(s) - 1;
    int count = 0;
    while (last >= 0) {
        if (count == 0 && s[last] == ' ') {
            last--;
        }
        else if (s[last] != ' ') {
            last--;
            count++;
        }
        else {
            break;
        }
    }
    return count;
}

//66. ��һ             ͨ��
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int n = 0;
    int i = 0;
    digits[digitsSize - 1] += 1;
    for (i = 0; i < digitsSize - 1; i++) {
        if (digits[digitsSize - 1 - i] == 10) {
            digits[digitsSize - 1 - i] = 0;
            digits[digitsSize - 2 - i] += 1;
        }
        else {
            break;
        }
    }
    i = 0;
    if (digits[0] == 10) {
        *returnSize = digitsSize + 1;
        int* arr = malloc(sizeof(int) * (digitsSize + 1));
        while (i < *returnSize)arr[i++] = 0;
        arr[0] = 1;
        return arr;
    }
    *returnSize = digitsSize;
    return digits;
}
