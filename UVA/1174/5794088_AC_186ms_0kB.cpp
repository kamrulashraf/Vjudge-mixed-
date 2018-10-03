#include <bits/stdc++.h>
using namespace std;
class data{
public:
string a,b;
int c;
  data(string a , string b , int c){
     this -> a = a;
     this -> b = b;
     this -> c = c;

  }
};
class comp{
    public:
       bool operator()(const data& x, const data& y){
           if(x.c > y.c) return true;
           else return false;
       }

};

class DSU{
 map < string , string > parent;
 map < string , int > rank;
 map < string , bool > hit;
 public:
    bool makeUnion(string a , string b){
       if(hit[a] == 0){
         parent[a] = a;
         hit[a] = 1;
        }
       if(hit[b] == 0){
         parent[b] = b;
         hit[b] = 1;
       }
       string parA = dsuFind(a);
       string parB = dsuFind(b);
       if(parA ==  parB) return 1;
       else{
     //      if(rank[parA] >= rank[parB]) swap(parA,parB);
           parent[parA] = parB;  // rank of parB is greater than parA
       //    if(rank[parA] == rank[parB]) rank[parB]++;   // increasing rank of parB( with whom connect anoter child)
           return 0;
       }
    }
    string dsuFind(string a){
        if(parent[a] == a) return a;
        return parent[a] = dsuFind(parent[a]);

    }

};
int main()
{
   int test;
   cin >> test;
   while(test--){
      priority_queue < data , vector < data> , comp> q;
      int node , edge;
      long long sum = 0;
      cin >> node >> edge;
      for(int i = 0 ; i < edge ; i++){
        string a,b;
        int c;
        cin >> a >> b >>  c;
              q.push(data(a,b,c));
      }
      DSU temp;
      while(!q.empty()){
          string tA , tB ;
          int tC;
          tA = q.top().a;
          tB = q.top().b;
          tC = q.top().c;
          if(!temp.makeUnion(tA , tB))
             sum += tC;
          q.pop();

      }
      cout << sum << endl;
      if(test) cout << "\n" ;

   }

}
