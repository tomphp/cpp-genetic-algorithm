#include <string>
#include <cstdlib>
#include "./individual.h"
#include "./gene.h"

using std::string;

Individual::Individual(
    const shared_ptr<Executor> executor) : executor_(executor) {
}

Individual::Individual(
        const shared_ptr<Executor> executor,
        const Sequence sequence) : executor_(executor) {
    set_sequence(sequence);
}

void Individual::initialize() {
    Sequence sequence = "";

    for (auto c = 0; c < kSequenceSize; c++) {
        sequence += std::to_string(rand() % 2);
    }

    set_sequence(sequence);
}

void Individual::set_sequence(const Sequence sequence) {
    sequence_ = sequence;

    result_ = executor_->execute(sequence);
}

Sequence Individual::sequence() const {
    return sequence_;
}

float Individual::value() const {
    return result_.value();
}

string Individual::formula() const {
    return result_.formula();
}

float Individual::fitness(float target) const {
    return 1.0 / abs(target - value()) * 100;
}
