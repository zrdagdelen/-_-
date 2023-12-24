#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }

    int buy1 = INT_MIN, sell1 = 0;
    int buy2 = INT_MIN, sell2 = 0;

    for (int i = 0; i < n; i++) {
        buy1 = max(buy1, -prices[i]);
        sell1 = max(sell1, buy1 + prices[i]);
        buy2 = max(buy2, sell1 - prices[i]);
        sell2 = max(sell2, buy2 + prices[i]);
    }

    return sell2;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Пример ввода массива цен акций от пользователя и передача его в функцию расчета прибыли
    vector<int> prices;
    int n;
    cout << "Введите количество дней: ";
    cin >> n;

    cout << "Введите цены акций для каждого дня: ";
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    int result = maxProfit(prices);
    cout << "Максимальная прибыль, которую можно получить: " << result << endl;

    return 0;
}
