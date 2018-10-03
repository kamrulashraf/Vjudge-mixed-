    #include <bits/stdc++.h>
    using namespace std;
    template < class T > inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
    template < class T > inline T lcm(T a, T b) {return (a/gcd(a,b)) * b;}
    int main()
    {
      int a , b, test,cs = 1;
      long long l;
      scanf("%d", &test);
      while(test--){
         scanf("%d %d %lld", &a , &b ,&l);
             long long temp = lcm(a,b);
             if(l%temp){
                printf("Case %d: impossible\n", cs++);
             }
             else{
               long long div = l/temp;
               long long d = gcd(div,temp);
               while(d!=1){
                 div *= d;
                 temp /= d;
                 d = gcd(div,temp);
               }
               printf("Case %d: %lld\n", cs++ ,div);
             }

         }
     return 0;
    }
