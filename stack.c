#define MAX_STACK_LENGTH 100

typedef int elementType;
typedef struct {
	elementType elements[MAX_STACK_LENGTH];
	int top;
}Stack;

void initStack(Stack *S){
	S->top=-1;
}

int emptyStack(Stack *S){
	return S->top==-1;
}

elementType Top(Stack *S){
	return S->elements[S->top];
}

void push(Stack *S, elementType e){
	S->elements[++S->top]=e;
}

void pop(Stack *S){
	if(!emptyStack(S)) S->top--;
}

