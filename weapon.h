#ifndef WEAPON_H
#define WEAPON_H
#include "dice.h"
#include "item.h"
#include "damage.h"
struct weaponProperties {
    bool twoHanded = false;
    bool finesse = false;
    bool heavy = false;
    bool light = false;
    bool thrown = false;
    bool reach = false;
    bool versatile = false;
    bool ammunition = false;
    bool loading = false;
    // below is a catch all for any new bool
    int special = 0;
};


class weapon : item
{
// General
    int range;
// To Hit
    int toHitAdder;
// Damage
    damageType damageTypes;
    dice damageDice;
    int damageAdder;
    weaponProperties properties;
public:
    weapon();
};

#endif // WEAPON_H
