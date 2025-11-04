//==============================================================================
// SOLID — це абревіатура, складена з перших літер п'яти базових принципів об'єктно-орієнтованого програмування та дизайну
// SRP — один клас = одна відповідальність
// OCP — відкритий для розширення, закритий для зміни
// LSP — підтипи замінимі базовими
// ISP — клієнт не залежить від непотрібних інтерфейсів
// DIP — залежність від абстракцій, не від деталей
//==============================================================================


#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <vector>
#include <stdexcept>


//============================================================================
// SRP — Single Responsibility Principle (Принцип єдиної відповідальності)
//============================================================================

// Клас відповідає тільки за дані
class User {
public:
    std::string Name;
    int Age;
};

// ❌ Порушення (Violating SRP)
class Report {
public:
    // Відповідальність 1: Генерація даних
    std::string GenerateReportData() const {
        return "Звіт: Деталі...";
    }

    // Відповідальність 2: Управління форматуванням/виводом
    void PrintReport() const {
        std::cout << "Printing: " << GenerateReportData() << std::endl;
    }
};

// ✅ Дотримання (Adhering to SRP)
// Відповідальність: Генерація даних
class ReportDataGenerator {
public:
    std::string GenerateReport() const {
        return "Звіт: Деталі...";
    }
};

// Відповідальність: Вивід
class ReportPrinter {
private:
    const ReportDataGenerator& _dataGenerator;

public:
    ReportPrinter(const ReportDataGenerator& dataGenerator) : _dataGenerator(dataGenerator) {}

    void PrintReport() const {
        std::cout << "Printing: " << _dataGenerator.GenerateReport() << std::endl;
    }
};

//=================================================================================
// OCP — Open/Closed Principle (Принцип відкритості/закритості)
//=================================================================================

// Абстракція (Відкритий для розширення)
class Shape {
public:
    virtual double Area() const = 0; // Чисто віртуальна функція
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    double Radius;
    double Area() const override { return M_PI * Radius * Radius; }
};

class Rectangle : public Shape {
public:
    double Width;
    double Height;
    double Area() const override { return Width * Height; }
};

// ❌ Порушення (Violating OCP)
class AreaCalculator {
public:
    // Цей метод повинен змінюватися при додаванні нової форми
    double TotalArea(const std::vector<Shape*>& shapes) const {
        double total = 0;
        
        for (const auto& shape : shapes) {
            total += shape->Area(); // Виклик поліморфного методу
        }

        return total;
    }
};


//=================================================================================
// LSP — Liskov Substitution Principle (Принцип підстановки Лісков)
//=================================================================================

class Animal {
public:
    virtual void MakeSound() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void MakeSound() const override {
        std::cout << "Bark" << std::endl;
    }
};

class Cat : public Animal {
public:
    void MakeSound() const override {
        std::cout << "Meow" << std::endl;
    }
};

void LetAnimalSound(const Animal& animal) {
    // Дотримання LSP: Ми можемо передати Dog або Cat, і програма працюватиме коректно
    animal.MakeSound();
}

//=================================================================================
// ISP — Interface Segregation Principle (Принцип розділення інтерфейсу)
//=================================================================================

// ❌ Порушення (Violating ISP)
class IComplexMachine {
public:
    virtual void Print(const std::string& document) = 0;
    virtual void Scan(const std::string& document) = 0;
    virtual void Fax(const std::string& document) = 0; // Не потрібен простому принтеру
    virtual void Staple(const std::string& document) = 0; // Не потрібен сканеру
    virtual void Bind(const std::string& document) = 0; // Не потрібен факсу
    virtual ~IComplexMachine() = default;
};

class SimplePrinter : public IComplexMachine {
public:
    void Print(const std::string& document) override {
        std::cout << "Printing document: " << document << std::endl;
    }

    // Вимушені реалізувати непотрібні методи, кидаючи винятки
    void Scan(const std::string& /* document */) override { throw std::runtime_error("Simple printer cannot scan."); }
    void Fax(const std::string& /* document */) override { throw std::runtime_error("Simple printer cannot fax."); }
    void Staple(const std::string& /* document */) override { throw std::runtime_error("Simple printer cannot staple."); }
    void Bind(const std::string& /* document */) override { throw std::runtime_error("Simple printer cannot bind."); }
};

// ✅ Дотримання (Adhering to ISP)
class IPrinter {
public:
    virtual void Print() = 0;
    virtual ~IPrinter() = default;
};

class IScanner {
public:
    virtual void Scan() = 0;
    virtual ~IScanner() = default;
};

class PrinterScanner : public IPrinter, public IScanner {
public:
    void Print() override { std::cout << "Printing..." << std::endl; }
    void Scan() override { std::cout << "Scanning..." << std::endl; }
};

//=================================================================================
// DIP — Dependency Inversion Principle (Принцип інверсії залежностей)
//=================================================================================

// ❌ Порушення (Violating DIP)
// Модуль низького рівня (Деталь - конкретний клас)
class EmailService_BadDIP {
public:
    void Send(const std::string& message) const {
        std::cout << "Sending email (Bad DIP): " << message << std::endl;
    }
};

// Модуль низького рівня (Деталь - конкретний клас)
class SmsService_BadDIP {
public:
    void Send(const std::string& message) const {
        std::cout << "Sending SMS (Bad DIP): " << message << std::endl;
    }
};

// Модуль високого рівня (Бізнес-логіка)
class OrderService_BadDIP {
private:
    // Жорстка залежність від конкретних класів EmailService_BadDIP та SmsService_BadDIP
    
    EmailService_BadDIP emailService_;
    SmsService_BadDIP smsService_;

public:
    void PlaceOrderEmail() const {
        // Пряма залежність від конкретної реалізації
        emailService_.Send("Order Placed Successfully! (via Email)");
    }

    void PlaceOrderSms() const {
        // Пряма залежність від конкретної реалізації
        smsService_.Send("Order Placed Successfully! (via SMS)");
    }
};




// ✅ Дотримання (Adhering to DIP)
// Абстракція (Інтерфейс)
class IMessageSender {
public:
    virtual void Send(const std::string& message) = 0;
    virtual ~IMessageSender() = default;
};

// Модуль низького рівня залежить від абстракції
class EmailService : public IMessageSender {
public:
    void Send(const std::string& message) override {
        std::cout << "Sending email: " << message << std::endl;
    }
};

class SmsService : public IMessageSender {
public:
    void Send(const std::string& message) override {
        std::cout << "Sending SMS: " << message << std::endl;
    }
};

// Модуль високого рівня залежить від абстракції
class OrderService {
private:
    // Використовуємо розумний вказівник (smart pointer) для управління залежністю
    std::shared_ptr<IMessageSender> _sender;

public:
    // Залежність "інвертована" через конструктор
    OrderService(std::shared_ptr<IMessageSender> sender) : _sender(sender) {}

    void PlaceOrder() {
        _sender->Send("Order Placed Successfully!"); // Викликаємо абстракцію
    }
};


int main()
{
    std::cout << "--- 1. SRP Example (C++) ---" << std::endl;
    ReportDataGenerator generator;
    ReportPrinter printer(generator);
    printer.PrintReport();



    
    std::cout << "\n--- 2. OCP Example (C++) ---" << std::endl;
    Circle circle;
    circle.Radius = 5.0;

    Rectangle rectangle;
    rectangle.Width = 4.0;
    rectangle.Height = 6.0;

    
    // Використання OCP: TotalArea не потрібно змінювати при додаванні нових форм
    std::vector<Shape*> shapes;
    shapes.push_back(&circle);
    shapes.push_back(&rectangle);
    
    AreaCalculator calculator;
    std::cout << "Total Area: " << calculator.TotalArea(shapes) << std::endl;
   




    std::cout << "\n--- 3. LSP Example (C++) ---" << std::endl;
    Dog dog;
    Cat cat;
    LetAnimalSound(dog);
    LetAnimalSound(cat);
    



    std::cout << "\n--- 4. ISP Example (C++) ---" << std::endl;
    PrinterScanner ps;
    ps.Print();
    ps.Scan();



    std::cout << "\n--- 5. DIP Example (C++) ---" << std::endl;
    // --- Порушення DIP ---
    OrderService_BadDIP badOrderProcessor;
    badOrderProcessor.PlaceOrderEmail();
    badOrderProcessor.PlaceOrderSms();

    // --- Дотримання DIP ---
    // Використання: EmailService
    std::shared_ptr<IMessageSender> emailService = std::make_shared<EmailService>();
    OrderService orderServiceEmail(emailService);
    orderServiceEmail.PlaceOrder();

    // Використання: SmsService
    std::shared_ptr<IMessageSender> smsService = std::make_shared<SmsService>();
    OrderService orderServiceSms(smsService);
    orderServiceSms.PlaceOrder();

    return 0;
}