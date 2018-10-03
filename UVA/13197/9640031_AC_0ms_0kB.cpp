#include <bits/stdc++.h>
using namespace std;
int main()
{
     int a, p;
     while(scanf("%d %d",&a,&p)==2){
        a %= p;
        vector < int > v;
        for(int i = 0 ; i< p ; i++){
            int temp = i*i*i;
            temp %= p;
            if(temp == a){
                v.push_back(i);
            }
        }

        for(int i = 0 ; i< v.size() ; i++){
             if(i) printf(" ");
             printf("%d",v[i]);
        }
        printf("\n");
     }

     return 0;
}
