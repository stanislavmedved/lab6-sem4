#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<int> readArrayFromFile(const std::string& filename) {
    std::ifstream file = std::ifstream(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::vector<int> array;
    int value;
    while (file >> value) {
        array.push_back(value);
    }

    file.close();
    return array;
}
void printVector(const std::vector<int>& array) {
    for (int value : array) {
        std::cout << value << " ";
    }
}
int findIndex(const std::vector<int>& vec, int element) {
    auto it = std::find(vec.begin(), vec.end(), element);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    else {
        return -1;
    }
}
int main() {
    setlocale(LC_ALL, "rus");
    std::string filename = "input.txt";
    //copyright by Aiacaxapa & stanislavmedved
    system("start copyright.mp4");

    std::vector<int> array = readArrayFromFile(filename);
    std::cout << "Начальный вектор: "; printVector(array); std::cout << std::endl;

    std::reverse(array.begin(), array.end());
    std::cout << "Реверсированный вектор: "; printVector(array); std::cout << std::endl;

    int minElement = *std::min_element(array.begin(), array.end());
    std::cout << "Минимальный элемент: " << minElement << std::endl;

    array.erase(std::remove_if(array.begin(), array.end(), [](int n) { return n % 2 == 0; }), array.end());
    std::cout << "Отфильтрованный вектор: "; printVector(array); std::cout << std::endl;

    std::sort(array.begin(), array.end(), [](int a, int b) { return a < b; });
    std::cout << "Отсортированный вектор: "; printVector(array); std::cout << std::endl;

    std::cout << "Введите число: ";
    int newElement = 0;
    std::cin >> newElement;
    array.push_back(newElement);

    std::sort(array.begin(), array.end(), [](int a, int b) { return a < b; });
    std::cout << "Вектор с новым элементом: "; printVector(array); std::cout << std::endl;

    int newElementIndex = findIndex(array, newElement);
    std::cout << "Индекс нового элемента: " << newElementIndex << std::endl;

    std::set<int> s(array.begin(), array.end());
    array.assign(s.begin(), s.end());
    std::cout << "Вектор без дубликатов: "; printVector(array); std::cout << std::endl;

    return 0;
}