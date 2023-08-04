#include<stdio.h>

//Programme for Number
struct node
{
  int info;
  struct node *next;
  struct node *prev;
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
   t->prev=NULL;
   return t;
}
void pushbeg()
{
   node *t,*z;
   t=creatnode();
   if(start==NULL)
   {
    start=t;
    start->next=start;
    start->prev=start;
    printf("%d added ", start->info);
   }
   else
   {
	z=start->prev;
	t->next=start;
	start->prev=t;
	z->next=t;
	t->prev=z;
	start=t;
	printf("%d added ", start->info);
     }

}

void pushend()
{
  node *t,*z;
  t=creatnode();
  if(start==NULL)
  {
   start=t;
   start->next=start;
   start->prev=start;
   printf("%d added ", t->info);
  }
  else
  {
    t->next=start;
    z=start->prev;
    t->prev=z;
    start->prev=t;
    z->next=t;
    printf("%d added ", t->info);
  }
}

void popbeg()
{
	node *z,*b;
	z=start;
	if(start==NULL)
	{
	printf("D.C.L.L is empty");
	}
	else if(start->next==start)
	{
	 printf("%d deleted",start->info);
	 start=NULL;
	 free(start);
	}
	else
	{
	  b=start->next;
	  printf("%d deleted from begining",start->info);
	  z=start->prev;
	  z->next=b;
	  b->prev=z;
	  free(start);
	  start=b;
	}
}

void popend()
{
	node *z,*b;
	z=start;
	if(start==NULL)
	{
	printf("D.C.L.L is empty");
	}
	else if(start->next==start)
	{
	  printf("%d deleted",start->info);
	 start=NULL;
	 free(start);
	}
	else
	{
	  z=start->prev;
	  b=z->prev;
	  b->next=start;
	  start->prev=b;
	  printf("%d deleted from the end ",z->info);
	  free(z);
	}

}
void pushspl()
{
  node *a,*n,*b;
  int i,c,pos;
  c=count();
  printf("Enter the position : ");
  scanf("%d",&pos);
  if(pos<1 || pos>c+1)
  {
   printf("Warning : Out of range\n [Range is from %d to %d]",1,c);
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
    n=creatnode();
    i=1;
    a=start;
    while(i!=pos-1)
    {
     i++;
     a=a->next;
    }
     b=a->next;
     n->prev=a;
     n->next=b;
     a->next=n;
     b->prev=n;
     printf("%d added at %d",n->info,pos);
  }

}
void popspl()
{
  node *a,*d,*b;
  int i,c,pos;
  c=count();
  printf("Enter the position : ");
  scanf("%d",&pos);
  if(pos<1 || pos>c)
  {
   printf("Warning : Out of range\n [Range is from %d to %d]",1,c);
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
    d=start;
    i=1;
    while(i!=pos)
    {
     i++;
     d=d->next;
    }

     printf("%d is removed from %d",d->info,pos);
     b=d->next;
     a=d->prev;
     a->next=b;
     b->prev=a;
     free(d);
  }
}

void search()
{
	node *z;
	int x,c=0;
	z=start;
	if(z==NULL)
	{
	   printf("D.C.L.L is empty");
	}
	else
	{
	   printf("Enter the data that you want to search : ");
	   scanf("%d",&x);
	   while(z->next!=start)
	   {
	    if(z->info==x)
	    {c++; break;}
	    else{z=z->next;}
	   }
	   if(z->info==x){c++;}
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
  printf("D.C.L.L is empty\n");
  return c;
  }
  else if(start->next==start)
  {
   return c=1;
  }
  else
  {
    while(z->next!=start)
    {
     c++;
     z=z->next;
    }
    return c+1;
  }
}
void display()
{
  node *z;
  z=start;
  if(z==NULL)
  {
  printf("D.C.L.L is empty");
  }
  else
  {
  printf("Your data : ");
  while(z->next!=start)
    {
     printf("%d ",z->info);
     z=z->next;
    }
    printf("%d ",z->info);
  }
}

void displayRev()
{
  node *z;
  if(start==NULL)
  {
  printf("D.C.L.L is empty");
  }
  else
  {
  z=start;
  z=start->prev;
  printf("Your data : ");
  while(z->prev!=start->prev)
    {
     printf("%d ",z->info);
     z=z->prev;
    }
    printf("%d ",z->info);
  }
}

void swap()
{
	int i,j,p=1,q=1,temp,c;
	node *a,*b;
	c=count();
	if(c==2)
	{
	 a=start;
	 b=start->next;
	 temp=a->info;
	 a->info=b->info;
	 b->info=temp;
	 printf("Swapping complete.");
	}
	else
	{
	printf("Enter the position of 1st node : ");
	scanf("%d",&i);
	  if(i>c+1||i<0)
		{printf("\nEntered position is invalid");}
	printf("Enter the position of 2nd node : ");
	scanf("%d",&j);
	  if(j>c+1||j<0)
	{printf("\nEntered position is invalid");}
		a=start;
		b=start;
		while(p!=i)
		{p++;a=a->next;}
		while(q!=j)
		{ q++; b=b->next;}
		temp=a->info;
		a->info=b->info;
		b->info=temp;
		printf("Swapping complete");
	}

}

void replace()
{
  int pos,c,temp;
  node *a;
  c=count();
  if(c==0)
  {

  }
  else
  {
    if(c==1)
    {
      printf("Enter new node data : ");
      scanf("%d",&start->info);
      printf("Data replaced");
    }
    else
    {
      int i=1;
      a=start;
      printf("Enter position : ");
      scanf("%d",&pos);
      if(pos>c || pos<0)
      {
       printf("Invalid positio");
      }
      else
      {
      while(i!=pos)
      {
       i++;
       a=a->next;
      }
      printf("Enter new node data : ");
      scanf("%d",&a->info);
      printf("Data replaced with %d",a->info);
	}

      }
 }
}


void main()
{
  int choice,c;
  clrscr();
  printf("Welcome to 'Doubly cicular link list programme' \n\n'Press enter'");
  getch();
  clrscr();
  do
  {
  printf("1.PUSH BEGENING\n");
  printf("2.PUSH END\n");
  printf("3.PUSH SPECIAL\n");
  printf("4.POP BEGENING\n");
  printf("5.POP END\n");
  printf("6.POP SPECIAL\n");
  printf("7.SEARCH DATA\n");
  printf("8.COUNT NODE\n");
  printf("9.DISPLAY\n");
  printf("10.DISPLAY REVERSE\n");
  printf("11.SWAPPING NODES\n");
  printf("12.REPLACE NODE\n");
  printf("0.EXIT\n");
  printf("\n\nEnter your choice : ");
  scanf("%d",&choice);
  switch(choice)
  {
	case 1: pushbeg();
		break;
	case 2: pushend();
		break;
	case 3: pushspl();
		break;
	case 4: popbeg();
		break;
	case 5: popend();
		break;
	case 6: popspl();
		break;
	case 7: search();
		break;
	case 8: c=count();
		printf("Total %d nodes",c);
		break;
	case 9: display();
		break;
	case 10:displayRev();
		break;
	case 11:swap();
		break;
	case 12:replace();
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
