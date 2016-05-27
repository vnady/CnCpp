#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main()
{
    //string str;
    for(int i=0; i < 2; i++)
    {
        fork();

        cout <<"k ";
    }

    return 0;
}
