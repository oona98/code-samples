/*
 * Program asks upper bound from user and prints all prime numbers which are smaller
 * than the given upper bound.
*/

#include <iostream>
#include <string>

void IsPrimeNumber(bool* itemptr, int size) {
    *(itemptr) = false;
    *(itemptr + 1) = false;

    for(int divider_number = 2; divider_number < size; ++divider_number) {
        for(int number = divider_number + 1; number < size; ++number) {
            if(number % divider_number == 0) {
                *(itemptr + number) = false;
            }
        }
    }
}

int main()
{
    std::string upper_bound;
    std::cout << "Enter an upper bound: ";
    std::getline(std::cin, upper_bound);

    int u_bound = std::stoi(upper_bound);

    bool array[u_bound];

    for(bool* i = array; i < array + u_bound; ++i) {
        *i = true;
    }

    IsPrimeNumber(array, u_bound);
    int number = 0;

    std::cout << "Prime numbers smaller than " << u_bound << ':' << std::endl;
    for(bool* i = array; i < array + u_bound; ++i) {
        if(*i == true) {
            std::cout << number <<  " ";
        }
        ++number;
    }
    std::cout << std::endl;
}
