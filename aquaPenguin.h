#ifndef AQUAPENGUIN_H
#define AQUAPENGUIN_H

#include "aquaClasses.h"
#include "aquaFish.h"
#include "aquaKillerWhale.h"
#include "aquaSea.h"

class Penguin
{
  private:
    int m_peng_health;   // 0-100
    int m_peng_posX;
    int m_peng_posY;
    bool m_peng_alive;
  public:
    Penguin ();
    int getX () {return m_peng_posX;};      // Delete later
    int getY () {return m_peng_posY;};      // Delete later
    void move (Sea obj_sea, Fish arr_fish [], int arr_fish_size,
               Killer_Whale arr_kw [], int arr_kw_size);
};

#endif