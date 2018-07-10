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

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   ll a[n+1];
      a[0]=0;
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   		a[i]+=a[i-1];
   }

   int q;
   cin>>q;
   while(q--)
   {
   		int i;
   		cin>>i;
   		int l=1,r=n,ans=n+1;
   		while(l<=r)
   		{
   			int mid=l+(r-l)/2;
   			if(a[mid]>=i)
   			{
   				ans=min(mid,ans);
   				r=mid-1;
   			}
   			else
   				l=mid+1;
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
