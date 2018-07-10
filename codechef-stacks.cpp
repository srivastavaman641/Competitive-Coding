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
   	int n;
   	cin>>n;
   	ll a[n+1],v[n+1];
   	for(int i=1;i<=n;i++)
   		cin>>a[i];
   	int j=1;
   	v[0]=0;
   	v[j]=a[1];
   	for(int i=2;i<=n;i++)
   	{
   		int low=0,high=j;
   		if(v[j]<=a[i])
   		{
   			j++;
   			v[j]=a[i];	
   		}
   		else{
   		while(low<high)
   		{
   			int mid=low+(high-low)/2;
   			if(v[mid]>a[i])
   			{
   				high=mid;
   			}
   			else
   				low=mid+1;
   		}
   		v[low]=a[i];
   	}
   	}
   	cout<<j<<" ";
   	for(int i=1;i<=j;i++)
   		cout<<v[i]<<" ";
   	cout<<endl;
   }


   return 0;
}
