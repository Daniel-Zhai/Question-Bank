#define _CRT_SECURE_NO_WARNINGS

//69. x ��ƽ����               ͨ��
int mySqrt(int x) {
    //����
    int left = 1;
    int right = x / 2;
    if (x == 1)return 1;
    while (left <= right) {
        long long int mid = left + (right - left) / 2;
        if (mid * mid > x)right = mid - 1;
        else if (mid * mid < x)left = mid + 1;
        else return mid;
    }
    return right;
}

//744. Ѱ�ұ�Ŀ����ĸ�����С��ĸ               ͨ��
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    if (target >= letters[lettersSize - 1])return letters[0];
    int left = 0;
    int right = lettersSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (letters[mid] > target)right = mid - 1;
        else if (letters[mid] < target)left = mid + 1;
        else {
            if (letters[mid] == letters[mid + 1])left = mid + 1;
            else return letters[mid + 1];
        }
    }
    return letters[left];
}