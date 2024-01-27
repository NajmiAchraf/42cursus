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
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++){
        delete (*it);
    }
    spells.clear();
}
    

void Warlock::introduce() const {
    cout << name << ": I am "<< name << ", " << title << "!" << endl;
}


void Warlock::learnSpell(ASpell *spell) {
    if (!spell)
        return;
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if (spell->getName() == (*it)->getName())
            return;
    }
    spells.push_back(spell->clone());
}

void Warlock::forgetSpell(const string &name) {
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if (name == (*it)->getName()){
            delete (*it);
            spells.erase(it);
            return;
        } 
    }
}

void Warlock::launchSpell(const string &name, const ATarget &target) {
    for (vector<ASpell *>::iterator it = spells.begin(); it != spells.end(); it++) {
        if (name == (*it)->getName()){
            (*it)->launch(target);
            return;
        } 
    }
}