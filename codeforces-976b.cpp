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
   ll n,m,k;
   ll ansx,ansy;
   cin>>n>>m>>k;
   if(k>n-1)
   {
   		ansx=n;
   		ansy=1;
   		k-=n-1;
   }
   else{
   	ansx=k+1;
   	ansy=1;
   	cout<<ansx<<" "<<ansy<<endl;
   	return 0;
   }
   if(k>m-1)
   {
   		ansx=n;
   		ansy=m;
   		k-=m-1;
   }
   else
   {
   		ansx=n;
   		ansy=k+1;
   		cout<<ansx<<" "<<ansy<<endl;
   		return 0; 
   }
   ll x=k%(m-1);
   ll y=k/(m-1);
   if(y%2==0)
   {
   		ansx=n-y;
   		ansy=m;
   		if(x>1)
   		ansy=m-x+1;
   }
   else
   {
   		ansx=n-y;
   		ansy=2;
   		if(x>1)
   		ansy=2+x-1;
   }
   if(x)
   {
   		ansx--;
   }
   cout<<ansx<<" "<<ansy<<endl;


   return 0;
}
