#include <iostream>

using namespace std;

long long sumAndMultiply(int n) {

    long long ans = 0;
    int numberWithoutZero = 0;
    int place = 1;
    int sum = 0;
    
    // remove all the zeros 
    while(n != 0){
        // get the last digit
        int digit = n % 10;

        if (digit != 0){
            numberWithoutZero = digit * place + numberWithoutZero;
            place *= 10;

            sum += digit;
        }
        
        n /= 10;
    }

    

    ans = numberWithoutZero * sum;

    return ans;
}

int main() {

    cout<<sumAndMultiply(10203004);

    return 0;
}
