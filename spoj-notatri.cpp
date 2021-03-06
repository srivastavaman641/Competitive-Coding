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
   while(1)
   {
   		int n;
   		cin>>n;
   		if(n==0)
   			return 0;
   		int a[n];
   		for(int i=0;i<n;i++)
   		{
   			cin>>a[i];
   		}
   		sort(a,a+n);
   		ll ans=0;
   		for(int i=0;i<n;i++)
   		{
   			for(int j=i+1;j<n;j++)
   			{
   				int low=j+1,high=n;
   				int x=a[i]+a[j];
   				while(low<high)
   				{
   					int mid=(low+high)/2;
   					if(a[mid]>x)
   						high=mid;
   					else
   						low=mid+1;
   				}
   			if(low!=n)
   			 ans+=((n-1)-low+1);
   			}
   		}
   		cout<<ans<<endl;

   }


   return 0;
}
