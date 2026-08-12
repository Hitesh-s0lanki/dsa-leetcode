#include <iostream>

using namespace std;

int gcd(int num1, int num2) {
    while (num2 != 0) {
        int remainder = num1 % num2;

        num1 = num2;

        num2 = remainder;
    }

    return num1;
}

int gcdOfOddEvenSums(int n) {
    // define
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 1; i <= 2 * n; i++) {
        if (i % 2 == 0)
            evenSum += i;
        else
            oddSum += i;
    }

    return gcd(evenSum, oddSum);
}

int main() {
    cout << gcdOfOddEvenSums(4);

    return 0;
}