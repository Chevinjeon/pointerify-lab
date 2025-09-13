// COMSC-210 | Lab 05 (Pointerify) | Chevin Jeon
// IDE used: VSC g++ (C++11)
//
// Program purpose:
//   Rework a reference-based swap function into a pointer-based version,
//   demonstrate calling it by passing addresses, and print results.
//
// Conventions covered:
//   - using namespace std;
//   - function headers + prototypes
//   - consistent 4-space indentation, no extra blank lines
//   - specific error messages (null pointer precheck)
//   - simple test harness in main()
//
// Notes:
//   This mirrors the instructor's starter but uses pointers (int*).
//   We keep behavior identical: swap two ints and return their sum.

#include <iostream>
using namespace std;

// ---------- Function Prototypes ----------
/*
 * swap_ptr(a, b)
 * purpose: Swap the integers pointed to by a and b, then return the sum.
 * arguments: a (int*), b (int*)
 * returns: int (sum of *a and *b after swap)
 * errors: If either pointer is null, prints a clear error and returns 0.
 */
int swap_ptr(int* a, int* b);

// ---------- main ----------
int main() {
    // Set up two integers to demonstrate swapping via pointers
    int x = 5;
    int y = 10;

    // Show initial values
    cout << "x = " << x << "  | y = " << y << endl;

    // Inform the user what we're doing
    cout << "Swapping using pointers...\n";

    // Call the pointer-based swap, passing addresses of x and y
    int sum = swap_ptr(&x, &y);

    // Show results after swap
    cout << "x = " << x << " | y = " << y << endl;
    cout << "sum = " << sum << endl;

    // (Light) extra tests
    cout << "\n-- Additional checks --\n";
    // Swap back to original to show symmetry
    swap_ptr(&x, &y);
    cout << "After swapping back: x = " << x << " | y = " << y << endl;

    // Demonstrate null check (won’t change values, should print an error)
    int* nullPtr = nullptr;
    swap_ptr(nullPtr, &y); // safely handled

    return 0;
}

// ---------- Function Definitions ----------
int swap_ptr(int* a, int* b) {
    // Validate pointers before dereferencing to avoid undefined behavior
    if (a == nullptr || b == nullptr) {
        cout << "ERROR: swap_ptr received a null pointer. "
             << "Both pointers must reference valid integers.\n";
        return 0; // Safe default; no swap performed
    }

    // Use *a and *b to access the integers at the provided addresses
    int temp = *a; // temporarily hold the value pointed to by a
    *a = *b;       // place b's value into a's location
    *b = temp;     // place temp (old a) into b's location

    // Return the sum of the swapped values
    return *a + *b;
}
