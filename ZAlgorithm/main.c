#include <stdio.h>
#include <string.h>
#define MAX 100
int main(int argc, char **argv)
{
	char s[MAX], p[MAX], input[MAX];
    long long int z[MAX], i, k, l, r, i1;
    //scanf("%s %s", s, p);
    strcpy(s,"asdfgasdf");
    strcpy(p,"asd");
    strcpy(input,p);
    strcat(input,"$");
    strcat(input,s);
    strcpy(input,"aabxaabxcaabxaabxay");
    printf("%s\n",input);
    
    z[0]=0;
    l=0;
    r=0;
    for(i=1;i<strlen(input);i++)
    {
        if(i>r)
        {
            r=l=i;
            while(r<strlen(input)&&input[r]==input[r-l])
            {
                r++;
            }
            z[i]=r-l;
            r--;
            printf("%d %d\n", l, r);
        }
        else
        {
            i1=i-l;
            if(i+z[i1]<r)
            {
                z[i]=z[i1];
            }
            else
            {
                l=i;
                while(r<strlen(input)&&input[r]==input[r-l])
                    r++;
            }
            z[i]=r;
            r--;
        }
    }
    for(i=0;i<strlen(input);i++)
        printf("%2d ",i);
    printf("\n");
    for(i=0;i<strlen(input);i++)
        printf("%2c ",input[i]);
    printf("\n");
    for(i=0;i<strlen(input);i++)
        printf("%2d ",z[i]);
    printf("\n");
    
    return 0;
}
