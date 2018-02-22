#ifndef AQUASEA_H
#define AQUASEA_H

#include "aquaClasses.h"

class Sea
{
  private:
    char m_sea_grid [MAX_SEA_GRID][MAX_SEA_GRID];
    int m_sea_size;
    int m_sea_height;
    int m_sea_width;
    void seaClear ();
    void seaPopulate ();
  public:
    Sea (const int grid_size_height, const int grid_size_width);
    friend std::ostream &operator<<(std::ostream &os, Sea obj);
    int getSeaHeight () {return m_sea_height;};
    int getSeaWidth () {return m_sea_width;};
    void setSeaCell (int obj_x, int obj_y, char cell_symbol);
    // Appropriate accessor/mutator functions
};

#endif