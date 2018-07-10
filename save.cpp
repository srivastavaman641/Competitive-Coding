#include<bits/stdc++.h>
#define LL long long int
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
int ar[2005];
int br[2005];
int ed[2005];
int ed1[2005];
int main()
{
	int n;
	cin>>n;
	int i,j;
	f(i,n)
	{
	cin>>ar[i+1];
     if(ar[i+1]==1)
     	br[i+1]=2;
     else
     	br[i+1]=1;
    }

    int l=1,r=1;
        ed[1]=0;
        ed[2]=1;

      for(i=2;i<n;i++)
      {
         if(ar[i]>=ar[i-1])
         	ed[i+1]=ed[i]+1;
         else
         	ed[i+1]=1;
      }
      ed1[n]=0;
      ed1[n-1]=1;
      for(i=n-1;i>1;i--)
      {
      	  if(ar[i]<=ar[i+1])
      	  	ed1[i-1]=ed1[i]+1;
      	  else
      	  	ed1[i-1]=1;
      }
     

      int mx=1;
      int cnt=1;
      for(i=1;i<=n;i++)
      {
      	cnt=0;
      	for(j=i;j<=n;j++)
      	{   
      		if(j==i || br[j]>=br[j-1])
      			cnt++;
      		if(cnt<(j-i+1))
      			break;
      		if((i==1 || br[i]>=ar[i-1]) && (j==n || br[j]<=ar[j+1]) && mx<(j-i+1+ed[i]+ed1[j]))
      		{
      			mx=max(mx,j-i+1+ed[i]+ed1[j]);
      			//cout<<i<<" "<<j<<endl;
      		}
      		if((i==1 || br[i]>=ar[i-1]) && mx<(j-i+1+ed[i]))
      			mx=max(mx,j-i+1+ed[i]);
      		if((j==n || br[j]<=ar[j+1]) && mx<(j-i+1+ed1[j]))
      			mx=max(mx,j-i+1+ed1[j]);
      		
      	}
      }

      cout<<mx<<endl;

	return 0;
}