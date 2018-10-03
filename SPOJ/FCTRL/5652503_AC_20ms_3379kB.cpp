#include <bits/stdc++.h>
using namespace std;
int solution(int num){
int sum = 0;
while(num)
 sum += (num/=5);
return sum;

}
int main()
{
 int test;
 cin >>test;
 while(test--){
  int num;
  scanf("%d", &num);
  printf("%d\n", solution(num));

 }
return 0;
}
