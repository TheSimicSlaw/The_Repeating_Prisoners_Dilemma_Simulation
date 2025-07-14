#include "Strategy.h"

Strategy::Strategy()
{
  roundNum = -1;
  currentSimulation = nullptr;
}

void Strategy::StartNewSimulation(int nrounds) // Strategies MUST proceed without taking into account the number of
                                               // rounds a Simulation will have. As such, use nrounds only to
                                               // construct the Simulation
{
  if (roundNum >= 0)
  {
    delete currentSimulation;
  }
  roundNum = 0;
  currentSimulation = new Simulation(nrounds);
}