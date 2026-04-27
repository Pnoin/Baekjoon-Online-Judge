#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, arr[500005], mean = 0, med = 0, mode = 0, ran = 0, cnt[8005] = {}, x = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(&arr[0], &arr[n]);
	ran = arr[n-1] - arr[0];
	for (int i = 0; i < n; i++) {
		mean += arr[i];
	}
	mean = round(double(mean)/n);
	int y = round(n / 2);
	med = arr[y];
	for (int i = 0; i < n; i++) {
		cnt[4000 + arr[i]]++;
	}
	for (int i = 0; i < 8001; i++){
		if (cnt[i] > x){
			x = cnt[i];
			mode = i;
		}
	}
	for (int i = mode + 1; i < 8001; i++){
		if (cnt[i] == x){
			mode = i;
			break;
		}
	}

	cout << mean << "\n" << med << "\n" << mode - 4000 << "\n" << ran;
}