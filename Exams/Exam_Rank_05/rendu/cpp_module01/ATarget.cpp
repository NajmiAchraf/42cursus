#include "ATarget.hpp"


const string &ATarget::getType() const {
    return type;
}


ATarget::ATarget(const string &type) : type(type) {
    
}

ATarget::~ATarget() {

}
        

void ATarget::getHitBySpell(const ASpell &spell) const {
    cout << type << " has been "<< spell.getEffects() << "!" << endl;
}