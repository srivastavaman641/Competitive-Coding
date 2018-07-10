#include<bits/stdc++.h>
#define ll long long int
using namespace std;
char s[255];
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
   		ll a;
   		cin>>a>>s;
   		if(a==0)
   		{
   			cout<<s<<endl;
   			continue;
   		}
   		ll c=0;
   		for(int i=0;i<strlen(s);i++)
   		{
   			c=(s[i]-'0'+c*10)%a;
   		}
   		if(c==0){cout<<a<<endl;continue;}
   		ll ans=__gcd(c,a);
   		cout<<ans<<endl;
   }


   return 0;
}
