#include "Badanie.hpp"
#include <iostream>

using namespace std;

int main() {
    int size, samples, operations;

    cout << "Podaj rozmiar struktury: ";
    cin >> size;
    cout << "Podaj liczbe egzemplarzy: ";
    cin >> samples;
    cout << "Podaj liczbe operacji: ";
    cin >> operations;

    int wybor;

    do {
        cout << "\nWYBIERZ METODE DO ZBADANIA:\n";
        cout << "0. Zakoncz\n";
        cout << "1. insert(key, value)\n";
        cout << "2. remove(key)\n";
        cin >> wybor;

        switch (wybor) {
            case 1:
                cout << "BADANIE: insert\n";
            Badanie::testInsert(size, samples, operations);
            break;
            case 2:
                cout << "BADANIE: remove\n";
            Badanie::testRemove(size, samples, operations);
            break;
            default:
                cout << "Nieprawidlowy wybor.\n";
        }

    } while (wybor != 0);

    return 0;
}
