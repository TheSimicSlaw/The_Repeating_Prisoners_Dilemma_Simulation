#include "Simulation.h"
#include <string>

class Strategy
{
private:
  Simulation *currentSimulation;
  int roundNum;

public:
  std::string strategyName;
  Strategy();
  void StartNewSimulation(int nrounds);
  virtual Response initialResponse();
  virtual Response continuedResponse(Response opponentresponse);
};
