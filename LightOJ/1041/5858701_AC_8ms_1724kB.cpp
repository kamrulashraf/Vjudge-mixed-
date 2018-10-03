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
           if(parA ==  parB) return 0;
           else{
               if(rank[parA] >= rank[parB]) swap(parA,parB);
               parent[parA] = parB;  // rank of parB is greater than parA
               if(rank[parA] == rank[parB]) rank[parB]++;   // increasing rank of parB( with whom connect anoter child)
               return 1;
           }
    }
    string dsuFind(string a){
        if(parent[a] == a) return a;
        return parent[a] = dsuFind(parent[a]);

    }

};
int main()
{
   int test , cs = 1;
   cin >> test;
   while(test--){
      int edge;
      cin >> edge ;
      set < string > s;
      set < string > :: iterator it;
      priority_queue < data , vector <data > , comp > q;
      for(int i = 0 ; i < edge ; i++){
         string a , b;
         int c;
         cin >> a >> b >> c;
         q.push(data(a,b,c));
         s.insert(a);
         s.insert(b);
      }
     DSU temp;
     int sum = 0;
     while(!q.empty()){
          string tA , tB ;
          int tC;
          tA = q.top().a;
          tB = q.top().b;
          tC = q.top().c;
          q.pop();
          if(tC == 0) temp.makeUnion(tA,tB);
          else if(temp.makeUnion(tA,tB)){
          //    cout << tA << ' ' << tB << '#' << tC << endl;
              sum += tC;
          }
    }
    it = s.begin();
    bool flag = 0;
    string var = temp.dsuFind(*it);
    for( ; it != s.end() ; it++){
        if(var != temp.dsuFind(*it)){
           flag = 1;
           break;
        }
    }
    if(flag) printf("Case %d: Impossible\n", cs++ );
    else printf("Case %d: %d\n", cs++, sum );
   }

}
