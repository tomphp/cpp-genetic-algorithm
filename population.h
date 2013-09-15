#ifndef _CPPGA_POPULATION_H_
#define _CPPGA_POPULATION_H_

#include <vector>
#include <memory>
#include "./individual.h"
#include "./executor.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;

typedef vector<Sequence> Sequences;

class Population {
  public:
    static const int kSize = 80;

    explicit Population(const shared_ptr<Executor> executor);

    Population(const shared_ptr<Executor> executor,
               const Sequences sequences);

    void create_population();

    void create_population(const Sequences sequences);

    void initialize();

    shared_ptr<Individual> fittest(const float target) const;

    Sequences offspring_sequences(const float target,
                                  const int count) const;

  private:
    void mutate(Sequence &sequence) const;

    Sequence random_sequence(const float target) const;

    vector<shared_ptr<Individual>> members_;

    shared_ptr<Executor> executor_;
};

#endif  // _CPPGA_POPULATION_H_
