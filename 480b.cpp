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
	int n,k;
	cin>>n>>k;
	char a[5][n+5];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j]='.';
	}
	if(k%2==0)
	{
		int l=k/2;
		for(int j=1;j<n-1;j++){
			for(int i=1;i<3;i++)
			{
				if(k>0){
					if(j%2){
						a[i][j/2+1]='#';
						k--;
					}
					else{
						a[i][n-(j/2)-1]='#';
						k--;
					}
				}
			}
		}
	}
	else if(k%2==1)
	{
		k--;
		int l=k/2;
		
		for(int j=1;j<n-1;j++){
			for(int i=1;i<3;i++)
			{
				if(k>0){
					if(j%2){
						a[i][j/2+1]='#';
						k--;
					}
					else{
						a[i][n-(j/2)-1]='#';
						k--;
					}
				}
			}
		}
		if(a[1][n/2]=='#')
		{
			cout<<"NO"<<endl;
			return 0;
		}
		a[1][n/2]='#';
	}
	cout<<"YES"<<endl;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<n;j++)
			cout<<a[i][j];
		cout<<endl;
	}

	return 0;
}
