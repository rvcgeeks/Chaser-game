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


scorekeeper::scorekeeper(){
    score=0;
    record.open(filename,ios::in);
    record.close();
    record.open(filename,ios::in|ios::out|ios::app|ios::ate);
}
int scorekeeper::getscore(){
    return score;
}
void scorekeeper::tick(){
    score++;
}
void scorekeeper::reset(){
    score=0;
}
void scorekeeper::save(){
    chunk tmp;
    cout<<"   Save score:\n   What is your name?!?:";
    cin>>tmp.name;tmp.score=score;
    record.write(reinterpret_cast<char*>(&tmp),sizeof(tmp));
}
void scorekeeper::display(){
    chunk tmp;
    record.seekg(0);
    cout<<"\n         SCOREBOARD:\n";
    while(record.read(reinterpret_cast<char*>(&tmp),sizeof(tmp)))
        cout<<"         "<<tmp.score<<"   "<<tmp.name<<endl;
    cout<<"\n\n";
}