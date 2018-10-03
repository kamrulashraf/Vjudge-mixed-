#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
   int r , g ,b;
   node( int a , int bb ,int c){

      r =a ;
      g = bb;
      b = c;
   }
};
int main()
{
    vector < node > mark;



      mark.push_back(node(255,255,255));
      mark.push_back( node(192,192,192));
      mark.push_back( node(128,128,128));
      mark.push_back(node(0,0,0));

      mark.push_back(node(255,0,0));
      mark.push_back(node(128,0,0));
      mark.push_back(node(255,255,0));
      mark.push_back(node(128,128,0));

      mark.push_back(node(0,255,0));
      mark.push_back(node(0,128,0));
      mark.push_back(node(0,255,255));
      mark.push_back(node(0,128,128));

      mark.push_back(node(0,0,255));
      mark.push_back(node(0,0,128));
      mark.push_back(node(255,0,255));
      mark.push_back(node(128,0,128));



    string s[] = {"White","Silver", "Gray" ,"Black" , "Red" , "Maroon", "Yellow" , "Olive" , "Lime" ,"Green" , "Aqua" , "Teal","Blue" ,"Navy" , "Fuchsia" , "Purple"};
    ll mmin = 1e9;
//
   int R , G  , B;
    while(cin >> R >> G >> B){
        string p;
        if(R == -1 && G == -1 && B == -1) break;
        mmin = 1e9;
        for(int i = 0 ; i< 16 ; i++){
            string temp = s[i];
            int r  = mark[i].r;
            int g = mark[i].g;
            int b = mark[i].b;
            ll res = 0;

            res += (b-B)*(b-B);
            res += (g-G)*(g-G);
            res += (r-R)*(r-R);

            if(res < mmin){
                mmin = res;
                p = temp;
            }
        }

        cout << p << endl;
    }

}
