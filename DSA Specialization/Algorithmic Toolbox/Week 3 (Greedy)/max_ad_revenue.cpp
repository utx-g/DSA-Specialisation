#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long max_ad_revenue(int n, vector <int> prices,vector <int> clicks)
{
    long max_revenue = 0;
    sort(prices.begin(), prices.end());
    sort(clicks.begin(), clicks.end());
    for(int i=0; i < n; ++i)
    {
        int revenue = prices[i]*clicks[i];
        max_revenue += revenue;
    }
    return max_revenue;
}

int main()
{
    int n;
    vector <int> prices;
    vector <int> clicks;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int inp;
        cin >> inp;
        prices.push_back(inp);
    }
    for(int i = 0; i < n; ++i)
    {
        int inp;
        cin >> inp;
        clicks.push_back(inp);
    }
    long answer = max_ad_revenue(n, prices, clicks);
    cout << answer << endl;
    return 0;
}
