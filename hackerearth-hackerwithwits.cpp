#include<bits/stdc++.h>
using namespace std;
int a[105];
int n;
int fn()
{
	int ans=0;
	int c1=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1)
			c1++;
		else
			c1=0;
		ans=max(ans,c1);
	}
	return ans;
}
int main()
{
	cin>>n;
	int c=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=fn();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]==1 && a[j]==0)||(a[i]==0 && a[j]==1))
			{
				swap(a[i],a[j]);
				ans=max(ans,fn());
				swap(a[j],a[i]);
			}
		}
	}
	cout<<ans<<endl;

}