#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void pintArray(vector <int> ar)
{
    int ar_size=ar.size();

    for(int p=0; p < ar_size; p++)
    {
        cout<<ar[p]<<' ';
    }

    cout<<'\n';
}
void insertionSort(vector <int>  ar) {
    int ar_size=ar.size();
    int i;
    int tmp;

    tmp = ar[ar_size-1];
    i = ar_size-2;
    for(; i > -1; i--)   
    {
        if(tmp < ar[i])
        {
            ar[i+1]=ar[i];
            pintArray(ar);
        }
        else
        {
            ar[i+1]=tmp;
            pintArray(ar);
            break;
        }
    }

    if(i == -1)
    {
        ar[0]=tmp;
        pintArray(ar);
    }
}
int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }
    
    insertionSort(_ar);
    return 0;
}
