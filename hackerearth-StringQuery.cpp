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
ll bit[26][200005];
bool vis[200005];
void update(int c,int x,int val)
{
	for(;x<=200004;x+=x&(-x))
		bit[c][x]+=val;
}
int query(int c,int x)
{
	int sum=0;
	for(;x>0;x-=x&(-x))
		sum+=bit[c][x];
	return sum;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   int m;
   cin>>s>>m;
   int n=s.length();
   for(int i=0;i<s.length();i++)
   		update(s[i]-'a',i+1,1);
   while(m--)
   {
   		char c;
   		int x;
   		cin>>x>>c;
   		int  ch=c-'a';
   		int low=1,high=200004,ans=high+1;
   		while(low<=high)
   		{
   			int mid=(low+high)/2;
   			if(query(ch,mid)>=x)
   			{
   				ans=min(ans,mid);
   				high=mid-1;
   			}
   			else
   				low=mid+1;
   		}
   		update(ch,ans,-1);
   		vis[ans-1]=1;
   }
   for(int i=0;i<n;i++)
   {
   		if(vis[i]==0)
   			cout<<s[i];
   }
   cout<<endl;


   return 0;
}
