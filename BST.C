#include<stdio.h>
struct node
{
	int info;
	struct node *lp,*rp;
};
typedef struct node node;

node * createBST(node *t, int number)
{
	if(t == NULL)
	{
		t = (node *)malloc(sizeof(node));
		t->info = number;
		t->lp = t->rp = NULL;
	}
	else if(t->info <= number)
	{
		t->rp = createBST(t->rp,number);
	}
	else
	{
		t->lp = createBST(t->lp,number);
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
	//int numbers[] = {10,20,50,3,9,8,-20,0,79,100},i;
	node *root = NULL;
	int number,ch;
	clrscr();
	do
	{
		printf("1. create BST\n");
		printf("2. PreOrder\n");
		printf("3. InOrder\n");
		printf("4. PostOrder\n");
		printf("0. Exit\n");

		printf("Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1 :
				/*for(i=0;i<=9;i++)
				{
					root = createBST(root,numbers[i]);
				} */
				while(1)
				{
					printf("Enter number & -1 for exit");
					scanf("%d",&number);
					if(number==-1)
						break;
					root = createBST(root,number);
				}
				break;
			case 2 :
				preorder(root);
				break;
			case 3 :
				inorder(root);
				break;
			case 4 :
				postorder(root);
				break;
			default :
				printf("Invalid choice ");
				break;
			case 0 : printf("Good Bye");
		}
	}while(ch!=0);
	getch();
}