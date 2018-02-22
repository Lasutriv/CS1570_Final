#ifndef AQUAKILLERWHALE_H
#define AQUAKILLERWHALE_H

#include "aquaClasses.h"
#include "aquaPenguin.h"

class Killer_Whale
{
  private:
    int m_killer_whale_amt_pengs;
    int m_killer_whale_x;
    int m_killer_whale_y;
  public:
    Killer_Whale ();
    int getX () {return m_killer_whale_x;};
    int getY () {return m_killer_whale_y;};
    void move (Penguin penguin_array []);
};

#endif