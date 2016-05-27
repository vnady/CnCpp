#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    vector<int> ver;

    for(int i=1; i<11; i++)
    {
        ver.push_back(i);
    }

    cout <<"sum of vertor: "<<accumulate(ver.begin(), ver.end(), 0)<<endl;
    cout <<"sum of vertor[3-10]: "<<accumulate(ver.begin()+3, ver.begin()+10, 0)<<endl;
    cout <<"sun of vertor[1-3]: "<<accumulate(ver.begin(), ver.begin()+3, 0)<<endl;

    return 0;
}
