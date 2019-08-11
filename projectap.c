#include<stdio.h>
#include<stdlib.h>
float cheack(float n);
void makeseries(float a,float d,float n);
int deci1(float z)
{

    // Directly print the number with .2f precision
    printf("%.2f , ", z);
    return 0;
}

void lawap()
{
FILE *ptr;
char str1;
ptr=fopen("ap.txt","r");
str1 = fgetc(ptr);
while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(ptr);
		}
fclose(ptr);
}

float sum(float a,float d,float n);
int AM(float s[5]);
int ap()
{
  int c;
 int ch=1;
 while(ch==1)
 {
 printf("\t\t\tARITHMETIC PROGRESSION\n");
 printf("WHAT YOU WANT TO DO IN AP:-\n1)TO MAKE A SERIES \n2)TO FIND SUM OF SERIES\n3)TO CHECK WHEATHER A SERIES IN AP [ARITHMETIC MEAN]\n4)TO FIND THE nth VALUE OF AN AP SERIES\n5)FINDING ELEMENTS WHEN FIRST AND LAST ELEMENTS ARE GIVEN AND NO. OF ELEMENTS\n  BETWEEN THEM IS GIVEN \n6)ALL FORMULAS\n");
 scanf("%d",&c);
 switch(c)
 {
  case 1:
  {
   float a,d,n;
   printf("\nENTER FIRST VALUE OF SERIES");
   scanf("%f",&a);
   printf("\nENTER THE COMMON DIFFERENCE");
   scanf("%f",&d);
   L:
   printf("\nENTER THE POSITION OF LAST VALUE");
   scanf("%f",&n);
   if(n<0||cheack(n)!=0)
   {
    printf("\nINVALID INPUT");
    goto L;
   }
   makeseries(a,d,n);
  }
  break;
  case 2:
  {
   float a,d,n;
   printf("\n ENTER THE FIRST ELEMENT OF SERIES");
   scanf("%f",&a);
   printf("\n ENTER THE COMMON DIFFERENCE");
   scanf("%f",&d);
   J:
   printf("\n ENTER THE POSITION OF LAST VALUE ");
   scanf("%f",&n);
   if(n<0||cheack(n)!=0)
   {
    printf("\nINVALID INPUT");
    goto J;
   }
   sum(a,d,n);
  }
  break;
  case 3:
  {
   printf("\nENTER A SERIES WITH 5 ELEMENTS");
   float s[5];
   int i,flag;
   for(i=0;i<5;i++)
   scanf("%f",&s[i]);
   flag=AM(s);
   if(flag==1)
   printf("\nTHIS IS AN ARITHMETIC PROGRESSION SERIES");
   else
   printf("\nTHIS IS NOT AN ARITHMETIC PROGRESSION SERIES");
   }
   break;
  case 4:
  {
   printf("\nENTER A SERIES WITH 5 ELEMENTS");
   float s[5],n,m;
   int j,flag;
   V:
   for(j=0;j<5;j++)
   scanf("%f",&s[j]);
   flag=AM(s);
   if(flag!=1)
   {
    printf("\nTHIS IS NOT AN ARITHMETIC PROGRESSION SERIES\n RE-ENTER AGAIN");
    goto V;
   }
   K:
   printf("\nENTER THE POSITION OF THE SERIES AT WHICH YOU WANT THE VALUE");
   scanf("%f",&n);
   if(n<0||cheack(n)!=0)
   {
    printf("\nINVALID INPUT");
    goto K;
   }
   m=s[0]+(n-1)*(s[2]-s[1]);
   printf("\nTHE VALUE is");
   deci1(m);
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
     float d;
     d=(s-a)/(n+1);
     float i,c=a;
     deci1(a);
     for(i=0;i<n;i++)
     {
      c=c+d;
      deci1(c);

     }
     deci1(s);
    }
    break;
    case 6:lawap();
    break;
   default:printf("***Wrong input***\n");
   }
    printf("\nPress 1 for AP menu or any other key to end AP operations  \n");
        scanf("%d",&ch);
 }
 return 0;
}
float cheack(float n)
{
 float v;
 v=(int) n;
 v=n-v;
 return v;
}

void makeseries(float a,float d,float n)
{
 float s,i;
 for(i=1;i<=n;i++)
 {
  s=a+(i-1)*d;
  deci1(s);
 }

}

float sum(float a,float d,float n)
{
float s;
s=n*(2*a+(n-1)*d)/2;
deci1(s);
}

int AM(float s[5])
{
    int flag=0;
  if(s[1]==(s[0]+s[2])/2&&s[3]==(s[2]+s[4])/2)
  flag=1;
  return flag;
}
