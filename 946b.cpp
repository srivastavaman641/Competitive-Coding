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
   ll m,n;
   cin>>m>>n;
   while(1)
   {
   	if(m==0 || n==0)
   				break;
   		if(m>=2*n)
   		{
   			ll a=m/n;
   			ll b=m%n;
   			if(a%2==0)
   			{
   				m=b;
   			}
   			else
   				m=b+n;
   		}
   		else if(n>=2*m)
   		{
   			ll a=n/m;
   			ll b=n%m;
   			if(a%2==0)
   			{
   				n=b;
   			}
   			else
   				n=b+m;
   		}
   		else
   			break;

   }
   cout<<m<<" "<<n<<endl;

   return 0;
}
