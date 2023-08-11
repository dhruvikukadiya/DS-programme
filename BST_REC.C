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

void preorder(node *t)
{
	if(t!=NULL)
	{
		printf("%d\t",t->info);
		preorder(t->lp);
		preorder(t->rp);
	}
}

void inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->lp);
		printf("%d\t",t->info);
		inorder(t->rp);
	}
}

void postorder(node *t)
{
	if(t!=NULL)
	{
		postorder(t->lp);
		postorder(t->rp);
		printf("%d\t",t->info);
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
			case 0: printf("Good Bye, Thank You %c",2);
				break;
		       default: printf("Invalid choice");
		}
	}while(ch!=0);
	getch();
}