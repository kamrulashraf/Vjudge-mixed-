#include <bits/stdc++.h>
using namespace std;
int main()
{
  map < string , string > h;
  h["HELLO"] = "ENGLISH";
  h["HOLA"] = "SPANISH";
  h["HALLO"] = "GERMAN";
  h["BONJOUR"] = "FRENCH";
  h["CIAO"] = "ITALIAN";
  h["ZDRAVSTVUJTE"] = "RUSSIAN";
  string s;
  int cs = 1;
  while(cin >> s){
    if(s == "#") break;
    printf("Case %d: ",cs++);
    if(h[s].empty())
        cout << "UNKNOWN" << endl;
    else cout << h[s] << endl;

  }
  return 0;
}

