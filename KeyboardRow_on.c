/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NULL (void*)(0)

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct words_return
 {
 	char * word;
 	struct words_return *next;
 }words_TypeDef;

int belongto(char word)
{
	//
	char row1[] ="qwertyuiopQWERTYUIOP";
	char row2[] = "asdfghjklASDFGHJKL";
	char row3[] = "zxcvbnmZXCVBNM";
	int i = 0 ;//用于循环比较，以确定word在哪一组
	for(;i<20;++i){
		if(word == row1[i]){
			return 1;
		}
	}
	i = 0;
	for(;i<18;++i){
		if(word == row2[i]){
			return 2;
		}
	}
	i = 0;
	for(;i<14;++i){
		if(word == row3[i]){
			return 3;
		}
	}
	printf("请输入字母");
	return 0;
}
 
char** findWords(char** words, int wordsSize, int* returnSize) {
    int i = 0;//用于外循环访问二维数组的一行
    int j = 0;//用于内循环访问字符串数组的单个字符串
    int len ;//表示字符串的长度，不包括'\0'
    int row_num;
    char** toReturn;
    words_TypeDef *head = (words_TypeDef*)malloc(sizeof(words_TypeDef));
    words_TypeDef *p = head;
    *returnSize = 0;
    for(;i<wordsSize;++i){
    	len = strlen(words[i]);
        j=0;
    	for(;j<len;++j){
    		if(j==0){
    			row_num = belongto(words[i][j]);
    		}else{
    			if(row_num!= belongto(words[i][j])) {
    				break;
    			}
    		}
    		
    	}
    	if(j==len){
    		p->next = (words_TypeDef*)malloc(sizeof(words_TypeDef));
    		p = p->next;
    		p->word = words[i];
    	}
    }
    p = head->next;
    while(p!=NULL){
    	++(*returnSize);
    	p = p->next;
    }
    toReturn = (char**)malloc(sizeof(char*)*(*returnSize));
    i = 0;
    p = head->next;
    for(;i<(*returnSize);++i){
    	    toReturn[i] = p->word;
    	    p = p->next;
    }
    return toReturn;

}
int main(){
    int returnSize;
    char **a = (char**)malloc(sizeof(char*)*4);
    a[0]="Hello";
    a[1]="Alaska";
    a[2]="Dad";
    a[3]="Peace";

    char **b ;
    int i=0;
    int j=0;
    b = findWords(a,4,&returnSize);
    for(;i<returnSize;++i){
        j=0;
        while(b[i][j]!='\0'){
            printf("%c",b[i][j]);
            ++j;
        }
        printf("\n");
    }
    return 0;
}