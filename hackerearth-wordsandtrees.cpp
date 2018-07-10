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
vector<int>v[100005];
vector< pair<int,string> >v1;
string s[100005];
int vis[100005],idx[30],idx2[30];
char a[100005];
string dfs(int x)
{
	vis[x]=1;
	string ans="";
	ans+=a[x];
	for(int i=0;i<v[x].size();i++)
	{
		if(!vis[v[x][i]])
		{
			ans+=dfs(v[x][i]);
		}
	}
	return s[x]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   }
   for(int i=0;i<n-1;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		v[x].pb(y);
   		v[y].pb(x);
   }
   string str=dfs(1);
   while(q--)
   {
   		int l;
   		string t;
   		cin>>l>>t;
   		int cn=0;
   		memset(idx,0,sizeof idx);
   		memset(idx2,0,sizeof idx2);
   		string ans=s[l];
   		for(int i=0;i<ans.length();i++)
   		{
   			idx[ans[i]-'a']++;
   		}
   		for(int i=0;i<t.length();i++)
   		{
   			idx2[t[i]-'a']++;
   		}
   		for(int i=0;i<t.length();i++)
   		{
   			if(((idx2[t[i]-'a'])>(idx[t[i]-'a']))){
   				cn+=((idx2[t[i]-'a'])-(idx[t[i]-'a']));
   				idx2[t[i]-'a']=0;
   				idx[t[i]-'a']=0;
   			}
   		}
   		cout<<cn<<endl;
   }
   return 0;
}
