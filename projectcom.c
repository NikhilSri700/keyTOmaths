#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct complex
{
 float x,y;
 struct complex *link;
};

void lawcom()
{
FILE *ptr;
char str1;
ptr=fopen("com.txt","r");
str1 = fgetc(ptr);
while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(ptr);
		}
fclose(ptr);
}

struct complex* inputcom()
{
 struct complex *start=NULL,*curr=NULL,*node;
  int a,b;
 printf("HOW MANY VECTOR YOU WANT TO ENTER\n");
 scanf("%d",&a);
 for(b=0;b<a;b++)
 {
  node=(struct complex*)malloc(sizeof(struct complex));
  printf("ENTER REAL PART OF YOUR %d COMPLEX NO.\n",b+1);
  scanf("%f",&node->x);
  printf("ENTER IMAGINARY PART OF YOUR %d COMPLEX NO.\n",b+1);
  scanf("%f",&node->y);
  node->link=NULL;
  if(start==NULL)
  {
   start=node;
   curr=node;
  }
  else
  {
   curr->link=node;
   curr=node;
  }
 }
 return start;

}

void sumcom()
{
 float ci=0.0,cj=0.0;
 struct complex *st;
 st=inputcom();
 do
 {
   ci=ci+st->x;
   cj=cj+st->y;
   st=st->link;
 }
 while(st->link!=NULL);
   ci=ci+st->x;
   cj=cj+st->y;
 printf("THE SUM OF ALL THE VECTORS GIVEN BY YOU IS \n(%.2f)+(%.2f)i\n",ci,cj);
}

struct complex* inputc(int x)
{
    struct complex *p;
    p=(struct complex*)malloc(sizeof(struct complex));
     printf("ENTER YOUR %d VECTOR\n",x);
     printf("REAL PART\n");
     scanf("%f",&p->x);
     printf("IMAGINARY PART\n");
     scanf("%f",&p->y);
     p->link=NULL;
     return p;
}

struct complex* product(struct complex *p,struct complex *q)
{
  struct complex *t;
  t=(struct complex*)malloc(sizeof(struct complex));
  t->x=(p->x*q->x)-(p->y*q->y);
  t->y=(p->x*q->y)+(p->y*q->x);
  return t;
}

float modulus(struct complex *v)
{
 float e;
     e=sqrt(pow(v->x,2)+pow(v->y,2));
     printf("MODULUS OF GIVEN COMPLEX NO. IS %.2f\n",e);
     return e;
}
void argument(struct complex *n,float r)
{
 float X,Y;
 X=acos(n->x/r)*180*7/22;
 Y=asin(n->y/r)*180*7/22;
printf("THE ARGUMENT FOR YOUR COMPLEX NO. IS %.2f IN DEGREES ",X);

}

int com()
{
int ch=1;
while(ch==1)
{


 int t;
 printf("\t\t\tCOMPLEX NUMBERS\n");
 printf("ENTER YOUR CHOICE\n1)ADDITION\n2)MULTIPLICATION\n3)CALCULATE MODULOUS\n4)CALCULATE ARGUMENT\n5)COMPLEX TO POLAR FORM\n6)ALL FORMULAS\n");
 scanf("%d",&t);
 switch(t)
 {
  case 1:
        sumcom();
        break;
  case 2:
      {
          struct complex *c1,*c2,*c3;
          c1=inputc(1);
          c2=inputc(2);
          c3=product(c1,c2);
          printf("THE PRODUCT BETWEEN GIVEN TWO COMPLEX NO. IS\n%.2f+%.2fi",c3->x,c3->y);
      }
      break;
  case 3:
    {
     struct complex *c;
     c=inputc(1);
     modulus(c);
    }
    break;
    case 4:
        {
          struct complex *c;
          c=inputc(1);
          float r;
          r=modulus(c);
          argument(c,r);
        }
        break;
    case 5:
        {
          struct complex *c;
          c=inputc(1);
          float r;
          r=modulus(c);
          float l;
          l=atan(c->y/c->x)*180*7/22;
          printf("THE POLAR FOR FOR YOUR COMPLEX NO. IS  %.2f<%.2f\n",r,l);
        }
        break;
        case 6:lawcom();
        break;
    default:printf("***WRONG INPUT***\n");
    }
     printf("\nPress 1 for Complex No. menu or any other key to end Complex No. operations  \n");
        scanf("%d",&ch);
 }
 return 0;
}
