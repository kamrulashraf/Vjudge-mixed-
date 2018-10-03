#include <bits/stdc++.h>
using namespace std;
char s[100000];
int tree[100005];
int nn = 10005;
void update(int indx, int val){
    while(indx <= nn){
         tree[indx] += val;
         indx += indx&-indx;
    }
}

int sum(int indx){
    int ret = 0;
    while(indx){
        ret += tree[indx];
        indx -= indx & -indx;
    }
    return ret;
}
int main()
{

    int test , cs = 1;

    while(1){
        int n;
        memset(tree,0,sizeof tree);
        scanf("%d",&n);
        if(n == 0) break;
        set < string > ss;
        map < string , int > mark;
        int mmax = 0;
        for(int i = 0 ; i< n ; i++){
             scanf("%s",&s);
             string temp = s;
             ss.insert(temp);
             mark[temp]++;
             mmax = max(mmax,mark[temp]);
        }
        vector  < int > v;
        for(auto x : ss){
             int temp = mark[x];
             update(1,1);
             update(temp+1,-1);
        }

        for(int i = 1 ; i<= mmax ; i++){
            v.push_back(sum(i));
        }
        sort(v.begin(),v.end());
        printf("Case %d: ",cs++);
        for(auto x : v){
             printf("%d",x);
        }
        printf("\n");
    }
}
