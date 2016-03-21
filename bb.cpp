#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> veStr;

    veStr.push_back("hello");
    veStr.push_back("world!");

    veStr.erase(veStr.begin()+1);

    cout<<veStr[0]<<endl;
    cout<<veStr.size()<<endl;

    return 0;
}
