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
   		int m;
   		cin>>m;
   		if(m==0)
   			break;
   		string s;
   		cin>>s;
   		int k=0;
   		int l=s.length();
   		int n=l/m;
   		char a[n][m];
   		for(int i=0;i<n;i++)
   		{
   			for(int j=0;j<m;j++)
   			{
   				if(i%2==0)
   				{
   					a[i][j]=s[k];
   					k++;
   				}
   				else
   				{
   					a[i][m-j-1]=s[k];
   					k++;
   				}
   			}
   		}
   		for(int i=0;i<m;i++)
   		{
   			for(int j=0;j<n;j++)
   			{
   				cout<<a[j][i];
   			}
   		}
   		cout<<endl;
   }


   return 0;
}
