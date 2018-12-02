 * ___________________________________________________________
 * ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
 * CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
 *
 * #RVCGEEKS chase game
 * created on 06.11.2018
 
 -------------------------------------------------------------------------
 
 a terminal based game that loads a maze from a text file
 and initializes your and enemy position and you have to run while enemy 
 chases you...  this project uses A* algorithm to achieve this... i have
 used the core of my previous project rvc_a_star which was for demonstration
 of the algorithm...
 
 -------------------------------------------------------------------------
 
 RUN --how to- 
 
 in the repo we have precompiled linux executable "rvc_chaser_amd64" that 
 opens with typical ubuntu OSes and amd64 architectures...
 
    SYNOPSIS:
 
 ~$ ./rvc_chaser_amd64 [path]
 
 its a commandline program which requires following parameters:
 but still you can run it w/o arguments after you let it load
 its inbuilt default demo maze (from ./mazes/apec2010.txt) for 
 playing instantly...
         
    ARGUMENTS:    
         
 [path] : the local path to the maze file which has to be loaded...
          0 is closed and space is open in input file
          this repo has a folder named "mazes" which has a huge collection
          of 408 compatable maze text files ...special thanks to
          https://github.com/micromouseonline/micromouse_maze_tool  :)
          (I have included its LICENCE file in that folder)
          
          you can import its mazes in this parameter by giving right path
          if they give error, then open that file in a text editor (kate)
          and erase the very last endline character...
 
 if your OS dosent support this executable then you need to build it from
 source given in 'src' folder ... in this case follow the given below steps:
 
 ---------------------------------------------------------------------------
 
 COMPILE --how to-
 
 if you require to build the project ,the source is given in src folder..
 1) open and mount your terminal in ./src/ folder
 2) the source has a Makefile so hit "make" command in terminal to produce
    the executable file "rvc_chaser_amd64" .. and you are ready to execute
    it by giving it right path to maze file and following above 
    runtime steps.
    
----------------------------------------------------------------------------

REPO TREE:
 
 >parent directory/
   >LICENCE
   >Readme.md
   >chaser_scores.dat (maybe records of previous tests)
   >rvc_chaser_amd64 (precompiled executable)
   >mazes/
     >LICENCE (micromouseonline)
     > * collection of 409 txt maze files
   >src/
     >Makefile
     >main.cpp
     >game_binder.hpp
     >astar_core/
       >astar.cpp
       >binder.hpp
       >maze.cpp
       >node.cpp
       >utils.cpp
       >defaultMazeArray.cpp
     >event_handler/
       >eventhandler.cpp
       >event_binder.hpp
       >input_methods.cpp
     >score_keeper/
       >scorestructs,hpp
       >scorekeeper.cpp

----------------------------------------------------------------------------

enjoy!!
<<<   STAY TUNED !!   >>>
 
