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
   int t;
   cin>>t;
   while(t--)
   {
   		int n,k;
   		cin>>n>>k;
   		vector<int>v1,v2;
   		for(int i=0;i<n;i++)
   		{
   			int x;
   			cin>>x;
   			if(i%2==0)
   				v1.pb(x);
   			else
   				v2.pb(x);
   		}
   		int sm1=0,sm2=0;
   		int k1=v1.size(),l=v2.size();
   		for(int i=0;i<k1;i++)
   			sm1+=v1[i];
   		for(int i=0;i<l;i++)
   			sm2+=v2[i];
   		if(sm2>sm1)
   		{
   			cout<<"YES"<<endl;
   			continue;
   		}
   		sort(v1.rbegin(),v1.rend());
   		sort(v2.begin(),v2.end());
   		
   		int mn=min(k1,l);
   		for(int i=0;i<k;i++)
   		{
   			if(i>mn-1)
   				break;
   			int x=v1[i];
   			v1[i]=v2[i];
   			v2[i]=x;
   		}
   		sm1=0,sm2=0;
   		for(int i=0;i<k1;i++)
   			sm1+=v1[i];
   		for(int i=0;i<l;i++)
   			sm2+=v2[i];
   		if(sm2>sm1)
   		{
   			cout<<"YES"<<endl;
   		}
   		else
   			cout<<"NO"<<endl;

   }

   return 0;
}
