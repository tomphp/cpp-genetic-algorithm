#include <sstream>
#include <string>
#include "./executor.h"
#include "./gene.h"

using std::string;

Result Executor::execute(const string sequence) const {
    auto program = compile(sequence);

    float total = program.front().value();
    auto formula = std::to_string(program.front().value());

    program.pop_front();

    while (!program.empty()) {
        auto op = program.front().value();
        program.pop_front();

        auto value = program.front().value();
        program.pop_front();

        switch (op) {
            case Gene::Operator::MULTIPLY:
                formula += "*";

                total *= value;
                break;

            case Gene::Operator::DIVIDE:
                formula += "/";

                total /= value;
                break;

            case Gene::Operator::ADD:
                formula += "+";

                total += value;
                break;

            case Gene::Operator::SUBTRACT:
                formula += "-";

                total -= value;
                break;
        }

        formula += std::to_string(value);
    }

    return Result(total, formula);
}

Program Executor::compile(const string sequence) const {
    Program program;

    auto expect_operator = false;

    for (auto c = 0; c < sequence.length(); c += 4) {
        Gene g(sequence.substr(c, 4));

        if (g.type() == Gene::Type::NOOP) {
            continue;
        }

        if (expect_operator && g.type() != Gene::Type::OPERATOR) {
            continue;
        }

        if (!expect_operator && g.type() != Gene::Type::NUMBER) {
            continue;
        }

        program.push_back(g);

        expect_operator = !expect_operator;
    }

    if (program.back().type() == Gene::Type::OPERATOR) {
        program.pop_back();
    }

    return program;
}
