# ___________________________________________________________
# ____________<<<___#_R_V_C_G_E_E_K_S___>>>__________________
# CREATED BY #RVCGEEKS @PUNE for more rvchavadekar@gmail.com
#
# #RVCGEEKS chase game
# created on 06.11.2018
# 
# this program reads a maze text file and initializes you and
# enemy at random position and then you have to run while
# enemy is chasing you...
#
# ./Makefile  : makefile for make utility ...
#

# program entry point at launcher main.cpp
ENTRYPOINT = main.cpp 

# name of executable
EXEC = rvc_chaser_amd64

# set CXXFLAGS to cpp ver 11 and optimization level to O1
CXXFLAGS = -std=gnu++11
OPTLEVEL = -O1

# build the binary
all: $(EXEC)

# hit the command
$(EXEC):
	@$(CXX) $(ENTRYPOINT) $(CXXFLAGS) $(OPTLEVEL) -o $(EXEC)
