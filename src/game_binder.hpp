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
 * ./game_hinder.hpp : header for all the sources
 * 
*/
#ifndef GAME_BINDER_H
#define GAME_BINDER_H

const char header[]="     \033[1;34m#RVCGEEKS CHASE GAME BY A* algo\n"
                    "     GENUINELY CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com\033[0m\n\n"
                    "     controls : a=left , d=right , w=up , s=right , x=exit from game  || you are green while enemy is red\n\n\n";
                    
const char defaultmaze[33][66]={
"o---o---o---o---o---o---o---o---o---o---o---o---o---o---o---o---o",
"|                                                               |",
"o   o---o---o---o---o---o---o---o---o---o---o---o---o---o   o---o",
"|   |           |           |           |                       |",
"o   o   o---o   o   o---o   o---o   o   o---o   o---o---o   o   o",
"|   |       |   |   |           |   |       |           |   |   |",
"o   o---o   o   o   o---o   o   o   o---o   o---o   o---o---o---o",
"|   |       |   |       |   |   |   |               |       |   |",
"o   o   o---o   o---o   o---o   o   o---o   o---o---o---o   o   o",
"|   |   |               |       |       |   |       |           |",
"o   o   o---o---o---o---o   o---o---o   o---o   o   o   o   o   o",
"|   |           |       |                   |   |       |   |   |",
"o   o---o---o   o   o   o---o---o---o---o---o   o---o---o---o   o",
"|   |   |   |       |   |               |       |           |   |",
"o   o   o   o---o---o   o   o---o---o   o   o---o   o---o   o   o",
"|   |           |   |   |   |       |   |   |       |       |   |",
"o   o   o   o---o   o   o   o   o   o   o   o   o---o   o---o   o",
"|   |   |   |           |   |       |   |   |   |           |   |",
"o   o   o   o   o---o---o   o   o---o   o   o   o   o   o---o   o",
"|   |   |       |       |           |   |       |   |   |   |   |",
"o   o   o---o---o   o   o   o---o---o   o---o---o   o---o   o   o",
"|   |   |       |   |       |       |           |           |   |",
"o   o   o   o   o   o---o---o   o   o---o---o   o---o---o   o   o",
"|   |   |   |           |       |                   |   |   |   |",
"o   o   o   o   o   o---o   o---o---o---o---o   o---o   o   o   o",
"|   |       |   |   |       |           |   |   |   |   |   |   |",
"o   o---o---o---o---o---o   o   o---o   o   o---o   o   o   o   o",
"|       |                   |       |           |           |   |",
"o   o   o   o---o---o---o---o---o   o---o   o   o   o   o   o   o",
"|   |   |                               |   |       |   |   |   |",
"o   o   o---o---o---o---o---o---o---o---o---o---o---o---o---o   o",
"|   |                                                           |",
"o---o---o---o---o---o---o---o---o---o---o---o---o---o---o---o---o"
};

#include<bits/stdc++.h>  //one utility include header !!! everything it has of all c++ vectors deques sets iostream etc ...all of it
using namespace std;
#include"astar_core/binder.hpp"
#include"score_keeper/scorestructs.hpp"

const char hackerman[]=
"                                                     ███████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓█\n"
"                                                     ████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬█\n"
"                                                     ███▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n"
"                                                     ████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n"
"                                                     ███▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓█\n"
"                                                     ████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬█\n"
"                                                     ███▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n"
"                                                     ████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n"
"                                                     ███▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n"
"                                                     █████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█\n"
"                                                     █████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██\n"
"                                                     █████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██\n"
"                                                     ████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬██\n"
"                                                     ████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓██\n"
"                                                     █████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓██\n"
"                                                     █████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬███\n"
"                                                     ██████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓███\n"
"                                                     ███████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬████\n"
"                                                     ███████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓████\n"
"                                                     ████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓█████\n"
"                                                     █████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓██████\n"
"                                                     ██████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓███████\n"
"                                                     ███████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓████████\n"
"                                                     ██████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬██████████\n"
"                                                     ███████████████▓▓▓██▓▓╬╬╬╬╬╬▓███████████\n";

#include"event_handler/event_binder.hpp"
#endif