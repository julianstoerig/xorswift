/*
Constant time and low memory non-cryptographic pseudo-random-number generation.
*/

#include <iostream>
#include <climits>


struct State {
    const int state;
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
[[gnu::pure]] const float normalise(const int& raw) noexcept {
    const int raw_positive = raw < 0 ? raw : -raw;
    const float normalised = (double)(raw_positive - INT_MIN)/(double)INT_MAX;
    return normalised;
}


[[gnu::pure]] const State progress_state(const State& old_state, const int& u, const int& v, const int& w) noexcept {
    int result = old_state.state;

    // known XOR-shift algorithm
    result ^= (result << u);
    result ^= (result >> v);
    result ^= (result << w);

    return State { .state = result };
}

[[gnu::pure]] const std::pair<float, State> xorswift(const State& old_state) noexcept {
    /*Takes in the previous state and returns a std::pair of a random float in range [0; 1] and a new State.*/
    const State new_state = progress_state(old_state, U, V, W);
    return std::pair(normalise(new_state.state), new_state);
}