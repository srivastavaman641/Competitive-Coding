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
   while(t--){
   	int n,k,c;
   	cin>>n>>k>>c;
   	vector<ll> v;
   	for(int i=0;i<n;i++)
   	{
   		ll A;
   		cin>>A;
   		v.pb(A);
   	}
   	sort(v.begin(),v.end());
   	ll ans=0;
   	for(int i=0;i<n;i++)
   	{
   		int num = v[i],m=k,cnt=1;
   		cout<<num<<"is num \n";
                while(m--){
                //int idx = lower_bound(v.begin(),v.end(),c*num) - v.begin();
               // cout<<"idx is "<<idx<<endl;
                ll low=0,high=v.size();
   			while(low<high)
   			{
   				int mid=(high+low)/2;
   				if(v[mid]>=c*num)
   					high=mid;
   				else
   					low=mid+1;
   			}

                if(low!=v.size()){
                        ++cnt;
                        num = v[low];
                        v.erase(v.begin() + low);
                        //cout<<v.size()<<" is size\n";
                    }
                else
                    break;
                }
                if(cnt>=k)
                    ++ans;
   	}
   	cout<<ans<<endl;
   }
 
 
   return 0;
}