//Insertion without recursion

#include<stdio.h>
typedef struct node
{
	int info;
	struct node *lp,*rp;
}node;
node *createBST(node *t,int num)
{
	if(t==NULL)
	{
		t=(node*)malloc(sizeof(node));
		t->info=num;
		t->lp=t->rp=NULL;
	}
	else if(t->info <= num)
	{
		t->rp=createBST(t->rp,num);
	}
	else{
		t->lp=createBST(t->lp,num);
	}
	return t;
}

node* insertNode(node *t,int num)
{       node *root,*z;
	root=t;
	while(t!=NULL)
	{
		z=t;
		if(t->info>num)
		{
			t=t->lp;
		}else{
			t=t->rp;
		}
	}
	t=(node*)malloc(sizeof(node));
	t->info=num;
	t->lp=t->rp=NULL;
	if(z->info>num)
	{
		z->lp=t;
	}else{
		z->rp=t;
	}
	return root;
}
void preorder(node *t)
{
	node *stack[10];
	int i=0;
	start:
	while(t!=NULL)
	{
		printf("%d\t",t->info);
		if(t->rp!=NULL)
		{
			stack[i]=t->rp;
			i++;
		}t=t->lp;
	}
	if(i!=0)
	{
		i--;
		t=stack[i];
		goto start;
	}

}

void inorder(node *t)
{
	node *stack[10];
	int i=0;
	start:
	while(t!=NULL)
	{
		stack[i]=t;
		i++;
		t=t->lp;
	}
	begin:
	if(i!=0)
	{
		i--;
		t=stack[i];
		printf("%d\t",t->info);
		if(t->rp!=NULL)
		{
			t=t->rp;
			goto start;
		}
		goto begin;
	}
}

struct postNode
{	node *temp;
	char ch;
};
void postorder(node *t)
{
	struct postNode stack[10];
	int i=0;
	char status;
	start:
	while(t!=NULL)
	{
		stack[i].ch='Y';
		stack[i].temp=t;
		i++;
		if(t->rp!=NULL)
		{
			stack[i].ch='N';
			stack[i].temp=t->rp;
			i++;
		}t=t->lp;
	}
	begin:
	if(i!=0)
	{
		i--;
		t=stack[i].temp;
		status=stack[i].ch;
		if(status=='N')
		{
			goto start;
		}else{
			printf("%d\t",t->info);
			goto begin;
		}
	}
}

void main()
{
	node *root= NULL;
	int num,ch;
	clrscr();
	do{
		printf("\n1. Create BST");
		printf("\n2. Preorder");
		printf("\n3. Inorder");
		printf("\n4. Postorder");
		printf("\n5. Insert Nodes");
		printf("\n0. Exit");

		printf("\nEnter your choice: ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				while(1)
				{
				printf("Enter number and -1 to exit: ");
				scanf("%d",&num);
				if(num==-1)
				break;
				root=createBST(root,num);
				}
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				while(1)
				{
				printf("Enter number and -1 to exit: ");
				scanf("%d",&num);
				if(num==-1)
				break;
				root=insertNode(root,num);
				}
				break;
			case 0: printf("Good Bye, Thank You %c",2);
				break;
		       default: printf("Invalid choice");
		}
	}while(ch!=0);
	getch();
}