#include<stdio.h>
typedef struct node
{
	int co;
	int pow;
	struct node *next;
}node;
void display(node *t)  // t = start1
{
	while(t->next!=NULL)
	{
		printf("%d*x^%d + ",t->co,t->pow);
		t = t -> next;
	}
	printf("%d = 0\n",t->co);
}

node * createNode()
{
	node *t;

	t = (node *)malloc(sizeof(node));

	printf("Enter co : ");
	scanf("%d",&t->co);

	printf("Enter power : ");
	scanf("%d",&t->pow);

	t -> next = NULL;

	return t;
}
node* createPoly()
{
	node *t,*z,*start = NULL;
	char ch;

	do
	{
		t = createNode();
		if(start == NULL)
		{
			start = t;
		}
		else
		{
			z = start;
			while(z -> next != NULL)
			{
				z = z -> next;
			}
			z -> next = t;
		}

		printf("Do you want to add more node ? (Y/N) ");
		fflush(stdin);
		scanf("%c",&ch);

	}while(ch=='Y' || ch=='y');

	return start;
}
node * appendNode(node *new,int co,int pow)
{
	node *t,*z;

	t = (node *)malloc(sizeof(node));
	t -> co = co;
	t -> pow = pow;
	t -> next = NULL;

	if(new == NULL)
	{
	       new = t;
	}
	else
	{
		z = new;
		while(z -> next != NULL)
		{
			z = z -> next;
		}
		z -> next = t;
	}
	return new;
}
node * addPoly(node *t1,node *t2)
{
	node *start = NULL,*t,*z;

	while(t1!=NULL && t2!=NULL)
	{
		if(t1 -> pow > t2 -> pow)
		{
			start = appendNode(start,t1->co,t1->pow);
			t1 = t1 -> next;
		}
		else if(t1 -> pow < t2 -> pow)
		{
			start = appendNode(start,t2->co,t2->pow);
			t2 = t2 -> next;
		}
		else
		{
			start = appendNode(start,t1->co+t2->co,t1->pow);
			t1 = t1 -> next;
			t2 = t2 -> next;
		}
	}
	while(t1 != NULL)
	{
		start = appendNode(start,t1->co,t1->pow);
		t1 = t1 -> next;
	}
	while(t2 != NULL)
	{
		start = appendNode(start,t2->co,t2->pow);
		t2 = t2 -> next;
	}
	return start;
}
void main()
{
	node *start1,*start2,*start3;

	clrscr();
	printf("Enter first Polynomial : \n");
	start1 = createPoly();
	printf("Enter second Polynomial : \n");
	start2 = createPoly();

	start3 = addPoly(start1,start2);

	printf("**** First Poly ****\n");
	display(start1);
	printf("**** Second Poly ****\n");
	display(start2);
	printf("**** Final Poly ****\n");
	display(start3);

	getch();
}