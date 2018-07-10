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
int va[1000005][2];
string op[1000005];
int parent[1000005],size[1000005];
int root(int x){
	while(parent[x]!=x)
	{
		parent[x]=parent[parent[x]];
		x=parent[x];
	}
	return x;
}
void un1(int x,int y){
	int root_x=root(x);
	int root_y=root(y);
	if(root_x==root_y)
		return;
	if(size[root_x]>size[root_y])
	{
		parent[root_y]=root_x;
		size[root_x]+=size[root_y];
	}
	else
	{
		parent[root_x]=root_y;
		size[root_y]+=size[root_x];	
	}
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
   	int n,k;
   	cin>>n>>k;
   	for(int i=0;i<1000005;i++){
   		parent[i]=i;
   		size[i]=1;
   	}

   	for(int i=0;i<k;i++)
   	{
   		cin>>va[i][0]>>op[i]>>va[i][1];
   		if(op[i][0]=='=')
   			un1(va[i][0],va[i][1]);
   	}
   	int flag=1;
   	for(int i=0;i<k;i++)
   	{
   		if(op[i][0]!='=')
   		{
   			if(root(va[i][0])==root(va[i][1]))
   			{
   				flag=0;
   				break;
   			}
   		}
   	}
   	if(flag==1)
   		cout<<"YES"<<endl;
   	else
   		cout<<"NO"<<endl;

   }


   return 0;
}
