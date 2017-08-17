//3ms
#define NULL (void*)(0)

#include <malloc.h>

typedef struct int_link
{
	int value ;
	struct int_link *next ;
}int_link_t;

int findComplement(int num) {
	int_link_t *num_str = (int_link_t*)malloc(sizeof(int_link_t));;
	num_str->value = 0;
	num_str->next = NULL;
	int_link_t *p = num_str;

	while(num/2!=0||num == 1){
		int bit = num%2;
		int_link_t *q = p->next;
		p->next = (int_link_t*)malloc(sizeof(int_link_t));
		p->next->value = bit;
		p->next->next = q;
		num = num/2;
	}
	p = num_str->next;
	int sum = 0;
	while(p!=NULL){
		sum = (sum<<1)+!(p->value);
		p = p->next;
	}
	return sum;
	
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