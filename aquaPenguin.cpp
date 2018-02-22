#include "aquaPenguin.h"
#include "aquaFunctions.cpp"

using namespace std;

Penguin::Penguin ()
{
  m_peng_health = rand () % (81 - 60) + 60;
  m_peng_posX = -1;
  m_peng_posY = -1;
  m_peng_alive = false;
}

void Penguin::move (Sea obj_sea, Fish arr_fish [], int arr_fish_size, 
                    Killer_Whale arr_kw [], int arr_kw_size)
{
  int amtMove = 0;
  int direction = 0;
  int distanceToFish = 0;
  int fishIndex = 0;
  int tempMoveX = 0;
  int tempMoveY = 0;
  bool moveAwayKillerWhale = false;
  bool moveToFish = false;

  // Determine amount of cells to move in sea
  if (m_peng_health >= 81 && m_peng_health <= 100)
  {
    amtMove = 5;
  }
  else if (m_peng_health >= 61 && m_peng_health <= 80)
  {
    amtMove = 4;
  }
  else if (m_peng_health >= 41 && m_peng_health <= 60)
  {
    amtMove = 3;
  }
  else if (m_peng_health >= 21 && m_peng_health <= 40)
  {
    amtMove = 2;
  }
  else if (m_peng_health >= 1 && m_peng_health <= 20)
  {
    amtMove = 1;
  }
  else
  {
    cout << "Chicken of the sea at: " << m_peng_posX << " " << m_peng_posY
         << endl;

    return;
  }

  // Move penguin towards fish if it can see it (8.0 see distance)
  // If cant see any fish/killer wahles then movement is random
  // If penguin sees killer whale then move away from killer whale
  // If sees both, we get to decide how to code it
  // Every cell moved through is -1 health

  // Find if any killer whales are near first

  // Find if any fish are near
  for (int i = 0; i < arr_fish_size; i++)
  {
    distanceToFish = calculate_distance (m_peng_posX, m_peng_posY,
                                         arr_fish[i]);
    if (distanceToFish <= 8)
    {
      moveToFish = true;
      fishIndex = i;
      i = arr_fish_size;
    }
  }

  // If both are found do something we decide

  // Move accordingly
  for (int k = 0; k < amtMove; k++)
  {
    if (moveToFish == true && moveAwayKillerWhale == false)
    {
      tempMoveX = m_peng_posX;
      tempMoveY = m_peng_posY;
      direction = calculate_direction (m_peng_posX, m_peng_posY,
                                       arr_fish[fishIndex]);
      cout << "Penguin pos before moving: " << m_peng_posX << ","
           << m_peng_posY << endl;
      cout << "Fish pos: " << arr_fish[fishIndex].getX () << ","
           << arr_fish[fishIndex].getY () << endl;

      if (m_peng_health == 0)
      {
        cout << "Chicken of the sea at: " << m_peng_posX << " " << m_peng_posY
             << endl;

        return;
      }
      if (direction == 1)
      {
        m_peng_health--;
        tempMoveY++;
        distanceToFish--;
      }
      else if (direction == 2)
      {
        m_peng_health--;
        tempMoveX++;
        tempMoveY++;
        distanceToFish--;
      }
      else if (direction == 3)
      {
        m_peng_health--;
        tempMoveX++;
        distanceToFish--;
      }
      else if (direction == 4)
      {
        m_peng_health--;
        tempMoveX++;
        tempMoveY--;
        distanceToFish--;
      }
      else if (direction == 5)
      {
        m_peng_health--;
        tempMoveY--;
        distanceToFish--;
      }
      else if (direction == 6)
      {
        m_peng_health--;
        tempMoveX--;
        tempMoveY--;
        distanceToFish--;
      }
      else if (direction == 7)
      {
        m_peng_health--;
        tempMoveX--;
        distanceToFish--;
      }
      else if (direction == 8)
      {
        m_peng_health--;
        tempMoveX--;
        tempMoveY++;
        distanceToFish--;
      }
      else
      {
        cout << "[ERROR]: Penguin direction messed up." << endl;
      }

      // Check conditions for moving
      if (tempMoveX > obj_sea.getSeaWidth ()
          || tempMoveX < -(obj_sea.getSeaWidth ()))
      {
        m_peng_posX = m_peng_posX;    // AKA dont move
        m_peng_posY = m_peng_posY;
      }
      else if (tempMoveY > obj_sea.getSeaHeight ()
               || tempMoveY < -(obj_sea.getSeaHeight ()))
      {
        m_peng_posX = m_peng_posX;    // AKA dont move
        m_peng_posY = m_peng_posY;
      }
      else
      {
        obj_sea.setSeaCell (m_peng_posX, m_peng_posY, 'O'); // Delete old cell
        m_peng_posX = tempMoveX;
        m_peng_posY = tempMoveY;
        obj_sea.setSeaCell (m_peng_posX, m_peng_posY, 'P'); // Set new cell
      }

      // Check situations after moving
      if (distanceToFish == 0)
      {
        // Stop moving
        amtMove = 0;
        // Eat fish
        m_peng_health += arr_fish[fishIndex].getFishAmtFood ();
        // Remove fish from grid
      }
      cout << "Penguin pos after moving: " << m_peng_posX << ","
           << m_peng_posY << endl;
    }
    else if (moveAwayKillerWhale == true && moveToFish == false)
    {

    }
    else if (moveAwayKillerWhale == false && moveToFish == false)
    {
      // If no fish, movement is random, else it's towards fish how ever many step
      //   the penguin can go
      direction = rand () % 8 + 1;
      if (direction == 1)
      {
        m_peng_posY++;
      }
      else if (direction == 2)
      {
        m_peng_posX++;
        m_peng_posY++;
      }
      else if (direction == 3)
      {
        m_peng_posX++;
      }
      else if (direction == 4)
      {
        m_peng_posX++;
        m_peng_posY--;
      }
      else if (direction == 5)
      {
        m_peng_posY--;
      }
      else if (direction == 6)
      {
        m_peng_posX--;
        m_peng_posY--;
      }
      else if (direction == 7)
      {
        m_peng_posX--;
      }
      else if (direction == 8)
      {
        m_peng_posX--;
        m_peng_posY++;
      }
      else
      {
        cout << "[ERROR]: Penguin random direction messed up." << endl;
      }
    }
  }

  return;
}