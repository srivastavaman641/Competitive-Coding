#include<stdio.h>
int arr[10][10];
int find(int r,int c,int n)
{
int temp=0; 
if(n==0)
return 0;
if(r<0||r>9||c<0||c>9)
return 0;
if(arr[r][c]==1&&n==1)
return 0;
if(n==1)
{
temp=1;
arr[r][c]=1;
}
return temp+find(r-2,c-1,n-1)+find(r-2,c+1,n-1)+find(r-1,c+2,n-1)+
find(r+1,c+2,n-1)+find(r+2,c+1,n-1)
+find(r+2,c-1,n-1)+find(r+1,c-2,n-1)+find(r-1,c-2,n-1);
}
int main()
{
int r,c,n;
scanf("%d %d %d",&r,&c,&n);
r--;
c--;
printf("%d",find(r,c,n+1));
return 0;
}