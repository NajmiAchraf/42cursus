#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
    for (vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        delete (*it);
    }
    targets.clear();
}


void TargetGenerator::learnTargetType(ATarget *target) {
    if (!target)
        return;
    for (vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        if (target->getType() == (*it)->getType())
            return;
    }
    targets.push_back(target->clone());
}

void TargetGenerator::forgetTargetType(const string &type) {
    for (vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        if (type == (*it)->getType()){
            delete (*it);
            targets.erase(it);
            return;
        } 
    }
}

ATarget* TargetGenerator::createTarget(string const &type){
    for (vector<ATarget *>::iterator it = targets.begin(); it != targets.end(); it++) {
        if (type == (*it)->getType()){
            return (*it)->clone();
        }
    }
    return NULL;
}