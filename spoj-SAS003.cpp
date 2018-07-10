#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
ll a[100005],b[100005],y[100005],bb[100005],isprime[1000005];
void seive()
{
	for(int i=0;i<=1000002;i++)
		isprime[i]=1;
	isprime[0]=isprime[1]=0;
	for(int i=2;i*i<=1000002;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=1000002;j+=i)
				isprime[j]=0;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n;
	seive();
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>x;
	for(int i=0;i<x;i++)
		cin>>b[i];
	if(isprime[a[0]])
	{
		y[0]=1;
	}
	else
		y[0]=0;

	for(int i=1;i<n;i++)
	{
		if(isprime[a[i]])
		{
			y[i]=1;
			y[i]+=y[i-1];
		}
		else
			y[i]+=y[i-1];
	}
	for(int i=0;i<x;i++)
	{
		if(b[i]>=0)
		{
			bb[i]=y[b[i]];
		}
		else
		{
			bb[i]=y[n-1]-y[abs(b[i])-1];
		}
	}
	for(int i=1;i<x;i++)
		bb[i]+=bb[i-1];
	int q;
	cin>>q;
	while(q--)
	{
		ll idx;
		cin>>idx;
		if(idx>bb[x-1])
			cout<<-1<<endl;
		else
		{
			int k=lower_bound(bb,bb+x,idx)-bb;
			int val,val1;
			if(k!=0)
				val=idx-bb[k-1];
			else 
				val=idx;
			int low,high,ans;
			if(b[k]>=0)
			{
				low=0,high=b[k],ans=b[k]+1,val1=0;
			}
			else
			{
				low=abs(b[k]),high=n-1,ans=n,val1=y[abs(b[k])-1];
			}
			while(low<=high)
			{
				int mid=(low+high)/2;
				if(y[mid]-val1>=val)
				{
					ans=min(ans,mid);
					high=mid-1;
				}
				else
					low=mid+1;
			}
			cout<<a[ans]<<endl;
		}
	}
	return 0;
}
