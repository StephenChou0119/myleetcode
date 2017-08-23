#define NULL (void*)0

#include <string.h>
#include <malloc.h>
typedef struct  StackNode
{
	/* data */
	char data;
	struct StackNode *next;
}StackNode_t;
typedef struct Stack
{
	StackNode_t *top;
}Stack_t;
typedef struct StackLink
{
	/* data */
	Stack_t *word;
	struct StackLink  *next;
}StackLink_t;
void pop(Stack_t *stack, char *toPop)
{
	*toPop = stack->top->next->data;
	StackNode_t *toFree = stack->top->next;
	stack->top->next = stack->top->next->next;
	free(toFree);
}
void push(Stack_t *stack, char toPush)
{
	StackNode_t *toPush_s =  (StackNode_t*)malloc(sizeof(StackNode_t));
	toPush_s->data = toPush;
	toPush_s->next = stack->top->next;
	stack->top->next = toPush_s;
}
int isEmpty(Stack_t *stack)
{
	if (stack->top->next == NULL){
		return !0;
	}else{
		return 0;
	}
}
char* reverseWords(char* s) 
{
    int len = strlen(s);
    int i = 0;
    StackLink_t *p = (StackLink_t*)malloc(sizeof(StackLink_t));
    p->word = (Stack_t*) malloc(sizeof(Stack_t));
    p->next = NULL;
    p->word->top = (StackNode_t*)malloc(sizeof(StackNode_t));
    p->word->top->next = NULL;
    StackLink_t *head = p;

    for(;i<len;++i){
    	if(s[i] == ' '){
    		p->next = (StackLink_t*)malloc(sizeof(StackLink_t));
    		p = p->next;
    		p->word = (Stack_t*) malloc(sizeof(Stack_t));
    		p->next = NULL;
    		p->word->top = (StackNode_t*)malloc(sizeof(StackNode_t));
    		p->word->top->next = NULL;
    	}else{
    		push(p->word, s[i]);
    	}
    }
    i = 0;
    p = head;
    for(;i<len;++i){
    	if(!isEmpty(p->word)){
    		pop(p->word,&s[i]);
    	}else{
    		p = p->next;

    	}
    	
    }
    return s;
}
int main()
{
	char s[]="God Ding";
	reverseWords(s);
	printf("%s",s);
}