#include <iostream>
#include <vector>
using namespace std;


int fibonacci(long long n, int m)
{
    int previous = 0;
    int current = 1;
    int period = 60;
    int reduced_n = n % period;
    if (reduced_n <= 1)
        return reduced_n;
    for (int i = 2; i <= reduced_n; i++)
    {
        int tmp = (previous + current) % m;
        previous = current;
        current = tmp;
    }
    return current;
}

int main()
{
    long long n;
    cin >> n;
    n = n+1;
    int breadth = fibonacci(n-1, 10);
    int length = fibonacci(n-2, 10);
    length += breadth;
    int answer = length*breadth;
    answer%= 10;
    cout << answer << endl;
    return 0;
}