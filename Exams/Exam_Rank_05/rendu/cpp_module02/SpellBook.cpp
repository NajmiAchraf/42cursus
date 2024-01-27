#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        delete (*it);
    }
    spells.clear();
}

void SpellBook::learnSpell(ASpell *spell) {
    if (!spell)
        return;
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if (spell->getName() == (*it)->getName())
            return;
    }
    spells.push_back(spell->clone());
}

void SpellBook::forgetSpell(const string &name) {
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if (name == (*it)->getName()){
            delete (*it);
            spells.erase(it);
            return;
        } 
    }
}

ASpell* SpellBook::createSpell(string const &name){
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if (name == (*it)->getName()){
            return (*it)->clone();
        }
    }
    return NULL;
}