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
 * ./main.cpp : entry point for game ...
 * 
*/
#include"game_binder.hpp"
main(int argc,char *argv[]){
    cout<<"\a";
    char opt=0;bool flag=false;
    if(argc!=2){
        cout<<header<<"   Synopsis:\n   \033[1;35m~$ "<<argv[0]<<" [path]\033[0m"
             " \n\n   Usage:\n   here [path] is file path where maze is stored...\n  "
             " for eg, you can hit\n\n       \033[1;31m"<<argv[0]<<" mazes/apec2010.txt\033[0m\n\n\n"
             " Do you still want to load a preloaded or default maze ?!? [y/n] ";
        opt=getch();
        if(opt!='y') return 0;
        else flag=true;
    }
    try{
    execute_events(flag,argv[1]);
    }
    catch(int){
        cout<<header<<"\n   FAILED TO LOAD MAZE FILE!!!\n\n\n";
    }
    cout<<"\n\n     <<<   STAY TUNED !!   >>>\n\n\n";
    return 0;
}