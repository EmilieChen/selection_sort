// selection_sort.cpp : définit le point d'entrée de l'application.
//

#include "selection_sort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

using namespace std;


template <class IT>
void my_sort(IT it_b, IT it_e) {

    for (IT it_1 = it_b; it_1 != it_e; ++it_1) {

        IT it_min = it_1;

        for (IT it_2 = it_1; it_2 != it_e; ++it_2) {

            if (*it_2 < *it_min) {
                it_min = it_2;
            }

        }

        if (*it_1 != *it_min) {
            auto intermediaire = *it_1;
            *it_1 = *it_min;
            *it_min = intermediaire;
        }
    }

}


template<class Cont>
void my_show(Cont c) {

    std::cout << "sorted" << std::endl;
    std::ofstream outfile("sorted.txt");

    std::cout << type_file << std::endl;
    std::cout << type_container << std::endl;

    outfile << type_file << std::endl;
    outfile << type_container << std::endl;

    for (const auto& e : c) {

        std::cout << e << std::endl;
        outfile << e << std::endl;
    }

    outfile.close();
}


template<class Cont>
void sort_and_show(Cont c) {

    my_sort(c.begin(), c.end());
    my_show(c);
}


template <class Cont, class T>
void read(std::ifstream& file) {

    std::string str;

    Cont v;

    while (file.peek() != EOF) {
        T val;

        file >> val;
        std::cout << val << std::endl;

        v.push_back(val);
        std::getline(file, str);

    }
    return sort_and_show(v);
}


template <class T>
void readContainer(std::ifstream& file) {

    std::string str;

    std::getline(file, str);

    type_container = str[0];

    std::cout << str << std::endl;

    switch (type_container) {
        case'v':
        {
            return read<std::vector<T>, T>(file);
            break;
        }
        case 'l':
        {
            return read<std::list<T>, T>(file);
            break;
        }
        case 'd':
        {
            return read<std::deque<T>, T>(file);
            break;
        }
        default:
            throw std::runtime_error("Unknown type container");
    }

}


void main()
{
    std::string str;

    std::ifstream file;
    file.open("example_3.txt");

    if (file.is_open()) {
        std::cout << "Successfully opened file" << std::endl;
    }
    else {
        std::cout << "Failed to open file" << std::endl;
    }

    std::getline(file, str);

    std::cout << str << std::endl;

    type_file = str[0];

    switch (type_file) {
        case'i':
        {
            return readContainer<int>(file);
            break;
        }
        case 'f':
        {
            return readContainer<float>(file);
            break;
        }
        case 's':
        {
            return readContainer<std::string>(file);
            break;
        }
        default:
            throw std::runtime_error("Unknown type file");
    }

}


