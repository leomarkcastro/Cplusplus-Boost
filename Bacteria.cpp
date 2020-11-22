#include "cppboost.cpp"

int sleep_duration = 0;

int transmission_rate = 56;

int sid = 1;

void arrayfiller(string *mapa, COORD mapsize){

    for(int y = 0; y < mapsize.Y; y++)
        for(int x = 0; x < mapsize.X; x++){
            mapa[y] += ' ';
        }



}

void arrayfiller2(string *mapa, COORD mapsize){

    for(int y = 0; y < mapsize.Y; y++)
        for(int x = 0; x < mapsize.X; x++){
            mapa[y][x] = ' ';
        }



}

void printr(string *mapa, COORD mapsize){

    for(int y = 0; y < mapsize.Y; y++){
        gotoxy(0, y); qprint(mapa[y]);
    }

}

COORD direction(int direcode){
    COORD direc;

    switch(direcode){
        case 0:
            direc.X = 0;
            direc.Y = -1;
            break;
        case 1:
            direc.X = 1;
            direc.Y = 0;
            break;
        case 2:
            direc.X = 0;
            direc.Y = 1;
            break;
        case 3:
            direc.X = -1;
            direc.Y = 0;
            break;
    }

    return direc;
}

void reactive(string *mapa, COORD mapsize){

    Sleep(sleep_duration);
    int randeter = 0;

    //work;

    for(int y = 0; y < mapsize.Y; y++){
        for(int x = 0; x < mapsize.X; x++)
            if(x < mapsize.X - 1 && y < mapsize.Y - 1 && x > 0 && y > 0)
                if(mapa[y][x] == 'X'){
                    if(sid) mapa[y][x] = '.'; else mapa[y][x] = ' ';
                    randeter = rand() % 101;
                    if(randeter < transmission_rate && y > 1 && mapa[y-1][x] == ' ') mapa[y-1][x] = 'Y';
                    randeter = rand() % 100;
                    if(randeter < transmission_rate &&  y < mapsize.Y - 2 && mapa[y+1][x] == ' ') mapa[y+1][x] = 'Y';
                    randeter = rand() % 100;
                    if(randeter < transmission_rate && x > 1 && mapa[y][x-1] == ' ') mapa[y][x-1] = 'Y';
                    randeter = rand() % 100;
                    if(randeter < transmission_rate && x < mapsize.X - 2 && mapa[y][x+1] == ' ') mapa[y][x+1] = 'Y';
                    //work;
                }
    }

    for(int y = 0; y < mapsize.Y; y++){
        for(int x = 0; x < mapsize.X; x++){
            if(mapa[y][x] == 'Y') mapa[y][x] = 'X';
            //work;
        }
    }


}

int main(){

    setcolor(F_RED | F_INTENSITY);

    font("Terminal", 1, 400, 1);

    resizewindow(0);

    activatemouse();

    srand(time(0));

    int maprow = 180;
    int mapcol = 425;

    COORD mapsize = {mapcol, maprow};

    string mapa[mapsize.Y];

    arrayfiller(mapa, mapsize);

    mapa[(maprow/2) - 1][(mapcol/2)] = 'X';
    mapa[(maprow/2) + 1][(mapcol/2)] = 'X';
    mapa[(maprow/2)][(mapcol/2) - 1] = 'X';
    mapa[(maprow/2)][(mapcol/2) + 1] = 'X';



    while(1){
        reactive(mapa, mapsize);
        printr(mapa, mapsize);

        int b = 0;

        gotoxy(mapcol+1, b); say "Transmission Rate: " << transmission_rate; b++;
        gotoxy(mapcol+1, b); say "Time Rate: " << sleep_duration;b++;
        gotoxy(mapcol+1, b); say "Petrisquare size: " << mapcol << " x " << maprow; b+=2;
        gotoxy(mapcol+1, b); say "Press Space to insert another culture"; b++;
        gotoxy(mapcol+1, b); say "Press C to clear petrisquare"; b++;

        //system("cls");


        if(GetAsyncKeyState(' ') & 0x8000){
            mapa[(maprow/2) - 1][(mapcol/2)] = 'X';
            mapa[(maprow/2) + 1][(mapcol/2)] = 'X';
            mapa[(maprow/2)][(mapcol/2) - 1] = 'X';
            mapa[(maprow/2)][(mapcol/2) + 1] = 'X';}
        if(GetAsyncKeyState('A') & 0x8000){ transmission_rate--;}
        if(GetAsyncKeyState('D') & 0x8000){ transmission_rate++;}
        if(GetAsyncKeyState('W') & 0x8000){ sleep_duration++;}
        if(GetAsyncKeyState('S') & 0x8000){ sleep_duration--;}
        if(GetAsyncKeyState('C') & 0x8000){ arrayfiller2(mapa, mapsize);}
    }

}
