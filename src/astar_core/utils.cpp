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

void dragger(maze *m,location& current,char move,const char controls[]){     //L R U D character controls
        if(move==controls[0]&&current.second>=0){
            current.second--;
            if(!(*m)[current].open)
                current.second++;
        }else if(move==controls[1]&&current.second<m->n-1){
            current.second++;
             if(!(*m)[current].open)
                current.second--;
        }else if(move==controls[2]&&current.first<m->m-1){
            current.first++;
             if(!(*m)[current].open)
                current.first--;
        }else if(move==controls[3]&&current.first>=0){
            current.first--;
             if(!(*m)[current].open)
                current.first++;
        }
}
void display(maze *mz,location src,location dest,path p,int score){
    cout<<"\033[2J\033[1;1H"<<header<<"   SCORE = "<<score<<"\n\n";
    for(int i=0;i<mz->m;i++){cout<<"      ";
        for(int j=0;j<mz->n;j++){
            if(make_pair(i,j)==src)
                cout<<"\033[1;31m██\033[0m";
            else if(make_pair(i,j)==dest)
                cout<<"\033[1;32m██\033[0m";
            else if(mz->grid[i][j].open){
                if(find(p.begin(),p.end(),make_pair(i,j))!=p.end())
                    cout<<"\033[38;5;255m██\033[0m";
                else cout<<"  ";
            }else cout<<"██";
        }cout<<"\033[1;94m"<<i<<"\033[0m"<<endl;      //row no
    }int w=0,g=mz->m;while(g/=10)w++;
    for(;w>=0;w--){cout<<"      ";
        for(int j=0;j<mz->n;j++)
            cout<<"\033[1;94m"<<(j/(int)pow(10,w))%10<<" \033[0m";   //col no
        cout<<endl;
    }cout<<endl;
}
void disppath(path p){
    cout<<"\nTRACED PATH:\nstart->";
    for(int i=0;i<p.size();i++)          //post climax scenes ;p
        cout<<"("<<p[i].first<<","<<p[i].second<<")->";
    cout<<"end \ntotal "<<p.size()<<" nodes to be travelled...\n";
}