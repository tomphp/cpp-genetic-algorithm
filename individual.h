#ifndef _CPPGA_INDIVIDUAL_H_
#define _CPPGA_INDIVIDUAL_H_

#include <string>
#include <memory>
#include "./result.h"
#include "./executor.h"

using std::string;
using std::shared_ptr;

class Gene;

typedef string Sequence;

class Individual {
    public:
        static const int kSequenceSize = 128;

        explicit Individual(const shared_ptr<Executor> executor);

        Individual(const shared_ptr<Executor> executor,
                   const Sequence sequence);

        void initialize();

        void set_sequence(const Sequence sequence);

        Sequence sequence() const;
        float value() const;
        string formula() const;
        float fitness(float target) const;

    private:
        Sequence sequence_;

        Result result_;

        shared_ptr<Executor> executor_;
};

#endif  // _CPPGA_INDIVIDUAL_H_
