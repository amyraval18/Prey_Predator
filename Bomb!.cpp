

#include "Bomb!.h"
#include "Organism.h"
using namespace std;

Bomb::Bomb(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord)
{
    death_tik = 5; // can use this for countdown for bomb bug to explode 
    
}

void Bomb::move()
{
   // breedTicks++;
   // death_tik++;
    death_tik--; 

    if (death_tik == 0)
    {
        if (world->getAt(x, y + 1) != nullptr)
        {
            delete world->getAt(x, y + 1);
            world->setAt(x, y + 1, nullptr);
        }
        if (world->getAt(x, y - 1) != nullptr)
        {
            delete world->getAt(x, y - 1);
            world->setAt(x, y - 1, nullptr);
        }
        if (world->getAt(x + 1, y) != NULL) // try NULL if nullptr doesn't work 
        {
            delete world->getAt(x + 1, y);
            world->setAt(x + 1, y, nullptr);
        }
        if (world->getAt(x - 1, y) != nullptr)
        {
            delete world->getAt(x - 1, y);
            world->setAt(x - 1, y, nullptr);
        }
        if (world->getAt(x + 1, y + 1) != NULL) 
        {
            delete world->getAt(x + 1, y + 1);
            world->setAt(x + 1, y + 1, nullptr); 
        }
        if (world->getAt(x - 1, y - 1) != NULL)
        {
            delete world->getAt(x - 1, y - 1);
            world->setAt(x - 1, y - 1, nullptr);
        }
        if (world->getAt(x + 1, y - 1) != nullptr) 
        {
            delete world->getAt(x + 1, y - 1);
            world->setAt(x + 1, y - 1, nullptr);
        }
        if (world->getAt(x - 1, y + 1) != nullptr)
        {
            delete world->getAt(x - 1, y + 1);
            world->setAt(x - 1, y + 1, nullptr);
        }

    }
    } 
    

       /* if (world->getAt(x, y + 1) != NULL)
        {
            if ((world->getAt(x, y + 1)->getType() == ANT) || (world->getAt(x, y + 1)->getType() == BUG)) // or bug. bomb bug would eat ant or bug 
            {
                death_tik = 0;
                delete world->getAt(x, y + 1);
                movesTo(x, y + 1); // kills ant or bug and deletes 
                return;
            }
        }

        if (world->getAt(x, y - 1) != NULL)
        {
            if ((world->getAt(x, y - 1)->getType() == ANT) || (world->getAt(x, y - 1)->getType() == BUG)) // or bug 
            {
                death_tik = 0;
                delete world->getAt(x, y - 1);
                movesTo(x, y - 1);
                return;
            }
        }

        if (world->getAt(x - 1, y) != NULL)
        {
            if ((world->getAt(x - 1, y)->getType() == ANT) || (world->getAt(x - 1, y)->getType() == BUG)) // or bug 
            {
                death_tik = 0;
                delete world->getAt(x - 1, y);
                movesTo(x - 1, y);
                return;
            }
        }
        if (world->getAt(x + 1, y) != NULL)
        {
            if ((world->getAt(x + 1, y)->getType() == ANT) || (world->getAt(x + 1, y)->getType() == BUG)) // or bug 
            {
                death_tik = 0;
                delete world->getAt(x + 1, y);
                movesTo(x + 1, y);
                return;
            }
        }

        Move mover = world->randomMove();
        switch (mover) {
        case UP:
            if (world->getAt(x, y + 1) == NULL && in_range(x, y + 1))
            {
                movesTo(x, y + 1);
            }
            break;
        case DOWN:
            if (world->getAt(x, y - 1) == NULL && in_range(x, y - 1))
            {
                movesTo(x, y - 1);
            }
            break;
        case LEFT:
            if (world->getAt(x - 1, y) == NULL && in_range(x - 1, y))
            {
                movesTo(x - 1, y);
            }
            break;
        case RIGHT:
            if (world->getAt(x + 1, y) == NULL && in_range(x + 1, y))
            {
                movesTo(x + 1, y);
            }
            break;
        default:
            break;
        }
        }
    

void Bomb::generateOffspring(int whereX, int whereY)
{
    new Bomb(this->world, whereX, whereY);
    breedTicks = 0;
}

void Bomb::breed()
{
    if (breedTicks >= BREED_BUGS)
    {
        breedAtAdjacentCell();
    }

} 
 */
    bool Bomb::isDead() const
{
    if (death_tik == 0) // explodes and then stops at zero 
    {
        return true;
    }
    else
    {
        return false;
    }
} 

OrganismType Bomb::getType() const
{
    return BOMB;
}


char Bomb::representation()const
{
    return 48+death_tik; // ensure the timer starts at 5 
}

int Bomb::size() const
{
    return 30;
}

/*bool Bomb::in_range(int xx, int yy)
{
    return (xx >= 0) && (xx < WORLDSIZE) && (yy >= 0) && (yy < WORLDSIZE); 
} */
