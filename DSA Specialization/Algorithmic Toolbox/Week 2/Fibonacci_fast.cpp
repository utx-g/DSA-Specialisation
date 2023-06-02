#include <iostream>
#include <cstdlib> 
#include <vector>
#define MYFILE_H
using namespace std;


int fibonacci(long n)
{
    vector<int> series;
    series.push_back(0);
    series.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        int element = series[i-1] +series[i-2];
        series.push_back(element);
    }
    return series[n];    
}

int main()
{
    int n;
    cin>>n;
    int answer = fibonacci(n);
    cout<<(answer);
}