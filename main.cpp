///////////////////////////////////////////////////////
// Programmer: Tanner Fry
// Begin: 11/22/17
// Files:
// Program Purpose:
//

// CURRENT WORK //
// - working on the sea function so that I can add in actors to the
//   grid and then delete/move them as needed
// - all animals must be aware of the sea boundaries as well as other
//   animals so that they don't hit each other.

#include "aquaClasses.h"

using namespace std;

int main ()
{
  srand (time (NULL));
  // Simulation
  Sea OpenSea (17, 17);
  cout << OpenSea;
  Fish fishies [200];
  Killer_Whale kWhales [2];
  Penguin penguins [50];
  penguins[0].move (OpenSea, fishies, 200);
}