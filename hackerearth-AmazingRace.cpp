#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

int main()
{
	long int T;
	long long int N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		long long int arr[N+1],rear[N+1],front[N+1],k,temp;
		front[1]=0;
		rear[N]=0;
		for(long long int i=1;i<=N;i++)
		{
			cin>>arr[i];
			if(i==1)
				continue;
			else
			{
				front[i]=1;
				k=i-1;
				while(arr[k]<arr[i] && k>1)
				{
					front[i]+=front[k];
					temp=k;
					k-=front[temp];
				}
			}
		}
		long long int max=((front[N])*N)%M,index=N;
		for(long long int i=N-1;i>0;i--)
		{
			rear[i]=1;
			k=i+1;
			while(k<N && arr[k]<arr[i])
			{
				rear[i]+=rear[k];
				temp=k;
				k+=rear[temp];
			}
			long long int sight=(((rear[i]+front[i])%M)*(i))%M;
			if(sight>=max)
			{
				max=sight;
				index=i;

			}
		}
		cout<<index<<endl;
	}
	return 0;
}