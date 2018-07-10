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
		string s;
		gs;
		while(s.length()==0)
			gs;
		//cout<<s<<endl;
		string s1[55];
		string str="";
		int k=0;
		vector<pii>v;
		for(int i=0;i<s.length();i++){
			while(s[i]!=' ' && i!=s.length())
			{
				str+=s[i];
				i++;
			}
			s1[k]=(str);
			v.pb(mp(str.length(),k));
			str="";
			k++;
		}
		
		sort(v.begin(),v.end());
		for(int i=0;i<v.size();i++)
		{
			cout<<" "<<s1[v[i].second];
		}
		cout<<endl;
	}


	return 0;
}
