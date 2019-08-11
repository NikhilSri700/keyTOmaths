#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int binaryToDecimal()
{
    int num;
    printf("Enter binary number ");
    scanf("%d",&num);
    int d= 0;
    int b= 1;

    int temp = num;
    while (temp)
    {
        int r=temp%10;
        temp=temp/10;
        d+= r*b;
        b = b*2;
    }

   printf("Decimal equivalent for given number is %d",d);
   printf("\n");
}


void decToBinary()
{
    int num;
    printf("Enter decimal number ");
    scanf("%d",&num);
    int binaryNum[32];
    int i = 0;
    while (num>0)
    {
        binaryNum[i] = num%2;
        num=num/2;
        i++;
    }
   for (int j = i - 1; j >= 0; j--)
        printf("%d",binaryNum[j]);
    printf("\n");
}
char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
int DecimalToOctal()
{
    int oct=0,i=1;
    int num;
    printf("Enter decimal number ");
    scanf("%d",&num);

    while (num!= 0)
    {
        oct += (num%8)*i;
        num /= 8;
        i *= 10;
    }

    printf("Octal eqivalent is %d",oct);
    printf("\n");
}

void octaltohexa()
{
    int OCTVAL[] = {0, 1, 10, 11, 100, 101, 110, 111};

    long long oct,tempoct,b,place;
    char hex[65] = "";
    int r;

    place = 1;
    b = 0;

    printf("Enter any octal number: ");
    scanf("%lld", &oct);
    tempoct = oct;

    while(tempoct > 0)
    {
        r=tempoct%10;
        b=(OCTVAL[r]*place)+b;
        tempoct /= 10;

        place *= 1000;
    }
    while(b>0)
    {
        r= b % 10000;
        switch(r)
        {
            case 0:
                strcat(hex, "0");
                break;
            case 1:
                strcat(hex, "1");
                break;
            case 10:
                strcat(hex, "2");
                break;
            case 11:
                strcat(hex, "3");
                break;
            case 100:
                strcat(hex, "4");
                break;
            case 101:
                strcat(hex, "5");
                break;
            case 110:
                strcat(hex, "6");
                break;
            case 111:
                strcat(hex, "7");
                break;
            case 1000:
                strcat(hex, "8");
                break;
            case 1001:
                strcat(hex, "9");
                break;
            case 1010:
                strcat(hex, "A");
                break;
            case 1011:
                strcat(hex, "B");
                break;
            case 1100:
                strcat(hex, "C");
                break;
            case 1101:
                strcat(hex, "D");
                break;
            case 1110:
                strcat(hex, "E");
                break;
            case 1111:
                strcat(hex, "F");
            break;
        }

        b /= 10000;
    }

    strrev(hex);

    printf("Octal number: %lld\n", oct);
    printf("Hexadecimal number: %s", hex);
    printf("\n");
}

void decToHexa()
{
    int n;
    printf("Enter decimal number ");
    scanf("%d",&n);
    char hex[100];
    int i = 0;
    while(n!=0)
    {
        int temp  = 0;
        temp=n%16;
        if(temp < 10)
        {
            hex[i]=temp+48;
            i++;
        }
        else
        {
            hex[i]=temp+55;
            i++;
        }
            n=n/16;
    }
    printf("Hexadecimal equivalent is ");
    for(int j=i-1; j>=0; j--)
        printf(" %d",hex[j]);
    printf("\n");
}

int hexadecimalToDecimal()
{
    char hex[20];
    printf("Enter Hexadecimal value ");
    scanf("%s",hex);
    int i;
    int len = strlen(hex);
    int base=1;
    int d= 0;

    for (i=len-1;i>=0;i--)
    {   if (hex[i]>='0'&&hex[i]<='9')
        {
            d+=(hex[i]-48)*base;
            base=base*16;
        }
        else if (hex[i]>='A'&&hex[i]<='F')
        {
            d+=(hex[i]-55)*base;
            base=base*16;
        }
    }
    printf("Decimal equivalent is %d ",d);
    printf("\n");
}

 long long OctalToBinary()
{
    int oct;
    printf("Enter octal number ");
    scanf("%d",&oct);

    int d=0,i=0;
    long long b=0;

    while(oct!=0)
    {
        d+= (oct%10)*pow(8,i);
        ++i;
        oct/=10;
    }
    i=1;
    while (d!=0)
    {
        b+=(d%2)*i;
        d/=2;
        i*=10;
    }
    printf("Binary equivalent is %lld",b);
    printf("\n");
}

void HexToBin()
{
    char hex[20];
    printf("Enter hexadecimal value ");
    scanf("%s",hex);

    long int i = 0;

    while (hex[i])
    {

        switch (hex[i])
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        default:
            printf("\nInvalid hexadecimal digit %c",hex[i]);
        }
        i++;
    }
    printf("\n");
}

long long OctalToDecimal()
{
    int d=0,i=0;
    long long oct;
    printf("Enter octal number ");
    scanf("%lld",&oct);
    while(oct!= 0)
    {
        d += (oct%10) * pow(8,i);
        ++i;
        oct/=10;
    }

    i=1;

    printf("Decimal eqivalent is %d",d);
    printf("\n");
}

int BinarytoOctal()
{
    long long b;
    printf("Enter binary number ");
    scanf("%lld",&b);
    int oct=0, d=0,i=0;

    while(b!=0)
    {
        d+=(b%10)*pow(2,i);
        ++i;
        b/=10;
    }

    i=1;

    while (d!= 0)
    {
        oct+=(d%8)*i;
        d/=8;
        i*=10;
    }

    printf("Octal eqivalent is %d ",oct);
    printf("\n");
}


int con()
{
    int x;
    int ch=1;
    while(ch==1)
    {
        printf("\t\t\tCONVERSIONS\n1.Decimal to Binary\n2.Decimal to Octal\n3.Decimal to Hexadecimal\n4.Octal to Binary\n5.Octal to Decimal\n6.Octal to Hexadecimal\n7.Hexadecimal to Binary\n8.Hexadecimal to Decimal\n9.Binary to Decimal\n10.Binary to Octal\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:decToBinary();
            break;
            case 2:DecimalToOctal();
            break;
            case 3:decToHexa();
            break;
            case 4:OctalToBinary();
            break;
            case 5:OctalToDecimal();
            break;
            case 6:octaltohexa();
            break;
            case 7:HexToBin();
            break;
            case 8:hexadecimalToDecimal();
            break;
            case 9:binaryToDecimal();
            break;
            case 10:BinarytoOctal();
            break;
            default:printf("***Wrong input***\n");
        }
        printf("\nPress 1 for conversion menu or any other key to end conversion operations  \n");
        scanf("%d",&ch);
    }

    return 0;
}
