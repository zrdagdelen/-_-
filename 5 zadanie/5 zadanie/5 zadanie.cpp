#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Функция для нахождения максимальной площади прямоугольника в гистограмме
int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int tp;  // Индекс верхнего элемента стека
    int areaWithTop;

    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        }
        else {
            tp = s.top();
            s.pop();
            areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);

            if (maxArea < areaWithTop) {
                maxArea = areaWithTop;
            }
        }
    }

    while (!s.empty()) {
        tp = s.top();
        s.pop();
        areaWithTop = heights[tp] * (s.empty() ? i : i - s.top() - 1);

        if (maxArea < areaWithTop) {
            maxArea = areaWithTop;
        }
    }

    return maxArea;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }

    int maxArea = 0;
    vector<int> heights(matrix[0].size(), 0);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == 0) {
                heights[j] = 0;
            }
            else {
                heights[j] += matrix[i][j];
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    setlocale(LC_ALL, "Russian");
    ifstream file("matrix.txt");// для txt файла (бинарный файл у меня не получилось создать)
    //ifstream file("matrix.bin", ios::binary); // для бинарного файла
    if (file) {
        // Чтение двоичного файла и создание матрицы
        vector<vector<int>> matrix;
        char c;
        vector<int> row;
        while (file.get(c)) {
            if (c == '0' || c == '1') {
                row.push_back(c - '0');
            }
            if (c == '\n') {
                matrix.push_back(row);
                row.clear();
            }
        }

        // Вызываем функцию для поиска максимальной прямоугольной области
        int maxRectangleArea = maximalRectangle(matrix);

        cout << "Максимальная площадь прямоугольника, содержащего только 1: " << maxRectangleArea << endl;
    }
    else {
        cerr << "Не удалось открыть файл matrix.bin" << endl;
        return 1;
    }

    return 0;
}
