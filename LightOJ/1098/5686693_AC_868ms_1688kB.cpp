#include <bits/stdc++.h>
using namespace std;
int main()
{
 //   freopen("a.txt", "w" , stdout);
    int test , cs = 1;
    scanf("%d", &test);
    while(test--){
        long long n;
        unsigned long long sum = 0;
        scanf("%lld", &n);
        if(n == 0){
          printf("Case %d: %llu\n", cs++ , sum);
          continue;
        }
        for(int i = 1 ; i*i <= n ; i++){
            long long temp;
            temp = n/i;
            sum += (temp*(temp+1))/2;
            if(i == temp) continue;
            long long rest = (n/i-n/(i+1));
            long long cou = ((i*(i+1))/2);
            temp = rest * cou;
            sum += temp;
        }
        sum  -= (n*(n+1))/2 + n -1;
        printf("Case %d: %llu\n", cs++ , sum);
    }

 return 0;
}

