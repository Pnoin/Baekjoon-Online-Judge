#include <iostream>
using namespace std;

int main() {
	int n, m;
    char arr[15][15]={};
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--)
			cout << arr[i][j];
		cout << '\n';
	}
}