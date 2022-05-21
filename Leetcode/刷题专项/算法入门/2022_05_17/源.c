#define _CRT_SECURE_NO_WARNINGS

//3. 无重复字符的最长子串          看题解通过
#define MAX_NUM 128

int myMax(int a, int b)
{
    return (a > b) ? a : b;
}

int lengthOfLongestSubstring(char* s)
{
    if (s == NULL) {
        return 0;
    }

    int len = strlen(s);
    int ret = 0;
    int cnt[MAX_NUM] = { 0 };

    int left = 0;
    int right = 0;
    while (right < len) {
        char c = s[right];
        right++;
        cnt[c]++;
        while (cnt[c] > 1) {
            char d = s[left];
            left++;
            cnt[d]--;
        }
        ret = myMax(ret, right - left);
    }

    return ret;
}