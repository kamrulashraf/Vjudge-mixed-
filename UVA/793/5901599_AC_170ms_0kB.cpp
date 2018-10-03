#include <bits/stdc++.h>
using namespace std;
map < int , vector < int > > g;
class DSU{
 int parent[10001], rank[10001],sz = 10001;
 public:
       void clr(){
            memset(rank,0,sizeof(rank));
            for(int i = 0 ; i< sz ; i++)
               parent[i] = i;
       }
    bool makeUnion(int a , int b){
       int parA = dsuFind(a);
       int parB = dsuFind(b);
       if(parA ==  parB) return 0;
       else{
           if(rank[parA] >= rank[parB]) swap(parA,parB);
           parent[parA] = parB;  // rank of parB is greater than parA
           if(rank[parA] == rank[parB]) rank[parB]++;   // increasing rank of parB( with whom connect anoter child)
           return 1;
       }
    }
    int dsuFind(int a){
        if(parent[a] == a) return a;
        return parent[a] = dsuFind(parent[a]);

    }

};
int main()
{
 //freopen("a.txt","w",stdout);
  int test;
  cin >> test;
  while(test --){
     int node,su = 0 , us = 0;
//     parent.clear();
     cin >> node;
     getchar();
     string s;
     vector < pair<int,int> > v;
     DSU temp;
     temp.clr();
     while(getline(cin , s)){
        if(s.empty()) break;
        char ch;
        int a, b;
        stringstream ss(s);
        ss >> ch >> a >> b;
        if(ch == 'q'){
            int x = temp.dsuFind(a);
            int y = temp.dsuFind(b);
            if(x==y) su++;
            else us++;
        }
        else{
           temp.makeUnion(a,b);
        }
     }
     cout << su << "," <<  us << endl;
     if(test) cout << "\n";
     g.clear();
  }
}

