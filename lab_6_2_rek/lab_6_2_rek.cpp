// lab_6_2_rek.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

// Функція для генерації масиву
void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Функція для виведення масиву
void Print(const int* a, const int size, int i) {
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}
// Функція для максимального значення
int Max(int* a, const int size, int i, int max)
{
    if (a[i] > max)
        max = a[i];
    if (i < size - 1)
        return Max(a, size, i + 1, max);
    else
        return max;
}
// Функція для мінімального значення
int Min(int* a, const int size, int i, int min)
{
    if (a[i] < min)
        min = a[i];
    if (i < size - 1)
        return Min(a, size, i + 1, min);
    else
        return min;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int size = 10;
    int a[size];
    const int Low = -10;
    const int High = 100;

    // Генерація масиву
    Create(a, size, Low, High, 0);
    cout << "massif a:" << endl;
    Print(a, size, 0);

    cout << "max = " << Max(a, size, 1, a[0]) << endl;
    cout << "min = " << Min(a, size, 1, a[0]) << endl;


    cin.get();
    return 0;
}

