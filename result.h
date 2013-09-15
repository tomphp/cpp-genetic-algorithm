#ifndef _CPPGA_RESULT_H_
#define _CPPGA_RESULT_H_

#include <string>

using std::string;

class Result {
    public:
        Result() {}

        Result(const float value, const string formula)
            : value_(value), formula_(formula) {}

        float value() const { return value_; }

        string formula() const { return formula_; }

    private:
        float value_{0};

        string formula_{""};
};

#endif  // _CPPGA_RESULT_H_
