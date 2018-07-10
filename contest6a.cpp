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
bool vis[100005];
int ans[10000];
void seive(int n)
{
    memset(vis, true, sizeof(vis));
 	vis[1]=false;
    for (int p=2; p*p<=n; p++)
    {
        
        if (vis[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                vis[i] = false;
        }
    }         
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   seive(100004);
   int t;
   cin>>t;
   
   while(t--){
   	int n;
   	cin>>n;
   	int c=0;
   	for(int i=1;i<=n;i++)
   	{
   		if(vis[i]==1)
   			c++;
   	}
   	if(c%2==0)
   		cout<<"Bob"<<endl;
   	else
   		cout<<"Alice"<<endl;
}

   return 0;
}