#ifndef DAMAGE_H
#define DAMAGE_H

struct damageType {
    bool acid = false;
    bool bludgeoning = false;
    bool cold = false;
    bool fire = false;
    bool force = false;
    bool lightning = false;
    bool necrotic = false;
    bool piercing = false;
    bool poison = false;
    bool psychic = false;
    bool radiant = false;
    bool slashing = false;
    bool thunder = false;
    // this is a catch all for any new damage type
    int other = 0;
};

class damage
{
public:
    damage();
};

#endif // DAMAGE_H
