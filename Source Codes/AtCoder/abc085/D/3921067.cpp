#include <iostream>
#include <stdlib.h>
#include <vector> //vector
#include <algorithm> //sort()

using namespace std;
//long a, b, c, d, i, j, k, n;


int main(){
//////////////////////////////////////////////////////

    long n, h;
    cin >> n >> h ;

    //long a[n] , b[n];
    vector<long> a(n);
    vector<long> b(n);
    for (int i = 0 ; i < n ; ++i )
    {
        cin >> a[i] >> b[i];
    }

    //debug
    //cout << "n:" << n << endl;
    //cout << "h:" << h << endl;

    // for ( int i = 0 ; i < n ; ++i)
    // {
    //     cout << i << ":" << a[i] <<"," << b[i] << endl;
    // }


    long sumh = 0;
    long turn = 0;

    //??
    //????????????
    //???????????????????????????????????????
    //???,??????????????????????
    //????????????????????????????????????????????????????

    //???????????????????????????
    //long max_a = *max_element(a.begin(), b.begin());
    long max_a = *max_element(a.begin(), a.end());

    //cout << "debug : max_a :" << max_a << endl;

    //??????
    vector<long> bs(b); //???????????????b????bs???
    sort(bs.begin(), bs.end());
    reverse(bs.begin(), bs.end());//?????

    for(long x : bs)
    {
        if( x < max_a )//?????????????????????????
        {
            continue;
        }
        sumh += x;
        turn ++;
        if ( h <= sumh)
        {
            //????
            cout << turn << endl;
            return 0;
        }
    }

    //cout << "debug: " << sumh << endl;
    // << "debug: " << turn << endl;

    //???????????
    while ( sumh < h )
    {
        sumh += max_a;
        turn ++;
    }
    //????
    cout << turn << endl;

    




    //long as[n], bs[n];
    //long_quicksort(as , a , n);
    //long_quicksort(bs , b , n);


    



    // long sum = 0;
    // for ( i = 0 ; i < n ; i ++ )
    // {
    //     sum += i;
    // }






    // cout <<      << endl;

//////////////////////////////////////////////////////
// Ctrl + Opt + N to make
    return 0;
}