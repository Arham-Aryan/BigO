#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int a[6000][6000];

int main ()
{
    int i,j,n,degree=0,edge=0,b=0;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);


    //generating graph
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=(rand()%2);
            printf("%d ",a[i][j]);
        }printf("\n");
    }printf("\n");



    //making it undirected and printing
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=a[j][i];
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }printf("\n");

    double time=clock();
    //calculating degree
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            {
                if(i==j){degree++;}
                degree++;
            }
        }
    }

    //calculating edges
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1 && a[j][i]==1)
            {
                edge++;
                a[j][i]=0;
            }
        }
    }
    if(degree=2*edge){b=1;}
    double t1= clock()-time;
    double t2=t1/CLOCKS_PER_SEC;
    double t3=t2*1000000000;
    printf("Total time= %0.3lf nano seconds\n",t3);
    printf("Edge= %d\n",edge);
    printf("Degree= %d\n",degree);
    if(b=1){printf("The Handshaking Theorem holds up\n");}
    else{printf("The Handshaking Theorem does not hold up\n");}
}
