#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

//The structure of the node is
typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;                   
 }node;


void decode_huff(node * root,string s)
{
    string result;
    int s_size = s.size();
    node *pCurrentNode = root;

    for(int i=0; i < s_size; i++)
    {
        switch(s[i])
        {
            case 0:
                {
                    if(pCurrentNode->data == '\0') 
                    {
                        pCurrentNode = pCurrentNode->left;
                    }
                    else
                    {
                        result.push_back(pCurrentNode->data);
                        pCurrentNode = root->left;
                    }
                }
            case 1:
                {
                    if(pCurrentNode->data == '\0') 
                    {
                        pCurrentNode = pCurrentNode->right;
                    }
                    else
                    {
                        result.push_back(pCurrentNode->data);
                        pCurrentNode = root->right;
                    }
                }
            default:
                {
                    cout <<"Error!!!\n"<<endl;
                    break;
                }
        }
    }

    cout <<result<<endl;
}

