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
   string s;
   cin>>s;
   s+="a";s+="b";s+="c";
   if(n==1)
   {
   		if(s[0]=='0')
   		{
   			cout<<"No"<<endl;
   			return 0;
   		}
   		else
   		{
   			cout<<"Yes"<<endl;
   			return 0;
   		}
   }
   if(n==2)
   {
   		if(s[0]==s[1] && s[0]=='0')
   		{
   			cout<<"No"<<endl;
   			return 0;
   		}
   		else if(s[0]!=s[1])
   		{
   			cout<<"Yes"<<endl;
   			return 0;
   		}
   }
   for(int i=0;i<n;i++)
   {
   		if(s[i]=='1' && s[i+1]=='1')
   		{
   			cout<<"No"<<endl;
   			return 0;
   		}
   		if(s[i]=='0' && s[i+1]=='0' && s[i+2]=='0')
   		{
   			cout<<"No"<<endl;
   			return 0;
   		}
   		if(i==0 && s[i]=='0' && s[i+1]=='0')
   		{
   			cout<<"No"<<endl;
   			return 0;
   		}
   		if(i==n-1 && s[i]=='0' && s[i-1]=='0')
   		{
   			cout<<"No"<<endl;
   			return 0;
   		}
   }

   cout<<"Yes"<<endl;

   return 0;
}
