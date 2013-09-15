#ifndef _CPPGA_GENE_H_
#define _CPPGA_GENE_H_

#include <string>

using std::string;

class Gene {
  public:
    enum Type { NUMBER, OPERATOR, NOOP };

    enum Operator { MULTIPLY = 10, DIVIDE = 11, ADD = 12, SUBTRACT = 13 };

    explicit Gene(const string code) { set_code(code); }

    explicit Gene(const unsigned int value) : value_(value) {}

    void set_code(const string code);

    Gene::Type type() const;

    unsigned int value() const;

  private:
    unsigned int value_;
};

#endif  // _CPPGA_GENE_H_
