#include <string>
#include <cstdlib>
#include "./population.h"

Population::Population(const shared_ptr<Executor> executor)
        : executor_(executor) {
    create_population();
}

Population::Population(
        const shared_ptr<Executor> executor,
        const Sequences sequences) : executor_(executor) {
    create_population(sequences);
}

void Population::create_population() {
    for (auto c = 0; c < kSize; c++) {
        auto member = make_shared<Individual>(executor_);

        member->initialize();

        members_.push_back(member);
    }
}

void Population::create_population(const Sequences sequences) {
    for (auto sequence : sequences) {
        auto member = make_shared<Individual>(executor_, sequence);

        members_.push_back(member);
    }
}

shared_ptr<Individual> Population::fittest(const float target) const {
    float fitval = 0;

    shared_ptr<Individual> fittest;

    for (auto member : members_) {
        auto fitness = member->fitness(target);

        if (fitness > fitval) {
            fitval = fitness;
            fittest = member;
        }
    }

    return fittest;
}

Sequences Population::offspring_sequences(const float target, int count) const {
    Sequences sequences;

    while (count--) {
        auto split = std::rand() % Individual::kSequenceSize;

        string new_sequence = random_sequence(target).substr(0, split);

        new_sequence += random_sequence(target).substr(split);

        mutate(new_sequence);

        sequences.push_back(new_sequence);
    }

    return sequences;
}

Sequence Population::random_sequence(const float target) const {
    auto chances = 0;

    for (auto member : members_) {
        chances += member->fitness(target);
    }

    auto choice = rand() % chances;

    auto count = 0;

    string sequence = members_.front()->sequence();

    for (auto member : members_) {
        count += member->fitness(target);

        if (count > choice) {
            break;
        }

        sequence = member->sequence();
    }

    return sequence;
}

void Population::mutate(Sequence &sequence) const {
    auto mutation_rate = 5;

    for (auto c = 0; c < sequence.length(); c++) {
        if (rand() % mutation_rate != 0) {
            continue;
        }

        if (sequence[c] == '1') {
            sequence[c] = '0';
        } else {
            sequence[c] = '1';
        }
    }
}
