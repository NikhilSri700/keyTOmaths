#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void crossProduct(int vect_A[], int vect_B[], int cross_P[])

{
  cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
  cross_P[1] = vect_A[0] * vect_B[2] - vect_A[2] * vect_B[0];
  cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
}

struct vec
{
 float i,j,k;
 struct vec *link;
};

struct vec* inputvec()
{
 struct vec *start=NULL,*curr=NULL,*node;
  int x,y;
 printf("HOW MANY VECTOR YOU WANT TO ENTER\n");
 scanf("%d",&x);
 for(y=0;y<x;y++)
 {
  node=(struct vec*)malloc(sizeof(struct vec));
  printf("ENTER i COMPONENT FOR %d VECTOR\n",y+1);
  scanf("%f",&node->i);
  printf("ENTER j COMPONENT FOR %d VECTOR\n",y+1);
  scanf("%f",&node->j);
  printf("ENTER k COMPONENT FOR %d VECTOR\n",y+1);
  scanf("%f",&node->k);
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

void sum2()
{
 float ci=0.0,cj=0.0,ck=0.0;
 struct vec *st;
 st=inputvec();
 do
 {
   ci=ci+st->i;
   cj=cj+st->j;
   ck=ck+st->k;
   st=st->link;
 }
 while(st->link!=NULL);
   ci=ci+st->i;
   cj=cj+st->j;
   ck=ck+st->k;
 printf("THE SUM OF ALL THE VECTORS GIVEN BY YOU IS \n(%.2f)i+(%.2f)j+(%.2f)k\n",ci,cj,ck);

}

struct vec* inputv(int x)
{
    struct vec *p;
    p=(struct vec*)malloc(sizeof(struct vec));
     printf("ENTER YOUR %d VECTOR\n",x);
     printf("i COEFFICIENT\n");
     scanf("%f",&p->i);
     printf("j COEFFICIENT\n");
     scanf("%f",&p->j);
     printf("k COEFFICIENT\n");
     scanf("%f",&p->k);
     p->link=NULL;
     return p;
}
struct vec* calcdiff(struct vec *p,struct vec *q,int l)
{
  struct vec *t;
  t=(struct vec*)malloc(sizeof(struct vec));
  if(l==1)
  {
  t->i=p->i-q->i;
  t->j=p->j-q->j;
  t->k=p->k-q->k;
  }
  else
  {
  t->i=p->i*q->i;
  t->j=p->j*q->j;
  t->k=p->k*q->k;
  }
   t->link=NULL;
  return t;
}
float calcdist(struct vec *ab)
{
    float s;
    s=sqrt(pow(ab->i,2)+pow(ab->j,2)+pow(ab->k,2));
    return s;
}
int deci2(float z)
{

    // Directly print the number with .2f precision
    printf("%.2f", z);
    return 0;
}
float roundoff(float f)
{
    float value = (int)(f*100);
    return (float)value / 100;

}
int vec()
{int ch=1;
 while(ch==1)
 {
 int t;
 printf("\t\t\tVECTORS\n");
 printf("ENTER YOUR CHOICE\n1)ADDITION OF VECTORS\n2)TO CHECK WHEATHER THE VECTORS ARE COLLINEAR\n3)DOT PRODUCT\n4)CROSS PRODUCT\n5)ANGLE BETWEEN TWO VECTORS\n");
 scanf("%d",&t);
 switch(t)
 {
  case 1:
      sum2();
      break;
  case 2:
    {
     struct vec *a,*b,*c;
     a=inputv(1);
     b=inputv(2);
     c=inputv(3);
     struct vec *ab,*ac,*bc;
     ab=calcdiff(b,a,1);
     ac=calcdiff(c,a,1);
     bc=calcdiff(c,b,1);
    float s,r,d;
     r=calcdist(ab);
     s=calcdist(ac);
     d=calcdist(bc);
     r=roundoff(r);
     s=roundoff(s);
     d=roundoff(d);
     float e,h,g;
     e=r+d;
     h=s+d;
     g=r+s;
     if(s==e||r==h||s==g)
        printf("THE VECTORS ENTERED BY YOU ARE COLLINER\n");
     else
        printf("THE VECTORS ENTERED BY YOU ARE NOT COLLINER\n");
    }
  case 3:
    {
        struct vec *v1,*v2,*c;
        v1=inputv(1);
        v2=inputv(2);
        c=calcdiff(v1,v2,2);
        float p;
        p=c->i+c->j+c->k;
        printf("%.2f",p);

    }
    break;
  case 4:
    {
      int vect_A[3];
    int vect_B[3];
    int cross_P[3],i;
    printf("\n\n\nENTER YOUR FIRST VECTOR BY ENTERING THE COEFFICENT OF i,j,k RESPECTIVELY\n");
    for(i=0;i<3;i++)
    {
     scanf("%d",&vect_A[i]);
    }
     printf("ENTER YOUR SECOND VECTOR BY ENTERING THE COEFFICENT OF i,j,k RESPECTIVELY\n");
    for(i=0;i<3;i++)
    {
     scanf("%d",&vect_B[i]);
    }
     printf( "CROSS PRODUCT:");
    crossProduct(vect_A, vect_B, cross_P);
        printf("(%d)i+(%d)j+(%d)k+ ",cross_P[0],cross_P[1],cross_P[2]);

    }
    break;
  case 5:
    {
      struct vec *a,*b,*c;
      a=inputv(1);
      b=inputv(2);
      c=calcdiff(a,b,2);
        float p,q,r,s,res;
        p=c->i+c->j+c->k;
        q=calcdist(a);
        r=calcdist(b);
        s=p/(q*r);
        res=acos(s);
        printf("ANGLE IN RADIANS=%.2fπ\n",res);
        res=acos(s)*180*7/22;
        printf("ANGLE IN DEGREES=%.2f\n",res);
    }
    break;
  default :printf("***WRONG INPUT***\n");
  }
   printf("\nPress 1 for Vector menu or any other key to end Vector operations  \n");
        scanf("%d",&ch);
 }
 return 0;
}
