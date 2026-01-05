#include <iostream>
#include <chrono>
#include <thread>

/* 
    Робота в якій використовуємо таймер для вимірювання часу виконання блоку коду
    А також простий приклад роботи з потоками
*/

// COLOR DEFINITIONS(PRINT) 
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

using namespace std;

class SimpleTimer {
public:
    SimpleTimer() {
        start_time_ = std::chrono::high_resolution_clock::now();
    }
    ~SimpleTimer() {
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end_time - start_time_;
        std::cout << BLUE << "Elapsed time: " << elapsed.count() << " ms" << RESET << std::endl;
    }   
private:
    std::chrono::high_resolution_clock::time_point start_time_;
};


void SomeFunction() {
    this_thread::sleep_for(std::chrono::milliseconds(2000));

    std::cout << RED << "ID potoca = " << this_thread::get_id() << RESET << GREEN << "| SomeFunction executed" <<  RESET << std::endl;

    this_thread::sleep_for(std::chrono::milliseconds(5000));

    std::cout << RED << "ID potoca = " << this_thread::get_id() << RESET << GREEN << "| SomeFunction executed" <<  RESET << std::endl;
}


int main() {
    SimpleTimer timer; // Timer starts here
    // or
    // початок вимірювання часу 
    // auto start_time_ = std::chrono::high_resolution_clock::now();

    std::thread t(SomeFunction); // Виозов функції в окремому потоці
    // SomeFunction();

    for (int i = 0; i < 5; ++i) {
       
        std::cout << RED << "ID potoca = " << this_thread::get_id() << RESET << GREEN << "| Iteration " << i + 1 << RESET <<  std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    t.join(); // Очікуємо завершення потоку



    // кінець вимірювання часу
    // auto end_time = std::chrono::high_resolution_clock::now();
    // std::chrono::duration<double> elapsed = end_time - start_time_;
    // std::cout << "Elapsed time: " << elapsed.count() << " ms" << std::endl;

    return 0;
}