#include <iostream>

int main() {
    float raggio;

    std::cout << "Inserire il raggio della sfera: ";
    std::cin >> raggio;

    float volume;
    const float PI = 3.14;
    volume = (4/3) * PI * raggio*raggio*raggio;
    std::cout << "Volume della sfera corrispondente: " << volume;
    return 0;
}