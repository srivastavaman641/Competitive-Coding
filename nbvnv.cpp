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
   int t;
   cin>>t;
   while(t--)
   {
   		ll n,ans=0;
   		cin>>n;
   		queue<ll>q;
   		map<ll,int>mp;
   		q.push(n);
   		while(!q.empty())
   		{
   			ll f=q.front();
   			q.pop();
   			if(f==1 && n==1){
   				break;
   			}
   			if(f==1)
   			{
   				ans++;
   				break;
   			}
   			if(f==n-1)
   			{
   				ans++;
   				n--;
   			}
   			if(f%2==0 && !mp[f/2]){
   				q.push(f/2);
   				mp[f/2]=1;
   			}
   			if(f%3==0 && !mp[f/3]){
   				q.push(f/3);
   				mp[f/3]=1;
   			}
   			if(!mp[f-1]){
   				q.push(f-1);
   				mp[f-1]=1;
   			}
   			
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
