
#include <bits/stdc++.h>
using namespace std;
int hit[150];
int list1[105] , n ,dp[105][105][105];
void init( string temp ){
    for(int i = 0 ; i< temp.size() ; i++){
        hit[temp[i]] = 1;
    }
}
void makeVowelOne(string temp){
    for(int i = 0 ; i< temp.size() ; i++){
        if(hit[temp[i]] == 1){
            list1[i] = 1;
        } else if(temp[i] == '?')
            list1[i] = 2;
    }
}

bool makeBad(){
    int con = 0;
    for(int i = 0 ; i< n ; i++){
         if(list1[i] == 0 || list1[i] == 2){
            con++;
         } else con = 0;
         if(con >=5) return true;
    }
    int vol = 0;
    for(int i = 0 ; i< n ; i++){
        if(list1[i] == 1 || list1[i] == 2){
            vol++;
        } else vol = 0;
        if(vol >= 3) return true;
    }
    return false;
}
bool call(int in , int con , int vol){
//    cout << in << ' ' << list1[in] << ' ' << con << ' ' << vol <<  endl;
    if(con >= 5 || vol >= 3) return false;
    if(n <= in){
        return true;
    }
    if(dp[in][con][vol] != -1) return dp[in][con][vol];
    if(list1[in] != 2){
        if(list1[in] == 0){
            con += 1;
        }
        else con = 0;

        if(list1[in] == 1){
             vol += 1;
        }
        else vol = 0;

        return dp[in][con][vol] = call(in+1 , con , vol);
    }
    else{
        bool p1 = call(in+1, con+1 , 0);
        bool p2 = call(in+1 , 0 , vol+1);
        return dp[in][con][vol] =  (p1|p2);
    }
}
int main()
{
    int test, cs = 1;
    string temp = "AEIOU";
    init(temp);
    scanf("%d", &test);
    while(test--){
        memset(list1,0,sizeof(list1));
        string s ;
        cin >> s;
        makeVowelOne(s);
        n = s.size();
        bool isbad = makeBad();
        memset(dp,-1,sizeof(dp));
        bool isgood = call(0,0,0);
//        cout << isbad << ' ' << isgood << endl;
        printf("Case %d: ",cs++);
        if(isbad == 0){
            printf("GOOD\n");
        }
        else if(isgood && isbad){
            printf("MIXED\n");
        }
        else if(isbad){
            printf("BAD\n");
        }
    }
}
