#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int a,b;
    int res=1;
    cin >>a>>b;

    cout <<(a^b);
    
    int yinzi = a^b; // max gongyinshu
    int bitN = 1;
    int count=0;

    if(yinzi == 0)
    {
        cout<<a;

        return 0;
    }

    while((bitN & yinzi) == 0)
    {
        count ++;

        bitN = bitN>>1;
        yinzi = yinzi>>1;
    }

    int bitM = 0;
    int i=count;
    while(i-- >0)
    {
        bitM = (bitM<<1) + 1;
    }

    res = (a>>count) * (b>>count) * (a&bitM);

    cout<<res;
    return 0;
}
