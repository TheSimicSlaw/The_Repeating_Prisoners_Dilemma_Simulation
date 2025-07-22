#include "Strategy.h"

class StrategyAlwaysDefect : Strategy
{
  StrategyAlwaysDefect()
  {
    Strategy();
    strategyName = "AlwaysDefect";
  }

  Response initialResponse() override
  {
    return DEFECT;
  }
  Response continuedResponse(Response opponentresponse) override
  {
    return DEFECT;
  }
};