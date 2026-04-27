#include <iostream>
#include <string>
using namespace std;

int main() {
   string abName;
   cin >> abName;
   if (abName == "NLCS") {
      cout << "North London Collegiate School";
   } 
   else if (abName == "BHA") {
      cout << "Branksome Hall Asia";
   } 
   else if (abName == "KIS") {
      cout << "Korea International School";
   } 
   else {
      cout << "St. Johnsbury Academy";
   }
}