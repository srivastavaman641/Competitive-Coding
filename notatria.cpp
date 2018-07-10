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
int ar[1000005];
int a[2005];
int main()
{
   while(1)
   {
   		int n;
   		cin>>n;
   		if(n==0)
   			return 0;

         for(int i=0;i<1000005;i++)
            ar[i]=0;

         memset(a,-1,sizeof a);

         for(int i=0;i<n;i++)
         {
            cin>>a[i];
            ar[a[i]]++;
         }
         sort(a,a+n);
   		for(int i=1000003;i>=0;i--)
         {
            ar[i]+=ar[i+1];
         }
         ll ans=0;
         for(int i=0;i<n;i++)
         {
            for(int j=i+1;j<n;j++)
            {
               if(a[i]+a[j]>1000000)
                  ans+=0;
               else
               ans+=(ar[a[i]+a[j]+1]);
            }
         }
         cout<<ans<<endl;
   }


   return 0;
}
