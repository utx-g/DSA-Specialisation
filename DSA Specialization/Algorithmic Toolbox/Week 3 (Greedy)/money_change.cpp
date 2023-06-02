#include <iostream>
#include <vector>
using namespace std;

int money_change(int money)
{
    int coins_num = 0;
    while(money>0)
    {
        if (money>=10)
        {
            int coins = money/10;
            money -= 10*coins;
            coins_num += coins;            
        }
        if (money>=5)
        {
            int coins = money/5;
            money -= 5*coins;
            coins_num += coins;            
        }
        if (money>=1)
        {
            int coins = money/1;
            money -= 1*coins;
            coins_num += coins;            
        }
    }
    return coins_num;
}

int main()
{
    int money;
    cin >> money;
    int answer = money_change(money);
    cout << answer << endl;
    return 0;
}
