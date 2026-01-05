
#include <iostream>
#include <string>

// int sum(int a = 5, int b = 10) {
//         return a + b;
// }

int sum(int a = 0, int b = 0, int c = 0) {
        return a + b + c;
}

int sum(double a, double b, double c, double d) {
        return a + b + c + d;
}

void printHello() {
        std::cout << "Hello\n";
}



// int main() 
// {
//     // =============================================================================
    // Модуль 1: Змінні і типи даних
    // int age = 20;
    // double grade = 95.5;
    // char letter = 'A';
    // std::string name = "Іван";
    // bool isStudent = true;

    // std::cout << name << " вік: " << age << "\n";




    
    // =============================================================================
    // Модуль 2: Логічні оператори й розгалуження
    // int score = 60;

    // if (score >= 90) std::cout << "Відмінно\n";
    // else if (score >= 70) std::cout << "Добре\n";
    // else std::cout << "Погано\n";

    // int x = 7;
    // std::cout << (x > 0 && x % 2 == 0 ? "Парне додатнє" : "Інше") << "\n";





    // =============================================================================
    // Модуль 3: Цикли
    // for (int i = 0; i < 5; ++i) {
    //     std::cout << i << " ";
    // }

    // int j = 0;
    // while (j < 5) {
    //     std::cout << j << " ";
    //     // ++j;
    // }

    // int k = 0;
    // do {
    //     std::cout << k << " ";
    //     ++k;
    // } while (k < 5);





    // =============================================================================
    // Модуль 4: Масиви
    // int arr[5] = {1, 2, 3, 4, 5};

    // for (int val : arr) std::cout << val << " ";
    // std::cout << "\n";


    // for (int i = 0; i < 5; ++i)
    //     std::cout << arr[i] << " ";






    // int matrix[2][3] = {{1,2,3}, {4,5,6}};
    // for (int i = 0; i < 2; ++i)
    //     for (int j = 0; j < 3; ++j)
    //         std::cout << matrix[i][j] << " ";




    
    // =============================================================================
    // Модуль 5: Функції


    // int res = sum();
    // std::cout << sum(5, 7) << "\n";

    // printHello();
    // std::cout << "Сума: " << res << "\n";




    // =============================================================================

    // Модуль 6: Покажчики
    // int x = 42;
    // int* ptr = &x;
    // std::cout << *ptr << "\n";  // 42

    // *ptr = 100;
    // std::cout << x << "\n";     // 100

    // int** pptr = &ptr;
    // std::cout << pptr << "\n"; // 100
    // std::cout << &ptr << "\n"; // адреса ptr
    // std::cout << &x << "\n"; // адреса x



    // int* arr = new int[3]{1,2,3};
    // for (int i = 0; i < 3; ++i)
    //     std::cout << arr[i] << " ";
    // std::cout << "\n";

    // int *temp = new int[4];
    // for (int i = 0; i < 3; ++i)
    //     temp[i] = arr[i];
    // temp[3] = 4;

    // delete[] arr;

    // arr = temp;

    // std::cout << "Після розширення:\n";
    // for (int i = 0; i < 4; ++i)
    //     std::cout << arr[i] << " ";
    // std::cout << "\n";

    // delete[] arr;

  

    // int* ptr = new int(50);
    // std::cout << *ptr << "\n";
    // delete ptr; 

    // arr = nullptr;
    // ptr = nullptr;









    // =============================================================================
    // Модуль 8: Багатовимірні динамічні масиви
    // int rows = 2, cols = 3;
    // int** mat = new int*[rows];
    // for (int i = 0; i < rows; ++i)
    //     mat[i] = new int[cols];

    // mat[0][0] = 1; mat[1][2] = 6;

    // // Звільнення
    // for (int i = 0; i < rows; ++i) delete[] mat[i];
    // delete[] mat;
// }







// Модуль 9: Структури
struct Student 
{
    int id;
    // std::string name;
    const char *name;
    double grade;

    void input(int i, const char* n, double g) 
    {

        if (g < 0.0) g = 0.0;
        else if (g > 100.0) g = 100.0;
        else grade = g;

        id = i;
        if (n != nullptr)
            name = n;
        else
            name = "Без імені";
        
    }

    void printInfo() 
    {
        std::cout << name << " - " << grade << "\n";
    }
} tmpStudent, anotherStudent;

// int main() 
// {
//     Student s = {};
//     s.input(1, "Іван", 95.0);
//     s.printInfo();

//     // std::cout << s.name << " - " << s.grade << "\n";

//     // Student* ps = new Student{2, "Петро", 100.0};
//     // delete ps;
// }






#include <fstream>
int main() 
{
    // Модуль 11: Файлова система
    std::ofstream out("data.txt", std::ios::app);
    out << "Bird\n";
    out.close();

    std::ifstream in("data.txt");
    if (in.is_open() == false) {
        std::cout << "Не вдалося відкрити файл!\n";
        return 1;
    }
    std::string line;
    while (std::getline(in, line))
        std::cout << line << "\n";
    std::cout << "----\n";

    std::string word;
    in.clear(); // Скидаємо стан потоку
    in.seekg(0, std::ios::beg); // Повертаємося на початок файлу
    while (in >> word)
        std::cout << word << "\n";


    char ch;    
    in.clear();
    in.seekg(0, std::ios::beg);

    std::cout << "----\n";
    while (in.get(ch))
        std::cout << ch << ' ';
    
    in.close();
}