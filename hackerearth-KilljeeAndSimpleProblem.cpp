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
ll a[1005],tree[4005];
map<ll,ll>m;
void build(int node,int start,int end)
{
    if(start==end)
    {
        tree[node]=a[start];
        return;
    }
    int mid=(start+end)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,end);
    tree[node]=tree[2*node]+tree[2*node+1];
}
ll query(int node,int start,int end,int l,int r)
{
    if(start>r || end<l)
        return 0;
    if(start>=l && end<=r)
        return tree[node];
    ll mid=(start+end)/2;
    return query(2*node,start,mid,l,r)+query(2*node+1,mid+1,end,l,r);
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int n;
 cin>>n;
 ll cnt=0;
 for(int i=1;i<=n;i++)
    cin>>a[i];
build(1,1,n);
for(int i=1;i<=n;i++)
{
    for(int j=i;j<=n;j++){
     ll x=query(1,1,n,i,j);   
     if(!m[x]){
      cnt++;
      m[x]=1;
  }
}
}
cout<<cnt<<endl;
return 0;
}
