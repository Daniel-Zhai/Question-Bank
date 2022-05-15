#define _CRT_SECURE_NO_WARNINGS


//344. ��ת�ַ���                    ͨ��
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}

//557. ��ת�ַ����еĵ��� III            ͨ��
void reverse(char* s, int left, int right) {
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);
    int left = 0;//ÿ�����ʵ����
    int right = 0;//ÿ�����ʵ��Ҷ�
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            right = i - 1;
            reverse(s, left, right);
            left = i + 1;
        }
        if (i == len - 1) {
            reverse(s, left, len - 1);
        }
    }
    return s;
}