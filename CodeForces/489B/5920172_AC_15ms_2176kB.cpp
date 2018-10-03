#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a , b ,i , j, ar[105] , br[105], hit[105] = {0}, counter = 0;
    cin >> a ;
    for(i = 0 ; i< a ; i++)
        cin >> ar[i];
    cin >> b;
    for(i = 0 ; i< b ; i++)
        cin >> br[i];
    sort(ar,ar+a);
    sort(br,br+b);
    for(i = 0 ; i< a ; i++)
    {
        for(j = 0 ;  j< b ; j++)
        {
            if(abs(ar[i]-br[j]) <= 1){
               if(hit[j] == 0){
                counter++;
                hit[j] = 1;
                break;
               }
            }
        }
    }
    cout << counter << endl;
}
