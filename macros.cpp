#include <iostream>
#include <string>
#include <vector>
#include <map>


#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <list>
#include <functional>

#include <iostream>
#include <algorithm>
#include <limits>




using namespace std;


// #include: Використовується для включення вмісту файлу в інший файл. Наприклад:
#include <iostream>
// #include <MY_HEADER>


// #define: Використовується для визначення макросів, які підставляються в код перед компіляцією. Наприклад:
#define PI 3.14159
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define SUM(a, b) ((a) + (b))
#define HELLO "Hello world"
#define MAX_INT 2000000000


// #undef: Використовується для скасування визначення макроса, створеного за допомогою #define. Наприклад:

#undef MAX_INT 



// fdef, #ifndef, #endif: Використовуються для умовного компіляції. Наприклад:
// Це запобігає повторному включенню файлу, якщо він вже був включений раніше.


#ifndef MY_HEADER
#define MY_HEADER

// Ваш код тут

#endif



// #ifdef, #else, #endif: Використовуються для умовного компіляції з альтернативою. Наприклад: а як це працює:
// #define DEBUG "World"

#define HELLO "Hello"

#ifdef DEBUG
    #undef DEBUG
    #define DEBUG "Hello"
#endif

#define DEBUG_MODE 30

#ifdef DEBUG
    #undef DEBUG_MODE
    #define DEBUG_MODE 20
#else
    #undef DEBUG_MODE
    #define DEBUG_MODE 10
#endif





#ifdef ENABLE_LOG
    #define LOG(message) std::cout << message << std::endl
#else
    #define LOG(message)
#endif




int main()
{


    std::cout << HELLO << std::endl;

    // int value1 = 10;
    // int value2 = 20;

    // int minValue = MIN(value1, value2);
    // std::cout << "Min value: " << minValue << std::endl;

    // int sumValue = SUM(value1, value2);
    // std::cout << "Sum value: " << sumValue << std::endl;

    // std::cout << MAX_INT << std::endl;


    std::cout << DEBUG_MODE << std::endl;


//     LOG("This message will be printed if ENABLE_LOG is defined.");


#ifdef DEBUG
    std::cout << "Debug mode is enabled." << std::endl;
#else
    std::cout << "Debug mode is disabled." << std::endl;
#endif
}


