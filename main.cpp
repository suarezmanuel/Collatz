#include <iostream>

// next step: use memoization to speed up the proccess
int collaz (int num, int count=1) {
    if (num < 1) { return -1; }
    if (num == 1) { return count; }
    if (num % 2 == 0) { collaz (num/2, count++); }
    else { collaz (3*num + 1, count++); }
}

int main () {
    std::cout << collaz(8) << std::endl;
}