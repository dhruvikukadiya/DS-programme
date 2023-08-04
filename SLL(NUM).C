#include<stdio.h>
struct node
{
  int info;
  struct node *next;
};
typedef struct node node;
struct node *start=NULL; //use to store first node address

node *creatnode()
{
   node *t;
   t=(node *)malloc(sizeof(node));
   printf("Enter the data : ");
   scanf("%d",&t->info);
   t->next=NULL;
   return t;
}
void pushbeg()
{
   node *t;
   t=creatnode();
   if(start!=NULL)
   {
    t->next=start;
   }
   start=t;
   printf("%d added ", t->info);
}


void pushend()
{
  node *t,*z;
  t=creatnode();
  if(start==NULL)
  {
   start=t;
  }
  else
  {
   z=start;
   while(z->next!=NULL)
   {
    z=z->next;
   }
   z->next=t;
  }
  printf("%d added ", t->info);

}
void pushspl()
{
   int pos,i,c;
   node *z,*t;
   c=count();
   printf("Enter the position : ");
   scanf("%d",&pos);
   if(pos>c+1 || pos<1)
   {
    printf("Invalid position (Total number of nodes = %d)",c);
   }
   else if(pos==1)
   {
     pushbeg();
   }
   else if(pos==c+1)
   {
     pushend();
   }
   else
   {
     t=creatnode();
     z=start;
     i=1;
     while(i!=pos-1)
       {
	 z=z->next;
	 i++;
       }
      t->next=z->next;
      z->next=t;
      printf("%d added at %d", t->info,pos);
   }

}

void popbeg()
{
	node *z;
	z=start;
	if(start==NULL)
	{
	printf("S.S.L is empty");
	}
	else
	{
	  z=start;
	  start=z->next;
	  free(z);
	  printf("%d deleted from begining",z->info);
	}
}

void popend()
{
	node *z,*t;

	if(start==NULL)
	{
	printf("S.S.L is empty");
	}
	else if(start->next==NULL)
		{
		  printf("only node %d, of the list is deleted",start->info);
		  start=NULL;
		  free(start);
		}
	else
	{
	  z=start;
	   while(z->next!=NULL)
		{
		  t=z;
		  z=z->next;
		}
		 printf("%d deleted from the last",z->info);
		 t->next=NULL;
		 free(z);
	}

}
void popspl()
{
   int pos,i,c;
   node *z,*t;
   c=count();
   printf("Enter the position : ");
   scanf("%d",&pos);
   if(pos>c+1 || pos<1)
   {
    printf("Invalid position \n(Range = %d to %d)",1,c+1);
   }
   else if(pos==1)
   {
     popbeg();
   }
   else if(pos==c)
   {
     popend();
   }
   else
   {
     z=start;
     i=1;
     while(i!=pos)
       {
	 t=z;
	 z=z->next;
	 i++;
       }
      t->next=z->next;
      printf("%d deleted from %d position", z->info,pos);
   }

}

void search()
{
	node *z;
	int x,c=0;
	z=start;

	if(z==NULL)
	{
	   printf("S.S.L is empty");
	}
	else
	{

	   printf("Enter the data that you want to search : ");
	   scanf("%d",&x);
	   while(z!=NULL)
	   {
	    if(z->info==x)
	    {c++; break;}
	    else{z=z->next;}
	   }
	   if(c>0){printf("Data found");}
	   else{printf("Data not found");}
	}

}


int count()
{
	node *z;
	int c=0;
	z=start;

  if(z==NULL)
  {
  printf("S.S.L is empty\n");
  return c;
  }
  else
  {
    while(z!=NULL)
    {
     c++;
     z=z->next;
    }
    return c++;
  }

}
void display()
{
  node *z;
  z=start;

  if(z==NULL)
  {
  printf("S.S.L is empty");
  }
  else
  {
  printf("Your data : ");
  while(z!=NULL)
    {
     printf("%d ",z->info);
     z=z->next;
    }
  }
}


void main()
{
  int choice,c=0;
  clrscr(); \
  do
  {
  printf("1.PUSH BEGENING\n");
  printf("2.PUSH END\n");
  printf("3.POP BEGENING\n");
  printf("4.POP END\n");
  printf("5.PUSH SPECIAL\n");
  printf("6.POP SPECIAL\n");
  printf("7.SEARCH DATA\n");
  printf("8.COUNT NODE\n");
  printf("9.DISPLAY\n");
  printf("0.EXIT\n");
  printf("\n\nENter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: pushbeg();
		break;
	case 2: pushend();
		break;
	case 3: popbeg();
		break;
	case 4: popend();
		break;
	case 5: pushspl();
		break;
	case 6: popspl();
		break;
	case 7: search();
		break;
	case 8: c=count();
		printf("Total %d node",c);
		break;
	case 9: display();
		break;
	case 0: printf(" Thank you ");
		break;
	default:printf(" Invalid choice,try again  ");
		break;
		}
		getch();
		clrscr();

  }while(choice!=0);
  getch();

}