
/*#include <stdio.h>
#include <stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main () {
   int n;

   printf("Before sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {
      printf("%d ", values[n]);
   }

   qsort(values, sizeof(values)/sizeof(int), sizeof(int), cmpfunc);

   printf("\nAfter sorting the list is: \n");
   for( n = 0 ; n < 5; n++ ) {   
      printf("%d ", values[n]);
   }
   return(0);
}*/
#include <stdio.h>
#include<stdlib.h>

int cmpFunc(const void *a,const void *b)
{
    return (*(int*)a-*(int*)b);
}

int main() {
    int i,j,t,n,m;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        int count = 0;
        int arr1[n+m],arr2[m];
        for(j=0;j<n;j++)
            scanf("%d",&arr1[j]);
        for(j=0;j<m;j++)
            scanf("%d",&arr1[n+j]);
        qsort(arr1,sizeof(arr1)/sizeof(int),sizeof(int),cmpFunc);
        for(j=0;j<n+m;j++)
            printf("%d ",arr1[j]);
        printf("\n");


    }
   return 0;
}