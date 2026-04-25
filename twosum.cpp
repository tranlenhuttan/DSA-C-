#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int targetSum = 9;

    unordered_map<int, int> numberPosition;

    for (int index = 0; index < numbers.size(); index++) {
        int currentNumber = numbers[index];
        int neededNumber = targetSum - currentNumber;

        if (numberPosition.find(neededNumber) != numberPosition.end()) {
            cout << numberPosition[neededNumber] << " " << index;
            return 0;
        }

        numberPosition[currentNumber] = index;
    }

    return 0;
}