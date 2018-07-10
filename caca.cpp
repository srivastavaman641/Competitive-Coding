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
map<char,int>m;
vector< pair<char,int> >v;
int vis[400005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	set< pair<char,int> >:: iterator it;

	for(int i=0;i<n;i++)
	{
		v.pb(mp(s[i],i));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
	{
		int x=v[i].second;
		vis[x]=1;
		k--;
		if(k==0)
			break;
	}
	string s1="";
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
			s1+=s[i];
	}
	cout<<s1<<endl;


	return 0;
}
