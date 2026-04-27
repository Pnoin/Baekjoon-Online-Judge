#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;int n,x[60005],y[120005],i,j,s,m;
#define f for(i=0;i<n;i++)
int main(){cin>>n;f cin>>x[i];f cin>>y[i],y[i+n]=y[i];f{for(s=j=0;j<n;j++)s+=x[j]*y[i+j];m=max(m,s);}cout<<m;}
