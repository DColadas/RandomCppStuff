#include <iostream>

int main(int argc, char const *argv[]) {
    if (argc > 1) [[unlikely]] {
        std::cout << argv[1];
    }
    else [[likely]] {
        std::cout << argv[0];
    }

    switch (argc) {
        [[likely]] case 1: 
            std::cout << argv[0];
            break;
        case 5:
            std::cout << argv[4];
            break;
        [[unlikely]] default: 
            std::cout << argv[0];
            break;
    }

    // Should check the assembly

    return 0;
}
