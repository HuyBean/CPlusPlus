#include <iostream>
using namespace std;

int countWord(char* para)
{
    int i = 0;
    int countWord = 0;
    bool word = false;
    for(int i =0; i< sizeof(para);i++)
    {
        if(para[i]=='.'||para[i]==','||para[i]==';'||para[i]=='!'||para[i]==' '||para[i]=='?')
        {

        }
    }
}

int main()
{
    char *para = new char[100];
    cout << "Input a long parragraph: ";
    cin >> para;
    cout << countWord(para) << endl;
    delete[] para;
    return 0;
}