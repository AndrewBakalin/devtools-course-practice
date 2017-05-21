// Copyright 2017 Alexander Gaivanuk

#include "include/statistical_calculator.h"
#include "include/statistical_moments.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <stdexcept>

using std::vector;
using std::string;

const char *StatisticalCalculator::help_message_ =
    "This is a statistical moments calculator\n"
    "Usage:\n"
    "   $ statistical_moments <operation> -v <values> -p <probabilities>\n\n"
    "   <values> is space-separated list of random variable values\n"
    "   <probabilities> is space-separated list of "
    "random variable probabilities\n"
    "   <operation> can take one of the following values:\n"
    "       -disp\n"
    "           calulate disperion\n"
    "       -exp\n"
    "           calculate expectation\n"
    "       -moment <order> <offset>\n"
    "           calculate statistical moment of "
    "the given order with the given offset\n"
    "For example:\n"
    "   statistical_calculator -moment "
    "3 1 -v 3.3 5 1.3 4.0 -p 0.25 0.45 0.1 0.2\n";

unsigned StatisticalCalculator::ParseInt(const char *s) {
    char *end = nullptr;
    auto value = std::strtol(s, &end, 10);

    if (end[0])
        throw string("unrecognized argument ") + s;
    if (value < 0)
        throw string("specified value ") + s + " is less then zero";

    return static_cast<unsigned>(value);
}

bool StatisticalCalculator::TryParseDouble(const char *s, double *value) {
    char *end = nullptr;
    *value = std::strtod(s, &end);
    return end[0] == 0;
}

int StatisticalCalculator::ParseList(
    int argc, const char *const *argv, int curArg, vector<double> *list) {
    double value = 0.0;
    while (curArg < argc && TryParseDouble(argv[curArg], &value)) {
        list->push_back(value);
        curArg++;
    }
    return curArg;
}

string StatisticalCalculator::operator()(
    int argc, const char *const *argv) const {
    if (argc == 1)
        return help_message_;

    try {
        if (argc < 6)
            throw string("too few arguments");

        int curArg = 1;

        string operation = argv[curArg++];
        unsigned order = 0;
        unsigned offset = 0;

        if (operation == "-moment") {
            if (argc < 8)
                throw string("too few arguments");
            order = ParseInt(argv[curArg++]);
            offset = ParseInt(argv[curArg++]);
        }

        vector<double> values;
        vector<double> probabilities;

        string arg = argv[curArg++];

        if (arg == "-v") {
            curArg = ParseList(argc, argv, curArg, &values);

            if (curArg >= argc) {
                throw string("two few arguments");
            }

            arg = argv[curArg++];
            if (arg == "-p") {
                ParseList(argc, argv, curArg, &probabilities);
            } else {
                throw string("unrecognized argument ") + arg;
            }
        } else {
            throw string("unrecognized argument ") + arg;
        }

        if (values.size() != probabilities.size())
            throw string("values and probabilities lists "
                         "must have the same length");

        try {
            double moment;

            if (operation == "-exp") {
                moment =
                    StatisticalMoments::GetExpectancy(values, probabilities);
            } else if (operation == "-disp") {
                moment =
                    StatisticalMoments::GetDispersion(values, probabilities);
            } else if (operation == "-moment") {
                moment =
                    StatisticalMoments::GetCustomMoment(
                        values, probabilities, order, offset);
            } else {
                throw string("unrecognized argument ") + operation;
            }

            return std::to_string(moment);
        } catch(const std::runtime_error &e) {
            return string("ERROR: ") + e.what();
        }
    }
    catch (const string &e) {
        return string("ERROR: ") + e;
    }
}
