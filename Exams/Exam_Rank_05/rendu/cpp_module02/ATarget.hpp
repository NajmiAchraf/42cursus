#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class ASpell;

class ATarget {
    private:
        string type;
    
    public:
        const string &getType() const;

        ATarget(const string &type);
        virtual ~ATarget();

        virtual ATarget *clone() const = 0;
        
        void getHitBySpell(const ASpell &spell) const;


};

#include "ASpell.hpp"