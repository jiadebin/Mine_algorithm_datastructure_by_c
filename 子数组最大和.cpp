#include <iostream>
#include <climits>

using namespace std;
/*
Problem:找子数组的最大和
Solution:用一个sum存储当前和,从头开始累加,一旦sum<0,清零

注意int最大值最小值在<limits.h>里,由于它是C语音里的,故包含时也可以写<climits>；
int是32位有符号数,其最大值为0x7fffffff,即最高位符号位为0其余为1;
最小值为负数,负数是补码形式表示的,故为0x80000000,即最高位符号位为1,其余为0(负数补码为所有数值位取反加1,故0x80000000-1=0xFFFFFFFF,取反变为0x80000000)
最小值=-1<<31(-1左移31位)
*/

#define MY_INT_MAX   0x7FFFFFFF
#define MY_INT_MIN   0x80000000

int findMaxSum(int *arr, int n){
    int sum=0, curmax=INT_MIN;
    for(int i=0; i<n; ++i){
        sum+=arr[i];
        if(sum>curmax)  curmax=sum;
        if(sum<0)   sum=0;    
    }
    return curmax;
}

int main()
{
    int arr[]={1, -2, 3, 10, -4, 7, 2, -5};

    int sum=findMaxSum(arr, 8);
    cout << sum << endl;
    return 0;
}
