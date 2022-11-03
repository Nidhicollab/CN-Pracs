#include<stdio.h>
#include<math.h>
/*int* reverse_array(int *b,int q)
{
    int *c,i;
    c=(int *)malloc(q*sizeof(int));
    for(i=(q-1);i>=0;i--)
    {
        c[i]=b[q-1-i];
    }
    return *c;
}*/
void main()
{
    int i,n,p,m,*a,sum1,sum2,sum3,y,q,w;
    int *b;
    printf("Enter the no. of bits in your string : ");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    m=n;
    printf("Enter the bits : \n");
    for(i=0;i<=n-1;i++)
    {
        scanf("%d",&a[i]);
    }

    //int *a = reverse_array(k,n);

    //to calculate p, no. of parity bits needed
    for(i=0;i<=n-1;i++)
    {
        if((int)(pow(2,i)) >= m+i+1)
        {
            p=i;
            break;
        }
    }
    printf("\nThe no. of parity bits are : %d\n",p);

    q=m+p;

    b=(int *)malloc(q*sizeof(int));

    for(y=0;y<=p-1;y++)
    {
            b[(((int)(pow(2,y)))-1)]=9;

    }



    int count_index_a = 0;
    for(i=0;i<=q-1;i++)
    {
        if(b[i]!=9)
        {
            b[i]=a[count_index_a];
            count_index_a++;
        }
    }


    printf("\n\nHamming Code with parity bits as 9 : \n");
    for(i=0;i<=q-1;i++)
    {
        printf("%d ",b[i]);

    }

    int x=0,z=0,par_count=0;

    for(i=0;i<p;i++)
    {
        x=((int)(pow(2,i)))-1;

        while(x<(q))
        {
            for(z=0;z<(int)(pow(2,i));z++)
            {
               if((x+z)<(q))
               {
                   if(b[x+z]==1)
                   {
                       par_count++;
                   }

               }
            }

            x+=2*(int)(pow(2,i));
        }

        printf("\n\nParity bit count at position %d : %d\n",(int)(pow(2,i)),par_count);

        if(par_count%2==0)
        {
            b[(int)(pow(2,i)-1)]=0;
        }
        else
        {
            b[(int)(pow(2,i)-1)]=1;
        }

        par_count = 0;
    }

    //int *c = reverse_array(b,q);

    printf("\n\nHamming Code is : \n");
    for(i=0;i<=q-1;i++)
    {
        printf("%d ",b[i]);

    }

    printf("\n");

    int *u,*f;


    printf("\n\nEnter the no. of bits of received data : ");
    scanf("%d",&w);

    u=(int *)malloc(w*sizeof(int));
    printf("Enter the bits : \n");
    for(i=0;i<=w-1;i++)
    {
        scanf("%d",&u[i]);
    }

    printf("\n\nReceived Code Word is : \n");
    for(i=0;i<=w-1;i++)
    {
        printf("%d ",u[i]);
    }

    //calculate r value

    //q=g+p;

    int v=0,s=0,par_count1=0;
    int *r;
    r=(int *)malloc(p*sizeof(int));

    for(i=0;i<p;i++)
    {
        v=((int)(pow(2,i)))-1;

        while(v<w)
        {
            for(s=0;s<(int)(pow(2,i));s++)
            {
               if(v+s<w)
               {
                   if(u[v+s]==1)
                   {
                       par_count1++;
                   }

               }
            }

            v+=2*(int)(pow(2,i));
        }

        printf("\n\nParity bit count at position %d : %d\n",(int)(pow(2,i)),par_count1);


        if(par_count1%2==0)
        {
            //b[(int)(pow(2,i)-1)]=0;
            r[p-1-i]=0;
        }
        else
        {
            //b[(int)(pow(2,i)-1)]=1;
            r[p-1-i]=1;
        }

        par_count1 = 0;
    }

    printf("\n\nThe value of r is : \n");

    for(i=0;i<p;i++)
    {
        printf("%d\t",r[i]);
    }

    //conversion of r (binary)  to r ( decimal )

    int decimal_num=0;

    int index=p-1;

    for(i=index;i>=0;i--)
    {
        if(r[i]==1)
        {
            decimal_num+=(int)(pow(2,index-i));
        }
    }


    printf("\n\nThe decimal value of r is : %d",decimal_num);

    printf("\n\nHence error detected at position %d in transmitted code word\n",decimal_num);

    if(decimal_num!=0)
    {
        if(u[decimal_num-1]==1)
        {
            u[decimal_num-1]=0;
        }
        else
        {
            u[decimal_num-1]=1;
        }
    }

    printf("\n\nCorrected received code word is : \n");

    for(i=0;i<=w-1;i++)
    {
        printf("%d ",u[i]);

    }

    printf("\n");
}
