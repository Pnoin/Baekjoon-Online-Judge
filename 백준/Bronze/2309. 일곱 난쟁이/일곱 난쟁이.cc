#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int a[10] = {}, total = 0, x = 0, y = 0, b[10] = {}, count = 0;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &a[i]);
        total = total + a[i];
    }
    for (int l = 0; l < 9; l++) {
        for (int m = 0; m < 9; m++) {
            if (a[l] == a[m]) {
                continue;
            }
            if (total - a[l] - a[m] == 100) {
                x = l;
                y = m;
            }
        }
    }
    for (int j = 0; j < 9; j++) {
        if (j == x or j == y) {
            continue;
        }
        else {
            b[count] = a[j];
            count++;
        }
    }
    sort(&b[0], &b[7]);
    for (int i = 0; i < 7; i++) {
        printf("%d\n", b[i]);
    }
}