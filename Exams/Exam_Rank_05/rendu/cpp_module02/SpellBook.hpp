#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "ASpell.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class SpellBook {
    private:
        vector<ASpell *> spells;
    
        SpellBook(const SpellBook &);
        SpellBook &operator=(const SpellBook &);
    
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(const string &name);
        ASpell* createSpell(string const &name);

};
