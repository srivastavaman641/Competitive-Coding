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
ll a[100005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,k,l,cnt=0;
   	cin>>n>>k>>l;
   for(int i=1;i<=n*k;i++)
   		cin>>a[i];
   sort(a,a+n*k+1);
   for(int i=1;i<=n*k;i++)
   {
   		if(a[i]-a[1]<=l)
   			cnt++;
   }
   if(cnt<n)
   {
   		cout<<0<<endl;
   		return 0;
   }
   
	int left=0;
	long long int sum=0;
	for(int i=n*k; i>0; i--)
	{
		left++;
		if(a[i]-a[1]<=l && left>=k)
		{
			left-=k;
			sum+=a[i];
		}
	}
   cout<<sum<<endl;




   return 0;
}
	