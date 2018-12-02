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

inline int random(int a,int b){
    return int(a+float(rand())/RAND_MAX*(b-a));
}

int msleep(unsigned long milisec){
    struct timespec req={0};
    time_t sec=(int)(milisec/1000);
    milisec-=sec*1000;
    req.tv_sec=sec;
    req.tv_nsec=milisec*1000000L;
    while(nanosleep(&req,&req)==-1)
        continue;
    return 1;
}

char getch(){
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        cerr<<"tcsetattr()";
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        cerr<<"tcsetattr ICANON";
    if(read(0,&buf,1)<0)
        cerr<<"read()";
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        cerr<<"tcsetattr ~ICANON";
    return buf;
}

bool kbhit(){
    termios term;
    tcgetattr(0, &term);
    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    tcsetattr(0, TCSANOW, &term);
    return byteswaiting > 0;
}
