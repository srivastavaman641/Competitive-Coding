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

vector<int>v[100005];

int dp[100005][2];
int vis[100005][2];
int dfs(int root,int choose,int parent)
{
    if(vis[root][choose])
        return dp[root][choose];
    vis[root][choose]=1;
    int ans=0;
    for(int i=0;i<v[root].size();i++)
    {
        if(v[root][i]==parent)
            continue;
        if(choose==1)
        {
            ans+=min(dfs(v[root][i],1,root),dfs(v[root][i],0,root));
        }
        else
            ans+=dfs(v[root][i],1,root);
    }
    if(choose==1)
        ans++;
    return dp[root][choose]=ans;

}

int main(){
    int n;
    cin >> n;
    memset(vis,0,sizeof vis);
    for(int i=0 ; i<n-1 ; i++){
        int x,y;
        cin >>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll ans=min(dfs(1,1,-1),dfs(1,0,-1));
    cout<<ans<<endl;
    return 0;
} 
