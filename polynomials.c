#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct polynomial
{

	int coeff;
	int exp;
	struct polynomial *link;

}polynomial;

void lawpol()
{
FILE *ptr;
char str1;
ptr=fopen("quad.txt","r");
str1 = fgetc(ptr);
while (str1 != EOF)
		{
			printf ("%c", str1);
			str1 = fgetc(ptr);
		}
fclose(ptr);
}

void node1(polynomial **);

void print(polynomial **);


void add(polynomial **head1,polynomial **head2);


void mult1(polynomial **head1,polynomial **head2);


void solquad(polynomial **head);


polynomial *head1,*head2;


int  pol()
{
	head1=head2=NULL;
	int ch=1;
	while(ch==1)
	{
	printf("\t\t\tpolynomials And Quadratic equations\n");
	printf("1.Addition\n2.Multiplication\n3.Solving Quadratic equation\n4.All Formulas\n");
	printf("Enter your choice\n");
	int n;
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		{
			printf("Note-Enter polynomial in decreasing orders of exponent\n");
			printf("enter first polynomial\n");
			while(ch)
	        {
		       node1(&head1);
		       printf("press 1 to continue-:");
		       scanf("%d",&ch);

	        }
	        print(&head1);
	        ch=1;
	        printf("\n");
	        printf("enter second polynomial\n");
	        while(ch)
	        {
		       node1(&head2);
		       printf("press 1 to continue-");
		       scanf("%d",&ch);

	        }

	        print(&head2);
	        printf("\n");
            add(&head1,&head2);
            head1=head2=NULL;
        }break;
        case 2:
        {
        	printf("Note-Enter polynomial in decreasing orders of exponent\n");
			printf("enter first polynomial\n");
			while(ch)
	        {
		       node1(&head1);
		       printf("press 1 to continue-:");
		       scanf("%d",&ch);

	        }
	        print(&head1);
	        ch=1;
	        printf("\n");
	        printf("enter second polynomial\n");
	        while(ch)
	        {
		       node1(&head2);
		       printf("press 1 to continue-");
		       scanf("%d",&ch);

	        }

	        print(&head2);
	        printf("\n");
	        mult1(&head1,&head2);


        }break;
        case 3:
        {
        	printf("Note-Enter LHS of Quadratic equation in standard form\nax^2+bx+c=0\n");
        	ch=0;
			while(ch<3)
	        {
		       node1(&head1);
		       ch++;

	        }
	        print(&head1);
	        printf("\n");
	        solquad(&head1);
        }
        break;
        case 4:lawpol();
        break;
        default:printf("***WRONG INPUT***");
    }
    printf("\nPress 1 for polynomial menu or any other key to end polynomial operations  \n");
    scanf("%d",&ch);

    }

	return 0;
}


void node1(polynomial **head)
{
	polynomial *p=(polynomial *)malloc(sizeof(polynomial));
	polynomial *temp;
	printf("Enter coefficient and then it's exponent-:");
	scanf("%d\n",&p->coeff);
	scanf("%d",&p->exp);
	if(*head==NULL)
	{
		*head=p;
		p->link=NULL;
	}

	else
	{
		temp=*head;
		while(temp->link!=NULL)
			temp=temp->link;
		temp->link=p;

	}
	p->link=NULL;
}


void print(polynomial **head)
{
	polynomial *temp=*head;


	printf("poynomial is -\n");
	while(temp!=NULL)
	{

		printf("%dx^%d",temp->coeff,temp->exp);
		printf("+");
		temp=temp->link;
	}


}
void add(polynomial **head1,polynomial **head2)
{

	polynomial *temp1,*temp2,*temp3;
	temp3=NULL;
	polynomial *head3=NULL;
	temp1=*head1;
	temp2=*head2;
	while(temp1!=NULL && temp2!=NULL)
	{
		polynomial *p=(polynomial *)malloc(sizeof(polynomial));
		if((temp1->exp) > (temp2->exp))
		{
			p->coeff=temp1->coeff;
			p->exp=temp1->exp;
			temp1=temp1->link;

		}
		else if((temp1->exp) < (temp2->exp))
		{
			p->coeff=temp2->coeff;
			p->exp=temp2->exp;

			temp2=temp2->link;

		}
		else
		{
			p->coeff=(temp1->coeff) + (temp2->coeff);
			p->exp=temp2->exp;

                  temp2=temp2->link;
                   temp1=temp1->link ;
		}
		if(head3==NULL)
			{
				head3=p;
				p->link=NULL;
			}
			else
			{
				temp3=head3;
				while(temp3->link!=NULL)
					temp3=temp3->link;
				temp3->link=p;
				p->link==NULL;
			}

	}
	if(temp2==NULL){
		while(temp1!=NULL)
		{
			polynomial *p=(polynomial *)malloc(sizeof(polynomial));
			p->coeff=temp1->coeff;
			p->exp=temp1->exp;
			while(temp3->link!=NULL)
					temp3=temp3->link;
				temp3->link=p;
				p->link==NULL;
				temp1=temp1->link;
		}


	}
	else
	{
		while(temp2!=NULL)
		{
			polynomial *p=(polynomial *)malloc(sizeof(polynomial));
			p->coeff=temp2->coeff;
			p->exp=temp2->exp;
			while(temp3->link!=NULL)
					temp3=temp3->link;
				temp3->link=p;
				p->link==NULL;
				temp2=temp2->link;
		}


	}
	temp3=head3;
	printf("Resutl is-:\n");
	while(temp3!=NULL)

	{

		printf("%dx^%d+",temp3->coeff,temp3->exp);
		temp3=temp3->link;
	}
}

void mult1(polynomial **head1,polynomial **head2)
{
	polynomial *temp1=*head1;
	polynomial *temp2=*head2;
	polynomial *head=NULL;

	while(temp1)
	{

		while(temp2)
		{
			polynomial *p=(polynomial *)malloc(sizeof(polynomial));
			p->coeff=(temp1->coeff)*(temp2->coeff);
			p->exp=(temp1->exp)+(temp2->exp);
			if(head==NULL)
	        {
		        head=p;
	        }

	        else
	        {
	        	polynomial *temp;
		        temp=head;
		        while(temp->link!=NULL)
			      temp=temp->link;
		        temp->link=p;

	        }
	        p->link=NULL;
            temp2=temp2->link;


		}
		temp1=temp1->link;
		temp2=*head2;
	}
	temp1=head;
	while(temp1)
	{
		temp2=temp1->link;

		while(temp2)
		{
			if(temp1->exp==temp2->exp)
			{
				temp1->coeff=(temp1->coeff)+(temp2->coeff);
				polynomial *temp=head;
				while(temp->link!=temp2 && temp!=NULL)
				{
					temp=temp->link;
				}
				if(temp2->link!=NULL)
				{
				  temp->link=temp2->link;
				}
				else{
					temp2->link=NULL;
				}



			}
			temp2=temp2->link;

		}
		temp1=temp1->link;
	}

	print(&head);
}
void solquad(polynomial **head)
{
	polynomial *temp=*head;
	float a=temp->coeff;
	temp=temp->link;
	float b=temp->coeff;
	temp=temp->link;
	float c=temp->coeff;
    float D=(b*b)-(4*a*c);
	if(D>=0)
	{
		float k=sqrt(D);
		printf("%.2f\n",k );
		float l=((-1*b)+k)/(2*a);

		float n=((-1*b)-k)/(2*a);
		printf("Roots are -:,%.2f %.2f",l,n);
	}
	else

	{
		float k=sqrt(-1*D);
		printf("%f\n",k );
		float n=(b/(2*a))*-1;
		printf("Roots are-: %.2f+i%.2f   %.2f-i%.2f\n",n,k/(2*a),n,k/(2*a) );
	}
}
