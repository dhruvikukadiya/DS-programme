#include<string.h>

char stack[20];
int top = -1;

void push(char ch)
{
	top++;
	stack[top]=ch;
}

char pop()
{
   char ch=stack[top];
   top--;
   return ch;
}

int priority(char ch)
{

	if( ch=='*'|| ch=='/')
	{
	 return 3;
	}
	else if( ch=='+'|| ch=='-')
	{
	 return 2;
	}
	else
	{
	 return 1;
	}
}
void convert(char infix[])
{
	char ch,result[20];
	int i,j;
	int n1,n2,p1,p2;
	i=j=0;
	strrev(infix);
	while(infix[i]!='\0')
	{
	n1=isdigit(infix[i]);
	n2=isalpha(infix[i]);
	if( n1!=0 || n2!=0 )
	{
	 result[j]=infix[i];
	 j++;
	}
	else if(top==-1)
	{
	 push(infix[i]); // i=0 ????
	}
	else
	{
	  p1=priority(infix[i]);
	  check:
	  p2=priority(stack[top]);
	  if(p1>=p2)
		{
			push(infix[i]);
		}
	  else
		{
			ch=pop();
			result[j]=ch;
			j++;
			if(top!=-1)
			{
				goto check;
			}
			else
			{
			push(infix[i]);
			}
		}
	}
	i++;
}
while(top!=-1)
{
 ch=pop();
 result[j]=ch;
 j++;
}
result[j]='\0';
strrev(result);
printf("Prefix : %s",result);
}


void main()
{
	char equ[20];
	clrscr();
	printf("Enter equ : ");
	scanf("%s",&equ);
	convert(equ);
	getch();
}