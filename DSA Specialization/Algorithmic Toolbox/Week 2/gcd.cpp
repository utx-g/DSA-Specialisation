#include <iostream>
#include <vector>

using namespace std;

long gcd_fast(long n, long m)
{
    if (m == 0)
        return n;
    return gcd_fast(m, n % m);
}

int main()
{
    long n, m;
    cin >> n >> m;
    long answer = gcd_fast(n, m);
    cout << answer << endl;
    return 0;
}
