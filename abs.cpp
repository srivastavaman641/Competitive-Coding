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
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.length();
        ll num1=0,num=0;
        ll mn=INT_MAX,ans;
        for(int i=0;i<n;i++)
        {
            num=num*10+s[i]-'0';
        }
        string s1=s;
        int mid=(n-1)/2;
        if(n%2!=0){
            int j=mid-1;
            for(int i=mid+1;i<n;i++)
            {
                s1[i]=s[j];
                j--;
            }
            if(s1==s)
            {
                cout<<s<<endl;
                continue;
            }
            for(int i=0;i<n;i++)
            {
                num1=num1*10+s1[i]-'0';
            }
        }
        else{
            int j=mid;
            for(int i=mid+1;i<n;i++)
            {
                s1[i]=s[j];
                j--;
            }
            if(s1==s)
            {
                cout<<s<<endl;
                continue;
            }
            for(int i=0;i<n;i++)
            {
                num1=num1*10+s1[i]-'0';
            }
        }
        mn=min(abs(num1-num),mn);
        ans=num1;
        int flag=0;
        if(s>s1)
            flag=1;
        if(flag==0){
            if(n%2==0)
            {
                if(s1[mid]!='0'){
                    s1[mid]--;
                    s1[mid+1]--;
                }
                else
                {
                    int i=mid,j=mid+1;
                    while(s1[i]=='0' && s1[j]=='0')
                    {
                        s1[i]=s1[j]='9';
                        i--;
                        j++;
                    }
                    s1[i]--;
                    s1[j]--;
                }
                num1=0;
                for(int i=0;i<n;i++)
                {
                    num1=num1*10+s1[i]-'0';
                }
                if(abs(num1-num)<=mn)
                {
                    ans=num1;
                    mn=abs(num1-num);
                }  
            }
            else
            {
                if(s1[mid]!='0')
                {
                    s1[mid]--;
                }
                else
                {
                    s1[mid]='9';
                    int i=mid-1,j=mid+1;
                    while(s1[i]=='0' && s1[j]=='0')
                    {
                        s1[i]=s1[j]='9';
                        i--;
                        j++;
                    }
                    s1[i]--;
                    s1[j]--;
                }
                num1=0;
                for(int i=0;i<n;i++)
                {
                    num1=num1*10+s1[i]-'0';
                }
                if(abs(num1-num)<=mn)
                {
                    ans=num1;
                    mn=abs(num1-num);
                }  
            }
        }
        else
        {
            if(s1[mid]!='9'){
                if(n%2)
                    s1[mid]+=1;
                else
                {
                    s1[mid]+=1;
                    s1[mid+1]+=1;
                }
                num1=0;
                for(int i=0;i<n;i++)
                {
                    num1=num1*10+s1[i]-'0';
                }
                if(abs(num1-num)<mn)
                {
                    ans=num1;
                    mn=abs(num1-num);
                }  
            }
            else
            {
                if(n%2){
                    int j=mid-1;
                    int i=mid+1;
                    s1[mid]='0';
                    while(s1[i]=='9' && s1[j]=='9'){
                        s1[i]='0';
                        s1[j]='0';
                        i++;
                        j--;
                    }
                    s1[i]+=1;
                    s1[j]+=1;
                }
                else{
                    int j=mid;
                    int i=mid+1;
                    while(s1[i]=='9' && s1[j]=='9')
                    {
                        s1[i]='0';
                        s1[j]='0';
                        i++;
                        j--;
                    }
                    s1[i]+=1;
                    s1[j]+=1;
                }
                num1=0;
                for(int i=0;i<n;i++)
                {
                    num1=num1*10+s1[i]-'0';
                }
                if(abs(num1-num)<mn)
                {
                    ans=num1;
                    mn=abs(num1-num);
                }  
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
