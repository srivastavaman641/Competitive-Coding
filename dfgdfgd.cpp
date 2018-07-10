#include<bits/stdc++.h>
#define LL long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
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

using namespace std;

int ar[100005];
unordered_map<LL,int> m1,ls,gr;
vector<LL> v1;
int main()
{
    std:ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        m1.clear();
        v1.clear();
        ls.clear();
        gr.clear();
        int n,q;
        cin>>n>>q;
        int i,j;
        for(i=1;i<=n;i++)
        {
         cin>>ar[i];
         m1[ar[i]]=i;
         v1.pb(ar[i]);
        }
       // int q;
       sort(v1.begin(),v1.end());
        for(i=0;i<n;i++)
        {
            ls[v1[i]]=i;
            gr[v1[i]]=n-1-i;
        }


        while(q--)
        {
            LL x;
            cin>>x;
            int lw=1;
            int high=n;
            int mid;
            //int cnt=0;
            LL aa=0,bb=0,a=0,b=0;
            while(lw<=high)
            {
                int mid=(lw+high)/2;
              //  cout<<lw<<" "<<high<<" "<<mid<<endl;
                if(ar[mid]==x)
                {
                //    cout<<cnt<<endl;
                    break;
                }
               else if(ar[mid]>x)
                {
                    if(mid>(m1[x]))
                    {
                        aa++;
                        high=mid-1;
                    }
                    else
                    {
                        b++;
                        lw=mid+1;
                    }
                }
               else if(ar[mid]<x)
                {
                    if(mid<m1[x])
                    {
                        bb++;
                        lw=mid+1;
                    }
                    else
                    {
                        a++;
                        high=mid-1;
                    }
                }
            }
            LL ans=min(a,b);

            if(b>a)
            {


                if(ls[x]-bb>=b)
                    cout<<b<<"\n";
                else
                    cout<<-1<<"\n";

            }
            else
            {
              //  cout<<gr[x]<<endl;
                if(gr[x]-aa>=a)
                    cout<<a<<"\n";
                else
                    cout<<-1<<"\n";
            }

        }
    }
    return 0;
}