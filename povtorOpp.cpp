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
using namespace std;

// повторення ООП

// Класи та об'єкти
// Клас — це шаблон або модель для створення об'єктів. 
// Клас визначає властивості (поля) та методи (функції), які мають належати кожному об'єкту. Об'єкт — це конкретний екземпляр класу.



// class Car {
// public:
//     std::string brand;
//     std::string model;
//     int year;

//     void displayInfo() {
//         std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << std::endl;
//     }
// };

// int main() {
//     Car car1;

//     car1.brand = "Toyota";
//     car1.model = "Camry";
//     car1.year = 2020;

//     car1.displayInfo(); // Виведе: Brand: Toyota, Model: Camry, Year: 2020

//     return 0;
// }





// Інкапсуляція
// Інкапсуляція полягає в об'єднанні даних і методів, які працюють з цими даними, в один клас, при цьому приховуючи внутрішню реалізацію від зовнішнього світу.
// Інкапсуляція дозволяє створювати об'єкти з чітко визначеним інтерфейсом і контролювати доступ до внутрішніх даних через геттери та сеттери.


class Person {
private:
    std::string name;
    int age;

public:
    void setName(std::string n) {
        name = n;
    }

    std::string getName() {
        return name;
    }

    void setAge(int a) {
        if (a > 0) {
            age = a;
        }
    }

    int getAge() {
        return age;
    }
};

int main() 
{
    Person person;
    person.setName("John");
    person.setAge(25);

    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << std::endl;

    return 0;
}










// Конструктори та деструктори
// Конструктори — це спеціальні методи, які викликаються при 
// створенні об'єкта для ініціалізації його властивостей. Деструктори викликаються при знищенні об'єкта для звільнення ресурсів.



class Car {
public:
    std::string brand;
    std::string model;
    int year;

    // Конструктор
    Car( std::string b, std::string m, int y ) : brand(b), model(m), year(y) {
        std::cout << "Car constructed: " << brand << " " << model << std::endl;
    }

    // Деструктор
    ~Car() {
        std::cout << "Car destructed: " << brand << " " << model << std::endl;
    }
};

int main() 
{
    Car myCar("Toyota", "Camry", 2020);

    {
        Car myCar2("Ford", "Mustang", 2018);
    }




    return 0;
}













// Перевантаження операторів
// Перевантаження операторів дозволяє змінювати поведінку операторів для користувацьких типів даних (класів).


class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Перевантаження оператора +
    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() 
{
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2; // Викликається перевантажений оператор +

    c3.display(); // Виведе: 4 + 6i

    return 0;
}









// Наслідування
// Наслідування дозволяє створювати нові класи на основі існуючих, успадковуючи їхні властивості та методи. 
// Це дозволяє уникнути дублювання коду та створювати більш загальні класи, які можуть бути перевикористані.


class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

// int main() 
// {
//     Dog myDog;
//     myDog.eat();  // Виклик методу, успадкованого від класу Animal
//     myDog.bark(); // Виклик методу класу Dog

//     return 0;
// }




// Поліморфізм

// Поліморфізм дозволяє об'єктам різних типів оброблятися однаково через загальний інтерфейс. 
// Поліморфізм може бути двох видів: компіляційний (перевантаження функцій і операторів) та виконання (віртуальні функції).

class Animal {
public:
    virtual void sound() {
        std::cout << "Some generic animal sound" << std::endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Bark" << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Meow" << std::endl;
    }
};

int main() 
{
    Animal* a1;
    
    a1 = new Dog;
    a1->sound(); // Виведе: Bark

    a1 = new Cat;
    a1->sound(); // Виведе: Meow


    delete a1;
    return 0;
}







// Абстракція
// Абстракція дозволяє створювати інтерфейси для класів, приховуючи складні деталі реалізації та надаючи лише необхідну функціональність. 
// В C++ абстракцію можна реалізувати через абстрактні класи та чисті віртуальні функції.


class Shape {
public:
    virtual void draw() = 0; // Чиста віртуальна функція
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Square" << std::endl;
    }
};

int main() {
    Shape* s1 = new Circle();
    Shape* s2 = new Square();

    s1->draw(); // Виведе: Drawing Circle
    s2->draw(); // Виведе: Drawing Square

    delete s1;
    delete s2;

    return 0;
}