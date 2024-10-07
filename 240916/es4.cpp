#include <iostream>

int main() {
    
    float dividendo, divisore;
    std::cout << "Dividendo: ";
    std::cin >> dividendo;
    std::cout << "Divisore: ";
    std::cin >> divisore;

    int quoziente = dividendo/divisore;
    int resto = int(dividendo)%int(divisore);

    std::cout << "Quoziente: " << quoziente << std::endl;
    std::cout << "Resto: " << resto;

}