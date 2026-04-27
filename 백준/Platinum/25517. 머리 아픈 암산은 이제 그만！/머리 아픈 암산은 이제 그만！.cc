//dhyang24 FAN 69
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <stack>
#include <set>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
const long double PI = acos(-1); 

int n,m,md=1e9+7,pre[105]={0,682498929,491101308,76479948,723816384,67347853,27368307,625544428,199888908,888050723,927880474,281863274,661224977,623534362,970055531,261384175,195888993,66404266,547665832,109838563,933245637,724691727,368925948,268838846,136026497,112390913,135498044,217544623,419363534,500780548,668123525,128487469,30977140,522049725,309058615,386027524,189239124,148528617,940567523,917084264,429277690,996164327,358655417,568392357,780072518,462639908,275105629,909210595,99199382,703397904,733333339,97830135,608823837,256141983,141827977,696628828,637939935,811575797,848924691,131772368,724464507,272814771,326159309,456152084,903466878,92255682,769795511,373745190,606241871,825871994,957939114,435887178,852304035,663307737,375297772,217598709,624148346,671734977,624500515,748510389,203191898,423951674,629786193,672850561,814362881,823845496,116667533,256473217,627655552,245795606,586445753,172114298,193781724,778983779,83868974,315103615,965785236,492741665,377329025,847549272,698611116};
set <int> st;
ll mx=1;
/*
void Factorial_preprocess(){
    ll total=1;
    cout << '{';
    for(int i=1; i<1000000001; i++){
      total*=i;
      total%=md;
      if(i%10000000==0){
        cout << total;
        if(i==1000000000){
          cout << '}';
        }
        else{
          cout << ',';
        }
      }
    }
}
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int num;
        cin >> num;
        st.insert(num);
    }
    if(n<10000000){
        for(int i=1; i<=n; i++){
            mx*=i;
            mx%=md;
        }
    }
    else{
        mx=pre[n/10000000];
        ll start=n/10000000;
        start*=10000000;
        for(int i=start+1; i<=n; i++){
            mx*=i;
            mx%=md;
        }
    }
    for(int i:st){
        ll temp=1,left=i,right=md-2;
        while(true){
            if(right==0){
                break;
            }
            if(right%2){
                temp*=left;
                temp%=md;
            }
            left*=left;
            left%=md;
            right/=2;
        }
        mx*=temp;
        mx%=md;
    }
    cout << mx;
}