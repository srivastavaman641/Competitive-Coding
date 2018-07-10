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
	int n;
	cin>>n;
	vector< string > v,v1;
	map<string,int>m;
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		if(!m[s]){
			v.pb(s);
			m[s]++;
		}
		else
			m[s]++;
	}
	for(int i=0;i<n;i++){
		string s1;
		cin>>s1;
		if(m[s1])
		{
			m[s1]--;
		}
		else
		{
			v1.pb(s1);
		}
	}
	for(int i=0;i<v1.size();i++){
		int mn = 1e6,idx=0,ans=0;
		for(int j=0;j<v.size();j++)
		{
			if( m[v[j]] && v[j].length()==v1[i].length())
			{
				ans=0;
				for(int k=0;k<v[j].length();k++)
				{
					if(v[j][k]!=v1[i][k])
						ans++;
				}
				if(ans<=mn)
				{
					mn=ans;
					idx=j;
				}
			}
		}
		m[v[idx]]--;
		cnt+=mn;
	}
	cout<<cnt<<endl;
	return 0;
}
