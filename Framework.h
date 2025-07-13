#include "Response.h"
#include "Strategy.h"

class Framework
{
private:
  void plot_simulation();
  void record_simulation();

public:
  void run_simulation(Strategy strategyone, Strategy strategytwo);
};
