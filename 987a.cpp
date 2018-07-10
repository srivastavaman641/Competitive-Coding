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
   map<string,string>m;
   map<string,int>m1;
   string s[]={"Power","Time","Space","Soul","Reality","Mind"};
   string s2[]={"purple","green","blue","orange","red","yellow"};
   for(int i=0;i<6;i++)
   {
   		m[s2[i]]=s[i];
   }
   vector<string>ans;
   for(int i=1;i<=n;i++)
   {
   		string s;
   		cin>>s;
   		m1[s]=1;
   }
   int c=0;
   for(int i=0;i<6;i++)
   {
   		if(!m1[s2[i]]){
   			c++;
   			ans.pb(m[s2[i]]);
   		}
   }
   cout<<c<<endl;
   for(int i=0;i<c;i++)
   {
   		cout<<ans[i]<<endl;
   }

   return 0;
}
