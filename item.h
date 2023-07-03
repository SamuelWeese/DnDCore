#ifndef ITEM_H
#define ITEM_H
#include <string>


struct size {
    bool small = false;
    bool medium = false;
    bool large = false;

};

class item
{
    // String
    std::string name;
    std::string description;
    std::string source;
    virtual std::string type;
    // Weight
    int weight;
    // Magic
    bool attuned;

    // Cost
private:
    int cost;
public:
    int getCostGP();
    int getCostSP();
    int getCostCP();
    item();
};

#endif // ITEM_H
