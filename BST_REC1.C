//Insertion & Deletion
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
{
	node *root,*z;
	root=t;
	z=NULL;
	while(t!=NULL)
	{       z=t;
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

	if(z==NULL)
	{
		root=t;
	}else if(z->info>num)
	{
		z->lp=t;
	}else{
		z->rp=t;
	}
	return root;
}
node *search(node *t,int n)
{       while(t!=NULL && t->info!=n)
	{
		if(n < t->info)
		{
			t=t->lp;
		}else{
			t=t->rp;
		}
	}
	return t;
}

void *deleteNode(node *t,int d)
{
	node *z,*x;
	int temp;

	while(t!=NULL && t->info!=d)
	{       z=t;
		if(d < t->info)
		{
			t=t->lp;
		}else{
			t=t->rp;
		}
	}

	if(t->lp!=NULL && t->rp!=NULL)
	{
		x=t;
		t=t->rp;
		if(t->lp==NULL)
		{
			z=x;
		}else{
			while(t->lp!=NULL)
			{       z=t;
				t=t->lp;
			}
		}
		temp    = x->info;
		x->info = t->info;
		t->info = temp;
	}

	if(t->lp==NULL && t->rp==NULL)
	{
		if(z->lp==t)
		{
			z->lp=NULL;
		}else
		{
			z->rp=NULL;
		}
	}
	else if(t->lp==NULL && t->rp!=NULL)
	{
		if(z->lp==t)
		{
			z->lp=t->rp;
		}else{
			z->rp=t->rp;
		}
	}
	else if(t->lp!=NULL && t->rp==NULL)
	{
		if(z->lp==t)
		{
			z->lp=t->lp;
		}else{
			z->rp=t->lp;
		}
	}

	printf("%d is deleted",t->info);
	free(t);
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
	node *t,*root= NULL;
	int num,ch,d;
	clrscr();
	do{     clrscr();
		printf("\n1. Create BST");
		printf("\n2. Preorder");
		printf("\n3. Inorder");
		printf("\n4. Postorder");
		printf("\n5. Insert node");
		printf("\n6. Delete node");
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
			case 6:
				if(root==NULL)
				{	printf("No nodes");
				}else{
					printf("\nEnter the number you want to delete: ");
					scanf("%d",&d);
					t=search(root,d);
					if(t==NULL)
					{
						printf("\nNumber not found");
					}else{
						deleteNode(root,d);
					}
				}
				break;
			case 0: printf("\nGood Bye, Thank You %c",2);
				break;
		       default: printf("\nInvalid choice");

		}getch();
	}while(ch!=0);
}