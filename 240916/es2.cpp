#include <iostream>

int main() {
    std::cout << "Temperatura (F°): ";
    float temperatura_F;
    std::cin >> temperatura_F;

    float temperatura_C = (temperatura_F-32)/1.8;

    std::cout << "Temperatura (C°): " << temperatura_C;

    return 0;
}