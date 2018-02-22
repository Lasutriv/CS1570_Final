#include "aquaClasses.h"
#include "aquaFunctions.cpp"

using namespace std;

//  - [row][column]
Sea::Sea (const int grid_size_height, const int grid_size_width)
{
  if ((grid_size_height || grid_size_width) <= 0)
  {
    if (grid_size_height <= 0 && grid_size_width > 0)
    {
      m_sea_size = MAX_SEA_GRID * grid_size_width;
      m_sea_width = grid_size_width;
      m_sea_height = MAX_SEA_GRID;
    }
    else if (grid_size_width <= 0 && grid_size_height > 0)
    {
      m_sea_size = MAX_SEA_GRID * grid_size_height;
      m_sea_width = MAX_SEA_GRID;
      m_sea_height = grid_size_height;
    }
    else if (grid_size_height <= 0 && grid_size_width <= 0)
    {
      m_sea_size = MAX_SEA_GRID * MAX_SEA_GRID;
      m_sea_height = MAX_SEA_GRID;
      m_sea_width = MAX_SEA_GRID;
    }
  }
  else
    {
      m_sea_size = grid_size_height * grid_size_width;
      m_sea_height = grid_size_height;
      m_sea_width = grid_size_width;
    }
  seaClear ();
  seaPopulate ();
  // Start grid push/pumping
}


ostream &operator<<(ostream &os, Sea obj)
{
  os << "Sea Height: " << obj.m_sea_width << endl << "Sea Wdith: "
     << obj.m_sea_width << endl << "Sea Size: " << obj.m_sea_size
     << endl;
  os << "Grid View: " << endl;
  for (int i = 0; i < obj.m_sea_height; i++)
  {
    for (int j = 0; j < obj.m_sea_width; j++)
    {
      os << obj.m_sea_grid [i][j];
    }
    os << endl;
  }
  return os;
}

void Sea::seaClear ()
{
  for (int i = 0; i < m_sea_height; i++)
  {
    for (int j = 0; j < m_sea_width; j++)
    {
      m_sea_grid[i][j] = 'O';
    }
  }
  return;
}

void Sea::seaPopulate ()
{
  // Populate the grid with the actors that are passed into the
  // function. Place 2 killer whalesm scatter 20 fish, and scatter
  // 5 penguins
  return;
}

void Sea::setSeaCell (int obj_x, int obj_y, char cell_symbol)
{
  cout << "Pos: " << obj_x << "," << obj_y << " char: "
       << cell_symbol << endl;

  // Shows the char on grid at obj location
  // MAIN ISSUE: Most sea creatures spawn at -1-1 which the grid starts
  //             at 0 and goes up to 16 (with size being 17 x 17)
  cout << m_sea_grid [obj_x][obj_y] << endl;
  //m_sea_grid [obj_x][obj_y] = cell_symbol;

  return;
}