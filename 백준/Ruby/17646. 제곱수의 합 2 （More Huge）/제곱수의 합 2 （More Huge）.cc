/*
  17633번
  문제에서 given: 모든 자연수는 넷 혹은 그 이하의 제곱수의 합으로 표현할 수 있다
  가능한 경우: 1,2,3,4
  1일 경우: n은 제곱수
  2일 경우: https://en.wikipedia.org/wiki/Fermat%27s_theorem_on_sums_of_two_squares
  3일 경우: https://en.wikipedia.org/wiki/Legendre%27s_three-square_theorem
  4일 경우: 그 외
*/

/*
  17646번
  접근 방식: 
  1개로 표현가능하다는 건 그 자연수가 이미 제곱수라는 소리니까 그냥 그 숫자가 답


  2024.05.31_11:19
  르장드르 세 제곱 정리를 생각해보면
  4^x(8y+7) {x,y are natural num} 형태의 자연수 꼴일 경우 제곱수 3개로 표현이 불가능 (즉, 4개로만 표현됨)
  임의의 N을 다음과 같이 정의할 떄: 
  N = a^2 + b^2 + c^2 + d^2
  N = 4^x(8y+7)
  thus, 4^x(8y+7) = a^2 + b^2 + c^2 + d^2
  
  a^2 + b^2 + c^2 + d^2 얘네가 다 제곱수인데
  예를 들어서
  a = A*2^x 라고 치면
  a^2 = (A*2^x)^2 = A^2 * 4^x
  이런식으로 a,b,c,d를 모두 변환하면
  a^2 + b^2 + c^2 + d^2 = (A^2 * 4^x) + (B^2 * 4^x) + (C^2 * 4^x) + (D^2 * 4^x)
  4^x로 묶어버리면 4^x(A^2 + B^2 + C^2 + D^2) = 4^x(8y+7)
  thus, (A^2 + B^2 + C^2 + D^2) = (8y+7)
  
  이걸 이용하여 (8y+7)를 제곱수 1개 + 제곱수 3개로 나누려고 하는데
  7이하의 제곱수는 1과 4가 있음
  즉, (8y+6)+1이나 (8y+3)+4로 쪼개서 A^2를 1이나 4로 설정해두면 
  B^2 + C^2 + D^2만 찾으면 됨
  
  
  2024.05.31_15:36
  그렇다면 제곱수 3개의 합을 구하는 방법 --> 비슷한 방식으로 3개짜리를 1+2개로 나누어서 보자
  1차 시도) 
  https://ko.wikipedia.org/wiki/%EB%9E%80%EB%8B%A4%EC%9A%B0-%EB%9D%BC%EB%A7%88%EB%88%84%EC%9E%94_%EC%83%81%EC%88%98
  란다우-라마누잔 상수: 어떤 양의 실수 b에 대해, 충분히 큰 x에 대해, x 이하의 양의 정수 중 두 제곱수의 합으로 나타내어지는 것의 개수가 점근적으로 bx/sqrt(ln x)임이 증명됨 (이때 b는 란다우-라마누잔 상수이며 값은 대략 0.764)
  sqrt(ln x)는 x에 비해 엄청 작을테니, x 이하의 양의 정수 중 두 제곱수의 합으로 나타내어지는 것의 개수 %가 상당히 높을 것. (즉, 경우의 수를 하나씩 찾아보더라도 잘하면 시간 초과 걸리지 않고 하나의 경우를 찾는 게 가능할 수도 있음)
  
  어떤 수 z에 대하여, z를 1부터 시작하여 계속 하나씩 증가시켜 가면서 다음의 식을 만족하는 경우를 찾으면 됨
  n - z^2 = x^2 + y^2
  n - z^2를 임의의 숫자 N이라 두었을 때, 란다우가 발견한 공식에 의해 위 식을 만족하는 x^2 + y^2의 갯수가 bN/sqrt(ln N)개나 있다는 걸 알 수 있으니, 결국 제곱수 4개의 합으로 나타내지는 경우를 1+3으로 쪼갰던 것처럼, 3개로 나타나는 경우도 1+2로 쪼개서 생각 가능. 
  
  
  2024.05.31_17:22
  그렇다면 제곱수 2개의 합을 구하는 방법만 찾으면 되는데
  
  
  2024.05.31_20:01
  조사하다가 Cornacchia's algorithm라는 걸 알게 됨
  원래 디오판토스 방정식을 풀기 위해 사용되는 알고리즘이라고 하는데
  x^2 + dy^2 = m {1<= d < m, GCD(d,m) = 1}인 식을 만족하는 x와 y를 구해준다고 함
  d를 1, m을 구하려는 수 N이라고 두면 x^2 + y^2 = N, 즉 우리가 찾으려는 제곱수 2개의 합 형태로 됨
  문제는 이게 구현하는 게 상당히 복잡했음. 
  https://math.stackexchange.com/questions/5877/efficiently-finding-two-squares-which-sum-to-a-prime/5895#5895
  --> 이 사이트에 마침 두 제곱수 합으로 표현하는 다양한 방법들이 있길래 참고함. Cornacchia's algorithm말고도 다양한 방법이 있는 걸 보고 참 신기하다 느꼈음.
  
  Cornacchia's algorithm과 관련된 논문같은 게 존재하길래 이를 참고하였는데, Tonelli-Shanks Algorithm이라는 걸 사용하여 이산제곱근을 구하는 과정을 최적화해야한다고 한다.
  
  Tonelli-Shanks Algorithm의 정보와 구현은 다음의 블로그를 참고하였음.
  https://sean9892.tistory.com/27
  정리가 잘되있긴해서 구현에 도움이 많이 되었지만, 솔직히 아직까지도 원리를 100% 이해하지는 못한 것 같다.
*/



// 17633 코드에서 약간 추가한 것. 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
#include <complex>
#include <cmath>
#include <cstring>
#include <bitset>
#include <set>
#include <tuple>
#include <ctime>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef complex<double> cpx;
typedef __int128_t li;

int primearr[12]={2,3,5,7,11,13,17,19,23,29,31,37},ansnum=0; 

ll n;
vector <li> ans;

li gcd(li x,li y){ ///유클리드 호제법
    if(x<y){
      return gcd(y,x);
    }
    li z;   
    while(y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

li Pow(li a, li n, li p){
    li fin=1; 
    a%=p;
    while(true){
        if(n==0){
            break;
        }
        if(n%2==1){
            fin=(fin*a)%p;
        }
        n/=2;
        a=(a*a)%p;
    }
    return fin;
}

bool Miller_Rabin(li p,li a){ ///P는 항상 홀수
    if(a%p==0){
        return true;
    }
    li k=p-1; ///K의 시작 값은 항상 짝수
    while(true){
        li temp=Pow(a,k,p);
        if(temp==p-1){
            return true;    
        }
        if(k%2==1){
            if(temp==1 or temp==p-1){
                return true;
            }
            else{
                return false;
            }
        }
        k/=2;
    }
}

bool Prime(li p){ ///짝수는 폴라드에서 걸러내짐
    for(int i=0; i<12; i++){
        li temp=primearr[i]; 
        if(temp==p){
            return true;
        }
        if(!Miller_Rabin(p,temp)){
            return false;
        }
    }
    if(p<=40){
      return false;
    }
    return true;
}

li f(li x, li c){
    li temp=(x*x+c)%n;
    return temp;
}


/*
    자료 출처: https://blog.naver.com/jinhan814/222141831551
*/
void Pollard(li n, vector <li> &ans) {
    if(n==1){
        return;
    }
    if(n%2==0){ /// 짝수를 걸러내어 2의 거듭제곱 인수를 최대한 빼놓음
        ans.push_back(2);
        Pollard(n/2,ans);
        return;
    }
    if(Prime(n)){ /// 폴라드 로는 소수에게는 사용할 수 없으며, 소수는 더 이상 소인수분해를 적용시킬 수가 없기 때문에 그대로 최종 벡터에 집어넣고 함수를 종료
        ans.push_back(n);
        return;
    }
    /// 함수 f(x) = x^2 + c
    li a,b,c;
    li g=n;
    while(true){
        if(g==n){
            a=rand()%(n-2)+2;
            b=a;
            c=rand()%10+1;
        }   
        /*
            비둘기 집의 원리를 통해 사이클이 형성될 것임이 증명됨
            사이클이 존재하는 상태에서 플로이드 순환 찾기 알고리즘을 사용하면
            각 연산마다 f를 한 번 적용하는 a와 f를 2번 적용하는 b는 연산이 진행될 때마다 값이 겹쳐질 때의 상태로 점점 다가감
        */
        a=f(a,c);
        b=f(f(b,c),c);
        g=gcd(abs(a-b),n);
        if(g!=1){ /// gcd가 1이 아니라는 소리는 abs(a-b)가 n의 약수 중 하나라는 소리
            break;
        }
    }
    Pollard(g,ans);
    Pollard(n/g,ans);
}

li legendre(li a,li p){
    return Pow(a,(p-1)/2,p);
}

li tonelli(li n, li p){   // 이전 코드에서 tonelli 알고리즘을 잘못 구현한 것 같아서 깃허브에 있는 코드를 참고하였음 : https://gist.github.com/LaurentMazare/6745649
  li s=0,q=p-1,z=1;
  while(true){ 
    if(q&1){
      break;
    }
    q/=2; 
    s++; 
  }
  if(s==1){
    li r=Pow(n,(p+1)/4,p);
    if((r*r)%p==n){
      return r;
    }
    return 0;
  }
  while(Pow(++z,(p-1)/2,p)!=p-1);
  li c=Pow(z,q,p),r=Pow(n,(q+1)/2,p),t=Pow(n, q, p),m=s;
  while(true){
    if(t==1){
      break;
    }
    li tt=t,i=0;
    while(true){
      if(tt==1){
        break;
      }
      tt=(tt*tt)%p;
      i++;
      if(i==m){
        return 0;
      }
    }
    li b=Pow(c,Pow(2,m-i-1,p-1),p);
    li b2=(b*b)%p;
    r=(r*b)%p;
    t=(t*b2)%p;
    c=b2;
    m=i;
  }
  if((r*r)%p==n){
    return r;
  }
  return 0;
}

pair <li,li> cornacchia(li m,li d=1){
    li r0=tonelli(m-d,m);
    li r1=m%r0;
    while(true){
        if(r1*r1<m){
          break;
        }
        li ttemp=r0;
        r0=r1;
        r1=ttemp%r1;
    }
    li s=(m-r1*r1)/d;
    if(s==(ll)sqrtl(s)*(ll)sqrtl(s)){
        return {r1,(ll)sqrtl(s)};
    } 
    else{
        r0=m-tonelli(m-d,m);
        r1=m%r0;
        while(true){
            if(r1*r1<m){
              break;
            }
            li ttemp=r0;
            r0=r1;
            r1=ttemp%r1;
        }
        s=(m-r1*r1)/d;
        if(s==(ll)sqrtl(s)*(ll)sqrtl(s)){
            return {r1,(ll)sqrtl(s)};
        }
    }
    return {0,0};
}


int checkans(ll n){
    ll sqrtck=sqrtl(n);  
    if(n==sqrtck*sqrtck){   // 1인 경우
        return 1;
    }
    ll copyn=n;
    while(true){
        if(copyn%4){
            break;
        }
        copyn/=4;
    }
    if((copyn-7)%8==0){ //르장드르 세 제곱수 정리
        return 4;
    }
    // 남은 경우의 수 : 2 또는 3
    ans.clear();
    Pollard((li)n,ans);
    sort(ans.begin(),ans.end());
    ll cnt=0;
    set <ll> ss;
    for(auto i:ans){
        if(ss.count(i)){
          ss.erase(i);
        }
        else{
          ss.insert(i);
        }
    }
    for(auto i:ss){
        if(i==2){
            continue;
        }
        if(i%4==3){
            return 3;
        }
    }
    return 2;
}

void find2(li N, ll counter){
    ans.clear();
    Pollard(N,ans);
    sort(ans.begin(),ans.end());
    map <ll,int> data;
    for(auto i:ans){
      data[i]++;
    }
    ll x=1,a=1,b=0;
    for(auto i:data){
        x*=powl(i.first,i.second/2);
        if(i.second%2){
            if(i.first==2){
                tie(a,b)=make_pair(abs(a-b),a+b);
                //cout << a << ' ' << b << '\n';
            } 
            else{
                auto tt=cornacchia(i.first);
                tie(a,b)=make_pair(abs(a*tt.first-b*tt.second),b*tt.first+a*tt.second);
                //cout << a << ' ' << b << '\n';
            }
        }
    }
    ll tmpa=a*x*counter,tmpb=b*x*counter;
    cout << tmpa << ' ' << tmpb << ' ';
    return;
}

void find3(li N){
  li tempnum2=N,tempcnt=1;
  while(true){
    if(tempnum2%4){
      break;
    }
    tempnum2>>=2;
    tempcnt<<=1;
  }
  li start=sqrtl(tempnum2);
  while(true){
    if(checkans(tempnum2-(start*start))==2){
      ll pp=start*tempcnt;
      cout << pp << ' ';
      break;
    }
    start--;
  }
  find2(tempnum2-(start*start),tempcnt);
  return;
}

void find4(li N){
  ll tempnum=N,start=1;
  while(true){
    if(tempnum%4){
      break;
    }
    tempnum/=4;
    start*=4;
  }
  cout << (ll)sqrtl(start) << ' ';
  find3(N-start);
  return;
}

int main(){
    //clock_t starttime, finish;
    //double duration;
    //starttime=clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    ansnum=checkans(n);
    cout << ansnum << '\n';
    if(ansnum==1){
      cout << (ll)sqrtl(n);
    }
    else if(ansnum==2){
      find2(n,1);
    }
    else if(ansnum==3){
      find3(n);
    }
    else{
      find4(n);
    }
    //finish = clock();
 
    //duration = (double)(finish - starttime) / CLOCKS_PER_SEC;
    //cout << duration << "초" << endl;
}
