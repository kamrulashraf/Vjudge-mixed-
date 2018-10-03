#include <bits/stdc++.h>
using namespace std;
#define pii pair < int , int>
#define ff first
#define ss second
char ch[15];
int main()
{
     int n;
     scanf("%d",&n);

     vector < pii > v;
     stack < int > st;
     for(int i = 0 ; i< 2*n ; i++){
         string s ;
         int n;

         int temp;
         scanf("%s",&ch);
         getchar();
         scanf("%d",&temp);
         s = ch;
         int t;
         if(st.size()) t = st.top();
         if(s == "in"){
             st.push(temp);
             if(st.size() > 1){
                v.push_back({t,temp});
             }
         }
         if(s == "out"){
             st.pop();
         }

     }

     for(int i = 0 ; i< v.size() ; i++){
          int u = v[i].ff;
          int q = v[i].ss;
          printf("%d %d\n",u,q);
     }
}
