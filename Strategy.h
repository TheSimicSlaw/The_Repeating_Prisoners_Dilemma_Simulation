#include "Simulation.h"
#include <string>
using std::string;

class Strategy
{
private:
  Simulation *currentSimulation;
  int roundNum;

public:
  string strategyName;
  Strategy();
  void StartNewSimulation(int nrounds);
  virtual Response initialResponse();
  virtual Response continuedResponse(Response opponentresponse);
};
