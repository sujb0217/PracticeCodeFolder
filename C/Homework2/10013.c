/*
【问题描述】用整数表示时间，如：1050表示10点50分，2010表示20点10分，现输入两个时间，求两个时间的和。
例:2030+850=520 不是2880;1055+850=1945 不是1905
【输入形式】两行数据，每行一个整数。
【输出形式】输出相加后的时间整数。如果是0点0分，输出"000"
【样例输入】
    2030
    850
【样例输出】520
【样例说明】表示20点30分加8点50分得5点20分。
*/
#include<stdio.h>
int main(){
    int H1,H2,M1,M2,h,m,T1,T2,t;
    scanf("%d%d",&T1,&T2);
    H1 = T1 / 100;
    M1 = T1 % 100;
    H2 = T2 / 100;
    M2 = T2 % 100;
    h = H1 + H2 + 1;
    h = (h >= 24) ? (h - 24) : h;
    m = M1 + M2;
    m = (m >= 60) ? (m - 60) : m;
    if(h == 0 && m / 100 == 0)printf("00%d\n",m);
    else if(h == 0 && m / 100 != 0)printf("0%d\n",m);
    else{
        t = h * 100 + m;
        printf("%d\n",t);
    }
    return 0;
}