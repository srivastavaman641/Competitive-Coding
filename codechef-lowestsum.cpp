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
#define pii pair<ll,int>

using namespace std;
ll ptr[20005],a[20005],b[20005],ans[10005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   	ll n,qe;
   	cin>>n>>qe;
   	priority_queue< pii,vector<pii>,greater<pii> >q;
   	
   	for(ll i=0;i<n;i++)
   	{
   		cin>>a[i];
   		ptr[i]=0;
   		ans[i]=0;
   	}
    for(ll i=0;i<n;i++)
   	{
   		cin>>b[i];
   	}
   	sort(a,a+n);
   	sort(b,b+n);
   	for(int i=0;i<n;i++)
   	{
   		q.push(mp(a[i]+b[0],i));
   	}
   	for(int i=0;i<10005;i++)
   	{
   		if(q.empty())break;
   		pii pr=q.top();
   		q.pop();
   		ptr[pr.second]++;
   		ans[i]=pr.first;
   		if(ptr[pr.second]<n)
   		q.push(mp(a[pr.second]+b[ptr[pr.second]],pr.second));	
   	}
   	while(qe--){
   		ll k;
   		cin>>k;
   		cout<<ans[k-1]<<endl;
   		}
   	}
   return 0;
}
