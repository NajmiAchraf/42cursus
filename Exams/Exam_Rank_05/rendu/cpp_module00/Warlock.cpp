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