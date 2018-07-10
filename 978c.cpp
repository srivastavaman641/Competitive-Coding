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
ll a[200005];
ll b[200005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m;
   cin>>n>>m;
   a[0]=0;
   for(int i=1;i<=n;i++){
   		cin>>a[i];
   		a[i]+=a[i-1];
   }
   for(int i=1;i<=m;i++)
   		cin>>b[i];
   for(int i=1;i<=m;i++)
   {
   		ll x=b[i];
   		int low=1,high=n,ans=n+1;
   		while(low<=high)
   		{
   			int mid=(low+high)/2;
   			if(a[mid]>=x)
   			{
   				ans=min(ans,mid);
   				high=mid-1;
   			}
   			else
   				low=mid+1;
   		}
   		cout<<ans<<" "<<x-a[ans-1]<<endl;
   }


   return 0;
}
