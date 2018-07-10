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
ll a[200005];
ll merge(int l,int r)
{
	int mid=l+(r-l)/2;
	int i=0,j=0,k=l;
	ll ans=0;
	int n=mid-l+1;
	int m=r-mid;
	ll temp1[n],temp2[m];
	for(int q=0;q<n;q++)
		temp1[q]=a[l+q];
	for(int q=0;q<m;q++)
		temp2[q]=a[mid+1+q];
	while(i<n && j<m)
	{
		if(temp1[i]<=temp2[j])
		{
			a[k]=temp1[i];
			i++;
		}
		else{
			ans+=(mid-i-l+1);
			a[k]=temp2[j];
			j++;
		}
		k++;
	}
	while(i<n){
		a[k]=temp1[i];
		k++;
		i++;
	}
	while(j<m){
		a[k]=temp2[j];
		k++;
		j++;
	}
	return ans;
}
ll merge_sort(int i,int j)
{
	if(i>=j)
		return 0;
	ll ans=0;
	int mid=i+(j-i)/2;
	ans=merge_sort(i,mid);
	ans+=merge_sort(mid+1,j);
	ans+=merge(i,j);
	return ans;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
   		int n;
   		cin>>n;
   		for(int i=0;i<n;i++)
   		{
   			cin>>a[i];
   		}
   		cout<<merge_sort(0,n-1)<<endl;
   }
   return 0;
}
