//Sets
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void uni() //Function for finding union of 2 sets
{
	int a,b,i,j,k;
	printf("Enter size of Set A ");
	scanf("%d",&a);
	printf("\nEnter size of Set B ");
	scanf("%d",&b);
	int a1[100],a2[100],a3[100];

	

	printf("\n Enter elements for set A "); //Taking input from user
	for(i=0;i<a;i++)
		scanf("%d",&a1[i]);

	printf("\n Enter elements for set B ");
	for(i=0;i<b;i++)
		scanf("%d",&a2[i]);
	for(i=0;i<a;i++)
		{a3[i]=a1[i];
			j=i;
		}
		j++;
		int l=j;

	for(i=0;i<b;i++)
	{
		int flag=0;
		for(k=0;k<j;k++)
			if(a2[i]==a3[k])
				{
					flag=1;
					break;
				}
		if(flag==0)
			{
				a3[l]=a2[i];
				l++;
			}
	}

		printf("Union of set A and B is - ");
	for(i=0;i<l;i++)
	{
		printf(" %d ",a3[i]);
	}
}
//To find intersection of Two sets

void inter()
{
	int a,b,i,k;
	printf("Enter size of Set A ");
	scanf("%d",&a);
	printf("\nEnter size of Set B ");
	scanf("%d",&b);
	int a1[100],a2[100];

	
	printf("\n Enter elements for set A "); //Taking input from user
	for(i=0;i<a;i++)
		scanf("%d",&a1[i]);

	printf("\n Enter elements for set B ");
	for(i=0;i<b;i++)
		scanf("%d",&a2[i]);

		printf("Intersection of set A and B is - ");
	int flag=0;
	for(i=0;i<a;i++)
	{
		for(k=0;k<b;k++)
			if(a1[i]==a2[k])
				{	flag=1;
					printf(" %d ",a1[i]);
				}
	}
	if(flag==0)
		printf(" Ø ");
}

void nosub()
{
	long long int a,n;
	printf("Enter size of Set ");
	scanf("%lli",&a);
	n=pow(2,a);
	printf("Number of subsets this set can have is = %lli",n);
}




void diff()
{
	int a,b,i,k;
	printf("Enter size of Set A ");
	scanf("%d",&a);
	printf("\nEnter size of Set B ");
	scanf("%d",&b);
	int a1[100],a2[100],a3[100];


	printf("\n Enter elements for set A "); //Taking input from user
	for(i=0;i<a;i++)
		scanf("%d",&a1[i]);

	printf("\n Enter elements for set B ");
	for(i=0;i<b;i++)
		scanf("%d",&a2[i]);
	int l=0;
	for(i=0;i<a;i++)
	{
		int flag=0;
		for(k=0;k<b;k++)
			if(a1[i]==a2[k])
				{
					flag=1;
					break;
				}
		if(flag==0)
			{
				a3[l]=a1[i];
				l++;
			}
	}
	printf("Elements in A-B are - ");
	if(l==0)
	printf(" Ø ");
	else
	for(i=0;i<l;i++)
		printf(" %d ",a3[i]);
	printf("\n");


}

int set()
{
	int x;
	int ch=1;
	while(ch==1)
	{
		printf("\t\t\tSET THEORY\n1.Find Union of two Sets\n2.Find intersection of two Sets\n3.Find total number of subsets of a set\n4.Difference between two sets\n5.All Laws of sets\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:uni();
			break;
			case 2:inter();
			break;
			case 3:nosub();
			break;
			case 4:diff();
			break;
			case 5:law();
			break;
			default:printf("***Wrong input***\n");
		}
		printf("\nPress 1 for Set menu or any other key to end set operations  \n");
		scanf("%d",&ch);
	}

	return 0;
}
