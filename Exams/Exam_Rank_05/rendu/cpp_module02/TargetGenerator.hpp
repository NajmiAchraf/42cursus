#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "ATarget.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class TargetGenerator {
    private:
        vector<ATarget *> targets;
    
        TargetGenerator(const TargetGenerator &);
        TargetGenerator &operator=(const TargetGenerator &);
    
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *spell);
        void forgetTargetType(const string &name);
        ATarget* createTarget(string const &name);

};
