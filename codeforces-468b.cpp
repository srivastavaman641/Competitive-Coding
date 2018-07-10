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
int n,a,b,mn,mx;
int fn(int x)
{
	if(x==1)
		return 0;
	int cn=0;
	while(x!=1 && x>0)
	{
		x/=2;
		cn++;
	}
	return cn;
}
int recur(int l,int h)
{
	if(l>=h)
		return 0;
	int ln=h-l+1;
	if(mn<l+(ln/2) && mx>=l+(ln/2))
		return fn(ln);
	else if(mn>=l+(ln/2) && mx>l+(ln/2))
		return recur(l+(ln/2),h);
	else
		return recur(l,l+(ln/2));
	return 0;

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin>>n>>a>>b;
    mn=min(a,b);
    mx=max(a,b);
 
   if(mn<=n/2 && mx>n/2)
   {
   		cout<<"Final!"<<endl;
   		return 0;
   }
   else{
   		cout<<recur(1,n)<<endl;
   		return 0;
   }
   

   return 0;
}
