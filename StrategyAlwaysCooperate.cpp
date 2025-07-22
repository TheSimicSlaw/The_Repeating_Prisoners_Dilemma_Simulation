#include "Strategy.h"

class StrategyAlwaysCooperate : Strategy
{
  StrategyAlwaysCooperate()
  {
    Strategy();
    strategyName = "AlwaysCooperate";
  }

  Response initialResponse() override
  {
    return COOPERATE;
  }
  Response continuedResponse(Response opponentresponse) override
  {
    return COOPERATE;
  }
};