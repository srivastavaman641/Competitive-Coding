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
#define INF 1e18
#define pii pair<int,int>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll k;
	cin>>k;
	map<int,int>mp;
	map<int,pii>m;
	int flag=0;
	for(int i=1;i<=k;i++)
	{
		ll n;
		cin>>n;
		ll x[n+1],s=0;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
			s+=x[j];
		}
		if(flag==0){
			for(int j=1;j<=n;j++)
			{
				if(mp[s-x[j]] && m[s-x[j]].first!=i)
				{
					cout<<"YES"<<endl;
				//ans.pb()
					cout<<m[s-x[j]].first<<" "<<m[s-x[j]].second<<endl;
					cout<<i<<" "<<j<<endl;
					flag=1;
					break;
				}
				else
				{
					mp[s-x[j]]=1;
					m[s-x[j]]=make_pair(i,j);
				}

			}
		}

	}
	if(flag==0)
		cout<<"NO"<<endl;
	return 0;
}




