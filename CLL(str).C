#include<string.h>
#include<stdio.h>
#include<ctype.h>

//Programme for String
struct node
{
  char info[15];
  struct node *next;
};
typedef struct node node;
struct node *start=NULL; //use to store first node address

node *creatnode()
{
   node *t;
   t=(node *)malloc(sizeof(node));
   printf("Enter the name : ");
   scanf("%s",&t->info);
   t->next=NULL;
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
    printf("%s added ",strupr(start->info));
   }
   else if(start->next==start)
   {
      t->next=start;
      start->next=t;
      start=t;
      printf("%s added ", strupr(start->info));
   }

   else
     {
	 z=start;
	 t->next=z;
	while(z->next!=start)
	{
	 z=z->next;
	}
	z->next=t;
	start=t;
	printf("%s added ", strupr(start->info));
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
   printf("%s added ", t->info);
  }
  else if(start->next==start)
  {
    t->next=start;
    start->next=t;
    printf("%s added ", t->info);
  }
  else
  { t->next=start;
    z=start;
    while(z->next!=start)
    {
     z=z->next;
    }
    z->next=t;
    printf("%s added ", t->info);
  }
}

void popbeg()
{
	node *z;
	z=start;
	if(start==NULL)
	{
	printf("C.S.L is empty");
	}
	else if(start->next==start)
	{
	  printf("%s only node deleted ",strupr(start->info));
	  start=NULL;
	  free(start);
	}
	else
	{
	  z=start;
	  printf("%s deleted from begining",strupr(start->info));
	  while(z->next!=start)
	  {
	   z=z->next;
	  }
	  z->next=start->next;
	  free(start);
	  z=z->next;
	  start=z;
	}
}

void popend()
{
	node *z,*b;
	z=start;
	if(start==NULL)
	{
	printf("C.S.L.L is empty");
	}
	else if(start->next==start)
	{
	  printf("%s only node deleted ",strupr(start->info));
	  start=NULL;
	  free(start);
	}
	else
	{
	  z=start;
	  while(z->next!=start)
	  {
	   b=z;
	   z=z->next;
	  }
	  b->next=start;
	  printf("%s deleted from the end ",z->info);
	  free(z);
	}

}
void pushspl()
{
  node *t,*z;
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
    t=creatnode();
    z=start;
    i=1;
    while(i!=pos-1)
    {
     i++;
     z=z->next;
    }

     z->next=t;
     t->next=z->next;
     printf("%s added at %d",t->info,pos);
  }

}
void popspl()
{
  node *t,*z;
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
    z=start;
    i=1;
    while(i!=pos)
    {
     i++;
     t=z;
     z=z->next;
    }
     t->next=z->next;
     printf("%s is removed from %d",z->info,pos);
     free(z);
  }
}

void search()
{
	node *z;
	char x[20];
	int b,c=0;
	z=start;
	if(z==NULL)
	{
	   printf("C.S.L.L is empty");
	}
	else
	{
	   printf("Enter the name that you want to search : ");
	   scanf("%s",&x);
	   b=strcmp(z->info,x);
	   while(z->next!=start)
	   {
	    if(b>0)
	    {c++; break;}
	    else{z=z->next;}
	   }
	   if(b<0){c++;}
	   if(c>0){printf("Name found");}
	   else{printf("Name not found");}
	}

}


int count()
{
	node *z;
	int c=0;
	z=start;
  if(z==NULL)
  {
  printf("C.S.L.L is empty\n");
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
  printf("C.S.L.L is empty");
  }
  else
  {
  printf("Your name : ");
  while(z->next!=start)
    {
     printf("%s ",z->info);
     z=z->next;
    }
    printf("%s ",z->info);
  }
}




void main()
{
  int choice,c;
  clrscr();
  printf("Welcome to 'Cicular singly link list programme' \n'Press enter'");
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
