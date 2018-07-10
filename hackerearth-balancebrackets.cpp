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
	string s;
	cin>>s;
	int n;
	cin>>n;
	stack<char> st;
	int count=0;
	if(n==2)
	{
		for(int i=0; i<s.length(); i++)
		{
			if(s[i]=='(')
			{
				if(st.empty())
				{
					count=0;
				}
				st.push('(');
				count++;
			}
			else if(s[i]==')')
			{
				st.pop();
			}
		}
	}
	else if(n==1)
	{
		for(int i=s.length()-1 ; i>=0 ; i--)
		{
			if(s[i]==')')
			{
				if(s.empty())
				{
					count=0;
				}
				st.push(')');
				count++;
			}
			else if(s[i]=='(')
			{
				st.pop();
			}
		}
	}
	cout<<count;
	return 0;
}
