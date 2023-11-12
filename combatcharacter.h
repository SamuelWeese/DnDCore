#ifndef COMBATCHARACTER_H
#define COMBATCHARACTER_H
#include "dice.h"


class combatCharacter
{
    // Header
private:
    std::string characterName;
    std::string className;
    std::string raceName;
    std::string backgroundName;
    std::string alignmentString;
    std::string playerName;
    std::string expPoints;
public:
    std::string classNameGen();
    std::string raceGen();
    // Abilities
private:
    int strenth;
    int dexterity;
    int constitution;
    int wisdom;
    int intelligence;
    int charisma;

// Skills

// Strength Skills

    int Athletics;

// Dexterity Skills

    int Acrobatics;
    int SleightOfHand;
    int Stealth;

    // Intelligence Skills

    int Arcana;
    int History;
    int Investigation;
    int Nature;
    int Religion;

    // Wisdom Skills

    int AnimalHandling;
    int Insight;
    int Medicine;
    int Perception;
    int Survival;

    // Charisma Skills

    int Deception;
    int Intimidation;
    int Performance;
    int Persuasion;

    // AC Calc
    int baseAC;
    int dexterityAC;
    int armorAC;
public:
    int getAC();
private:
    // Weapon Calc
    int weaponToHit;
    dice weaponDamage;
    int weaponAdder;
    int weaponRange;

public:
    int getToHit();
    int getDamage();

// HP Calc
private:
    int maxHP;
    int hitDice;
    int deathSaves;
    int temporaryHP;
    int currentHP;

// String Data
private:
    std::string personalityTraits;
    std::string ideals;
    std::string bonds;
    std::string flaws;
    std::string featuresAndTraits;
public:
    std::string featuresAndTraitsGen();
public:
    combatCharacter();

    // Aurora

    // File Reading
};

#endif // COMBATCHARACTER_H
