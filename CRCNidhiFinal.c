#include<stdio.h>
#include<stdlib.h>
int* EXORdivision(int *q,int *r,int n1,int n2)
{
    int i,j,l,*s,*t,pos,count;//i = dividend, j = divisor
    s=(int *)malloc(n2*sizeof(int));
    t=(int *)malloc(n2*sizeof(int));

    for(j=0; j < n2; j++)
    {
        t[j] = r[j];
    }

    i=0;
    while(i<=n1+n2-1)// i traversing the whole dividend
    {
        for(j=0;j<n2;j++) // j no. of bits in divisor
        {
            //for(k=0;k<n2;k++) // k no. of bits in the dividend, traversing the dividend

                if(t[j]==q[j])
                {
                    s[j]=0;
                }
                else
                {
                    s[j]=1;
                }

        }
        /*printf("\nRemainder after 1st exor in the division : \n");
        for(l=0;l<n2;l++)
        {
            printf("%d\t",*(s+l));
        }*/

        for(j=0;j<n2;j++)
        {
            if(s[j]==1)
            {
                pos=j;
                count=n2-j;
                break;
            }
        }
        for(j=0;j<count;j++)
        {
            t[j]=s[pos];
            pos++;
        }
        if(i==0)
        {
           i=i+n2;
        }

        for(j=0;j<n2-count;j++)
        {
            t[count+j]=r[i];
            i++;
        }

        printf("\nRemainder after 2nd exor in the division : \n");
        for(l=0;l<n2;l++)
        {
            printf("%d\t",*(t+l));
        }

    }

    return t;
}
void main()
{
    int i,j,n1,n2,*p,*q,*r, *u;
    printf("Enter the number of bits in the data word : ");
    scanf("%d",&n1);
    p=(int *)malloc(n1*sizeof(int));
    printf("\nEnter the bits : \n\n");
    for(i=0;i<=n1-1;i++)
    {
        printf("Enter the bit : ");
        scanf("%d",&p[i]);
    }

    printf("\nData Word is : \n");
    for(i=0;i<=n1-1;i++)
    {
        printf("%d\t",*(p+i));
    }

    printf("\n\nEnter the number of bits in the generator polynomial string : ");
    scanf("%d",&n2);
    q=(int *)malloc(n2*sizeof(int));
    printf("\nEnter the bits : \n\n");
    for(i=0;i<=n2-1;i++)
    {
        printf("Enter the bit : ");
        scanf("%d",&q[i]);
    }

    printf("\nGenerator polynomial string is : \n");
    for(i=0;i<=n2-1;i++)
    {
        printf("%d\t",*(q+i));
    }

    r=(int *)malloc((n1+n2-1)*sizeof(int));

    for(i=0;i<n1;i++)
    {
        r[i]=p[i];
    }

    for(i=0;i<(n2-1);i++)
    {
        r[n1+i]=0;
    }

    printf("\n\nGenerator Polynomial final dividend after extra 0's : \n");
    for(i=0;i<(n1+n2-1);i++)
    {
        printf("%d\t",*(r+i));
    }



    int *t= EXORdivision(q,r,n1,n2);
    printf("\n\nCRC is : \n");
    for(j=0; j<n2-1;j++)
    {
        printf("%d\t", *(t+j));
    }

     u=(int *)malloc((n1+n2-1)*sizeof(int));
     for(int z=0; z<n1; z++)
     {
         u[z]= p[z];
     }
     for(int y=0; y<n2-1; y++)
     {
         u[n1+y] = t[y];
     }

     printf("\nTransmitted Data Word : \n");
        for(int l=0;l<n2+n1-1;l++)
        {
            printf("%d\t",*(u+l));
        }
}
