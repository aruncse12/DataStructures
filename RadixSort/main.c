#include <stdio.h>
#define MAX 100
void radixSort(long long int arr[], long long int n, long long int digit)
{
    long long int freq[10],out[n],i,j;
    for(i=0;i<10;i++)
        freq[i]=0;
    
    for(i=0;i<n;i++)
        out[i]=0;
    
    for(i=0;i<n;i++)
        freq[(arr[i]/digit)%10]++;
    
    for(i=1;i<10;i++)
        freq[i]+=freq[i-1];
    
    for(i=n-1;i>=0;i--)
    {
        out[freq[(arr[i]/digit)%10]-1]=arr[i];
        freq[(arr[i]/digit)%10]--;
    }
    
    for(i=0;i<n;i++)
    {
        arr[i]=out[i];
    }
        
}
int main(int argc, char **argv)
{
    long long int numTc, m, arrM[MAX], i, max, digit;
	scanf("%lld",&numTc);
    while(numTc)
    {
        scanf("%lld",&m);
        digit=1;
        max=0;
        for(i=0;i<m;i++)
        {
            scanf("%lld",&arrM[i]);
            if(max<arrM[i])
                max=arrM[i];
        }
        while(max)
        {
            radixSort(arrM,m,digit);
            digit*=10;
            max/=10;
        }
        printf("\n");
        for(i=0;i<m;i++)
        {
            printf("%lld ",arrM[i]);
        }
        numTc--;
    }
	return 0;
}
