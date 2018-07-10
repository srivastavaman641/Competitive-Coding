#include<bits/stdc++.h>

using namespace std;
#define ll long long int
 bool prime[100005];
void SieveOfEratosthenes(int n)
{
   
    memset(prime, true, sizeof(prime));
 
    for (int p=2; p*p<=n; p++)
    {
        
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
  }
 stack<int>s[1205];
 stack<int>s2[1205];
int main()
{
  SieveOfEratosthenes(100005);
  int j=0,arr[100005];
    for (int p=2; p<=100002; p++){
       if (prime[p]){
                 arr[j]=p;
                 j++;

          
       }
     }

	 int n,q;
   cin>>n>>q;
   for(int i=0;i<n;i++)
   {
    ll x;
    cin>>x;
    s[0].push(x);
   }
   for(int i=0;i<q;i++)
   {
    while(!s[i].empty())
    {
        if(((s[i].top())%arr[i])==0){
          s2[i+1].push(s[i].top());
        
        s[i].pop();
      }
      else
      {
        s[i+1].push(s[i].top());
        s[i].pop();
      }
    }
   }
   for(int i=1;i<=q;i++){
   while(!s2[i].empty())
   {
    cout<<s2[i].top()<<endl;
    s2[i].pop();
   }
 }
   while(!s[q].empty())
   {
    cout<<s[q].top()<<endl;
    s[q].pop();
   }
    return 0;
}