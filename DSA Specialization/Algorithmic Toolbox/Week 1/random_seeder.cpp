#include <iostream>
#include <cstdlib> 
#include <vector>
#define MYFILE_H
using namespace std;


vector<int> rand_vector(int n, int limit)
{
    vector<int> rand_vec;
    int element;
    for (int i = 0; i < n; i++)
    {
        element = rand() % limit + 1;
        rand_vec.push_back(element);
    }
    return rand_vec;
}

int main()
{
    vector<int> output = rand_vector(10 , 2397);
    for(int i = 0; i < 10;++i)
    {
        cout<<output[i]<<endl;
    }
}