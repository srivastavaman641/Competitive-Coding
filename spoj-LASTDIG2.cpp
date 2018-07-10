#include<bits/stdc++.h>
#define ll long long int

using namespace std;
ll power(ll x,ll y,ll MOD)
{
	ll ans=1;
	while(y)
	{
		if(y%2)
			ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		y/=2;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		ll b;
		cin>>s>>b;
		ll c=0;
		for(int i=0;i<s.length();i++)
		{
			c=(c*10+s[i]-'0')%10;
		}
		cout<<power(c,b,10)<<endl;
	}
	return 0;
}
