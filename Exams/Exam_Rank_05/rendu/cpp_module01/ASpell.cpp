#include "ASpell.hpp"


const string &ASpell::getName() const {
    return name;
}

const string &ASpell::getEffects() const {
    return effects;
}


ASpell::ASpell(const string &name, const string &effects) : name(name), effects(effects) {

}

ASpell::~ASpell() {

}


void ASpell::launch(const ATarget &target) const {
    target.getHitBySpell(*this);
}