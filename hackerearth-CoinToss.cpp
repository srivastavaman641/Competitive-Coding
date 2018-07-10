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
void multiply1(ll a[1][3],ll b[3][3])
{
	ll x=(a[0][0]*b[0][0]%mod+a[0][1]*b[1][0]%mod+a[0][2]*b[2][0]%mod)%mod;
	ll y=(a[0][0]*b[0][1]%mod+a[0][1]*b[1][1]%mod+a[0][2]*b[2][1]%mod)%mod;
	ll z=(a[0][0]*b[0][2]%mod+a[0][1]*b[1][2]%mod+a[0][2]*b[2][2]%mod)%mod;
	a[0][0]=x;
	a[0][1]=y;
	a[0][2]=z;
}
void multiply(ll a[3][3],ll b[3][3])
{
    ll mul[3][3];
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            mul[i][j] = 0;
            for (int k=0;k<3;k++)
                mul[i][j]=(mul[i][j]+(a[i][k]*b[k][j])%mod)%mod;
        }
    }
    for (int i=0;i<3;i++)
        for (int j=0;j<3; j++)
            a[i][j]=mul[i][j];
}
void power(ll f[3][3],ll y)
{
	ll M[3][3]={{0,0,1},{1,0,1},{0,1,1}};
	if (y==1 || y==0)
        return;
 
    power(f,y/2);
    multiply(f,f);
 
    if (y%2!=0)
        multiply(f,M);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll f[1][3]={{2,4,7}};
		ll ans[3][3]={{0,0,1},{1,0,1},{0,1,1}};
		if(n==1)
		{
			cout<<2<<endl;
		}
		else if(n==2)
		{
			cout<<4<<endl;
		}
		else if(n==3)
		{
			cout<<7<<endl;
		}
		else{
			power(ans,n-3);
			multiply1(f,ans);
			cout<<f[0][2]<<endl;
		}
	}


	return 0;
}
