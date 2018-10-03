#include <bits/stdc++.h>
using namespace  std;

#define N 400005
#define inf 2e9
#define rep(i,x,y)  for(int i = x ; i< y ; i++)
#define F(i,x)  for(int i = 0 ; i< x ; i++)
#define ff first
#define ss second
#define pii pair < int , int>
#define ll long long
#define ull unsigned ll
#define MP make_pair
#define PB push_back
#define sca(a) scanf("%d",&a)
#define scaa(a,b) scanf("%d%d",&a,&b)
#define scaaa(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define write() freopen("out.txt", "w" , stdout)
#define read() freopen("in.txt" , "r", stdin)
const long long MOD[] = {1000000007LL, 2117566807LL};
const long long BASE[] = {1572872831LL, 1971536491LL};

int main()
{
    string s[] = {"Alice" , "Ariel" , "Aurora" ,"Phil", "Peter","Olaf","Phoebus", "Ralph","Robin"};
    string p[] = {"Bambi" , "Belle" , "Bolt", "Mulan" , "Mowgli", "Mickey", "Silver" , "Simba" , "Stitch"};
    string t[] = {"Dumbo" , "Genie" , "Jiminy" , "Kuzko" ,"Kida" , "Kenai" , "Tarzan" , "Tiana" , "Winnie"};


    vector< string >v;
    int n;
    cin >> n;
    for(int i = 0 ; i< n ; i++){
         string temp;
         cin >> temp;
         v.push_back(temp);
    }
    vector < string > str[3];
    map < string , int > mark;
    for(int i = 0 ; i< 9 ; i++){
         mark[s[i]] = 0;
    }
    for(int i = 0 ; i< 9; i++){
         mark[p[i]] = 1;
    }
    for(int i = 0 ; i< 9; i++){
         mark[t[i]] = 2;
    }

    int cur = 0;
    int res = 0;
    int counter = 0;
    for(int k = 0 ; k< v.size() ; k++){
        counter += abs(cur-mark[v[k]]);
        cur = mark[v[k]];
//        cout << v[k] << endl;
    }
    cout << counter << endl;
    return 0;
}
