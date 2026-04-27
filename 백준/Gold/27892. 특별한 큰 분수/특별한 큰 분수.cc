#include <iostream>

#include <algorithm>

#include <cmath>

#include <string>

#include <cstring>

#include <vector>

#include <queue>

#pragma GCC optimize("O3")

typedef long long int ll;

using namespace std;

ll x,n;

int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

    cin >> x >> n;

    for(ll i=1; i<=n; i++){

        if(x%2==0){

            x=(x/2)^6;

        }

        else if(x%2==1){

            x=(2*x)^6;

        }

        if(x==0){

            if((n-i)%4==0){

                cout << 0;

                return 0;

            }

            else if((n-i)%4==1){

                cout << 6;

                return 0;

            }

            else if((n-i)%4==2){

                cout << 5;

                return 0;

            }

            else if((n-i)%4==3){

                cout << 12;

                return 0;

            }

        }

        if(x==4){

            cout << 4;

            return 0;

        }

        if(x==8){

            if((n-i)%3==0){

                cout << 8;

                return 0;

            }

            else if((n-i)%3==1){

                cout << 2;

                return 0;

            }

            else if((n-i)%3==2){

                cout << 7;

                return 0;

            }

        }

    }

    cout << x;

}