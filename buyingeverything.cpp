#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];
int main() {
    int n,m,k,c=0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i])
        c++;
}
if(c<m){
    cout<<-1<<endl;
    return 0;
}
int x=c;
int idx=0;
for(int i=0;i<n;i++)
{
    if(a[i]){
        idx=i;
        c--;
    }
    if(c==m-1)
        break;
}
int j=0;
long long int ans=0;
c=0;
for(int i=idx;i<n;i++)
{
    if(a[i]){
        if(c==0){
            ans=ans+i-j;
            c++;
            j=i;
        }
        else{
            ans=ans+(i-j)*k*c;
            j=i;
            c++;
        }
    }
}
cout<<ans<<endl;
return 0;
}
