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
ll bit[100005],a[100005];
void update(ll x,ll val)
{
	for(;x<=100004;x+=x&(-x))
		bit[x]+=val;
}
ll query(ll x)
{
	ll sum=0;
	for(;x>0;x-=x&(-x))
		sum+=bit[x];
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,cnt=0,idx=1;
	while(cin>>n){
			//cin>>n;
			if(n==0){
				memset(bit,0,sizeof bit);
				memset(a,0,sizeof a);
				cnt=0,idx=1;
				cout<<endl;
				continue;
			}
			if(n==-1)
			{
				ll low=1,high=100005,ans=high+1;
				while(low<=high){
					ll mid=(low+high)/2;
					if(query(mid)>=(cnt+1)/2)
					{
						ans=min(ans,mid);
						high=mid-1;
					}
					else
						low=mid+1;
				}
   			//cout<<ans<<endl;
				cout<<a[ans]<<endl;
				update(ans,-1);
				cnt--;	
			}
			else
			{
				cnt++;
				a[idx]=n;
				update(idx,1);
				idx++;

			}

	}
	return 0;
}
