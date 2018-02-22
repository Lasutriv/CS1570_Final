#include "aquaClasses.h"

using namespace std;

// Functions

template <typename TYPE>
int calculate_direction (int obj1_x, int obj1_y, TYPE obj2)
{
  int calculatedX = obj2.getX () - obj1_x;
  int calculatedY = obj2.getY () - obj1_y;
  int direction = 0;
  if (calculatedX == 0 && calculatedY > 0)
  {
    direction = 1;
  }
  else if (calculatedX > 0 && calculatedY > 0)
  {
    direction = 2;
  }
  else if (calculatedX > 0 && calculatedY == 0)
  {
    direction = 3;
  }
  else if (calculatedX > 0 && calculatedY < 0)
  {
    direction = 4;
  }
  else if (calculatedX == 0 && calculatedY < 0)
  {
    direction = 5;
  }
  else if (calculatedX < 0 && calculatedY < 0)
  {
    direction = 6;
  }
  else if (calculatedX < 0 && calculatedY == 0)
  {
    direction = 7;
  }
  else if (calculatedX < 0 && calculatedY > 0)
  {
    direction = 8;
  }
  else
  {
    cout << "[ERROR]: Direction calculation failed." << endl;
  }

  return direction;
}

template <typename TYPE>
int calculate_distance (int obj1_x, int obj1_y, TYPE obj2)
{
  int distance = sqrt ((obj1_x - obj2.getX ())
                       * (obj1_x - obj2.getX ())
                       + (obj1_y - obj2.getY ())
                       * (obj1_y - obj2.getY ()));

  return distance;
}