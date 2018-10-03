#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

string convert(int n){
   string temp;
   while(n){
      int tt = n&1;
      temp += (char) (tt+48);
      n/=2;
   }
   while(temp.size() < 8){
     temp += '0';
   }
   reverse(temp.begin(),temp.end());
   return temp;
}


void print(string s){
     int temp = 0;
   for(int i = 0 ; i<= 32 ; i++){
      if(i%8==0 && i){
//         if(i==32 && temp > 252) temp = 252;
         printf("%d",temp);
         temp = 0;
         if(i!=32) printf(".");
         if(i==32) break;
      }
      temp = temp*2+s[i]-48;
   }
   printf("\n");
   return;

}



int main()
{
      freopen("ip.in","r",stdin);
      int  test ;
      cin >> test;
      vector  < string > v;
      while(test--){
         int a , b, c , d;
         scanf("%d.%d.%d.%d",&a,&b,&c,&d);
         string s;
         s += convert(a);
         s += convert(b);
         s += convert(c);
         s += convert(d);
//         cout << s << endl;
//         cout << s << endl;
         v.push_back(s);
      }
      string s = v[0];
//      if(s[31]=='1') s[31] = '0';
//      else s[31] = '1';
      int before = s.size();
      for(int i = 1; i< v.size() ; i++){
          int counter = 0;
//              cout << s << ' ' << v[i] << endl;

          for(int j = 0 ; j< s.size() ; j++){
              if(s[j] == v[i][j]) counter++;
              else break;
          }
          if(counter < before){
              before = counter;
              s = v[i];
          }
      }

      string res1 , res2;
      for(int i = 0 ; i < before ; i++){
         res1 += s[i];
         res2 += '1';
      }
      for(int i = before ; i< 32 ; i++){
         res1 += '0';
         res2 += '0';
      }
      freopen("ip.out","w",stdout);
//      cout << before << endl;
//      if(before == 32){
//         print(v[0]);
//         printf("255.255.255.254\n");
//      }
//      else{
          print(res1);
          print(res2);
//      }
      return 0;
}
