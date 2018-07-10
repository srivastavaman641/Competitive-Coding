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
int a[105],b[105];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,d;
   cin>>n>>d;
   memset(a,0,sizeof a);
   int mn=INT_MAX;
   for(int i=0;i<n;i++)
   {
   		cin>>b[i];
   }	
   sort(b,b+n);
   for(int i=0;i<n;i++)
   {
   		for(int j=i;j<n;j++)
   		{
   			if(b[j]-b[i]<=d)
   			{
   				mn=min(mn,(n-(j-i+1)));
   			}
   		}
   }
   cout<<mn<<endl;
   return 0;
}
