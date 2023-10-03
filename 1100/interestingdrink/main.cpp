#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, i;
    cin >> n; // number of stores in the city
    vector<int> prices(100001);
    while (n--) // read prices
    {
        cin >> i;
        prices[i]++; // number of stores with a particular price
    }
    for (i=1; i<prices.size(); i++) prices[i] += prices[i-1]; // number of stores with a price less or equal to 'i' 
    
    cin >> n; // number of days
    while(n--)
    { 
        cin >> i; // number of coins
        cout << (i >= prices.size() ? prices.back() : prices[i]) << '\n';
    }
}
