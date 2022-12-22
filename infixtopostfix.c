#include<stdio.h>
#include<stdlib.h>


//declaring stack size and top position
char stack[20];
int top=-1;


//function to add element in stack
void push(char x)
{
	stack[++top]=x;
}


//function to remove element from stack
char pop()
{
	if(top==-1){
		return -1;
	}
	else{
		return stack[top--];
	}
}

//function to determone the priority of elemnts
int priority(char x)
{
	if(x=='(') return 0;
	if(x=='+' || x=='-') return 1;
	if(x=='*' || x=='/') return 2;
}


//main function
int main(){
	char exp[20];
	char *e,x;
	printf("Enter the expression:\n");
	scanf("%s",exp);
	
	e=exp;
	
	//while function untill condition met
	while(*e!='\0')
	{
		if(isalnum(*e)){
			printf("%c",*e);
		}
		else if(*e == '('){
			push(*e);
		}
		else if(*e == ')')
		{
			while((x=pop())!='(')
			printf("%c",x);
		}
		else
		{
			while(priority(stack[top])>=priority(*e))
				printf("%c",pop());
			push(*e);
		
		}
		e++;
	}
	while(top!=-1){
	printf("%c",pop());
	
	
	}
}
