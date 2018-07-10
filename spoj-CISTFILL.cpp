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
int n;
ll b[50005],h[50005],w[50005],d[50005];
double x(double a)
{
    double vol=0.0;
    for(int i=1;i<=n;i++)
    {
        if(a<b[i]*1.0)continue;
        double k=min(a-1.0*b[i],1.0*h[i]);
        vol+=(1.0*k*w[i]*d[i]);
    }
    return vol;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--){
    cin>>n;
    double vol=0.0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i]>>h[i]>>w[i]>>d[i];
        vol+=(1.0*h[i]*w[i]*d[i]);
    }
    double v;
    scanf("%lf", &v);
    if(v>vol)
    {
        cout<<"OVERFLOW"<<endl;
        continue;
    }
    double low=0.0,high=1000000000.0,mid=0.0;
    while((high-low)>0.00000001)
    {
       // cout<<'x'<<endl;
        mid=(low+high)/2;
        if(x(mid)>=v)
            high=mid;
        else
            low=mid;    
    }
    printf("%.2lf\n",low);
   }

   return 0;
}
