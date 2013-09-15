#ifndef _CPPGA_EXECUTOR_H_
#define _CPPGA_EXECUTOR_H_

#include <string>
#include <list>
#include "./result.h"

using std::string;
using std::list;

class Gene;

typedef list<Gene> Program;

class Executor {
    public:
        Result execute(const string sequence) const;

        float value() const;

        string formula() const;

        float fitness(float target) const;

    private:
        Program compile(const string sequence) const;
};

#endif  // _CPPGA_EXECUTOR_H_
