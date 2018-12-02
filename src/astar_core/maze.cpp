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

void maze::load(){                  //load maze from default array
    m=33;n=65;
    grid=new node*[m];                   //make the required sized bed ;p
    for(int i=0;i<m;i++)
        grid[i]=new node[n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            grid[i][j]=node(i,j);
            grid[i][j].open=defaultmaze[i][j]==' ';     
        }
    }
}
void maze::load(const char filepath[]){                  //load maze from file
    fstream file(filepath,ios::in);
    if(file.is_open()){
        char buf[100];
        file.getline(buf,100);
        m=0;n=strlen(buf);
        file.seekg(0);
        while(!file.eof())
        {file.getline(buf,100);m++;}
        grid=new node*[m];                   //make the required sized bed ;p
        for(int i=0;i<m;i++)
            grid[i]=new node[n];
        file.seekg(0);
        for(int i=0;i<m;i++){
            file.getline(buf,100,'\n');
            for(int j=0;j<n;j++){
                grid[i][j]=node(i,j);
                grid[i][j].open=buf[j]==' ';     //decorate it... if its a space ...its an open node
            }
        }file.close();
    }else throw 0;       //integer exception if file fails to open
}
void maze::reset_heuristics(){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(grid[i][j].open){
                grid[i][j].current=make_pair(i,j);
                grid[i][j].parent=make_pair(-1,-1);
                grid[i][j].f=grid[i][j].g=grid[i][j].h=0.0f;
            }
}
node& maze::operator[](location l){
    return grid[l.first][l.second];
}
bool maze::isvalid(location current){
    return current.first>=0  &&
           current.first<m   &&
           current.second>=0 &&
           current.second<n;
}
