#include "xorshift_rng"
#include <iostream>
#include <chrono>
#include <thread>
#include <climits>

using namespace std;
using namespace ranges;

int main() {
    for (auto n : views::iota(0,1000)) {
        if xorshift() > 1 || xorshift() < 0 {
            return 1;
        }
    }
    
    return 0;
};