#include <iostream>
#include <string>
#include <random>
using namespace std;

// ---------------- Verhoeff Tables ----------------

// Multiplication table (d)
int d_table[10][10] = {
    {0,1,2,3,4,5,6,7,8,9},
    {1,2,3,4,0,6,7,8,9,5},
    {2,3,4,0,1,7,8,9,5,6},
    {3,4,0,1,2,8,9,5,6,7},
    {4,0,1,2,3,9,5,6,7,8},
    {5,9,8,7,6,0,4,3,2,1},
    {6,5,9,8,7,1,0,4,3,2},
    {7,6,5,9,8,2,1,0,4,3},
    {8,7,6,5,9,3,2,1,0,4},
    {9,8,7,6,5,4,3,2,1,0}
};

// Permutation table (p)
int p_table[8][10] = {
    {0,1,2,3,4,5,6,7,8,9},
    {1,5,7,6,2,8,3,0,9,4},
    {5,8,0,3,7,9,6,1,4,2},
    {8,9,1,6,0,4,3,5,2,7},
    {9,4,5,3,1,2,6,8,7,0},
    {4,2,8,6,5,7,3,9,0,1},
    {2,7,9,3,8,0,6,4,1,5},
    {7,0,4,6,9,1,3,2,5,8}
};

// Inverse table (inv)
int inv_table[10] = {0,4,3,2,1,5,6,7,8,9};

// ---------------- Verhoeff Functions ----------------

// Generate checksum digit
char generateChecksum(const string &num) {
    int c = 0;
    int len = num.size();

    for (int i = 0; i < len; i++) {
        int digit = num[len - i - 1] - '0';
        c = d_table[c][p_table[(i + 1) % 8][digit]];
    }

    return '0' + inv_table[c];
}

// Validate full number
bool validateVerhoeff(const string &num) {
    int c = 0;
    int len = num.size();

    for (int i = 0; i < len; i++) {
        int digit = num[len - i - 1] - '0';
        c = d_table[c][p_table[i % 8][digit]];
    }

    return (c == 0);
}

// ---------------- Utility ----------------

// Generate random 11-digit base number
string generateRandomBase() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 9);

    string num = "";

    for (int i = 0; i < 11; i++) {
        num += to_string(dist(gen));
    }

    return num;
}

// ---------------- Main ----------------

int main() {
    // Step 1: Generate random base number (11 digits)
    string base = generateRandomBase();

    // Step 2: Generate checksum
    char checksum = generateChecksum(base);

    // Step 3: Form full number
    string fullNumber = base + checksum;

    // Step 4: Validate
    bool isValid = validateVerhoeff(fullNumber);

    // Output
    cout << "Generated Base Number : " << base << endl;
    cout << "Checksum             : " << checksum << endl;
    cout << "Full Aadhaar-like No : " << fullNumber << endl;
    cout << "Validation Result    : " << (isValid ? "Valid ✅" : "Invalid ❌") << endl;

    return 0;
}