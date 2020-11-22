#include "cppboost.cpp"

int main(){

    int ret;
    getcolor(ret);
    system("cls");

    system("color 0F");
    activatemouse();
    font("Terminal", 15);
    Sleep(500);
    resizewindow(2);

    fitbufferscreen();

    Sleep(500);

    //coordfindermouse();

    boxfill((B_BLUE), 176, 1, 1, 2);
    boxfill((B_WHITE), 176, 48, 1, 3);
    gotoxy(2,1); setcolor(B_BLUE|F_WHITE); say " COMMAND PROMPT PAINT ";
    gotoxy(174,1); setcolor(B_RED|F_WHITE); say " X ";
    gotoxy(166,1); setcolor(B_BLUE|F_WHITE); say " SAVE ";
    gotoxy(159,1); setcolor(B_GREEN|F_WHITE); say " LOAD ";
    boxfill((255), 168, 43, 4, 6, ' ');

    gotoxy(5,4); setcolor(B_BLACK|F_WHITE); say " BLK ";
    gotoxy(11,4); setcolor(B_BLUE|F_WHITE); say " BLU ";
    gotoxy(17,4); setcolor(B_GREEN|F_WHITE); say " GRN ";
    gotoxy(23,4); setcolor(B_SKY|F_WHITE); say " SKY ";
    gotoxy(29,4); setcolor(B_RED|F_WHITE); say " RED ";
    gotoxy(35,4); setcolor(B_VIOLET|F_WHITE); say " VLT ";
    gotoxy(41,4); setcolor(B_YELLOW|F_WHITE); say " GLD ";
    gotoxy(47,4); setcolor(B_WHITE|B_INTENSITY|F_BLACK); say " CRM ";
    gotoxy(53,4); setcolor(B_INTENSITY|B_BLACK|F_WHITE); say " GRY ";
    gotoxy(59,4); setcolor(B_INTENSITY|B_BLUE|F_WHITE); say " LBL ";
    gotoxy(65,4); setcolor(B_INTENSITY|B_GREEN|F_WHITE); say " LGR ";
    gotoxy(71,4); setcolor(B_INTENSITY|B_SKY|F_WHITE); say " LSK ";
    gotoxy(77,4); setcolor(B_INTENSITY|B_RED|F_WHITE); say " LRD ";
    gotoxy(83,4); setcolor(B_INTENSITY|B_VIOLET|F_WHITE); say " LVT ";
    gotoxy(89,4); setcolor(B_INTENSITY|B_YELLOW|F_WHITE); say " LGL ";
    gotoxy(95,4); setcolor(B_INTENSITY|B_WHITE|B_INTENSITY|F_BLACK); say " WHT ";

    gotoxy(169,4); setcolor(B_RED|B_INTENSITY|F_WHITE); say " CLR ";

    int run = 1;
    int save = 0;
    COORD mouse;
    int color = 0;
    char letter = 'A';

    while(run){

        mouseloc2(mouse);

        if((mouse.X > 3) && (mouse.Y > 5)&&(mouse.X <= 171) && (mouse.Y < 49)){
            if(mouseclick() == 1) {gotoxy(mouse.X, mouse.Y); setcolor(color); say letter;}
            if(mouseclick() == 2) {gotoxy(mouse.X, mouse.Y); setcolor(255); qfill(' ');}
        }

        else if((mouse.Y == 4)&&(mouseclick() == 1)){
            if((mouse.X >= 5)&&(mouse.X <= 9)) {color =   0; letter = 'A';}
            else if((mouse.X >= 11)&&(mouse.X <= 15)) {color =  17; letter = 'B';}
            else if((mouse.X >= 17)&&(mouse.X <= 21)) {color =  34; letter = 'C';}
            else if((mouse.X >= 23)&&(mouse.X <= 27)) {color =  51; letter = 'D';}
            else if((mouse.X >= 29)&&(mouse.X <= 33)) {color =  68; letter = 'E';}
            else if((mouse.X >= 35)&&(mouse.X <= 39)) {color =  85; letter = 'F';}
            else if((mouse.X >= 41)&&(mouse.X <= 46)) {color = 102; letter = 'G';}
            else if((mouse.X >= 47)&&(mouse.X <= 51)) {color = 119; letter = 'H';}
            else if((mouse.X >= 53)&&(mouse.X <= 57)) {color = 136; letter = 'I';}
            else if((mouse.X >= 59)&&(mouse.X <= 63)) {color = 153; letter = 'J';}
            else if((mouse.X >= 65)&&(mouse.X <= 69)) {color = 170; letter = 'K';}
            else if((mouse.X >= 71)&&(mouse.X <= 75)) {color = 187; letter = 'L';}
            else if((mouse.X >= 77)&&(mouse.X <= 81)) {color = 204; letter = 'M';}
            else if((mouse.X >= 83)&&(mouse.X <= 87)) {color = 221; letter = 'N';}
            else if((mouse.X >= 89)&&(mouse.X <= 93)) {color = 238; letter = 'O';}
            else if((mouse.X >= 95)&&(mouse.X <= 99)) {color = 255; letter = ' ';}
            else if((mouse.X >=169)&&(mouse.X <=173)) {boxfill((B_WHITE | B_INTENSITY), 168, 43, 4, 6);}
        }

        else if(((mouse.X == 174)||(mouse.X == 175)||(mouse.X == 176))&&(mouse.Y == 1)&&(mouseclick() == 1)) run = FALSE;

        else if(((mouse.X >= 166)&&(mouse.X <= 171))&&(mouse.Y == 1)&&(mouseclick() == 1)){

            int a = 0;
            int b = 0;
            int inp = 1;
            char inpute;
            string filename;
            string draw[43];
            int i = 0;
            for(int y = 6; y <= 48; y++){
                for(int x = 4; x <= 171; x++){
                    draw[i] += getcursorchar(x,y);
                }
                i++;
            }


            gotoxy(32, 50); setcolor(B_BLUE|F_WHITE|F_INTENSITY); say "Save as:                                            ";
            while(inp){
                gotoxy(42, 50); say filename;
                inpute = getch();
                if(inpute != '\r') {filename += inpute;}
                else {filename.append(".txt"); inp = 0;}
            }
            gotoxy(32, 50); setcolor(B_WHITE|F_WHITE); say "                                                             ";
            stringpointtofile(draw, 42, filename);

        }

        else if(((mouse.X >= 159)&&(mouse.X <= 164))&&(mouse.Y == 1)&&(mouseclick() == 1)){

            int inp = 1;
            char inpute;
            string fileName;
            string draw[43];
            int i = 0;

            gotoxy(62, 50); setcolor(B_GREEN|F_WHITE|F_INTENSITY); say "Load File:                                            ";
            while(inp){
                gotoxy(73, 50); say fileName;
                inpute = getch();
                if(inpute != '\r') {fileName += inpute;}
                else {fileName.append(".txt"); inp = 0;}
            }
            gotoxy(62, 50); setcolor(B_WHITE|F_WHITE); say "                                                             ";

            int lngth = 0;

            string getContent;

            ifstream inFile;
            inFile.open(fileName.c_str());

            if(!inFile.is_open()){
                gotoxy(62, 50); setcolor(B_RED|F_WHITE|F_INTENSITY); say "Error while opening file                       ";
                getch();
                gotoxy(62, 50); setcolor(B_WHITE|F_WHITE); say "                                                             ";
                goto ends;
            }

            if(inFile.is_open())
            {


                while(! inFile.eof())
                {
                    getline(inFile, getContent);
                    draw[lngth] = getContent;
                    lngth++;
                }
            }

            inFile.close();


            /*system("cls");
            system("color 0f");

            for(int i = 0; i < 42; i++){
                for(int j = 0; j < 167; j++){
                    say draw[i][j];
                }
                say endl;
            }*/


            for(int y = 6, a = 0; y <= 48; y++){
                for(int x = 4, b = 0; x <= 171; x++){
                    gotoxy(x,y);
                    switch(draw[a][b]){
                        case ' ': setcolor(255); qfill(' '); break;
                        case 'A': setcolor(  0); qfill('A'); break;
                        case 'B': setcolor( 17); qfill('B'); break;
                        case 'C': setcolor( 34); qfill('C'); break;
                        case 'D': setcolor( 51); qfill('D'); break;
                        case 'E': setcolor( 68); qfill('E'); break;
                        case 'F': setcolor( 85); qfill('F'); break;
                        case 'G': setcolor(102); qfill('G'); break;
                        case 'H': setcolor(119); qfill('H'); break;
                        case 'I': setcolor(136); qfill('I'); break;
                        case 'J': setcolor(153); qfill('J'); break;
                        case 'K': setcolor(170); qfill('K'); break;
                        case 'L': setcolor(187); qfill('L'); break;
                        case 'M': setcolor(204); qfill('M'); break;
                        case 'N': setcolor(221); qfill('N'); break;
                        case 'O': setcolor(238); qfill('O'); break;}
                    b++;}
                    a += 1;}

            ends:
                Sleep(0);

        }

        gotoxy(2,50); setcolor(B_SKY | F_BLACK); printf("X: %3i | Y: %3i | Click: %1i", mouse.X, mouse.Y, mouseclick());

    }

    setcolor(ret);
    system("cls");
}
