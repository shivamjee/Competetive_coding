#include <stdio.h>

int main() {
    int i,j,t,n;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        int c[n-1];
        int temp=0;
        int sum=0;
        for(j=0;j<n-1;j++)
        {
            scanf("%d",&c[j]);
            temp+=c[j];
        }
        for(j=1;j<n+1;j++)
            sum+=j;
        printf("%d",sum-temp);    
    }
	return 0;
}