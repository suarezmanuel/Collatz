#include <iostream>

int calc (int num, int count) {
    if (num == 1) { return count; }
    if (num % 2 == 0) { return calc (num/2, ++count); }
    else { return calc (3*num + 1, ++count); }
}

int collaz (int num, int count=0) {
    if (num < 1) { return -1; }
    return calc (num, count);
}

int main () {
    std::cout << "enter your number bigger than 0" << std::endl;
    int n = 0; std::cin >> n;
    std::cout << "collaz(" << n << ")" << " takes " << collaz(n) << " iterations" << std::endl;
}