#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
 long long int a,b,c,d,i,sum;
 char s[1000001];
 while(scanf("%lld %lld %lld %lld", &a, &b, &c, &d)==4)
 {
  getchar();
  gets(s);
  for(sum = 0,i=0;i<strlen(s);i++)
  {
      if(s[i]==49) sum += a;
      if(s[i]==50) sum += b;
      if(s[i]==51) sum += c;
      if(s[i]==52) sum += d;
  }
  cout << sum << "\n";
 }
}
