#include<bits/stdc++.h>

using namespace std;
#define ll long long int
int main()
{
	int n,q;
	cin>>n>>q;
	vector<int>v[n];
    ll ans=0;
    while(q--)
    {
       ll z,x,y;
       cin>>z>>x>>y;
       if(z==1)
       {
       	ll idx=(x^ans)%n;
       	//cout<<idx<<endl;
       	v[idx].push_back(y);
       }
       else if(z==2)
       {
       	ll idx=(x^ans)%n;
       	ll sz=v[idx].size();
       	ans=v[idx][y%sz];
       	cout<<ans<<endl;
       }
    }
    return 0;
}