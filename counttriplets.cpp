#include <iostream>
#include<algorithm>
using namespace std;



int  main()
{
	int n,sum;
	cin>>n>>sum;
	int arr[n],count =0;
	for(int i =0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int k =0;k<n-2;k++)
	{
		int i =k+1,j=n-1;
		while(i<j)
		{
			if(arr[k]+arr[i]+arr[j]<sum)
			{
				for(int l=i+1;l<=j;l++)
				{
					cout<<arr[k]<<" "<<arr[i]<<" "<<arr[l]<<endl;
					count++;	
				}
				i++;
			}
			else
			{
				j--;
			}
		}
	}
	cout<<count<<endl;

}
