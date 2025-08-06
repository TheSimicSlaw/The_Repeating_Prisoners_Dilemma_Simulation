# The_Repeating_Prisoners_Dilemma_Simulation
An experiment based on Robert Axelrod's "tournament" about the Prisoner's Dilemma.

The goal of this experiment is to determine how different diplomatic strategies interact, which ones come out on top, and how these might apply to the real world.

There are three parts of this experiment:
1) The Classic Tournament
   - This is a one-to-one replication to the original tournament. I aim to determine if the results hold, and in addition it is useful to have this as a baseline to establish before adding more layers.
   - The idea of the original tournament was that it would replicate the repeated prisoner's dilemma using various submitted strategies. The conditions were thus:
         a) There would be two "strategies" facing off against each other. Each would be able to determine whether they would "cooperate" or "defect" each round. This could change from the previous round.
         b) If both cooperated, they would get 3 points. If both defected, they would get 1 point. If one defected and the other cooperated, the defector would get 5 points and the cooperator would get 0 points.
         c) This would continue for 200 rounds.
         d) They could not communicate with each other and instead had to base their decisions on the previous record of what both strategies had previously chosen.
     - The strategies would be categorized. Those that defected without the other defecting would be considered "nasty" strategies, while those that would not defect before the other did were considered "nice" strategies.
     - In the original experiment, "nice" strategies almost always came out on top. I aim to see if this persists.
2) The Tournament With Announced Actions
     - This maintains the previous concepts, including the point structure, with one modification: Each strategy is allowed to announce whether it intends to defect or cooperate.
     - The strategies do not necessarily have to tell the truth when they announce their action.
     - The strategies may also choose not to announce their actions.
     - Each strategy may now in addition to taking previous actions into account consider the opponent's announcement and previous announcements.
3) The Tournament With Announced Reactions
     - In this, the final and most complex tournament, the previous concepts are implemented, but now strategies may declare reactions. In addition to announcing what it intends to do this round, the strategy may announce how it intends to react to the other strategy's action (e.g. "If you defect I will defect next round, but if you cooperate I will cooperate next round").
     - The strategy may announce its reaction up to three actions in the future.
     - Each strategy may now consider previous actions, current announcements, and previous announcements, and it may predict how the other strategy will react.
     - Each strategy may lie, and each strategy may consider that the other may be lying.
  
This should give us interesting insights into real-world situations like diplomacy, interpersonal relations, and even communal animal interactions. However, it is worth noting certain limitations to this experiment. For the sake of avoiding overcomplexity, I have not included parts regarding more than two strategies interacting, nor have I left room for complex negotiations. These may be explored in future simulations, but for now it is best to keep them out. 
My personal hypothesis is that the nice (doesn't defect first), retaliatory but forgiving (will retaliate in response to defection but won't retaliate indefinitely), clear (relatively simple and easy to understand), honest (doesn't lie in announcements), and canny (doesn't assume the other is being honest) strategies will end up with the most points. 

I intend to create a framework for Part 1 and create a few strategies (I shall at least include tit-for-tat, sample, always cooperate, random, Friedman, and Joss) and then open it up to other submissions. From this we can have a more in-depth study. 

If you wish to learn more about the original Prisoner's Dilemma Tournament, I recommend reading https://axelrod.readthedocs.io/en/fix-documentation/reference/index.html. Alternatively, you can also watch this video https://youtube.com/watch?v=mScpHTIi-kM, which provides a sound overview of it.
