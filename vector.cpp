#include<bits/stdc++.h>
using namespace std;
 
///////////////////////////////////Nikhil Srivastava////////////////////////////////////////
///////////////////////////////////IIT Jodhpur//////////////////////////////////////////////
///////////////////////////////////Bazinga//////////////////////////////////////////////////
#define sci(a) scanf("%d",&a)
#define scl(a) scanf("%I64d",&a)
#define scc(a) scanf("%c",&a)
#define scf(a) scanf("%f",&a)
#define scd(a) scanf("%lf",&a)
#define scs(a) scanf("%s",&a)
#define printi(a) printf("%d",a)
#define printl(a) printf("%I64d",a)
#define printc(a) printf("%c",a)
#define printf(a) printf("%f",a)
#define printd(a) printf("%lf",a)
#define prints(a) printf("%s",a)
#define loop(i,a,n) for(int i=a;i<n;++i)
#define loopd(i,a,n) for(int i=a;i>=n;--i)
#define nl printf("\n");
#define ll long long int
#define mp(a,b) make_pair(a,b)
#define pi pair < int,int >
#define pl pair < ll,ll >
#define pb push_back
 
 
 
int main()
{
        int t;
        sci(t);
        while(t--)
        {
            int n,k,c;
            cin>>n>>k>>c;
            vector<ll> a(n);
            loop(i,0,n)cin>>a[i];
            sort(a.begin(),a.end());
            int ans = 0;
            loop(i,0,n){
                int num = a[i],m=k,cnt=1;
                while(m--){
                int idx = lower_bound(a.begin(),a.end(),c*num) - a.begin();
              //  cout<<"idx is "<<idx<<endl;
                if(idx!=a.size()){
                        ++cnt;
                        num = a[idx];
                        a.erase(a.begin() + idx);
                    }
                else
                    break;
                }
                if(cnt>=k)
                    ++ans;
            }
            cout<<ans<<"\n";
        }
}
 