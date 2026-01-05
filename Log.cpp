#include <iostream>
#include <string>
// #include <spdlog/spdlog.h>
// #include <spdlog/sinks/stdout_color_sinks.h>
// #include <spdlog/sinks/basic_file_sink.h>



// #include <glog/logging.h>
// #include <spdlog/spdlog.h>

int main(int argc, char* argv[]) {
    // Ініціалізація (обов'язково)
    // google::InitGoogleLogging(argv[0]);
    // google::InstallFailureSignalHandler(); // опціонально

    // LOG(INFO) << "Програма запущена";
    // LOG(WARNING) << "Увага: значення = " << 42;
    // LOG(ERROR) << "Помилка сталася!";




    int number1, number2;
    std::cout << "Enter number1: ";
    std::cin >> number1;

    std::cout << "Enter number2: ";
    std::cin >> number2;

    std::cout << ((number1 > number2) ? (std::to_string(number2) + " " + std::to_string(number1)) 
                                      : (std::to_string(number1) + " " + std::to_string(number2))) << std::endl;

    (number1 > number2) ? (std::cout << number2 << ' ' << number1 << std::endl) : (std::cout << number1 << ' ' << number2 << std::endl);



    // Лог у файл: logs/INFO_*.log, WARNING_*.log тощо
    return 0;
}


// int main()
// {
//     auto console = spdlog::stdout_color_mt("console");
//     auto file = spdlog::basic_logger_mt("file", "logs/app.txt");
//     spdlog::set_default_logger(std::make_shared<spdlog::logger>("multi", spdlog::sinks_init_list{console, file}));
    
//     spdlog::info("Привіт, {}!", "Світ");
//     spdlog::warn("Увага: {}", 42);
//     spdlog::error("Помилка!");[]
// }