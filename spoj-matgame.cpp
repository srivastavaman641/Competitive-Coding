#include <bits/stdc++.h>
#define N 51
using namespace std;
    
    int M[N][N];
    int main()
    {
    int n,m,sg,t,r,i,j;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    scanf("%d",&M[i][j]);
    r = 0;
    for(i=0;i<n;i++)
    {
    sg = M[i][m-1];
    for(j=m-2;j>=0;j--)
    {
    if(M[i][j]>sg) sg=M[i][j];
    else sg = M[i][j]-1;
    }
    r^=sg;
    }
    puts(r?"FIRST":"SECOND");
    }
    return 0;
    } 