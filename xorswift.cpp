/*
Constant time and low memory non-cryptographic pseudo-random-number generation.
*/

#include <iostream>
#include <chrono>
#include <thread>
#include <climits>

using namespace::std;


float normalise(int raw) {
    int preprocessed = raw < 0 ? raw : -raw;
    return (double)(preprocessed - INT_MIN)/(double)INT_MAX;
}


int xorshift_parametarised(int state, const int& u, const int& v, const int& w) {

    state ^= (state << u);
    state ^= (state >> v);
    state ^= (state << w);

    return state;
}




class Rng {
public:
    float next();
private:
    int xorshift_parametarised(int state, const int& u, const int& v, const int& w);
    void xorshift();
    void initialise();
    float random_number;
    int state;
    const int u = 13;
    const int v = 17;
    const int w = 5;
};



float Rng::next() {
    xorshift();
    return normalise(state);
}


void Rng::initialise() {
    state = 314159265;
}




int main() {
        Rng rng;
    while (true) {
        
        cout << rng.random_number << endl;
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    return 0;
}