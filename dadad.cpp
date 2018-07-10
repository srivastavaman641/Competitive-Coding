#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    string str="";
	    while(n)
	    {
	        int k=n%26;
	        if(k==0)
	        {
	            n=(n/26)-1;
	            str+='Z';
	        }
	        else
	        {
	            n/=26;
	            str+=(char)(65+k-1);
	        }
	    }
	    reverse(str.begin(),str.end());
	    cout<<str<<endl;

	    
	}
	return 0;
}