#include <experimental/source_location>
#include <iostream>
#include <string_view>

void log(std::string_view message,
         const std::experimental::source_location& location = std::experimental::source_location::current()) {
    std::cout << location.file_name() << ':'
              << location.line() << ':'
              << location.column() << ':'
              << location.function_name() << ' '
              << message << '\n';
}

int main() {
    log("Hello world!");
    // Output:
    // source_location.cpp:15:0:main Hello world!
}