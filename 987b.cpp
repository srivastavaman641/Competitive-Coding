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
   ll x,y;
   cin>>x>>y;
   if(x==y)
   {
    cout<<'='<<endl;
    return 0;
 }
 ll mx=max(x,y);
 ll mn=min(x,y);
 if(mx==4 && mn==2)
 {
    cout<<'='<<endl;
    return 0;
 }
 if(mn>2)
 {
    if(mx==x)
      cout<<'<'<<endl;
   else
      cout<<'>'<<endl;
}
else if(mn==2)
{
   if(mx==3){
      if(mn==x)
         cout<<"<"<<endl;
      else
         cout<<">"<<endl;
      return 0;
   }
   else
   {
     if(mx==x)
      cout<<'<'<<endl;
   else
      cout<<'>'<<endl;
}
}
else
{
 if(mx==x)
   cout<<'>'<<endl;
else
   cout<<'<'<<endl;
}
return 0;
}