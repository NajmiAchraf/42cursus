#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "ASpell.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Warlock {
    private:
        string name, title;
        vector<ASpell *> spells;
    
        Warlock();
        Warlock(const Warlock &);
        Warlock &operator=(const Warlock &);
    
    public:
        const string &getName() const;
        const string &getTitle() const;
        
        void setTitle(const string &title);

        Warlock(const string &name, const string &title);
        ~Warlock();
    
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(const string &name);
        void launchSpell(const string &name, const ATarget &target);

};
