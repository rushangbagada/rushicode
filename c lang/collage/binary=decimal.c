
#include <stdio.h>
#include <math.h>

int main() {
    long long binaryNumber;
    int decimalNumber = 0, position = 0, digit;

    // Prompt user for input
    printf("Enter a binary number: ");
    scanf("%lld", &binaryNumber);

    // Convert binary to decimal
    while (binaryNumber != 0) {
        digit = binaryNumber % 10;
        decimalNumber += digit * pow(2, position);
        binaryNumber /= 10;
        position++;
    }

    // Output the result
    printf("Decimal equivalent: %d\n", decimalNumber);

    return 0;
}
