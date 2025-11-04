#include <iostream>

using namespace std;

int main()
{

    // завдання 1:
    // Користувач вводить два числа порахувати їх суму та середнє арифметичне
    
    // int x, y;

    // std::cout << "enter x: ";
    // std:cin >> x;

    // std::cout << "enter y: ";
    // std::cin >> y;

    // int sum = x + y;
    // int av = sum / 2;

    // std::cout << "sum = " << sum << std::endl;
    // std::cout << "av = " << av << std::endl;







    // Завдання 2:
    // Напишіть програму, яка дозволяє користувачу вводити два числа, 
    // а потім обмінює їх значеннями з використання додаткової змінної.




    // int x, y;

    // std::cout << "enter x: ";
    // std:cin >> x;

    // std::cout << "enter y: ";
    // std::cin >> y;


    // std::cout << "x = " << x << std::endl;
    // std::cout << "y = " << y << std::endl; 

    // int c = x;
    // x = y;
    // y = c;

    // std::cout << "x = " << x << std::endl;
    // std::cout << "y = " << y << std::endl; 

    // > < == != >= <=

    // std::cout << (x > y) << std::endl; 







     // && (логічне "І"): Повертає true, якщо обидва операнди є true.
     // || (логічне "АБО"): Повертає true, якщо хоча б один із операндів є true.
     // ! (логічне "НЕ"): Використовується для інвертування значення логічного виразу.





    // int C = 5;
    // int A = 5;
    // int B = 5;

    // std::cout << ((A > B) && (A > C)) << std::endl;
    // std::cout << ((A < B) || (A > C)) << std::endl;
    // std::cout << ((A < B) || !(A > C)) << std::endl;
    // std::cout << (A - B || B) << std::endl;
    // std::cout << ((B > C) || !(B == A)) << std::endl;  







     // if / if - else / if - else if - else


    //  int X = 10, Y = 5;

    //  if ( X < Y )
    //  {

    //     std::cout << "X > Y" << std::endl;

    //  }





    //  int A = 10, B = 5, C = 12;

    //  if ((A > B) && !(A > C)) // комбіноване твердження
    //  {
    //       std::cout << "A between B and C" << std::endl; // на екрані A between B and C
    //  }


    
    //  if ((A > B) || (A > C)) // комбіноване твердження
    //  {
    //       std::cout << "A > B || A < B and A > C || A < C" << std::endl; // на екрані A between B and C
    //  }
    



    //  int A = 0;

    //  if (A++)
    //  {
    //       std::cout << "Best test!! 1 = " << A << std::endl; // true
    //  }
     
    //  if (A++)
    //  {
    //       std::cout<< "Best test!! 2 = " << A << std::endl; // true
    //  }



    // яка буде вихідна величина у змінній "result", якщо "x" дорівнює 10, а "y" дорівнює 5, для такого фрагмента коду?
    // int x = 10;
    // int y = 5;
    // int result = 0;

    // if (x < y)
    // {

    //     result = x - y;            // дія номер 1
    // }
    // else
    // {
    //       result = y - x;            // дія номер 2
    // }

    // std::cout << result << std::endl;





//один рядок то фігурні дужки можна не вказувати

    //  int A = 20, B = 20;

    //  if (A > B)
    //       cout << "A > B" << endl;
    //  else
    //       cout << "A < B || A == B"<< endl;

    
    
    
//  if - else if - else

    //  int A = 10;
    //  int B = 10;
    

    // if (A > B)
    //       cout << "A > B" << endl;
    // else if (A < B)
    //       cout << "A < B" << endl;
    // else 
    //       cout << "A == B" << endl;



// // Кожному оператору if відповідає лише один оператор else.
// // Сукупність цих операторів - else if означає, що якщо не виконалося
// // Попереднє умова, то перевірити це. Якщо жодна з умов не вірна,
// // виконується тіло оператора else.









// ТЕРНАРНИЙ ОПЕРАТОР
     // ( ) ? дія номер 1 : дія номер 2;

     // () ? : ;

     int a = 5, b = 10;
    //  int max = 0;

    //  if (a > b)
    //       max = a;
    //  else
    //       max = b;

    //  max = (a > b) ? a : b;

    //  std::cout << max << std::endl;
// 
    // =========================================================================


    // int max = (a > b)? a: b;
    // int min = (a < b)? a: b;

    // cout << "MAX: " << max << "\tMIN: " << min << endl;


    // // =========================================================================

    // if (a % 2 == 0) std::cout << "a is even" << std::endl;
    // else std::cout << "a is odd" << std::endl;

    // std::cout << ((a % 2 == 0) ? "a is even" :  "a is odd") << std::endl;


    // // =========================================================================
    // int A = 15, B = 15;
    // if (A > B)
    //       cout << "A > B" << endl;
    // else if (A < B)
    //       cout << "A < B" << endl;
    // else 
    //       cout << "A == B" << endl;

    // std::cout << ((A > B) ? "A > B" : (A < B) ? "A < B" : "A == B") << std::endl;


    // int value;
    // std::cout << "enter number: ";
    // std::cin >> value;

    // std::string result = ((value > 0) ? "value > 0" : (value < 0 ) ? " value < 0 " : "value = 0");
    // std::cout << "result = " << result << std::endl;


    // std::cout << ((value > 0) ? "value > 0" : (value < 0 ) ? " value < 0 " : "value = 0") << std::endl;



// SWITCH

    //  enum WEEKS
    // {
    //     Monday = 1,
    //     Tuesday,
    //     Wednesday, 
    //     Thursday,
    //     Friday,
    //     Saturday,
    //     Sunday,
    // };


    // char value;
    // std::cout << "Enter number of weeks: ";
    // std::cin >> value;

    // switch (value)
    // {
    // case 'A':
    //     std::cout << "Навчається !!!" << std::endl;
    //     break;
    // case WEEKS::Tuesday:
    //     std::cout << "Навчається !!!" << std::endl;
    //     break;
    // case WEEKS::Wednesday:
    //     std::cout << "Навчання/робота !!!" << std::endl;
    //     break;
    // case WEEKS::Thursday:
    //     std::cout << "Прогулянка !!!" << std::endl;
    //     break;
    // case WEEKS::Friday:
    //     std::cout << "Спортзал !!!" << std::endl;
    //     break;
    // case WEEKS::Saturday:
    //     std::cout << "Відпочинок !!!" << std::endl;
    //     break;
    // case WEEKS::Sunday:
    //     std::cout << "Відпочинок !!!" << std::endl;
    //     break;
    // default:
    //     std::cout << "Нічого не робить !!!" << std::endl;
    // }


// Завдання 1
// Користувач вводить із клавіатури число. 
// Якщо воно парне, помножити його на три, інакше — поділити на два. Результат вивести на екран.
}