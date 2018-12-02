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

a_star::a_star(maze *p,location s,location d){
    m=p;src=s;dest=d;
}


path a_star::fire(){                        //mmmm here we go!!!
    path sp;
    if(!m->isvalid(src)){cout<<"Source is out of bounds!!\n";return sp;}
    if(!m->isvalid(dest)){cout<<"Destination is out of bounds!!\n";return sp;}
    if(src==dest){cout<<"We are already at Destination!!\n";
        sp.push_back(src);return sp;
    }path closedlist;set<pPair> openlist;
    int i=src.first,j=src.second;float fnew,gnew,hnew; 
    m->grid[i][j]=node(make_pair(i,j),make_pair(i,j),0.0f,0.0f,0.0f);
    openlist.insert(make_pair(0.0,make_pair(i,j))); 
    while(!openlist.empty()){
        pPair p=*openlist.begin();
        openlist.erase(openlist.begin());
        closedlist.push_back(p.second);
        i = p.second.first;j = p.second.second;
        for(int k=1;k<=8;k++){location successor;switch(k){  //the 'star' of the A-star algo ;)
                case 1:successor=make_pair(i-1,j  );break;   //N
                case 2:successor=make_pair(i-1,j+1);break;   //NE
                case 3:successor=make_pair(i  ,j+1);break;   // E
                case 4:successor=make_pair(i+1,j+1);break;   //SE
                case 5:successor=make_pair(i+1,j  );break;   //S
                case 6:successor=make_pair(i+1,j-1);break;   //SW
                case 7:successor=make_pair(i  ,j-1);break;   // W
                case 8:successor=make_pair(i-1,j-1);break;   //NW
                }if(m->isvalid(successor)){
                    if(successor==dest){       //gotcha you!! climax
                        (*m)[successor].parent=make_pair(i,j);
                        int row = dest.first,col = dest.second;
                        while(!(m->grid[row][col].parent==make_pair(row,col))){ 
                            sp.push_front(make_pair(row,col));
                            location temp=m->grid[row][col].parent;
                            row = temp.first;col = temp.second; 
                        }sp.push_front(make_pair(row, col));
                        m->reset_heuristics();
                        return sp; 
                    }else if(find(closedlist.begin(),closedlist.end(),successor)==closedlist.end()&&(*m)[successor].open){
                        gnew = m->grid[i][j].g+(float)sqrt(2-k%2);
                        hnew = sqrt(pow((successor.first-dest.first),2)+pow((successor.second-dest.second),2));
                        fnew = gnew + hnew;
                        if((*m)[successor].f==numeric_limits<float>::max()||(*m)[successor].f>fnew){
                            openlist.insert(make_pair(fnew,successor));
                            (*m)[successor]=node(make_pair(i,j),make_pair(i,j),fnew,gnew,hnew);
                            closedlist.push_back(successor);
                        }
                }
            }
        }
    }m->reset_heuristics();
    return sp; //uuh thug life ...look for someone else...(destination)
}
