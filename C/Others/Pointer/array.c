#include<stdio.h>
int main(){
    char a[30] = "9983745853",** b[20];
    printf("a:%d,&a:%d,*a:%d,*a+1:%d,a+1:%d,*(a+1):%d,&a+1:%d,*(a+2):%d.\n",a,&a,*a,*a+1,a+1,*(a+1),&a+1,*(a+2));
    printf("b:%d,b+1:%d",b,b+1);
    return 0;
}
//a:-388544112,&a:-388544112,*a:57,*a+1:58,a+1:-388544111,*(a+1):57,&a+1:-388544082,*(a+2):56.
//a+1:首行地址 *(a+1):首行首元素地址 (多维数组)
//区别一下a,a+1:元素+1;&a,&a+1:行+1
//b:-323798800,b+1:-323798792   (+8:This is the step of a pointer varible)