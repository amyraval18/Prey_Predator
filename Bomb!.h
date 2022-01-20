//
//  Bug.h
//  INHERITANCE_AND_POLYMORPHISM
//
//  Created by Kristjan Thorsteinsson on 01/04/14.
//  Copyright (c) 2014 Kristjan Thorsteinsson. All rights reserved.
//



#include <iostream>

#include "World.h"
#include "Organism.h"

class Bomb : public Organism
{
public:

    Bomb(World* aWorld, int xcoord, int ycoord);
    // In the given world moves this organism.
    void move();

    // Bomb bug does not breed = initialze.
    void breed() {};

    // Returns the type of this organism.
    OrganismType getType() const;

    // The character representation of this organism.
    char representation() const;

    // The size of this organism.
    int size() const;
    // Returns true if organism is dead, false otherwise.
    bool isDead() const;

    bool in_range(int xx, int yy);

private:
    // bomb bug does not generate offspring 
    void generateOffspring(int whereX, int whereY) {};
    int death_tik;
};



