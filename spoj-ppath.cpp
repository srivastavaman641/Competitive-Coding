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
bool isprime[10005];
int dis[10005];
void seive(int n)
{
	isprime[1]=isprime[0]=0;
	for(int i=2;i*i<=n;i++)
	{
		if(isprime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				isprime[j]=0;
		}
	}
}
int digittonum(int a[])
{
	int num=0;
	for(int i=0;i<4;i++)
	{
		num=num*10+a[i];
	}
	return num;
}
void numtodigit(int x,int a[])
{
	int idx=3;
	while(x)
	{
		a[idx]=x%10;
		x/=10;
		idx--;
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   for(int i=2;i<=10004;i++)
   		isprime[i]=1;
   seive(10004);
   while(t--)
   {
   		int n,m;
   		int digit[4];
   		cin>>n>>m;
   		memset(dis,-1,sizeof dis);
   		dis[n]=0;
   		queue<int>q;
   		q.push(n);
   		while(!q.empty())
   		{
   			int f=q.front();
   			q.pop();
   			if(f==m)
   				break;
   			for(int i=0;i<4;i++)
   			{
   				numtodigit(f,digit);
   				for(int j=0;j<=9;j++)
   				{
   					digit[i]=j;
   					int x=digittonum(digit);
   					if(isprime[x] && dis[x]==-1 && x>=1000)
   					{
   						dis[x]=dis[f]+1;
   						q.push(x);
   					}
   				}
   			}
   		}
   		if(dis[m]==-1)
   			cout<<"Impossible"<<endl;
   		else
   			cout<<dis[m]<<endl;

   }


   return 0;
}
