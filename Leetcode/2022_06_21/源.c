#define _CRT_SECURE_NO_WARNINGS

//来自字节
//一开始在0位置，每一次都可以向左跳或者向右跳
//第i次跳i步
//请问从0到x(+)，至少几次可以到达
long sum(long n) {
    long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}
//sum的变化规律是奇奇偶偶奇奇...
//所以求得刚好大过target的sum值与target的差值，差值为偶数则可以直接返回，差值为奇数则需要多走一步或两步，直到差值为偶数
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

//来自同维数码
//每个会议给定开始时间和结束时间
//后面的会议如果与前面的会议冲突，则完全取消之前的冲突会议，安排现在的
//给定一个会议数组，返回安排的会议列表
https://github.com/algorithmzuo/publicclass2020/blob/master/src/class082/Code02_ArrangeMeetingPosCancelPre.java
//来自左神，用到线段树