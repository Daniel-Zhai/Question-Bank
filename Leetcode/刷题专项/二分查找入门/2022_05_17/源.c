#define _CRT_SECURE_NO_WARNINGS

//441. ����Ӳ��             ͨ��
int arrangeCoins(int n) {
    //x*(1+x)/2<=n�����x
    int l = 1;
    int r = n;
    int ans;
    while (l <= r) {
        long long int mid = l + (r - l) / 2;
        if (mid * (mid + 1) / 2 <= n) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return ans;
}

//1539. �� k ��ȱʧ��������       
// �����������Ĵ������
//1.ȱʧ��������һ�� >= k
//2.������ÿ����һ�� <= k ������, ��ζ������һ��ȱʧ������, ��ʱk+1
int findKthPositive(int* arr, int arrSize, int k) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] <= k)k++;
    }
    return k;
}
//���ַ��㲻��
