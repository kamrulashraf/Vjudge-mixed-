#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   string s;
   cin >> s;
   map < char , int > hit;
   for(int i = 0 ; i< n ; i++){
      hit[s[i]]++;
   }

   int counter = 0;
   for(int i = 0 ; i< n ; i++){
      if(s[i] == 'A' || s[i] == 'I'){
           hit[s[i]]--;
           if(hit['I'] == 0 && (hit['F'] || hit['A']))
              counter++;
           hit[s[i]]++;
      }
   }

   cout << counter << endl;
}
