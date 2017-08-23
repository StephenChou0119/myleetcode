/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NULL (void*)(0)

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>

int letter_num(char letter)
{
    int num[] = {
        11,24,22,13,3,14,15,16,8,17,18,19,26,25,9,10,1,4,12,5,7,23,2,21,6,20,
        37,50,48,39,29,40,41,42,34,43,44,45,52,51,35,36,27,30,38,31,33,49,28,47,32,46
        };
    if(letter<91){
        return num[letter-65];
    }else if(letter>96){
        return num[letter-71];//letter-96+26-1
    }else{
        return 0;
    }

}
int belongto(char letter)
{
    int num = letter_num(letter);
    if(num<11||(num<37&&num>26)){
        return 1;
    }else if(num<20||(num>36&&num<46)){
        return 2;
    }else{
        return 3;
    }
}
 
char** findWords(char** words, int wordsSize, int* returnSize) {
    int i = 0;//用于外循环访问二维数组的一行
    int j = 0;//用于内循环访问字符串数组的单个字符串
    int k = 0;//存储符合条件的行号
    int len ;//表示字符串的长度，不包括'\0'
    int row_num;
    char** toReturn;
    *returnSize = 0;
    if (wordsSize==0){
        return words;
    }
    int fit_row_nums[wordsSize];

    for(;i<wordsSize;++i){
        fit_row_nums[i] = wordsSize;

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
    	if((len!=0)&&(j==len)){
            ++(*returnSize);
            fit_row_nums[k] = i;
            ++k;
    	}
    }
    k=0;
    toReturn = (char**)malloc(sizeof(char*)*(*returnSize));
    for(;k<(*returnSize);++k){
        toReturn[k] = words[fit_row_nums[k]];
    }
    return toReturn;

}
int main(){
    int returnSize;
    char **a = (char**)malloc(sizeof(char*)*5);
    a[0]="Hello";
    a[1]="Alaska";
    a[2]="Dad";
    a[3]="qwee";
    a[4] = "";
    char **b ;
    int i=0;
    int j=0;
    b = findWords(a,5,&returnSize);
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