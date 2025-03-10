#include <iostream>
using namespace std;

int gcd(int a, int b, int shift = 0) {

    if (a == 0) return b << shift;
    if (b == 0) return a << shift;

    if ((a & 1) == 0 && (b & 1) == 0) {
        return gcd(a >> 1, b >> 1, shift + 1);
    }

    if ((a & 1) == 0) {
        return gcd(a >> 1, b, shift);
    }

    if ((b & 1) == 0) {
        return gcd(a, b >> 1, shift);
    }

    if (a > b) {
        return gcd((a - b) >> 1, b, shift);
    } else {
        return gcd((b - a) >> 1, a, shift);
    }
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << "GCD is " << result << endl;

    return 0;
}
