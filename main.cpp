// Таким чином, завдяки цій функції ви можете встановити місце розташування як Україна або інша країна і користуватися тим алфавітом і тим часом, який є в цій країні.
// #include "windows.h"
// setlocale (LC_CTYPE, "ukr");
#include <iostream>
#include <chrono>
#include <list>
#include <iterator>
#include <algorithm> // для функції std::max_element
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <vector>

#include <functional> // для std::function


// #include <spdlog/spdlog.h>
// #include <spdlog/sinks/stdout_color_sinks.h>
// #include <spdlog/sinks/basic_file_sink.h>



// https://youtu.be/bP5GJN3-zIo

// Лямбда Функції


using namespace std;

void process_data(const std::vector<int>& data, void (*func) (int)) {
    for (auto d : data) {
        func(d);
    }
}



class Person {
public:
    Person(std::string name, int age) : name_(name), age_(age) {}

    std::string get_name() const { return name_; }
    int get_age() const { return age_; }

private:
    std::string name_;
    int age_;
};


// void print_element(int a)
// {
//     cout << a << endl;
// }


void print_vector( std::vector<Person> &arr, void (*fun)(Person) )
{
	for (auto &element : arr)
		fun(element);
}

class MyFunctor
{
	public:
		void operator()(int a)
		{
			if (a % 2 != 0)
				std::cout << a << " is odd" << std::endl;
		
		}
};

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::for_each(v.begin(), v.end(), MyFunctor());

	// Лямбда-вираз у С++ — анонімна функція, яка підтримує стан між викликами і 
	// може отримати доступ до змінних зі своєї області видимості. Використовуючи лямбда-вирази, можна оголошувати функції в будь-якому місці коду.

    // [code..] (code...) {code...};

    int SUM = 0;

	auto sum =  [] ( int a, int b ) -> int
    { 
        return a + b;
    };

	int result = sum(2, 3); // result буде 5

	std::cout << result << std::endl;



    //  Лямбда з доступом до зовнішніх змінних
    int multiplier = 4;

    auto multiply = [ multiplier ] ( int x )
    {

        return x * multiplier; 
        
    };

    std::cout << "Результат: " << multiply( 5 ) << std::endl;





    //  Лямбда з захопленням змінної за посиланням
    int count = 0;
    auto increment = [ &count ] () -> void
    { 
        ++count; 
    };

    increment();
    increment();

    std::cout << "count: " << count << std::endl;  // Виведе: 2





	// Використання лямбда-функції в якості параметру функції:

	std::vector<int> vec = {3, 2, 1, 5, 4};
	process_data(vec, [](int val) { std::cout << val << " "; });



	// Використання лямбда-функції для порівняння об'єктів класу:
	// Цей код відсортує вектор об'єктів класу Person за зростанням віку.

	std::vector<Person> people = {
		{"Alice", 25},
		{"Bob", 30},
		{"Charlie", 20},
	};


	print_vector( people, [](const Person a)
	{
		std::cout << a.get_age() << ' ' << a.get_name() << std::endl;
	});
    cout <<  " =================================================================" << endl;

	std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
		return a.get_age() < b.get_age();
	});

	print_vector(people, [](const Person a)
	{
		std::cout << a.get_age() << ' ' << a.get_name() << std::endl;
	});
	cout <<  " =================================================================" << endl;


    // // 3. Підрахунок елементів за умовою (count_if):
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int cnt = count_if(nums.begin(), nums.end(), [](int x) { return x > 3; });
    cout << cnt; 


    // // 4. Використання з for_each:
    vector<int> nums = {10, 20, 30, 33};
    for_each(nums.begin(), nums.end(), [](int x) {
        if (x % 2 != 0)
			std::cout << x << " is odd" << std::endl;
    });

}