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
   string s;
   cin>>s;
   string s1=s;
   int q;
   cin>>q;
   for(int i=0;i<q;i++)
   {
   		char a;
   		int x;
   		cin>>x>>a;
   		s[x-1]=a;
   }
   string s2=s;
   int m;
   cin>>m;
   for(int i=0;i<m;i++)
   {
   		int x,y;
   		cin>>x>>y;
   		reverse(s.begin()+x-1,s.begin()+y);
   }
   cout<<s2<<endl;
   cout<<s<<endl;
   int cnt=0;
   for(int i=0;i<s.length();i++)
   {
   		if(s2[i]==s[i])
   			cnt++;
   }
   cout<<cnt<<endl;


   return 0;
}
