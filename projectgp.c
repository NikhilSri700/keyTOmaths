#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sum1(int x,int y,int z)
{
 int w;
 w=(x*(1-pow(y,z)))/(1-y);
 printf("THE SUM OF THE SERIEES IS %d\n",w);
}
void input1(int *ptr,int i)
{
    printf("ENTER THE %d ELEMENT OF YOUR SERIES",i);
    scanf("%d",ptr);
}
void lawgp()
{
FILE *ptr;
char str1;
ptr=fopen("gp.txt","r");
str1 = fgetc(ptr);
while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(ptr);
		}
fclose(ptr);
}
struct node
{
 int data;
 struct node *link;
};
int deci(float z)
{

    // Directly print the number with .2f precision
    printf("%.2f , ", z);
    return 0;
}
int gp()
{
 int ch=1;
 while(ch==1)
 {
 int a;
 printf("\t\t\tGEOMETRIC PROGRESSION\n");
 printf("ENTER YOUR CHOICE\n1)MAKE A SERIES\n2)CALCULATE THE SUM \n3)TO CHECK THE SERIES\n4)TO FIND NTH VALUE OF THE SERIES\n5)TO INSERT ELEMENTS BETWEEN GIVEN FIRST AND LAST ELEMENTS\n6)ALL FORMULAS\n");
 scanf("%d",&a);
 switch(a)
 {
  case 1:
   {
     int a,d,n,i,c;
     printf("\n ENERT FIRST VALUE ,COMMON RATIO AND NO. OF ELEMENTS IN SERIES RESPECTIVELY\n");
     scanf("%d%d%d",&a,&d,&n);
     c=a;
     struct node *start=NULL,*curr=NULL,*nnode,*temp;

     for(i=0;i<=n;i++)
     {
      nnode=(struct node*)malloc(sizeof(struct node));
      nnode->data=c;
      nnode->link=NULL;
      if(start==NULL)
      {
       start=nnode;
       curr=nnode;
      }
      else
      {
       curr->link=nnode;
       curr=nnode;
      }
      c=c*d;
     }
     temp=start;
     while(temp->link!=NULL)
     {
       printf("%d ,",temp->data);
       temp=temp->link;
     }
   }
   break;
  case 2:
    {
     int a,r,s;
     printf("ENERT FIRST VALUE ,COMMON RATIO AND POSITION OF LAST ELEMENT RESPECTIVELY\n");
     scanf("%d%d%d",&a,&r,&s);
     sum1(a,r,s);
    }
    break;
  case 3:
    {
     int *p,i,ar[5];
     p=&ar[0];
     for(i=0;i<5;i++)
        input1((p+i),i+1);
        int c,v;
        c=sqrt((*p)*(*(p+2)));
        v=sqrt((*(p+2))*(*(p+4)));
        if(c==*(p+1)&&v==*(p+3))
            printf("THIS IS A GEOMETRIC PROGRESSION SERIES\n");
        else
            printf("THIS IS NOT A GEOMETRIC PROGRESSION SERIES\n");

    }
    break;
  case 4:
    {
       int a,r,n,s;
       printf("ENERT FIRST VALUE ,COMMON RATIO AND POSITION AT WHICH YOU WANT THE VALUE RESPECTIVELY\n");
       scanf("%d%d%d",&a,&r,&n);
       s=a*pow(r,n-1);
       printf("%d",s);
    }
    break;
  case 5:
    {
     float a,n,s;
     printf("ENTER THE FIRST ELEMENT\n");
     scanf("%f",&a);
     printf("ENTER THE LAST ELEMENT\n");
     scanf("%f",&s);
     printf("ENTER THE TOTAL ELEMENTS B/W THEM\n");
     scanf("%f",&n);
     float r;
     r=pow(s/a,1.0/(n+1));
      float i,c=a;
     deci(a);
     for(i=0;i<n;i++)
     {
      c=c*r;
      deci(c);

     }
     deci(s);
    }
    break;
    case 6:lawgp();
    break;
  default: printf("***WRONG INPUT***\n");
    }
 printf("\nPress 1 for GP menu or any other key to end GP operations  \n");
        scanf("%d",&ch);
}
return 0;
}
