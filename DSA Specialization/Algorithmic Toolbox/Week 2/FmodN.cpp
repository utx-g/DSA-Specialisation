#include <iostream>
#include <vector>
using namespace std;


int pisano(int m)
{
    int previous, current;
    previous = 0;
    current = 1;
    vector<int> series;
    series.push_back(0);
    series.push_back(1);
    while(true)
    {
        previous++;
        current++;
        int element = series[current-2] + series[current-1];
        series.push_back(element%m);
        if(series[previous] == 0 && series[current] == 1)
        {
            return previous;
        }
    }
    return -1;
}
int fibonacci(long long n, int m)
{
    int previous = 0;
    int current = 1;
    int period = pisano(m);
    int reduced_n = n%period;
    // cout<<period<<"period"<<endl;
    vector<int> series;
    series.push_back(0);
    series.push_back(1);
    for (int i = 2; i < period; i++)
    {
        int tmp = (series[i-2] + series[i-1])%m;
        series[i] = tmp;
        // cout<<series[i]<<' ';
    }
    // cout<<endl<<series[0]<<' ';
    // cout<<endl << reduced_n<<endl;
    cout<<  series[reduced_n];  
    return series[reduced_n];  
}

int main()
{
    long long n;
    int m;
    cin >> n >> m;
    // int answer = pisano(m);
    int answer = fibonacci(n, m);
    cout << answer << endl;
    return 0;
}
