#include "./gene.h"
#include <bitset>
#include <string>

void Gene::set_code(const string code) {
  std::bitset<4> bits;

  for (auto bit = 0; bit < 4; bit++) {
    bits.set(3-bit, (code[bit] == '1'));
  }

  value_ = bits.to_ulong();
}

Gene::Type Gene::type() const {
  if (value_ == 0) {
    return Gene::Type::NOOP;
  }

  if (value_ < 10) {
    return Gene::Type::NUMBER;
  }

  if (value_ < 14) {
    return Gene::Type::OPERATOR;
  }

  return Gene::Type::NOOP;
}

unsigned int Gene::value() const {
  return value_;
}
