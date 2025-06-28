#include "Simulation.h"

class Strategy
{
private:
  Simulation currentSimulation;
  int roundNum = 0;

public:
  void StartNewSimulation();
  Response initialResponse();
  Response continuedResponse(Response opponentresponse);
};
