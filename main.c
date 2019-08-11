#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int ch=1;
    while(ch==1)
    {
        printf("\t\t\tKEY TO MATHS\nSelect chapter :- \n1.Matrices\n2.Polynomial\n3.Converstions\n4.Vectors\n5.Sets\n6.Arithmatic Progression\n7.Geometric Progression\n8.Complex Numbers\n9.Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:mat();
            break;
            case 2:pol();
            break;
            case 3:con();
            break;
            case 4:vec();
            break;
            case 5:set();
            break;
            case 6:ap();
            break;
            case 7:gp();
            break;
            case 8:com();
            break;
            case 9:exit(1);
            default:printf("***Wrong input***\n");
        }
        printf("\nPress 1 for main menu and any other key to exit \n");
        scanf("%d",&ch);
    }

    return 0;
}
