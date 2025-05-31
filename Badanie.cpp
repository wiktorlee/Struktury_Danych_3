#include "Badanie.hpp"
#include "TablicaDynamiczna.hpp"
#include "KubelkiJednokierunkowe.hpp"
#include "AVLTree.h"
#include "DaneGenerator.hpp"
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

void Badanie::testInsert(int size, int samples, int operations) {
    long long t_tab = 0, t_list = 0, t_avl = 0;

    for (int s = 0; s < samples; ++s) {
        TablicaDynamiczna ht1;
        KubelkiJednokierunkowe ht2(size/2);
        AVLTree ht3;

        auto pary = DaneGenerator::generujParyKluczWartosc(size + operations);

        for (int i = 0; i < size; ++i) {
            ht1.insert(pary[i].first, pary[i].second);
            ht2.insert(pary[i].first, pary[i].second);
            ht3.insert(pary[i].first, pary[i].second);
        }

        for (int i = size; i < size + operations; ++i) {
            auto [key, value] = pary[i];

            auto t0 = high_resolution_clock::now();
            ht1.insert(key, value);
            auto t1 = high_resolution_clock::now();
            t_tab += duration_cast<nanoseconds>(t1 - t0).count();

            t0 = high_resolution_clock::now();
            ht2.insert(key, value);
            t1 = high_resolution_clock::now();
            t_list += duration_cast<nanoseconds>(t1 - t0).count();

             t0 = high_resolution_clock::now();
             ht3.insert(key, value);
             t1 = high_resolution_clock::now();
             t_avl += duration_cast<nanoseconds>(t1 - t0).count();
        }

        delete[] pary;
    }

    double n = static_cast<double>(samples * operations);
    cout << "Sredni czas insert (Tablica): " << t_tab / n << " ns\n";
    cout << "Sredni czas insert (Lista): " << t_list / n << " ns\n";
    cout << "Sredni czas insert (AVL): " << t_avl / n << " ns\n";
}

void Badanie::testRemove(int size, int samples, int operations) {
    long long t_tab = 0, t_list = 0, t_avl = 0;

    for (int s = 0; s < samples; ++s) {
        TablicaDynamiczna ht1;
        KubelkiJednokierunkowe ht2(size/2);
        AVLTree ht3;

        auto pary = DaneGenerator::generujParyKluczWartosc(size + operations);

        for (int i = 0; i < size + operations; ++i) {
            ht1.insert(pary[i].first, pary[i].second);
            ht2.insert(pary[i].first, pary[i].second);
            ht3.insert(pary[i].first, pary[i].second);
        }

        for (int i = 0; i < operations; ++i) {
            int key = pary[i].first;

            auto t0 = high_resolution_clock::now();
            ht1.remove(key);
            auto t1 = high_resolution_clock::now();
            t_tab += duration_cast<nanoseconds>(t1 - t0).count();

            t0 = high_resolution_clock::now();
            ht2.remove(key);
            t1 = high_resolution_clock::now();
            t_list += duration_cast<nanoseconds>(t1 - t0).count();

            t0 = high_resolution_clock::now();
             ht3.remove(key);
             t1 = high_resolution_clock::now();
             t_avl += duration_cast<nanoseconds>(t1 - t0).count();
        }

        delete[] pary;
    }

    double n = static_cast<double>(samples * operations);
    cout << "Sredni czas remove (Tablica): " << t_tab / n << " ns\n";
    cout << "Sredni czas remove (Lista): " << t_list / n << " ns\n";
    cout << "Sredni czas remove (AVL): " << t_avl / n << " ns\n";
}
