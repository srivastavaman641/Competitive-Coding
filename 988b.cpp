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
   int n;
   cin>>n;
   vector< pair<int,string> >v;
   for(int i=0;i<n;i++){
   		string s;
   		cin>>s;
   		v.pb(mp(s.length(),s));
   }
   sort(v.begin(),v.end());
   int flag=1;
   for(int i=1;i<n;i++)
   {
   		string s=v[i].second;
   		string s1=v[i-1].second;
   		if(s.find(s1)==string::npos)
   		{
   			flag=0;
   			break;
   		}
   }
   if(flag==0)
   {
   		cout<<"NO"<<endl;
   		return 0;
   }
   else
   {
   		cout<<"YES"<<endl;
   		for(int i=0;i<n;i++)
   		{
   			cout<<v[i].second<<endl;
   		}
   }



   return 0;
}
