#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//leetcode
//第9题 回文数  通过
//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
//例如，121 是回文，而 123 不是。

bool isPalindrome(int x) {
    int num[10] = { 0 };
    int i = 0;
    if (x < 0)return false;
    while (x)
    {
        num[i] = x % 10;
        x /= 10;
        i++;
    }
    int left = 0;
    int right = i - 1;
    while (left < right)
    {
        if (num[left] == num[right])
        {
            left++; right--;
        }
        else return false;
    }
    return true;
}

//第1784题 检查二进制字符串字段  通过
//给你一个二进制字符串 s ，该字符串 不含前导零 。
//如果 s 包含 零个或一个由连续的 '1' 组成的字段 ，返回 true​​​ 。否则，返回 false

bool checkOnesSegment(char* s) {
    int i = 1;
    while (s[i] != '\0')
    {
        if (s[i] == '1')i++;                 //——'1',不是1！！！
        else
        {
            while (s[i] != '\0')
            {
                if (s[i] == '1')return false;           //——'1', 不是1！！！
                i++;
            }
            //return true;
        }
    }
    return true;
}

//第13题 罗马数字转整数
//未通过
int num(char* a)
{
    if (*a == 'I')return 1;
    if (*a == 'V')return 5;
    if (*a == 'X')return 10;
    if (*a == 'L')return 50;
    if (*a == 'C')return 100;
    if (*a == 'D')return 500;
    if (*a == 'M')return 1000;
    return 0;
}
int romanToInt(char* s) {
    int ret = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (num(&s[i]) < num(&s[i + 1]))
        {
            char s1[2] = { 0 };
            s1[0] = s[i];
            s1[1] = s[i + 1];
            if (strcmp(s1, "IV") == 0)ret += 4;
            if (strcmp(s1, "IX") == 0)ret += 9;
            if (strcmp(s1, "XL") == 0)ret += 40;
            if (strcmp(s1, "XC") == 0)ret += 90;
            if (strcmp(s1, "CD") == 0)ret += 400;
            if (strcmp(s1, "CM") == 0)ret += 900;
            i++;
        }
        else ret += num(&s[i]);
        i++;
    }
    return ret;
}
//第20题 有效的括号
//超时  未通过
typedef struct {
    char* base;
    char* top;
    int stacksize;
}Sqstack;//栈

bool isValid(char* s) {
    Sqstack S;
    S.base = (char*)malloc(sizeof(char) * 10000);
    S.top = S.base;
    S.stacksize = 10000;
    while (s)
    {
        if (*s == '(' || *s == '[' || *s == '{') {
            *S.top++ = *s++;
        }
        else if (*s == ')')
        {
            S.top--;
            if (*S.top != '(')
            {
                return false;
            }
            s++;
        }
        else if (*s == ']')
        {
            S.top--;
            if (*S.top != '[')
            {
                return false;
            }
            s++;
        }
        else if (*s == '}')
        {
            S.top--;
            if (*S.top != '{')
            {
                return false;
            }
            s++;
        }
    }
    return true;
}