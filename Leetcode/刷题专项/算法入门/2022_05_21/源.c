#define _CRT_SECURE_NO_WARNINGS

//3. 无重复字符的最长子串       通过
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


//567. 字符串的排列             滑动窗口，看答案通过
bool equal(int* cnt1, int* cnt2) {
    for (int i = 0; i < 26; i++) {
        if (cnt1[i] != cnt2[i]) {
            return false;
        }
    }
    return true;
}

bool checkInclusion(char* s1, char* s2) {
    int n = strlen(s1);
    int m = strlen(s2);
    if (n > m)return false;

    int cnt1[26] = { 0 };
    int cnt2[26] = { 0 };
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < n; i++) {
        ++cnt1[s1[i] - 'a'];
        ++cnt2[s2[i] - 'a'];
    }
    if (equal(cnt1, cnt2)) {
        return true;
    }
    for (int i = n; i < m; i++) {
        ++cnt2[s2[i] - 'a'];
        --cnt2[s2[i - n] - 'a'];
        if (equal(cnt1, cnt2)) {
            return true;
        }
    }
    return false;
}