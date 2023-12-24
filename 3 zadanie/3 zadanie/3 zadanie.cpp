#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // первая половина элементов (упорядочена по убыванию)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // вторая половина элементов (упорядочена по возрастанию)

public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num); // Добавляем в maxHeap
        minHeap.push(maxHeap.top()); // Добавляем максимальный элемент из maxHeap в minHeap
        maxHeap.pop(); // Удаляем максимальный элемент из maxHeap
        // Балансируем размеры куч
        if (maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top()); // Добавляем минимальный элемент из minHeap в maxHeap
            minHeap.pop(); // Удаляем минимальный элемент из minHeap
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};
#include <iostream>

int main() {
    // Создаем объект MedianFinder
    MedianFinder mf;
    setlocale(LC_ALL, "Russian");

    // Добавляем числа и выводим медиану
    mf.addNum(1);
    std::cout << "Медиана: " << mf.findMedian() << std::endl; // Ожидаем 1.0
    mf.addNum(2);
    std::cout << "Медиана: " << mf.findMedian() << std::endl; // Ожидаем 1.5
    mf.addNum(3);
    std::cout << "Медиана: " << mf.findMedian() << std::endl; // Ожидаем 2.0

    return 0;
}
