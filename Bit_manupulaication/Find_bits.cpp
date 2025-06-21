#include <iostream>
#include <bitset>

int main() {
    int x = 2;  // Example number

    // Method 1: Using bitset
    std::bitset<32> bits(x);  // 32 bits for a 4-byte integer
    std::cout << "Bits using bitset: " << bits << std::endl;

    // Method 2: Using bitwise operations
    std::cout << "Bits using bitwise operations: ";
    for (int i = 31; i >= 0; --i) {
        std::cout << ((x >> i) & 1);
    }
    std::cout << std::endl;

    return 0;
}
