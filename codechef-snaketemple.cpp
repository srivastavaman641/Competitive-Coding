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
ll a[100005],l[100005],r[100005];
int main()
{
	cout<<-1%20;
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   	int n;
   	ll s=0;
   	cin>>n;
   	for(int i=0;i<n;i++){
   		cin>>a[i];
   		s+=a[i];
   	}
   	int k=0;
   	for(int i=0;i<n;i++)
   	{
   		if(a[i]>=k+1)
   			k++;
   		else
   			k=a[i];
   		l[i]=k;
   	}
   	k=0;
   	for(int i=n-1;i>=0;i--)
   	{
   		if(a[i]>=k+1)
   			k++;
   		else
   			k=a[i];
   		r[i]=k;
   	}
   	ll mx=0;
   	for(int i=0;i<n;i++)
   	{
   		mx=max(mx,min(l[i],r[i]));
   	}
   	ll ans=s-(mx*mx);
   	cout<<ans<<endl;
   }


   return 0;
}
