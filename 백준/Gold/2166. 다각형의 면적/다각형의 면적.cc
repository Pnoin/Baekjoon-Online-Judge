#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <queue>
using namespace std;
typedef long long int ll;
typedef complex<double> cpx;
const double PI = acos(-1); 

int n; 
vector <int> x;
vector <int> y;
long double ans=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    for(int i=1; i<n-1; i++){
        long double x1=x[0],y1=y[0],x2=x[i],y2=y[i],x3=x[i+1],y3=y[i+1];
        ans+=((x1*y2 + x2*y3 + x3*y1)-(y1*x2 + y2*x3 + y3*x1))/2;
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans); 
}