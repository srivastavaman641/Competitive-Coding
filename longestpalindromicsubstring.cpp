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
bool isprime[10004];
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
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   fill(isprime,isprime+10004,1);
	seive(10004);
   while(t--)
   {
   		string s;
   		cin>>s;
   		int ans=1;
   		int n=s.length();
   		for(int i=1;i<n;i++)
   		{
   			int low=i-1,high=i+1;
   			while(low>=0 && high<n && s[low]==s[high])
   			{
   				ans=max(high-low+1,ans);
   				low--;
   				high++;
   			}
   			low=i-1,high=i;
   			while(low>=0 && high<n && s[low]==s[high]){
   				ans=max(ans,high-low+1);
   				low--;
   				high++;
   			}
   		}
   		if(isprime[ans])
			cout<<"PRIME"<<endl;
		else
			cout<<"NOT PRIME"<<endl;
   }


   return 0;
}
