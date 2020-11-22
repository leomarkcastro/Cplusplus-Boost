//{

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <thread>


#define wait getch()
//#define clean system("cls")
#define say cout<<
#define input cin>>
#define work cout<<"Working!\t"

#define B_BLACK        0
#define B_BLUE         16
#define B_GREEN        32
#define B_SKY          48
#define B_RED          64
#define B_VIOLET       80
#define B_YELLOW        96
#define B_WHITE        112

#define F_BLACK	    0
#define F_BLUE      1
#define F_GREEN	    2
#define F_SKY  	    3
#define F_RED       4
#define F_VIOLET    5
#define F_YELLOW    6
#define F_WHITE     7
//}

using namespace std;


int thread_opened = 0;

const int maprow = 35;  ///Change the map row and column here if you wish to change the map size
const int mapcol = 35;  ///The map itself is in the main function.

const int anim_speed = 10; ///Change this to lower value for faster animation
const int node_speed = 0;   ///If you want to see the nodes, then set this above 0

const char nodesprite = ' '; ///Change if you want to see the nodes created for the maze.

const int move_style = 0; ///0 is the erratic but more effective one; 1 is the straightforward but shitty one

const int wait_before_solution = 1; ///Change to 1 if you want to pause before proceeding in answering

const int tweak_opt = 0; ///Experimental method to make the calculation go faster. Might cause error, turn off in case.


/// MAZE SOLVER. BAGUHIN MO YUNG PARAMETERS ABOVE AS YOU WISH



/// The premise is that this program will attempt to find the shortest route from start to finish of a maze.

/// It will assume that there is only one start above and one end at the bottom. Anything else will not work. The highest Start will be the assumed start and the End placed in the lowest part is the assumed end of the maze <if you will try to put multiple terminals>

/// Thanks to multi threading, ambilis na niya magsolve

/// Achievement na sakin maimplement yung recursion of function saka multithreading kahit di ko pa sya totally gets hahahaha




vector<COORD> anspath;
int optisteps = 0;

COORD randompoint(string *vmap){

    int ycoord, xcoord;

    do{
        ycoord = rand() % maprow;
        xcoord = rand() % mapcol;

    } while(vmap[ycoord][xcoord] == '#');

    COORD retcor = {ycoord, xcoord};

    return retcor;

}

void activatemouse(){   /// You should initiate this function before using any function that involves the mouse

    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events;
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 25;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &cci);

    SetConsoleMode(hin, ENABLE_EXTENDED_FLAGS | ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
}

void setcolor(int x = 240){      ///Change text cell color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

void gotoxy(int x = 0, int y = 0){    ///Move to console position
    COORD coord = {0,0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printr(string *vmap){

    for(int i = 0; i < maprow; i++){
        say vmap[i] << endl;
    }

}

int nodes(string *vmap, vector<COORD> &lcrd, COORD &mstart, COORD &mend){

    /*size_t rowend = 0;
    while (!vmap[rowend].empty()) ++rowend;*/
    int nodecount = 0;

    for(int row = 0; row < maprow; row++){
        for(int column = 0; column < mapcol; column++){
            if (vmap[row][column] == 'S') {lcrd.push_back({row, column}); mstart = {row, column}; nodecount++;}
            if ((vmap[row][column] == ' ')&&((((vmap[row][column+1] != '#')+(vmap[row][column-1] != '#'))> 0))&&((((vmap[row+1][column] != '#')+(vmap[row-1][column] != '#'))> 0))&&((((vmap[row][column+1] != '#')+(vmap[row][column-1] != '#')+(vmap[row+1][column] != '#')+(vmap[row-1][column] != '#')+(vmap[row+1][column+1] != '#')+(vmap[row+1][column-1] != '#')+(vmap[row-1][column+1] != '#')+(vmap[row-1][column-1] != '#'))<= 7))) {lcrd.push_back({row, column}); nodecount++;}
            if (vmap[row][column] == 'E') {lcrd.push_back({row, column}); mend = {row, column}; nodecount++;}
    }}

    return nodecount;
}

COORD direction(int dir){
    COORD direct;
    switch (dir){
    case 0:{
        direct.Y = 0;
        direct.X = -1;
    break; }
    case 1:{
        direct.Y = 1;
        direct.X = 0;
    break; }
    case 2:{
        direct.Y = 0;
        direct.X = 1;
    break; }
    case 3:{
        direct.Y = -1;
        direct.X = 0;
    break; }
    }

    return direct;
}

void traverser(string *vmap, vector<COORD> lcrd, vector<int> nodestat, COORD mstart, COORD mend, int direc, vector<COORD> pcrd, int countersteps, int &routesexp, int &routesfin){
    COORD flow = direction(direc);
    bool run = TRUE;
    routesexp++;
    //gotoxy(mapcol+1,0); setcolor(F_WHITE|B_BLACK); printf("Best Route No. of Steps: %4d", optisteps);
    //gotoxy(mapcol+1,1); setcolor(F_WHITE|B_BLACK); printf("%d", routesexp);
    //gotoxy(mapcol+1,2); setcolor(F_WHITE|B_BLACK); printf("Routes that reached the finish: %d", routesfin);

    //bool solve = FALSE;
    if(node_speed > 0){
    gotoxy(mstart.Y,mstart.X); say direc;
    Sleep(node_speed);}


    while(run){
        mstart.X += flow.X;
        mstart.Y += flow.Y;
        countersteps++;

        if(countersteps > optisteps){run = 0; break;}

        if(vmap[mstart.X][mstart.Y] == '#'){run = 0; break;}

        if(mstart.X < 0 || mstart.X > maprow || mstart.Y < 0 || mstart.Y > mapcol) {run = 0; break;}

        if(mstart.X == mend.X && mstart.Y == mend.Y) {
            run = 0; //solve = 1;
            pcrd.push_back({mstart.X, mstart.Y});
            nodestat[nodestat.size() - 1] = 1;
            routesfin++;

            if(countersteps < optisteps){

            anspath = move(pcrd);
            optisteps = countersteps;


            /*
            for(int i = 0; i != anspath.size(); i++){
                printf("i: %2i | X: %2i | Y: %2i | nS: %2i\n", i, anspath[i].X, anspath[i].Y, nodestat[i]);
            }
            wait;*/

            }

            break;}

        for(int i = 0; i != lcrd.size(); i++){
            if (mstart.X == lcrd[i].X && mstart.Y == lcrd[i].Y) {
                if(nodestat[i] == 1) {run = 0; break;}
                //else {run = 0; break;}
                else{

                nodestat[i] = 1;

                pcrd.push_back({mstart.X, mstart.Y});

                if(move_style == 1){

                if(direc == 2){
                if(vmap[mstart.X+1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 2, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y+1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 1, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y-1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 3, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X-1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 0, pcrd, countersteps, routesexp, routesfin);}
                }
                else if(direc == 0){
                if(vmap[mstart.X-1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 0, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y-1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 3, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y+1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 1, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X+1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 2, pcrd, countersteps, routesexp, routesfin);}
                }
                else if(direc == 3){
                if(vmap[mstart.X][mstart.Y-1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 3, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X+1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 2, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X-1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 0, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y+1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 1, pcrd, countersteps, routesexp, routesfin);}
                }
                else if(direc == 1){
                if(vmap[mstart.X][mstart.Y+1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 1, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X+1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 2, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X-1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 0, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y-1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 3, pcrd, countersteps, routesexp, routesfin);}
                }
                }
                else if(move_style == 0 && thread_opened < 500){

                int use_thread = 0;
                int intarray[5];

                if(vmap[mstart.X+1][mstart.Y] != '#'){
                intarray[use_thread] = 2;
                use_thread++;
                }

                if(vmap[mstart.X][mstart.Y+1] != '#'){
                intarray[use_thread] = 1;
                use_thread++;
                }

                if(vmap[mstart.X][mstart.Y-1] != '#'){
                intarray[use_thread] = 3;
                use_thread++;
                }

                if(vmap[mstart.X-1][mstart.Y] != '#'){
                intarray[use_thread] = 0;
                use_thread++;
                }


                thread threads[use_thread];

                for(int i = 0; i < use_thread; i++){
                thread_opened++;
                threads[i] = thread(traverser, vmap, lcrd, nodestat, mstart, mend, intarray[i], pcrd, countersteps, ref(routesexp), ref(routesfin));}


                for(int i = 0; i < use_thread; i++)
                    threads[i].join();




                //gotoxy(mapcol+1,1); setcolor(F_WHITE|B_BLACK); printf("%d", routesexp);

                }
                else if(move_style == 0){

                if(vmap[mstart.X+1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 2, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y+1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 1, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X][mstart.Y-1] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 3, pcrd, countersteps, routesexp, routesfin);}
                if(vmap[mstart.X-1][mstart.Y] != '#'){
                traverser(vmap, lcrd, nodestat, mstart, mend, 0, pcrd, countersteps, routesexp, routesfin);}
                }



                run = 0;
                break;}
            }
        }
    }

}

int main(){

    activatemouse();

    while(1){

    srand(time(0));

    int routesexplored = 0;
    int routesfinished = 0;
    vector<COORD> listcoord;
    vector<COORD> pathcoord;
    int nodecount = 0;
    int countersteps = 0;
    int stepstaken = 0;
    COORD mstart, mend;

    string mapa[maprow+1] = {
        "###################################",
        "##                          #######",
        "## ############# ########## #######",
        "## #                   #### #######",
        "####### ######## ##### #### #######",
        "##      ######## ###         ######",
        "## #### #################### ######",
        "##    # ########  #  #           ##",
        "## ####      ####            ### ##",
        "## #### #### ####  ###       ### ##",
        "##      #### #    ## #        ## ##",
        "## #### #####  ##### ###    #### ##",
        "## #### ###   #      ###  ###### ##",
        "## #### ### ## ##### ###         ##",
        "## #### #   ## ##### ##### ##### ##",
        "## #### # # ##       ##### ##### ##",
        "## #### # ##     ######### ##### ##",
        "## #### ######## ######### ##### ##",
        "#                                ##",
        "###  ################## ###########",
        "####  #################         ###",
        "#####  ######################## ###",
        "######  ########                ###",
        "#######  ####### ############# ####",
        "########  ###### ############# ####",
        "#######    ##### ############# ####",
        "####### ##   ### ############# ####",
        "####### ####               ### ####",
        "####### ###### ###########  ## ####",
        "####### #      ############  # ####",
        "#######   ####       ####### # ####",
        "############## ##### ####### #  ###",
        "#                                ##",
        "###     ###    ####################",
        "###################################",

    };

    COORD mapstart = randompoint(mapa);
    COORD mapend = randompoint(mapa);

    mapa[mapstart.X][mapstart.Y] = 'S';
    mapa[mapend.X][mapend.Y] = 'E';

    nodecount = nodes(mapa, listcoord, mstart, mend);

    vector<int> nodestat (nodecount);
    std::fill( nodestat.begin(), nodestat.end(), 0 );


    for(int i = 0; i != listcoord.size(); i++){
        mapa[listcoord[i].X][listcoord[i].Y] = nodesprite;
    }

    //printf("\nNode Count: %i", nodecount);

    /*for(int i = 0; i != listcoord.size(); i++){
       printf("i: %2i | X: %2i | Y: %2i | nS: %2i\n", i, listcoord[i].X, listcoord[i].Y, nodestat[i]);
    }*/

    if(tweak_opt == 0) optisteps = mapcol * maprow;
    else optisteps = 3*nodecount / (float(maprow/mend.Y) * float(mapcol/mend.X));


    printr(mapa);

    gotoxy(mstart.Y, mstart.X); setcolor(B_BLUE | F_WHITE); say 'S';
    gotoxy(mend.Y, mend.X); setcolor(B_RED | F_WHITE); say 'E';

    gotoxy(0, maprow+1); setcolor(15); printf("Working with maze. May be fast, too slow, or crash");

    int movedir = 2;

    if(mapa[mstart.X+1][mstart.Y] != '#') movedir = 2;
    if(mapa[mstart.X-1][mstart.Y] != '#') movedir = 0;
    if(mapa[mstart.X][mstart.Y+1] != '#') movedir = 1;
    if(mapa[mstart.X][mstart.Y-1] != '#') movedir = 3;
    traverser(mapa, listcoord, nodestat, mstart, mend, movedir, pathcoord, countersteps, routesexplored, routesfinished);

    if(wait_before_solution == 1){
        gotoxy(0, maprow+1);
        setcolor(B_BLUE | F_WHITE); printf("NOW READY!!! PRESS ANY KEY TO CONTINUE"); setcolor(B_BLACK | F_WHITE); printf("            ");
        wait;
    }


    /*for(int i = 0; i != anspath.size(); i++){
        printf("i: %2i | X: %2i | Y: %2i | nS: %2i\n", i, anspath[i].X, anspath[i].Y, nodestat[i]);
    }*/


    for(int i = 0; i != anspath.size(); i++){

        int next =1;
        while(next){

                gotoxy(mstart.Y, mstart.X); setcolor(F_BLUE | B_BLUE); say ' ';
                gotoxy(maprow+1, mapcol-3); setcolor(F_WHITE | B_RED); printf("goalX: %2i | goalY: %2i", anspath[i].X, anspath[i].Y);
                gotoxy(maprow+1, mapcol-2); setcolor(F_WHITE | B_BLUE); printf("youX: %2i | youY: %2i", mstart.X, mstart.Y);

                if(mstart.X > anspath[i].X){mstart.X-= 1;}
                else if(mstart.X < anspath[i].X){mstart.X+=1;}
                else if(mstart.Y > anspath[i].Y){mstart.Y-=1;}
                else if(mstart.Y < anspath[i].Y){mstart.Y+=1;}

                //Sleep(anim_speed);
                Sleep(anim_speed);
                stepstaken++;
                if ((mstart.X == anspath[i].X)&&(mstart.Y == anspath[i].Y)) next = 0;


        }

        gotoxy(mstart.Y, mstart.X); setcolor(F_BLUE | B_BLUE); say ' ';

    }


    gotoxy(0, maprow+2);
    setcolor(B_BLACK|F_RED);

    if(anspath.size() == 0)
        say "\n\nRecheck your map, it is impossible to reach the end. Check if some hashes blocks the path.\n\n";

    else{
        setcolor(B_BLACK|F_WHITE);
        printf("Step Taken: %2d\n", stepstaken);
        printf("Nodes created: %2d\n\n", nodecount);
        printf("Thread created: %2d\n\n", thread_opened);}

    wait;

    system("cls");
    setcolor(15);

    optisteps = maprow * mapcol;
    }


}
