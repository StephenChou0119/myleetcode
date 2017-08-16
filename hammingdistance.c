#include <stdio.h>
int hammingDistance(int x, int y) {
    int consequence = x^y;
    int count=0;
    do{
        int lowest = consequence & 1;//结果用于判断最高位是否为1，为1时count++
        if(lowest == 1){
            count++;
        }
    }while(consequence>>=1);
    printf("the hamming distance is %d",count);
}
int main(){
    int a,b;
    printf("please input the two numbers:");
    scanf("%d%d",&a,&b);
    hammingDistance(a,b);
}
