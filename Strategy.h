#include "Simulation.h"

class Strategy
{
private:
  Simulation *currentSimulation;
  int roundNum;

public:
  Strategy();
  void StartNewSimulation(int nrounds);
  virtual Response initialResponse();
  virtual Response continuedResponse(Response opponentresponse);
};
