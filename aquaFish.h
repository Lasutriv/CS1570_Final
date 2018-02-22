#ifndef AQUAFISH_H
#define AQUAFISH_H

#include "aquaClasses.h"

class Fish
{
  private:
    int m_fish_amt_food;
    int m_fish_x;
    int m_fish_y;
    bool m_fish_alive;
  public:
    Fish ();
    int getX () {return m_fish_x;};
    int getY () {return m_fish_y;};
    int getFishAmtFood () {return m_fish_amt_food;};
    void move ();
};

#endif