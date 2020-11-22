#include "cppboost.cpp"

int main(){


    system("color f0");
    activatemouse();
    COORD mouse, mouse2;
    COORD box = {11,11};
    int run = 1;
    int x = 1;
    int y = 1;
    int x1 = 10, x2 = 10,x3 = 10,y1 = 9,y2 = 10,y3 = 11;

    resizewindow(0);

    boxborder(1, 86-2, 26-2, F_GREEN, 0, 2, 2);

    gotoxy(box.X, box.Y); cout << char(219);

    while(run){

        gotoxy(0,0); printf("%3i - %3i | %2i", mouse.X, mouse.Y, mouseclick());

        mouseloc2(mouse);

        setcolor(B_WHITE | B_INTENSITY);
        gotoxy(x1, y1); say ' ';
        gotoxy(x2, y2); say ' ';
        gotoxy(x3, y3); say ' ';

        if((mouse.X < 84) && (mouse.X > 54)){x1 = x2 = x3 = (mouse.X- 1);}
        if((mouse.Y < 23) && (mouse.Y > 4)){
        y1 = mouse.Y - 1;
        y2 = mouse.Y;
        y3 = mouse.Y + 1;}

        gotoxy(x1, y1); say '|';
        gotoxy(x2, y2); say '|';
        gotoxy(x3, y3); say '|';

        gotoxy(box.X, box.Y); cout << " ";

        if(box.X >= 84) x *= -1;
        if(box.X <= 3) x *= -1;

        if(box.Y >= 24) y *= -1;
        if(box.Y <= 3) y *= -1;

        if(((box.X == x1 - 1) || (box.X == x1)) && ((box.Y == y1) || (box.Y == y2) || (box.Y == y3))) x *= -1;

        box.X = box.X + (1*x);
        box.Y = box.Y + (1*y);

        /*
        if(mouse.X == box.X - 1 && mouse.Y == box.Y){
            gotoxy(box.X, box.Y); cout << " ";
            if (box.X < 84) box.X++;
            gotoxy(box.X, box.Y); cout << char(219);
        }
        if(mouse.X == box.X + 1 && mouse.Y == box.Y){
            gotoxy(box.X, box.Y); cout << " ";
            if (box.X > 3) box.X--;
            gotoxy(box.X, box.Y); cout << char(219);
        }
        if(mouse.Y == box.Y - 1 && mouse.X == box.X){
            gotoxy(box.X, box.Y); cout << " ";
            if (box.Y < 24)box.Y++;
            gotoxy(box.X, box.Y); cout << char(219);
        }
        if(mouse.Y == box.Y + 1 && mouse.X == box.X){
            gotoxy(box.X, box.Y); cout << " ";
            if (box.Y > 3) box.Y--;
            gotoxy(box.X, box.Y); cout << char(219);
        }
        */

        gotoxy(box.X, box.Y); cout << char(219);
        Sleep(50);

    }

    coordfindermouse();


    say "Now Working!";
}

