#include<stdio.h>

#define MAX 10

int main()
{
    int mp[MAX], p[MAX], m, n, i, j, t, flag[MAX], rem, diff, min;

    mp[0]=300; 
    mp[1]=600; 
    mp[2]=350; 
    mp[3]=200; 
    mp[4]=750; 
    mp[5]=125; 
    m=6; 

    
    p[0]=115;
    p[1]=500;
    p[2]=358;
    p[3]=200;
    p[4]=375;
    n=5; 

    for(i=0; i<m; i++)
        flag[i]=0;

    printf("Memory Partitions:\n");
    for(i=0; i<m; i++)
        printf("%d ", mp[i]);
    printf("\n");

    printf("Processes:\n");
    for(i=0; i<n; i++)
        printf("%d ", p[i]);
    printf("\n\n");

    
    for(i=0; i<n; i++)
    {
        rem = -1;
        min = mp[m-1]+1;

        for(j=0; j<m; j++)
        {
            if(flag[j]==0 && mp[j]>=p[i])
            {
                diff = mp[j]-p[i];
                if(diff<min)
                {
                    min = diff;
                    rem = j;
                }
            }
        }

        if(rem!=-1)
        {
            flag[rem]=1;
            printf("Process %d is allocated memory partition %d of size %d.\n", i+1, rem+1, p[i]);
        }
        else
        {
            printf("Process %d cannot be allocated memory.\n", i+1);
        }
    }

    return 0;
}
