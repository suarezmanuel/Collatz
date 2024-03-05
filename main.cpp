#include <iostream>

int t;

int calc_recursive (int num, int count=0) {

    if (num == 1) { return count; }
    t = (num % 2 == 0) ? num/2 : 3*num + 1;
    return calc_recursive (t, ++count);
}

int calc_iterative (int num, int count=0) {

    while (num != 1) {
        num = (num % 2 == 0) ? num/2 : 3*num + 1;
        count ++;
    }
    return count;   
}

int collaz (int num, int(*calc)(int, int), int count=0) {
    if (num < 1) { return -1; }
    return calc (num, count);
}

int main () {
    std::cout << "enter your number bigger than 0" << std::endl;
    int n; std::cin >> n;

    std::cout << std::endl << "iterations for calculating " << "collaz(" << n << "): " << std::endl;
    std::cout << std::endl;
    std::cout << "iteratively: " << collaz(n, calc_iterative) << std::endl; 
    std::cout << "recursively: " << collaz(n, calc_recursive) << std::endl; 
}