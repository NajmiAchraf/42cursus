#include "Warlock.hpp"


const string &Warlock::getName() const {
    return name;
}

const string &Warlock::getTitle() const {
    return title;
}


void Warlock::setTitle(const string &title) {
    this->title = title;
}


Warlock::Warlock(const string &name, const string &title) : name(name), title(title) {
    cout << name << ": This looks like another boring day." << endl;
}


Warlock::~Warlock() {
    cout << name << ": My job here is done!" << endl;
}
    

void Warlock::introduce() const {
    cout << name << ": I am "<< name << ", " << title << "!" << endl;
}


void Warlock::learnSpell(ASpell *spell) {
    spellbook.learnSpell(spell);
}

void Warlock::forgetSpell(const string &name) {
    spellbook.forgetSpell(name);
}

void Warlock::launchSpell(const string &name, const ATarget &target) {
    ASpell *spell = spellbook.createSpell(name);

    if (spell)
        spell->launch(target);

    delete spell;
}