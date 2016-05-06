#include <iostream>
#include <chrono>
using namespace std;

int main(int argc, char *argv[])
{
    auto t1 = std::chrono::high_resolution_clock::now();

    int i;
    cout << "Digite um valor inteiro\n";
    cin >> i;

    auto t2 =  std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = t2 - t1;
    cout << "Tempo total gasto na digitação: " << tempo.count() << "\n";
    return 0;
}

