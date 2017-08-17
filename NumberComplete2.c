//6ms
/*#include <math.h>*/
#include <stdio.h>
int findComplement(int num) {
	int i =0 ;
	int num_ = num;
	while(num_/2!=0||num_ == 1){
		++i;
		num_ = num_/2;
	}
	int sum = 0;
	while(i--){
		sum = (sum<<1)+1;
	}
	return sum -num;
	
	/*6ms version:return pow(2,i)-1-num;	*/
}


int main(int argc, char const *argv[])
{
	int num;
	printf("please input a number :\n");
	scanf("%d",&num);
	int result = findComplement(num);
	printf("%d\n", result);
	return 0;
}