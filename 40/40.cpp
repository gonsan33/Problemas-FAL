//GONZALO SÁNCHEZ MONTESINOS
//DG29


#include <iostream>
#include <vector>
using namespace std; 

int f_nf(int a, int b) {

    if (b < 10) {
        return (a / 10) * 10 + (a % 10 + b) % 10; 
    }
    else {
        return (a % 10 + b % 10) % 10 + 10 * f_nf(a / 10, b / 10); 
    }
}

int f_f(int a, int b, int suma, int pot) {
    if (a < 10 && b < 10) return ((a + b) % 10) * pot + suma; 
    else {
        return f_f(a / 10, b / 10, ((a % 10 + b % 10) % 10) * pot +  suma, 10*pot); 
    }
}

void resuelveCasos() {
    int a, b; 
    std::cin >> a >> b; 
    std::cout << f_nf(a, b) << " " << f_f(a, b, 0, 1) << '\n'; 
}


int main()
{
    int n; 
    std::cin >> n; 
    for (int i = 0; i < n; ++i) resuelveCasos();
    return 0; 
}

