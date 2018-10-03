    #include <bits/stdc++.h>
    using namespace std;
    #define ull unsigned long long
    int main()
    {
   // freopen("a.txt","w" ,stdout);
    unsigned long long a, temp,i,cs = 1;
    while(scanf("%llu", &a) && a){
        ull mod = a%9;
        temp = (a/9)*10+mod;
        int counter = 0;
        for(i = temp -3; i<= temp+3 ; i++){
        if(i-i/10 == a){
          if(counter> 0)
             printf(" ");
          counter++;
          printf("%lld",i);
        }
    }
    printf("\n");

    }
    return 0;
    }

