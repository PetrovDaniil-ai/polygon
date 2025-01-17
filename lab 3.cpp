#include <iostream>
#include <vector>
#include <unordered_set>
#include <random>

using namespace std;

vector<int> reservoirSampling(istream& input, int K) {
    vector<int> reservoir(K);
    unordered_set<int> uniqueElements;
    int count = 0;

    // Читаем элементы из потока
    int num;
    while (input >> num) {
        // Если элемент уникален и еще не добавлен в множество
        if (uniqueElements.find(num) == uniqueElements.end()) {
            uniqueElements.insert(num);
            if (count < K) {
                reservoir[count] = num; // Заполняем резервуар
            } else {
                // Генерируем случайное число от 0 до count
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(0, count);
                int j = dis(gen);
                if (j < K) {
                    reservoir[j] = num; // Заменяем элемент в резервуаре
                }
            }
            count++;
        }
    }

    return reservoir;
}


