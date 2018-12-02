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


void execute_events(bool isdefault,const char maze_filename[]){
    restart:
    int delay;
    cout<<"How much delay do u want? (ms):";
    cin>>delay;
    srand(time(0));
    scorekeeper scores;
    path p;location enemy,you;
    bool initflag=true,startscoring=false;
    while(global_control_move!='x'){
        maze M;
        if(isdefault) M.load();
        else M.load(maze_filename);
        if(initflag){
            while(you==enemy||!M[you].open||!M[enemy].open){
                you=make_pair(random(0,M.m-1),random(0,M.n-1)),
                enemy=make_pair(random(0,M.m-1),random(0,M.n-1));
            }initflag=false;
        }if(kbhit()){
            startscoring=true;
            global_control_move=getch();
            dragger(&M,you,global_control_move,"adsw");
            a_star algo(&M,enemy,you);
            p=algo.fire();
        }else msleep(delay);
        if(!p.empty()){
            enemy=p.front();
            p.pop_front();
        }if(startscoring)
            scores.tick();
        display(&M,enemy,you,p,scores.getscore());
        if(you==enemy){char opt;
            cout<<"\033[2J\033[1;1H"<<header<<"\a\n\n"<<hackerman
                <<"\n\n    YOU ARE CAUGHT!!!";
            scores.save();scores.display();
            cout<<" PLAY AGAIN?!? [y/n]";
            opt=getch();
            if(opt=='y')
                goto restart;
            else break;
        }disppath(p);
        cout<<"\n\n  >>> ";
    }
}
