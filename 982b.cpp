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
#define pii pair<ll,ll>

using namespace std;
int a[400005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   priority_queue<pii,vector<pii>,greater<pii> >q;
   priority_queue<pii>q1;
   stack<pii>st;
   for(int i=1;i<=n;i++)
   {
   		ll x;
   		cin>>x;
   		q.push(mp(x,i));
   		q1.push(mp(x,i));
   }
    string s;
   cin>>s;
    if(n==1)
   {
   		cout<<1<<" "<<1<<endl;
   		return 0;
   }
   for(int i=0;i<2*n;i++)
   {
   		if(s[i]=='0')
   		{
   			cout<<q.top().second<<" ";
   			st.push(q.top());
   			q.pop();
   		}
   		if(s[i]=='1')
   		{
   			if(st.empty())
   			{
   				cout<<q1.top().second<<" ";
   				q1.pop();
   			}
   			cout<<st.top().second<<" ";
   			st.pop();
   		}
   }
   	cout<<endl;

   return 0;
}
