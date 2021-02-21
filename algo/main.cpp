#include <iostream>
#include <vector>
#include<algorithm>
#include <unordered_map>
#include "sorts.h"

using namespace std;


int main() {
   vector<int> v = {1, 2};
   vector<int> v1 = {3, 4};
   vector<int> v2;
   for(auto& i : v)
       v2.push_back(i);
   for(auto& i : v1)
       v2.push_back(i);

   sort(v2.begin(), v2.end());
   for(auto& i : v2)
       cout << i << " ";
   cout << endl;

   cout << v2[v2.size()/2-1] <<  " " << v2[v2.size()/2] << endl;

   double a = v2[v2.size()/2-1];
   double b = v2[v2.size()/2];
   cout << (a+b)/2;

   return 0;
}
