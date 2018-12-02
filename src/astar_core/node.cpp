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

node::node(int x,int y){
    current=make_pair(x,y);
    parent=make_pair(-1,-1);
    f=g=h=numeric_limits<float>::max();
}
node::node(location p,location c,float tf,float tg,float th){
    current=c;parent=p;
    f=tf;g=tg;h=th;open=true;
}