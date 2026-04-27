/*
  전체 과정이 너무 길다보니 풀이과정은 티스토리에 나중에 따로 정리해놓기


  모든 참고자료 정리:
  
  선적분:
  https://m.blog.naver.com/cronix/220334075353
  https://m.blog.naver.com/cindyvelyn/221828338012
  
  오일러 라그랑주 방정식
  https://namu.wiki/w/오일러%20방정식#s-2
  
  룽게 쿠타
  https://lpsa.swarthmore.edu/NumInt/NumIntFourth.html
  https://math.okstate.edu/people/yqwang/teaching/math4513_fall11/Notes/rungekutta.pdf
  
  Shooting method
  https://reference.wolfram.com/language/tutorial/NDSolveBVP.html
  
  Simpson 1/3 rule
  https://www.cuemath.com/simpsons-rule-formula/
  https://atozmath.com/example/CONM/NumeInte.aspx?q=S13&q1=E1
  https://youtu.be/AamSY0Naly0?si=5244BtA6iygYXypw
  
  전체적인 문제 아이디어
  #solved.ac discord 14346,14347 thread
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <time.h>   
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef __int128_t li;
typedef complex<double> cpx;
const ld PI=acos(-1); 
const ll INF=1e18;

int t,n;
ld a,b,c;

struct State {
    ld y; // y(x)
    ld u; // y'(x)
};

// 오일러-라그랑주 방정식을 기반으로 y''(x)를 계산
inline ld compute_ypp(ld x, ld y, ld u){
    // 분모 계산: (x^2 + y^2) * (x^2 + y^2 + 1)
    ld denominator=(x*x+y*y)*(x*x+y*y+1.0);
    // 분모가 너무 작아지면 수치적 불안정을 방지하기 위해 최소값으로 설정
    if(fabs(denominator)<1e-12){
        denominator=1e-12;
    }
    
    // y''(x) 계산: ((2x * u - 2y) * (1 + u^2)) / denominator
    return ((2.0*x*u-2.0*y)*(1.0+u*u))/denominator;
}

// Runge-Kutta 4차 방법을 사용하여 ODE를 한 스텝 통합하는 함수
inline State runge_kutta4(ld x,const State& state,ld h){
    ld k1_y=state.u,k1_u=compute_ypp(x,state.y,state.u);
    ld y_k2=state.y+h*k1_y/2.0,u_k2=state.u+h*k1_u/2.0;
    ld k2_y=u_k2,k2_u=compute_ypp(x+h/2.0,y_k2,u_k2);
    ld y_k3=state.y+h*k2_y/2.0,u_k3=state.u+h*k2_u/2.0;
    ld k3_y=u_k3,k3_u=compute_ypp(x+h/2.0,y_k3,u_k3);
    ld y_k4=state.y+h*k3_y,u_k4=state.u+h*k3_u;
    ld k4_y=u_k4,k4_u=compute_ypp(x+h,y_k4,u_k4);
    
    // y와 u 업데이트: y_new = y + (h/6)(k1_y + 2k2_y + 2k3_y + k4_y)
    ld y_new=state.y+(h/6.0)*(k1_y+2.0*k2_y+2.0*k3_y+k4_y);
    // u 업데이트: u_new = u + (h/6)(k1_u + 2k2_u + 2k3_u + k4_u)
    ld u_new=state.u+(h/6.0)*(k1_u+2.0*k2_u+2.0*k3_u+k4_u);
    return State{y_new,u_new};
}

// ODE를 통합하고 y 및 u 값을 수집하는 함수
tuple<State, vector <ld>, vector <ld>> integrate_ode(ld A, ld initial_slope){
    ld x=-10.0,h=0.001;           
    int steps=20000;            
    State state={A,initial_slope};
    vector <ld> y_vals,u_vals;  
    y_vals.reserve(steps+1);
    u_vals.reserve(steps+1);
    y_vals.push_back(state.y);       
    u_vals.push_back(state.u);    
    // RK4 방법을 사용하여 ODE 통합
    for(int i=0; i<steps; i++){
        state=runge_kutta4(x,state,h);  
        x+=h;                             
        y_vals.push_back(state.y);          
        u_vals.push_back(state.u);          
    }
    return make_tuple(state,y_vals,u_vals);
}

// Simpson's 1/3 규칙을 사용하여 수치 적분을 수행
inline ld simpson_integrate(const vector <ld> &F, ld h){
    int fs=F.size()-1;             
    if(fs%2){
        fs--;              
    }
    ld integral=0.0;    
    for(int i=0; i<fs; i+=2){
        // Simpson's 1/3 규칙 적용: (h/3)(F[i] + 4F[i+1] + F[i+2])
        integral+=(h/3.0)*(F[i]+4.0*F[i+1]+F[i+2]);
    }
    return integral;                  
}

// 총 방사선량 J를 계산하는 함수
ld compute_J(const vector <ld> &y_vals,const vector <ld> &u_vals){
    int steps=y_vals.size();         
    vector <ld> F_vals;        
    F_vals.reserve(steps);
    // 각 x 값에 대해 적분할 함수 F(x)를 계산
    for(int i=0; i<steps; i++){
        ld x_i=-10.0+i*0.001,y_i=y_vals[i],u_i=u_vals[i];               
        // 방사선량 계산: (1 + 1/(x^2 + y^2)) * sqrt(1 + u^2)
        ld denominator=x_i*x_i+y_i*y_i;
        if(denominator<1e-12){
            denominator=1e-12; // 분모가 너무 작아지는 것 방지
        }
        ld sum_radiation=1.0/denominator;
        ld F_i=(1.0+sum_radiation)*sqrt(1.0+u_i*u_i);
        F_vals.push_back(F_i);      
    }
    return simpson_integrate(F_vals,0.001);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                
    cout.tie(NULL);
    /*
    clock_t start,finish;
    double duration;
    start=clock();
    */
    
    cin >> t;
    for(int test=0; test<t; test++){
        cin >> n >> a >> b >> c;
        // y 좌표를 섬의 위치로 이동시켜 계산 단순화 (y_shifted = y_original - c)
        ld shifted_A=a-c,shifted_B=b-c;
        // 이분 탐색을 위한 기울기 계산: slope = (c - a) / 10
        ld slope=(c-a)/10.0;
        // 첫 번째 이분 탐색
        ld l1=-2.0,r1=slope,tol=1e-4,best_J1=1e18;
        while(fabs(r1-l1)>tol){
            ld mid=(l1+r1)/2.0;
            auto [final_state1, y_J1, u_J1]=integrate_ode(shifted_A,mid);
            ld y_end=final_state1.y;
            if(y_end>shifted_B){
                // 최종 y(x)가 목표보다 크면, 기울기를 줄임 
                r1=mid;
            }
            else{
                // 최종 y(x)가 목표보다 작거나 같으면, 기울기를 늘림 
                l1=mid;
            }
        }
        ld slope1=(l1+r1)/2.0;
        auto [final_state_J1, y_J1, u_J1]=integrate_ode(shifted_A,slope1);
        ld J1=compute_J(y_J1,u_J1); 

        ld l2=slope,r2=2.0,best_J2=1e18; // 두 번째 이분탐색
        while(fabs(r2-l2)>tol){
            ld mid=(l2+r2)/2.0; 
            auto [final_state2, y_J2, u_J2]=integrate_ode(shifted_A,mid);
            ld y_end2=final_state2.y; 
            if(y_end2>shifted_B){
                r2=mid;
            }
            else{
                l2=mid;
            }
        }
        ld slope2=(l2+r2)/2.0;
        auto [final_state_J2, y_J2, u_J2]=integrate_ode(shifted_A,slope2);
        ld J2=compute_J(y_J2,u_J2);
        cout << fixed << setprecision(2);
        cout << "Case #" << test+1 << ": " << min(J1,J2) <<'\n';
    }
   
    /*
    finish=clock();
    duration=(double)(finish-start)/CLOCKS_PER_SEC;
    cout<<duration<<"초";
    */
}