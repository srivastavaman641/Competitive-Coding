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
int a[205],bit[105];
void update(int x,int val)
{
	for(;x<105;x+=x&(-x))
		bit[x]+=val;
}
int query(int x)
{
	int sum=0;
	for(;x>0;x-=x&(-x))
		sum+=bit[x];
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	map<int,int>m;
	int cnt=0;
	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		if(!m[a[i]])
		{
			cnt++;
			m[a[i]]=cnt;
		}
	}
	int ans=0;
	for(int i=1;i<=2*n;i++)
		a[i]=m[a[i]];
	for(int i=2*n;i>0;i--)
	{
		ans+=query(a[i]-1);
		update(a[i],1);
	}
	cout<<ans<<endl;


	return 0;
}
