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
#define pii pair<string,int>

using namespace std;
string s1[10005],s2[10005];
ll p[10005];
map<string,int>m1,m2,m;
map<string,int> :: iterator it;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		int n;
   		cin>>n;
   		if(n==1)
   		{
   			cout<<0<<endl;
   			continue;
   		}
   		m.clear();
   		m1.clear();
   		m2.clear();
   		for(int i=1;i<=n-1;i++)
   		{
   			cin>>s1[i]>>s2[i]>>p[i];
   			m[s1[i]]++;
   			m[s2[i]]++;
   			m2[s2[i]]=i;
   			m1[s1[i]]=i;
   		}
   		int start,end;
   		for(it=m.begin();it!=m.end();it++)
   		{
   			if((it->second)==1)
   			{
   				if(m1[it->first])
   					start=m1[(it->first)];
   				else
   					end=m2[(it->first)];
   			}
   		}
   		int i=start,j=end;
   		int ans=0;
   		while(i!=j)
   		{
   			cout<<s1[i]<<" "<<s2[i]<<" "<<p[i]<<endl;
   			ans+=p[i];
   			i=m1[s2[i]];
   		}
   		cout<<s1[j]<<" "<<s2[j]<<" "<<p[j]<<endl;
   		ans+=p[j];
   		cout<<ans<<endl;
   }


   return 0;
}
