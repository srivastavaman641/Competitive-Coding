#include<bits/stdc++.h>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		long long int a,b;
   		cin>>a>>b;
   	 	long long int ans=1;
   		while(b)
   		{
   			if(b%2!=0)
   			{
   				ans=(a*ans)%10;
   			}
   			a=(a*a)%10;
   			b/=2;
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
