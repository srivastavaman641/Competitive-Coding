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
   map<int,int>mp;
   for(int i=0;i<n;i++)
   {
   		cin>>a[i];
   		mp[a[i]]++;
   }
   sort(a,a+n);
   int ans;
   for(int i=0;i<n;i++)
   {
   		if(a[i]!=0){
   			ans=i;
   			break;
   		}
   }
   int ans1=n-ans;
   int cnt=0;
   for(int i=ans;i<n-1;i++)
   {
   		if(a[i]==a[i+1])
   			cnt++;
   }
   cout<<ans1-cnt<<endl;
   return 0;
}
