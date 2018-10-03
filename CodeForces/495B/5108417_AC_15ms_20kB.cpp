#include <bits/stdc++.h>
using namespace std;
int main()
{
  int i , a , b,counter = 0;
  set <int> v;
  cin >> a >> b;
  int temp = a-b;
  if(temp == 0){
    cout << "infinity" << endl;
    return 0;
  }
  for(i = 1; i*i<= temp ; i++)
  {
      if(temp%i == 0)
      {
          int t = temp/i;
          if(a%i==b) v.insert(i);
          if(a%t == b) v.insert(t);
      }
  }
  cout << v.size() << endl;
  return 0;
}
