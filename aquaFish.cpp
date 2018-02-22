#include "aquaClasses.h"
#include "aquaFunctions.cpp"

using namespace std;

Fish::Fish ()
{
  int randomNum = rand () % 10 + 1;
  m_fish_amt_food = randomNum;
  m_fish_x = -1;
  m_fish_y = -1;
}

void Fish::move ()
{
  int randomDir = rand () % 8 + 1;
  if (randomDir == 1)
  {
    m_fish_y++;
  }
  else if (randomDir == 2)
  {
    m_fish_x++;
    m_fish_y++;
  }
  else if (randomDir == 3)
  {
    m_fish_x++;
  }
  else if (randomDir == 4)
  {
    m_fish_x++;
    m_fish_y--;
  }
  else if (randomDir == 5)
  {
    m_fish_y--;
  }
  else if (randomDir == 6)
  {
    m_fish_x--;
    m_fish_y--;
  }
  else if (randomDir == 7)
  {
    m_fish_x--;
  }
  else if (randomDir == 8)
  {
    m_fish_x--;
    m_fish_y++;
  }

  return;
}