#include "cppboost.cpp"
#include <cmath>

#define torad 3.14159/180
#define todeg 180/3.14159

#define angz (int(angle)%359)

int main(){

    int plX = 8, plY = 8;
    float rX = 0, rY = 0;
    float angle = 0;
    int raytr = 0;

    while(1){

    gotoxy(0,0);

    string world[15]={
    "111111111111111",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "1             1",
    "111111111111111",
    };

    char inp = getch();

        switch(inp){
            //case 'q': playerangle += 90.0; type *= -1; break;
            //case 'e': playerangle -= 90.0; type *= -1; break;
            case 'a': plX -= 1; break;
            case 'd': plX += 1; break;
            case 'w': plY -= 1; break;
            case 's': plY += 1; break;
            case ' ': raytr = 1; gotoxy(20,19); say "Angle: "; input angle; break;
            }


    world[plY][plX] = '9';

    if(raytr == 1){
        int hit = 0;
        int type = 1;
        float dsX = 0, dsY = 0;
        rX = plX, rY = plY;

        if(angz < 45) {type = 1;}
        else if(angz >= 45 && angz <= 135) {type = 2;}
        else if(angz >= 136 && angz <= 225) {type = 1;}
        else if(angz >= 226 && angz <= 315) {type = 2;}
        else if(angz >= 316) {type = 1;}

        while(hit == 0){

            angle -= 22.5;

            string world[15]={
                "111111111111111",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "1             1",
                "111111111111111",
                };

            world[plY][plX] = '9';


            rX += -sin(angle * torad);
            rY += -cos(angle * torad);

            ((type == 1) ? dsX:dsY) = abs(plX - rX);
            ((type == 1) ? dsY:dsX) = abs(plY - rY);


            gotoxy(20,20); printf("Side from: %2.2f  |  Away from you: %2.2f",dsX, dsY);

            if (world[int(rY)][int(rX)] == '1') hit = 1;

            world[int(rY)][int(rX)] = '2';

            gotoxy(0,0);
            for(int i = 0; i < 15; i++){
                qprint(world[i]);
                say endl;
            }

            Sleep(50);

        }

        raytr = 0;

    }


    gotoxy(0,0);
    for(int i = 0; i < 15; i++){
        qprint(world[i]);
        say endl;
    }

    }
}
