#include <ranges>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#include <fstream> // Підключаємо бібліотеку

int main() {
    // Відкриваємо файл для запису
    ofstream outFile("output.txt");

    int n = 10;
    int sum {n + 4};
    
    // Перевіряємо, чи файл відкрився успішно
    if (!outFile) {
        cerr << "Не вдалося відкрити файл для запису." << endl;
        return 1;
    }
    
    // Записуємо дані у файл
    outFile << "Привіт, світ!" << endl;
    outFile << "Це тестовий файл." << endl;
    
    // Закриваємо файл
    outFile.close();
    
    cout << "Дані успішно записані у файл." << endl;

    ifstream inFile("output.txt");
    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання." << endl;
        return 1;
    }
    string lines[2];
    int i = 0;
    while (getline(inFile, lines[i]) && i < 2) {
        cout << "Зчитано з файлу: " << lines[i] << endl;
        i++;
    }
    
    // std::vector<std::string> line = {"one", "two", "four", "six"};
    // auto even = line | std::views::filter([](const std::string& s){
    //     return s.size() % 2 == 0;
    // });

    // for (const auto& s : even) std::cout << s << '\n'; // виведе "four", "six"

    inFile.close();
    return 0;
}