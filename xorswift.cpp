/*
Constant time and low memory non-cryptographic pseudo-random-number generation.
*/

#include <iostream>
#include <climits>

using namespace::std;


struct State {
    int state;
};


static constexpr int U = 13;
static constexpr int V = 17;
static constexpr int W = 5;
static constexpr State STATE = State {
    .state = 314159265 // magic number, ask wikipedia
};


/// @brief take any integer between [INT_MIN; INT_MAX] and map them to ]0; 1]
/// @param the value to normalise
/// @return the normalised value
float normalise(const int& raw) {
    int raw_positive = raw < 0 ? raw : -raw;
    float normalised = (double)(raw_positive - INT_MIN)/(double)INT_MAX;
    return normalised;
}


State progress_state(const State& old_state, const int& u, const int& v, const int& w) {
    int result = old_state.state;

    result ^= (result << u);
    result ^= (result >> v);
    result ^= (result << w);

    return State { .state = result };
}


pair<float, State> xorswift(const State& old_state) {
    /*Takes in the previous state and returns a std::pair of a random float in range [0; 1] and a new State.*/
    const State new_state = progress_state(old_state, U, V, W);
    return pair(normalise(new_state.state), new_state);
}