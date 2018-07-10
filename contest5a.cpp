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
map<int,int>mp1,mp2;
vector<int>v;
int a[200005],b[200005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cin>>a[i];
   	mp1[a[i]]+=1;
   }
   int m;
   cin>>m;
   for(int i=0;i<m;i++)
   {
   	cin>>b[i];
   	mp2[b[i]]+=1;
   }
   for(int i=0;i<m;i++)
   {
   	if(mp2[b[i]]!=mp1[b[i]]){
   		v.push_back(b[i]);
   		mp2[b[i]]=0;
   		mp1[b[i]]=0;
   	}
   }
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++)
   {
   	cout<<v[i]<<" ";
   }
   return 0;

}
