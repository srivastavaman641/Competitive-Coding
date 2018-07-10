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
int a[105];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   n=n/2;
   for(int i=1;i<=n;i++)
   		cin>>a[i];
   sort(a,a+n+1);
   int pos1=1,pos2=2,ans1=0,ans2=0;
   for(int i=1;i<=n;i++)
   {
   		ans1=ans1+abs(pos1-a[i]);
   		ans2=ans2+abs(pos2-a[i]);
   		pos1+=2;
   		pos2+=2;
   }
   cout<<min(ans1,ans2)<<endl;


   return 0;
}
