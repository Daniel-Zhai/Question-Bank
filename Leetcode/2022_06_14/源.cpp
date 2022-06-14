#define _CRT_SECURE_NO_WARNINGS
//leetcode

//43. 字符串相乘                  通过
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")return "0";
        if (num1 == "1")return num2;
        if (num2 == "1")return num1;

        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }

        int m = num1.length();
        int n = num2.length();
        string ansstr(m + n, '0');

        for (int i = n - 1; i >= 0; i--) {
            if (num2[i] == '0')continue;
            int c_in = 0;
            for (int j = m - 1; j >= 0; j--) {
                int ans = (num1[j] - '0') * (num2[i] - '0') + (ansstr[i + j + 1] - '0') + c_in;
                c_in = ans / 10;
                ans = ans % 10;
                ansstr[i + j + 1] = char(ans + '0');
            }
            if (c_in > 0)ansstr[i] = (c_in + '0');
        }
        //去掉前面的0
        int i = 0;
        while (ansstr[i] == '0')i++;
        return ansstr.substr(i, m + n - i);
    }
};

//50. Pow(x, n)               未通过
class Solution {
public:
    double myPow(double x, long long int n) {
        double ans = 1.0;
        if (x == 1.0)return x;
        if (n >= 0) {
            for (int i = 0; i < n; i++) {
                ans *= x;
            }
        }
        else {
            n = -n;
            for (int i = 0; i < n; i++) {
                ans *= 1 / x;
            }
        }
        return ans;
    }
};
