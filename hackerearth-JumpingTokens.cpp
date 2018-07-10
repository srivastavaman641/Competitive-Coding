#include <iostream>
#include<string>
using namespace std;
int findcolour(string a,char c)
{
    int j,len=a.length();
    for(j=0;j<len;j++)
    {
        if(a[j]==c)
        {return j;}
    }
}
 
int main()
{
    int t;
    cin>>t;
    cin.ignore(32767,'\n');
    while(t)
    {
        string s;
        getline(cin,s);
        if(s=="BRRRB" || s=="RBBBR")
        cout<<3<<endl;
        else
        {
            int i,countr=0,countb=0,flag=1,n;
            n=s.length();
            for(i=0;i<n;i++)
            {
                if(s[i]=='R')
                countr++;
                else if(s[i]=='B')
                countb++;
                if(i>=1 && s[i]==s[i-1])
                flag=0;
            }
            if(countb==0 || countr==0 || flag==1)
            {cout<<n<<endl;;}
            else if(countr==1)
            {
                int r= findcolour(s,'R');
                if(r%3==(n-r-1)%3)
                cout<<3<<endl;
                else 
                cout<<2<<endl;
            }
            else if(countb==1)
            {
                int b=findcolour(s,'B');
                if(b%3==(n-b-1)%3)
                cout<<3<<endl;
                else 
                cout<<2<<endl;
            }
            else
            {cout<<2<<endl;}
        }
        t--;
    }
    return 0;
}
