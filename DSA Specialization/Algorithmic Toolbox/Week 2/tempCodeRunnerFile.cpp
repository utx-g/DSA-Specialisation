#include <iostream>
#include <vector>
using namespace std;

int fibonacci(long n)
{
    vector<int> series;
    series.push_back(0);
    series.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        int element = series[i-1] +series[i-2];
        series.push_back(element%10);
    }
    return series[n];    
}

int main()
{
    long n;
    cin >> n;
    int answer = fibonacci(n);
    cout << answer << endl;
    return 0;
}
