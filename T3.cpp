#include <iostream>
#include <vector>
#include <functional>


// 1. In C++ write a function summing all vector elements:
// std::vector xs = { 1, 2, 3, 4 };
// vectorSum(xs); // 10

void vectorSum(const std::vector<int>& xs) {
    int sum = 0;
    for (const auto& x : xs) {
        sum += x;
    }
    std::cout << "Sum: " << sum << std::endl;
}





// 2. Let's separate iteration and an operation to be done.
// Write a function aggregating a vector with any given function:
// aggregate(xs, add); // 10
// aggregate(xs, mul); // 24

// void aggregate(const std::vector<int>& xs, int (*operation)(int, int))  // or std::function<int(int, int)>
// {
//     int result = 0;
//     for (const auto& x : xs) {
//         result = operation(result, x);
//         std::cout << "Current result: " << result << std::endl;
//     }
//     std::cout << "Aggregate result: " << result << std::endl;
// }

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) 
{
    if (a == 0) return b;
    return a * b;
}



// 3. Add an optional parameter to start aggregating with.
// aggregate(xs, mul, 10); // 240
// aggregate(xs, concat, std::string("0")); // "01234"



template<typename T>
void aggregate(const std::vector<int>& xs, T (*operation)(T, int), T start = T()) {
    T result = start;
    for (const auto& x : xs) {
        result = operation(result, x);
    }
    std::cout << "Aggregate result: " << result << std::endl;
}

std::string concat(const std::string a, int b) {
    return a + std::to_string(b);
}




//  4. Implement `aggregate` recursively.
// Let's also make it work with static arrays (and maybe other collections?)


template<typename T, typename Iterator>
T aggregate_recursive_impl(Iterator current, Iterator end, T (*operation)(T, int), T result) {
    if (current == end) {
        return result;
    }
    result = operation(result, *current);
    return aggregate_recursive_impl(++current, end, operation, result);
}


template<typename T, typename Container>
void aggregate_recursive(const Container& xs, T (*operation)(T, int), T start) {
    T final_result = aggregate_recursive_impl(xs.begin(), xs.end(), operation, start);
    std::cout << "Aggregate result: " << final_result << std::endl;
}


int main()
{
    std::vector<int> xs = { 1, 2, 3, 4 };
    vectorSum(xs); 

    aggregate<int>(xs, add);
    aggregate<int>(xs, mul);



    aggregate<int>(xs, mul, 10);
    aggregate<std::string>(xs, concat, std::string("0"));
}