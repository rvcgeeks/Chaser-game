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
 * ./eventhandler/ : handling interrupt based routines ...
 * 
*/

#ifndef __EVENTBINDER_H
#define __EVENTBINDER_H

#include<sys/ioctl.h>  //_for khbit
#include<unistd.h>     //_for getch and khbit
#include<termios.h>    //_for getch

#include"input_methods.cpp"
char global_control_move;

#include"eventhandler.cpp"
#endif