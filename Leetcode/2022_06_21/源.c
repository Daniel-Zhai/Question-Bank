#define _CRT_SECURE_NO_WARNINGS

//�����ֽ�
//һ��ʼ��0λ�ã�ÿһ�ζ���������������������
//��i����i��
//���ʴ�0��x(+)�����ټ��ο��Ե���
long sum(long n) {
    long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
//sum�ı仯����������żż����...
//������øպô��target��sumֵ��target�Ĳ�ֵ����ֵΪż�������ֱ�ӷ��أ���ֵΪ��������Ҫ����һ����������ֱ����ֵΪż��
int reachNumber(long target) {
    if (target == 0)return 0;
    long l = 0;
    long r = target;
    long m = 0;
    long near = 0;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (sum(m) < target)l = m + 1;
        else {
            near = m;
            r = m - 1;
        }
    }
    if (sum(near) == target)return (int)near;
    if ((sum(near) - target) & 1 == 1)near++;
    if ((sum(near) - target) & 1 == 1)near++;
    return (int)near;

}

//����ͬά����
//ÿ�����������ʼʱ��ͽ���ʱ��
//����Ļ��������ǰ��Ļ����ͻ������ȫȡ��֮ǰ�ĳ�ͻ���飬�������ڵ�
//����һ���������飬���ذ��ŵĻ����б�
https://github.com/algorithmzuo/publicclass2020/blob/master/src/class082/Code02_ArrangeMeetingPosCancelPre.java
//���������õ��߶���