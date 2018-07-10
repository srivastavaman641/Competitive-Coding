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
 typedef unsigned long long ull;
ull valid[100005];
 ull sum[100005];
 int n,k,q;
 char s[100005];
 void calculate()
 {
 	int c0=0,c1=0,j=1;
 	for(int i=1;i<=n;i++)
 	{
 		while(j<=n+1 && c1<=k && c0<=k)
 		{
 			if(s[j]=='1')
 				c1++;
 			else
 				c0++;
 			j++;
 		}
 		valid[i]=j-1;
 		if(s[i]=='1')
 			c1--;
 		else
 			c0--;
 	}
 	sum[0]=0;
 	for(int i=1;i<=n;i++)
 		sum[i]=sum[i-1]+valid[i];
 }
 ull query(ull l,ull r)
 {
 	int lo=l-1,hi=r;
 	while(hi-lo>1){
 		int mid=(lo+hi)/2;
 		if(valid[mid]<=r)
 			lo=mid;
 		else
 			hi=mid;
 	}
 	int k=lo;
 	//cout<<k<<"is lo"<<endl;
 	return sum[k]-sum[l-1]+(r-k)*(r+1)-((r*(r+1)/2)-(l*(l-1)/2));
 }
 int main()
 {
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n>>k>>q;
 		for(int i=1;i<=n;i++)
 			cin>>s[i];
 		s[n+1]='\0';
 		calculate();
 		/*for(int i=1;i<=n;i++)
 			cout<<valid[i]<<" ";*/
 		while(q--)
 		{
 			ull x,y;
 			cin>>x>>y;
 			cout<<query(x,y)<<endl;
 		}


 	}
 
 
    return 0;
 }
 