#include <bits/stdc++.h>
using namespace std;
#define N 1000005
struct node{
   int mark;
   node *child[10];

   node(){
      for(int i = 0 ; i< 10 ; i++){
         child[i] = NULL;
      }
      mark = 0;
   }
} *root;

string s[N];


void insertTrie(string s ){
      node *cur = root;
      int sz = s.size();
      for(int i = 0 ; i < sz ; i++){
          int temp = s[i]-'0';
//          cout << temp << ' ' << cur -> child[temp] <<  endl;
          if(cur -> child[temp] == NULL){

             cur -> child[temp] = new node();
          }
          cur = cur-> child[temp];
      }
      cur -> mark = 1;
}

string findMax(string s){
    node *cur = root;
    int sz = s.size();
    string res;
    for(int i = 0 ; i < sz ; i++){
        int tt = s[i] - '0';
        int mmax = 0, save = 0;
        for(int j = 0 ; j< 10 ; j++){
             int temp = (tt+j)%10;
             if(cur->child[j] != NULL && temp >= mmax){
               mmax = temp;
               save = j;
             }
        }
//        cout <<  i << ' ' << save << ' ' << mmax <<  endl;
        if(cur -> child[save] != NULL){
            res += (char) mmax+48;
            cur = cur -> child[save];
        }
    }
//    cout << res << endl;
    return res;
}


string findMin(string s){
    node *cur = root;
    int sz = s.size();
    string res;
    for(int i = 0 ; i < sz ; i++){
        int tt = s[i] - '0';
        int mmin = 99 , save = 0;
        for(int j = 0 ; j< 10 ; j++){
             int temp = (tt+j)%10;
             if(cur->child[j] != NULL && temp < mmin){
               mmin = temp;
               save = j;
             }
        }
        if(cur -> child[save] != NULL){
            res += (char) mmin+48;
            cur = cur -> child[save];
        }
    }
    return res;
}


string fun(string s){
    string ret;
    int flag = 0;
    for(int i = 0 ; i< s.size() ; i++){
         if(flag == 0 && s[i] == '0') continue;
         flag = 1;
         ret += s[i];
    }
    if(ret.size() == 0) ret += '0';

    return ret;
}

char ttt[N];
int main()
{
    int n;
    root = new node();
    scanf("%d",&n);
    int msz = 0;
    for(int i = 0 ; i< n ; i++){
         scanf("%s",ttt);
         for(int j = 0 ; ttt[j] ; j++){
             s[i] += ttt[j];
         }
         msz = max(msz ,(int) s[i].size());
    }
    for(int i = 0 ; i< n ; i++){
         int tt = msz - s[i].size();
         string temp ;
         for(int j = 0 ; j< tt ; j++)
             temp += '0';
         temp += s[i];
         s[i] = temp;
         temp.clear();
    }

    string res, res1 ;
    for(int i = 0 ; i< msz ; i++){
         res += '0';
         res1 +='9';
    }

//    for(int i = 0 ; i< n ; i++){
//        cout << i << ' ' << s[i] << endl;
//    }

    insertTrie(s[0]);
    for(int i = 1 ; i< n ; i++){
        string rr =  findMax(s[i]) ;
        res = max(res,rr);
        string pp = findMin(s[i]);
        res1 = min(res1,pp);
//        cout << i << ' ' << res1 << ' ' << res << endl;
//        if(res.empty()) res =temp;
//        else res = max(res,temp);
        insertTrie(s[i]);
    }
    res = fun(res);
    res1 = fun(res1);

    cout << res1 << ' ' << res << endl;


}
