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
ll a[1005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,w;
   cin>>n>>w;
   ll cnt=0,mns=INT_MAX,mxs=INT_MIN;
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   		cnt+=a[i];
   		mxs=max(mxs,cnt);
   		mns=min(mns,cnt);
   }
   ll ul=w,lll=0;
   if(mxs>w){
   		cout<<0<<endl;
   		return 0;
   }
   else if(mxs<=0)
   		ul=w;
   else
   		ul=w-mxs;
   if(mns<0)
   		lll=-mns;
   	if(lll>ul){
   		cout<<0<<endl;
   		return 0;
   	}
   	else
   		cout<<ul-lll+1<<endl;

   return 0;
}
	