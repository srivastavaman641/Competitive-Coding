
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
   int mx=INT_MIN;
   map<int,int>m;
   int c1=0,c2=0;
   for(int i=0;i<n;i++)
   {
   		int x;
   		cin>>x;
   		if(x<0 && !m[x]){
   			c1++;
   			m[x]=1;
   		}
   		else if(x>0 && !m[x]){
   			m[x]=1;
   			c2++;
   		}
   }
   cout<<c1+c2<<endl;


   return 0;
}
