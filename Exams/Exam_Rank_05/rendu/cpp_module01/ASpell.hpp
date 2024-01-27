#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class ATarget;

class ASpell {
    private:
        string name, effects;
    
    public:
        const string &getName() const;
        const string &getEffects() const;

        ASpell(const string &name, const string &effects);
        virtual ~ASpell();

        virtual ASpell *clone() const = 0;
        
        void launch(const ATarget &target) const;
};

#include "ATarget.hpp"