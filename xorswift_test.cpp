#include "xorswift.cpp"
#include <iostream>
#include <climits>

using namespace std;


int main() {
    State state = STATE;
    float rnd;

    while (true) {
        tie(rnd, state) = xorswift(state);
        cout << rnd << endl;
    };
    
    return 0;
};