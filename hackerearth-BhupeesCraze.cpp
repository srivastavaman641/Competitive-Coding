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
string prv="";
ll fact[55];
string s[26];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   fact[0]=fact[1]=1;
   for(int i=2;i<=54;i++)
   		fact[i]=i*fact[i-1];
   while(t--)
   {
   		int n;
   		cin>>n;
   		map<int,string>m;
   		if(n==0){
   			cout<<prv<<endl;
   			continue;
   		}
   		ll mn=INT_MAX,idx=0;
   		for(int i=0;i<n;i++)
   		{
   			cin>>s[i];
   			m[i]=s[i];
   			set<char>st;
   			for(int j=0;j<s[i].length();j++)
   				st.insert(s[i][j]);
   			int x=st.size();
   			if(fact[x]<=mn)
   			{
   				mn=fact[x];
   				idx=i;
   			}
   		}
   		cout<<m[idx]<<endl;
   		prv=m[idx];

   }
   return 0;
}
