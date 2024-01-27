#pragma once

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Warlock {
    private:
        string name, title;
    
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

};
