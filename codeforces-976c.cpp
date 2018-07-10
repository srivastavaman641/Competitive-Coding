#include<bits/stdc++.h>
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
#define pii pair<long long int,long long int>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,idxi=-1,idxj=-1;
   cin>>n;
   vector< pair<long long int,pii> >v;
   for(int i=1;i<=n;i++)
   {
   		long long int x,y;
   		cin>>x>>y;
   		v.pb(mp(x,mp(y,i)));
   }
   sort(v.begin(),v.end());
   long long int mn=INT_MAX,mx=INT_MIN;
   for(int i=0;i<n;i++)
   {
   		long long int a=v[i].first;
   		long long int b=v[i].second.first;
   		int low=i+1,high=n-1,ans=n;
   		while(low<=high)
   		{
   			int mid=low+(high-low)/2;
   			//cout<<"mid"<<mid<<endl;
   			if(v[mid].second.first<=b)
   			{
   				//cout<<"abcd"<<v[mid].second<<endl;
   				ans=v[mid].second.second;
   				idxj=ans;
   				idxi=v[i].second.second;
   				break;
   			}
   			if(v[mid].first==a && v[mid].second.first>=b)
   			{
   				idxi=v[mid].second.second;
   				idxj=v[i].second.second;
   				break;
   			}
   			else
   			{
   				high=mid-1;
   			}
   		}
   }
   cout<<idxj<<" "<<idxi<<endl;

   return 0;
}
