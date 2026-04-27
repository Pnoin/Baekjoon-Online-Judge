#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string returnAbb (string name) {
   if (name == "North London Collegiate School") {
      return "NLCS";
   } else if (name == "Branksome Hall Asia") {
      return "BHA";
   } else if (name == "Korea International School") {
      return "KIS";
   } else {
      return "SJA";
   }
}
int main(void) {
   string lock;
   cin >> lock;
   string names[4] = {"North London Collegiate School", "Branksome Hall Asia", "Korea International School", 
"St. Johnsbury Academy"};
   for (int i = 0; i < 4; i ++) {
      string check = names[i];
          check.erase(remove(check.begin(), check.end(), ' ' ), check.end() );
      for (int k = 0; k < check.length(); k++) {
         if (!((int)check[k] >= 65 && (int)check[k] <= 90) && !((int)check[k] >= 97 && (int)check[k] <= 122)) {
            check.erase(check.begin() + k);
         }
         if ((int)check[k] >= 65 && (int)check[k] <= 90) {
            check[k] += 32;
         }
      }
      check.erase(10, check.length());
      for (int j = 0; j <= 25; j++) {
         string check2 = check;
         for (int l = 0; l < check2.length(); l++) {
            if (check2[l] + j > 122) {
               check2[l] += j;
               check2[l] -= 26;
            }
            else {
               check2[l] += j;
            }
         }
         if (check2 == lock) {
            cout << returnAbb(names[i]) << endl;
            return 0;
         }
      }
   }
}
