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
#define INF 1e18
#define pii pair<int,int>

using namespace std;
typedef unsigned long long int ull;

ull a[100005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   	ull n,k;
   	cin>>n>>k;
   	map<ull,ull> mp;
   	for(int i=0;i<n;i++)
   	{
   		cin>>a[i];
   	}
   	int l=0,r=k;
   	ull ans=0;
   	mp[a[0]]++;
   	for(int i=1;i<k;i++)
   		mp[a[i]]++;
   	for(l=0;l<n;l++)
   	{
   		if(r==n)
   			break;
   		while(r<n && mp[a[l]])
   		{
   			if(a[r]==a[l])
   			{
   				mp[a[l]]++;
   				r++;
   			}
   			else{
   				mp[a[l]]--;
   				r++;
   			}
   		}
   		}
   		ans=ans+r-l;
   		mp[a[l]]--;
   	ans=ans+(r-l+1)*(r-l+2)/2;
   	cout<<ans<<endl;
   	}
   return 0;
}
