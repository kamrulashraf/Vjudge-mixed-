#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
string source , target;
string s[3];
map < string  ,int > mark;
void call(int indx , string send){
        if(indx == 3){
            mark[send] = 1;
            return;
        }
        for(int i = 0 ; i< s[indx].size() ; i++){
             string temp = send+s[indx][i];
             call(indx+1, temp);
        }
}
 
 
char fun(char a , int flag){
    int temp  = a-97;
    temp = (temp+flag+26)%26;
    temp = temp+97;
    return (char) temp;
}
map < string , int > level, vis;
int bfs(string s , string t){
    int flag  = 0;
    if(mark[s] == 1) return -1;
    queue < string > q;
    q.push(s);
    level[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        string u = q.front();
        q.pop();
        if(u == t){
           flag = 1;
           break;
        }
        for(int i = 0 ; i< 3 ; i++){
            string temp = u;
            temp[i] = fun(temp[i],1);
            if(mark[temp]==0 && vis[temp] == 0){
                q.push(temp);
                level[temp] = level[u]+1;
                vis[temp] = 1;
            }
        }
        for(int i = 0 ; i< 3 ; i++){
            string temp = u;
            temp[i] = fun(temp[i],-1);
            if(mark[temp] == 0 && vis[temp] == 0){
                q.push(temp);
                level[temp] = level[u]+1;
                vis[temp] = 1;
            }
        }
 
    }
    if(flag == 0) level[t] = -1;
    return level[t];
}
int main()
{
     int test , cs = 1;
     cin >> test;
     while(test--){
         cin >> source >> target;
         int n;
         cin >> n;
         for(int i = 0 ; i< n ; i++){
             for(int j = 0 ; j< 3 ; j++){
                cin >> s[j];
             }
             string temp;
             call(0,temp);
         }
         int res = bfs(source, target);
         mark.clear();
         level.clear();
         vis.clear();
         printf("Case %d: %d\n",cs++,res);
     }
}
 