/* ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS chase game
 * created on 06.11.2018
 * 
 * this program reads a maze text file and initializes you and
 * enemy at random position and then you have to run while
 * enemy is chasing you...
 * 
 * ./score_keeper/ : scorekeeping routines ...
 * 
*/


struct chunk{
    char name[20];
    int score;
};

const char filename[]="chaser_scores.dat";

class scorekeeper{
    int score;
    fstream record;
public:
    scorekeeper();
    int getscore();
    void reset(),
         tick(),
         save(),
         display();
};

#include"scorekeeper.cpp"