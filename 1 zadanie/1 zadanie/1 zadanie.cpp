#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
// Структура TreeNode для представления узлов бинарного дерева
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Функция для построения бинарного дерева на основе введенных значений
TreeNode* buildTree() {
    std::string input;
    // Читаем ввод пользователя
    std::getline(std::cin, input);
    std::istringstream stream(input);
    std::vector<std::string> values;
    std::string temp;
    // Разбираем ввод, извлекаем значения и сохраняем их в векторе
    while (stream >> temp) {
        values.push_back(temp);
    }
    // Если ввод пустой или корневой узел - null, возвращаем нулевой указатель
    if (values.empty() || values[0] == "null") {
        return nullptr;
    }
    // Создаем корень бинарного дерева на основе первого значения
    TreeNode* root = new TreeNode(std::stoi(values[0]));
    std::vector<TreeNode*> nodes = { root };
    size_t index = 1;
    // Строим бинарное дерево на основе введенных значений
    while (index < values.size() && !nodes.empty()) {
        std::vector<TreeNode*> nextNodes;
        // Обходим текущий уровень узлов и создаем дочерние узлы
        for (auto node : nodes) {
            if (index < values.size() && values[index] != "null") {
                node->left = new TreeNode(std::stoi(values[index]));
                nextNodes.push_back(node->left);
            }
            index++;

            if (index < values.size() && values[index] != "null") {
                node->right = new TreeNode(std::stoi(values[index]));
                nextNodes.push_back(node->right);
            }
            index++;
        }

        nodes = nextNodes;
    }
    // Возвращаем корень построенного бинарного дерева
    return root;
}
// Вспомогательная функция для рекурсивного нахождения максимальной суммы пути
int maxPathSumUtil(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0;
    }

    int leftSum = std::max(0, maxPathSumUtil(root->left, maxSum));
    int rightSum = std::max(0, maxPathSumUtil(root->right, maxSum));

    maxSum = std::max(maxSum, leftSum + rightSum + root->val);

    return std::max(leftSum, rightSum) + root->val;
}
// Основная функция для вычисления максимальной суммы путей
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxPathSumUtil(root, maxSum);
    return maxSum;
}

int main() {
    setlocale(LC_ALL, "Russian"); //текст выводим на русском языке
    std::cout << "Введите значения узлов бинарного дерева через пробел (используйте 'null' для отсутствующих узлов):" << std::endl;
    TreeNode* root = buildTree();

    std::cout << "Максимальная сумма путей в дереве: " << maxPathSum(root) << std::endl;

    return 0;
}
