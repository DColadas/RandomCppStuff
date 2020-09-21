#include <iostream>
#include <memory>

int main(int argc, char const *argv[]) {
    // You can use mutable lambdas as generators
    auto count = [i = 0]() mutable {
        return i++;
    };

    auto fib = [i = 0, j = 1]() mutable {
        i = std::exchange(j, j + i);
        return i;
    };

    while (count() < 10) {
        std::cout << fib() << '\n';
    }

    return 0;
}
