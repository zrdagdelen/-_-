#include <iostream>
using namespace std;
int main() {
    int numsSize;
    cout << "Enter the size of nums array: ";
    cin >> numsSize;
    int* nums = new int [numsSize];
    //int nums[numsSize]
    
    std::cout << "Enter the elements of nums array: ";
    for (int i = 0; i < numsSize; ++i) {
        std::cin >> nums[i];
    }
   
    int indexDiff, valueDiff;
    std::cout << "Enter indexDiff: ";
    std::cin >> indexDiff;
    std::cout << "Enter valueDiff: ";
    std::cin >> valueDiff;

    bool pairExists = false;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (abs((long long)nums[i] - (long long)nums[j]) <= valueDiff && abs(i - j) <= indexDiff) {
                pairExists = true;
                break;
            }
            if (pairExists) {
                break;
            }
        }
    }

    if (pairExists) {
        std::cout << "True" << std::endl;
    }
    else {
        std::cout << "False" << std::endl;
    }

    return 0;
}
