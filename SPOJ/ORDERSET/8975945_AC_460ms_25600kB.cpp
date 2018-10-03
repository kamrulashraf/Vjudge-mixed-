#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
// #ifdef __mr__
//     #include "prettyprint.hpp"
// #endif
#define endl                        ('\n')
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using orderset = tree<
    T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;

int main() {
    int n;
    scanf("%d",&n);
    orderset < int > s;
    for(int i = 0 ; i < n ; i++){
         char ch ;
         int x;
         getchar();
         scanf("%c %d",&ch,&x);
         if(ch=='I'){
             s.insert(x);
         }
         if(ch == 'D'){
            s.erase(x);
         }
         if(ch == 'K'){
            if(s.find_by_order(x-1) == s.end()){
                printf("invalid\n");
            }
            else
            cout << *s.find_by_order(x-1) << endl;
         }
         if(ch == 'C'){
            cout << s.order_of_key(x) << endl;
         }
    }
    return 0;
}


// orderset< int > s;
// s.insert(5);
// s.erase(5);
// *s.find_by_order(n - 1);
// pos = s.order_of_key(k);