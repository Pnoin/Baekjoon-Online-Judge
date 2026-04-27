#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <complex>
#include <queue>
#include <set>
#pragma GCC optimize("O3")
typedef long long int ll;
using namespace std;

int n,m,arr[1050][1050]={},x,y,xx,yy;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> arr[i][j];
    }
  }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] += arr[i-1][j];
    }
  }
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] += arr[i][j-1];
    }
  }
	for(int i=0;i<m;i++){
    cin >> x >> y >> xx >> yy;
		cout << arr[xx][yy]-arr[x-1][yy]-arr[xx][y-1]+arr[x-1][y-1] << '\n';
	}
}






