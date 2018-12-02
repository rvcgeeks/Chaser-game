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
 * ./astar_core/ : core source for maze play and A* path finding 
 * 
*/

#ifndef __ASTAR_H
#define __ASTAR_H
typedef pair<int,int> location;
typedef deque<location> path;
typedef pair<float,location> pPair;
class maze;


class node{
    location parent,current;
    float f,g,h;      //to store params for a*
public:
    bool open;
    node(){}
    node(int,int);
    node(location,location,float,float,float);
friend class maze;
friend class a_star;
friend void display(maze*,location,location,path,int);
};


class maze{
    node **grid;
public:int m,n;
    maze(){}
    void load();                                    //load defaultmaze
    void load(const char[]);                        //load maze from file
    void reset_heuristics();                        //reset heuristics for A*
    node& operator[](location);
    bool isvalid(location);
friend class a_star;
friend void display(maze*,location,location,path,int);
};


class a_star{
    maze *m;location src,dest;
public:
    a_star(maze*,location,location);
    path fire();
};

#include"node.cpp"
#include"maze.cpp"
#include"utils.cpp"
#include"astar.cpp"
#endif