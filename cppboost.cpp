//{Pre Processor Directives
//the following line is necessary for the GetConsoleWindow() function to work!
//It basically says that you are running this program on Windows 2000 or higher
//#define _WIN32_WINNT 0x0500
//It basically says that you are running this program on Windows Vista or higher
#define _WIN32_WINNT 0x0601

#include <iostream>
#include <iomanip>  // I used this for setw and setfill on text padding
#include <stdio.h>  // I used this for printf
#include <conio.h>  // I used this for getch()
#include <time.h>   // I used this for timer
#include <stdlib.h>     // I used this for randomizer
#include <sstream>      // I used this for stringstream in filetoint function
#include <windows.h>    // I used this for console modifier
#include <fstream>      // I used this for file reading
//}

//{Short Cut Codes

#define c_wait getch()
//#define clean system("cls")
#define say cout<<
#define input cin>>
#define work cout<<"Working!\t"

//}

//{Color Palletes Definitions
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

#define F_INTENSITY	8
#define B_INTENSITY	128

//How to use
//setcolor(F_WHITE | F_INTENSITY | B_BLACK);      << THis will make the font white in a different intensity. Black background

//}

//{Character Codes

#define WHITESMILE 1
#define BLACKSMILE 2
#define HEART      3
#define DIAMOND    4
#define CLUB       5
#define SPADE      6
#define TRIANGLE_LEFT 16
#define TRIANGLE_RIGHT 17
#define TRIANGLE_UP 30
#define TRIANGLE_DOWN 31
#define BLOCK 219
#define BLOCK2 178
#define BLOCK3 177
#define BLOCK4 176


//}

/*
    This is a Cplusplus Console Function Booster.

    This library contains most of the useful console modifier for everyone to use or learn from.
    I'm also a beginner C++ Coder. Most of the codes here are manually coded by me, but the functions like the font.
    Filestream and such are coded with the help of internet. In short, I don't want to own anything and this is a free for all library/script.

    To use this script, import this as a header in your code: #include "cppboost.cpp"
    With this script, you don't need to redeclare the headers already declared here

*/

//{ Tutorials   How to use the functions

///COORD getbuffersize(int Type);
//   Gets the available rows and columns in the console dimension.
//    |   Type = +0  ===   Gets the buffersize relative to window size
//    |   Type = 1  ===   Gets the buffersize based on the window full screen
//    |   Type = 2  ===   Gets the buffersize based on its max buffer size

///void fitbufferscreen()
//   Automatically sets the console output buffer size according to window size

///void clean()
//   According to some myths, using system("cls") is both unstable, slow and demanding. Use this function instead

///COORD getxy();
//   Gets the current position of the cursor in rows and columns. Returns as a coord value.

///void gotoxy(int X coordinate, int Y coordinate);
//   Position the cursor typepoint to an area.
//    |   X and Y Coordinate   ===   Position of Terminal to jump into

///void setcolor(int Color Code);
//   Change the cell color of text.
//    |   Color Code   ===   The code of the color bg and text combination. Run colorcodes() to check for color codes. Or refer to the Color Palletes Definitions at the start of this program

///bool getcolor(int Color Receiver, int X coordinate, int Y coordinate);
//   Get the cell color code of the current text coordinate.
//    |   Color Receiver       ===   The integer variable receiver of this function
//    |   X and Y coordinate   ===   The code of the color bg and text combination. Run colorcodes() to check for color codes.

///char getcursorchar(int X coordinate, int Y coordinate);
//   Get the cell letter of the current text coordinate. You could leave the coordinates blank or input a specific coordinate to check

///COORD mouseloc();
//   This function will locate the coordinates of the mouse cursor and return it to a COORD variable. It usually bugs the first time you initiate this and it is recommended to use this in a loop rather than a single initiation.

///int mouseclick();
//   This function will check if you click on the mouse and return the value to an int variable. It will return 1 if you click the left button, 2 for the right button and 0 if nothing is clicked.

///void activatemouse();
//   This function will set the comand prompt settings to make the mouse useable. It will deactivate the input text cursor, quickedit and insert mode on the console settings.

///int getresolution(char Position, int GetType);
//   Get the resolution (or coordinate) of your desired window
//    |   GetType = 0      ===    Screen Coordinate
//    |   GetType = 1      ===    Console Coordinate
//    |   Position = 't'   ===    Get the top coordinate
//    |   Position = 'b'   ===    Get the bottom coordinate
//    |   Position = 'l'   ===    Get the left coordinate
//    |   Position = 'r'   ===    Get the right coordinate

///void resizewindow(int GetType, int X coordinate, int Y coordinate, int Width, int Height);
//   Move and Resize the console
//    |   GetType = 0          ===    Full Screen v1 /// Generally unstable and only useable once. Don't fill other parameter
//    |   GetType = 1          ===    Custom /// Fill in the other parameters for implementation
//    |   GetType = 2          ===    Full Screen v2 /// May not work perfectly but is an alternative if Full Screen v1 does not work
//    |   X and Y Coordinate   ===   The Position of the console. Most of the time, the coordinate of the upperleft is (-6, -6)
//    |   Width and Height     ===   The Size of the screen from the X and Y coordinate

///void title(string Title);
//   Rename the console title

///void font(string FontName, int FontSize, int FontWeight, int FontStretch);
//   Change the font of the console.
//    |  FontName   ===   Change the typeface of the console. I tried and found that Arial, Times New Roman, Consolas, Lucida Console works here.
//    |  FontSize   ===   Change the font size of the console.
//    |  FontWeight   ===   Set the value below 700 for a normal font. Set above 700 for a bold font.
//    |  FontStretch   ===   The horizontal stretch value of the fonts.
//
//      Raster fonts are refered to as "Terminal" font. Raster fonts are the most complete font, containing all the available symbol for console.

///void padtext(string TextVariable, int Xstart, int Ystart, int Width, int Height);
//   Outputs a text with formatted margin. Automatically cuts text if it is too long for the given parameters.
//    |  TextVariable                 ===   The string variable to output
//    |  Margin Parameters (x,y,w,h)  ===   The box that will contain the said text.

///void dailogtext(string TextVariable, int Xstart, int Ystart, int Width, int Height, int TextSpeed);
//   Outputs a text with formatted margin. Automatically cuts text if it is too long for the given parameters.
//    |  TextVariable                 ===   The string variable to output
//    |  Margin Parameters (x,y,w,h)  ===   The box that will contain the said text.
//    |  Text Speed                   ===   The speed of how the text will be printed

///string filetostring(string FileName);
//   Read a file and return it as a single string to a variable <<< variable = filetostring("NewFile.txt"); >>>
//    |  FileName   ===   The file should be in the same folder.
//
//   Variable should be declared a string

///string filetostringpoint(string FileName, string ArrayReceiver, int LengthReceiver);
//   Read a file and return it to a string array to a variable <<< p = filetostring("NewFile.txt"); >>>
//    |  FileName          ===   The file should be in the same folder.
//    |  Array Receiver    ===   The variable receiver of the string arrays
//    |  Length Receiver   ===   The variable receiver of the array member count
//
//   Variable should be an integer pointer  <<< string *p >>>>
//   You could access the pointer p like an array <<< p[1] or p[2] and beyond >>>

///int filetointpoint(string FileName, int ArrayReceiver, int LengthReceiver);
//   Read a file and return it to an integer array to a variable <<< p = filetostring("NewFile.txt"); >>>
//    |  FileName          ===   The file should be in the same folder.
//    |  Array Receiver    ===   The variable receiver of the int arrays
//    |  Length Receiver   ===   The variable receiver of the array member count
//
//   Refer to the function howtousefiletoint() for proper implementation
//
//   Variable should be an integer pointer  <<< int *p >>>>
//   You could access the pointer p like an array <<< p[1] or p[2] and beyond >>>
//   Access like an array p[3] = "n" or as a pointer *(p+3) = "n"

///int filetomultiarray(string FileName, string StringArrayReceiver, int StringArrayLength, int IntArrayReceiver, int IntArrayLength)
//   Read a file and return it to an integer array to a variable <<< p = filetostring("NewFile.txt"); >>>
//    |  FileName               ===   The file should be in the same folder.
//    |  StringArrayReceiver    ===   The variable receiver of the string arrays
//    |  StringArrayLength      ===   The variable receiver of the string array member count
//    |  IntArrayReceiver       ===   The variable receiver of the int arrays
//    |  IntArrayLength         ===   The variable receiver of the int array member count
//
//   You'll need to use a dummy pointer variable to use this. Bur later on, you could instead array input variables here as the means of accessing the values

///void stringtofile(string TextBody, string FileName);
//   Take a single string and save it into a file.
//    |  TextBody   ===   The single string variable to save.
//    |  FileName   ===   The name of the file to save the string.
//
//   Variable should be a string

///void stringpointtofile(string *PointerString, int Range, string FileName);
//   Take an array(pointer) of string and save it into a file.
//    |  PointerString   ===   The pointer to a string array to save
//    |  Range           ===   The number of variables to save.
//    |  FileName        ===   The name of the file to save the string array.
//
//   Variable should be an array string <<<  string *p >>>
//   You could access the pointer p like an array <<< p[1] or p[2] and beyond >>>
//   Access like an array p[3] = "n" or as a pointer *(p+3) = "n"

///void intpointtofile(int *PointerInteger, int Range, string FileName);
//   Take an array(pointer) of string and save it into a file.
//    |  PointerInteger   ===   The pointer of integer pointer variable to save.
//    |  Range            ===   The number of variables to save.
//    |  FileName         ===   The name of the file to save the string.
//
//   Variable should be a string

///void createtextfile(string TextName, string PreincrementText);
//   Take an array(pointer) of string and save it into a file.
//    |  TextName             ===   The Name of the New File
//    |  Preincrement text   ===   The content of the new file
//
//   Variables should be a string

///void boxfill(int Color, int Width, int Height, int Xstart, int Ystart, char FillerText)
//   Fills a range with character and color
//    |  Color                           ===   The filler color
//    |  Width, Height, Xstart, Ystart   ===   The coordinates of the fill
//    |  Filler Text                     ===   The character to be used while filling

///void boxborder(int GetType = 0, int Width, int Height, int Color, int LineType ,int Xstart, int Ystart)
//    |  GetType                         ===   Border method.
//      | 0  =  will automatically create border based on window size
//      | 1  =  create a border based on given parameters
//    |  Width, Height, Xstart, Ystart   ===   The coordinates of the border
//    |  Color                           ===   The color of the border
//    |  Line Type                       ===   The border thickness that will be used
//      | 0  =  The border will have a thick line
//      | 1  =  The border will have a thin line

///void changecolor(int Color, int Width, int Height, int Xstart, int Ystart)
//   Fills a range with character and color
//    |  Color                           ===   The color to replace the coordinates
//    |  Width, Height, Xstart, Ystart   ===   The coordinates of the color change



///Available function-tutorials.
///These functions aren't useful but contains snippets of codes of how to implement the following:



///void coordfinder(int GetType)
// This program if called takes the coordinate of a cursor, then saves it to a text file
    // GetType = 0 : Do not change anything on the screen.
    // GetType = 1 : Sets the console to full screen. Text into Consolas, 18, normal stretch.
    // GetType = 2 : Calls a font and screen size editor before going to the screen itself

///void colorcodes()
// Calling this function will execute a program where it will show all color codes along with their bg and text color

///void asciitable(string fontName, int fontSize, int fontWeight, int Stretch)
// Calling this function will execute a program where it will show the conversion between integers and its char counterpart

///void time()
// How to use time function in C and C++

///void dice()
// How to make a random guess in C and C++. This includes srand(time(0)) so that the pseudo guesses will be trully random.

///void fillarray()
// Fill an entire char array with a char.

///void howtousefiletoint()
// Especially designed for users of filetoint function. Shows how to declare a pointer that will act as an array.

//}

//{ THE WHOLE BUNCH BELOW DECLARES THE FONT COMMAND
typedef struct _CONSOLE_FONT_INFOEX {
  ULONG cbSize;
  DWORD nFont;
  COORD dwFontSize;
  UINT  FontFamily;
  UINT  FontWeight;
  WCHAR FaceName[LF_FACESIZE];
} CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus

}
#endif
//}


using namespace std;

////////////////////////////////////{   Function Builds

/////////////////////////////////// Screen Buffer

COORD getbuffersize(int Type = 0){  ///Gets the available row and column of the console
    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    if ((GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))&&(Type == 1)){
        return cbsi.dwMaximumWindowSize;    //Max available space based on max window size and font size

    }

    else if ((GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))&&(Type == 0)){

        COORD coord;
        coord.X = cbsi.srWindow.Right;
        coord.Y = cbsi.srWindow.Bottom;
        return coord;               //Based on window size
    }

    else if ((GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))&&(Type == 2)){

        return cbsi.dwSize;                 //The max available screen buffer size
    }

    else{
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

void fitbufferscreen(){     ///Fits the screen size into the available row and column
    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))
    {
        SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), cbsi.dwMaximumWindowSize);}
}

void setbuffersize(string type = "max", int column = 120, int width = 40){   ///Set minimum buffer size

    if(type == "max"){

        string pc2 = "";

        string setter = "MODE CON COLS=";

        stringstream ss;
        ss << column;
        pc2 = ss.str();
        setter.append(pc2);
        setter += " LINES=";
        ss.str("");
        ss << width;
        pc2 = ss.str();
        setter.append(pc2);

        system("MODE CON COLS=140 LINES=40");
    }

    if(type == "min"){
    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))
    {
        SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), {short(column), short(width)});
        }
    }
}

void clean(){   ///Alternative and more friendly console screen cleaner
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
    SetConsoleCursorPosition(hConsole, coordScreen);
    return;
}

//////////////////////////////////// Cursor Manipulation

COORD getxy(){  ///Gets the current X and Y coordinate of the typepoint

    CONSOLE_SCREEN_BUFFER_INFO cbsi;

    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = { 0, 0 };
        return invalid;
    }
}

void qfill(char txt = ' ', int length = -1){   ///Best Character Spammer. Does not work well with loops.
    if(length == -1){ length = 1;}

    COORD coord = getxy();
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputCharacter(hConsole, txt, length, coord, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, coord, &cCharsWritten);
    return;
}


void qprint(string txt = " "){   ///Best Character Spammer. Does not work well with loops.

    int length = txt.length();

    COORD coord = getxy();
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    WriteConsoleOutputCharacter(hConsole, txt.c_str(), length, coord, &cCharsWritten);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, coord, &cCharsWritten);
    return;
}

void gotoxy(int x = 0, int y = 0){    ///Move to console position
    COORD coord = {0,0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(int x = 240){      ///Change text cell color
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}

bool getcolor(int &ret, int x = -1, int y = -1){    ///Gets the current color

        if((x != -1) && (y != -1)) gotoxy(x,y);

        CONSOLE_SCREEN_BUFFER_INFO info;
        if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info))
            return false;
        ret = info.wAttributes;
        return true;
}

char getcursorchar(int x = -1, int y = -1){ /// Function which returns character on console's cursor position || Totally not copied from the Internet

    char c = '\0';
    if(x != -1 && y != -1) gotoxy(x,y);
    CONSOLE_SCREEN_BUFFER_INFO con;
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hcon != INVALID_HANDLE_VALUE &&
        GetConsoleScreenBufferInfo(hcon,&con))
    {
        DWORD read = 0;
        if (!ReadConsoleOutputCharacterA(hcon,&c,1,
            con.dwCursorPosition,&read) || read != 1
            )
            c = '\0';
    }
    return c;
}

//////////////////////////////////// Mouse Interception

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

COORD mouseloc(){   /// Gets the mouse coordinates in rows and columns and returns it to a COORD variable
    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events;
    COORD coord;

    /*do{
    ReadConsoleInput(hin, &InputRecord, 1, &Events);

    coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
    coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

    FlushConsoleInputBuffer(hin);}while(coord.X == 1 && coord.Y == 0 );*/

    ReadConsoleInput(hin, &InputRecord, 1, &Events);

    switch ( InputRecord.EventType ){
        case MOUSE_EVENT: // mouse input
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            FlushConsoleInputBuffer(hin);
    }

    return coord;

}

bool mouseloc2(COORD &coord){   /// Gets the mouse coordinates in rows and columns and returns it to a COORD variable

    HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD InputRecord;
    DWORD Events;
    GetNumberOfConsoleInputEvents(hin, &Events);

    if(Events != 0){

    ReadConsoleInput(hin, &InputRecord, 1, &Events);

    coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
    coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;

    FlushConsoleInputBuffer(hin);}

    /*ReadConsoleInput(hin, &InputRecord, 1, &Events);

    switch ( InputRecord.EventType ){
        case MOUSE_EVENT: // mouse input
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            FlushConsoleInputBuffer(hin);
            break;
    }*/

    return 1;

}

int mouseclick(){   /// Checks for mouse clicks.

    if((GetKeyState(VK_LBUTTON) & 0x100) != 0) return 1;
    else if((GetKeyState(VK_RBUTTON) & 0x100) != 0) return 2;
    else return 0;

}

//////////////////////////////////// Window Size

int getresolution(char position = 'b', int type = 0){      ///Get Screen Resolution

    RECT dim;

    // 0 - Desktop
    // 1 - Console
    HWND handler = (type == 0 ? GetDesktopWindow() : GetConsoleWindow()); //call the screen to be recorded

    GetWindowRect(handler, &dim);

    switch (position){
        case 't': return dim.top; break;
        case 'b': return dim.bottom; break;
        case 'l': return dim.left; break;
        case 'r': return dim.right; break;
    }

}

void resizewindow(int type, int x = 0, int y = 0, int width = 800, int height = 600){   ///Move or Fullscreen Window

    HWND handler = GetConsoleWindow();
    COORD buff;

    buff.X = x;
    buff.Y = y;


    switch(type){
    case 0: ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); break; //Just make it fullscreen
    case 1: MoveWindow(handler, x, y, width, height, 1); break; //MoveWindow(window_handle, x, y, width, height, redraw_window); break;
    case 2: MoveWindow(handler, -6, -6, 800, 600, 1); Sleep(500); MoveWindow(handler, -6, -6, getresolution('r') + 25, getresolution('b') + 25, 1); break;    //Fullscreen method if case 0 does not work
    }

}

//////////////////////////////////// COnsole Title

void title(string name = "Leo Mark D.C Castro"){  ///Change console title
    string title = (name);
    SetConsoleTitle(title.c_str());
}

//////////////////////////////////// Font Manipulation

void font(string fnt = "Consolas", int y = 20, int weight = 400, int x = 0){   /// Changes the font of the console

    string narrow_string(fnt);
    wstring wide_string = wstring(narrow_string.begin(), narrow_string.end());
    const wchar_t* fontname = wide_string.c_str();

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof cfi;
    cfi.nFont = 0;
    cfi.dwFontSize.X = x;
    cfi.dwFontSize.Y = y;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = weight;
    wcscpy(cfi.FaceName, fontname);
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

//////////////////////////////////// Text Padding

void padtext(string textvar, int x, int y, int width, int height){  /// Outputs text with defined margin and automatically cuts character if needed

    int jump = 0;
    int letter = 0;

    int run = 1;

    while(run){
        gotoxy(x, y+jump);
        for(int i = 0; i < width; i++){
            if(textvar[letter] == '\n'){letter++; break;}
            else say textvar[letter];
            letter++;
            if (letter >= textvar.length()) {run = 0; break;}
        }
        jump++;
        if(jump >= height){break;}

    }
}

void dialogtext(string textvar, int x, int y, int width, int height, int speed){    ///Behaves like padtext but has text animation and text continuation if too long

    int jump = 0;
    int letter = 0;

    int run = 1;

    while(run){
        gotoxy(x, y+jump);
        for(int i = 0; i < width; i++){
            Sleep(speed);

            if(kbhit()){
                char inp;
                inp = getch();

                switch(inp){
                    //case '+': speed += 10; break;
                    case ' ': speed = 0; break;
                    //default: speed = 0; break;
                }
            }

            if(textvar[letter] == '\n'){letter++; break;}
            else say textvar[letter];
            letter++;
            if (letter >= textvar.length()) {run = 0; break;}
        }
        jump++;

        if(jump >= height){
            int jump2 = 0;
            int reset = 1;
            getch();
            while(reset){
            gotoxy(x,y + jump2);
            for(int i = 0; i < width ; i++) {
                cout << ' ';
            }
            jump2++;
            if (jump2 >= height) {reset = 0;}
            jump = 0;}
        }
    }
    c_wait;
}

//////////////////////////////////// File Importing

string filetostring(string fileName = "save.txt"){  /// Read a file and put it to a single string variable

    string getContent;
    string output;

    ifstream inFile;
    inFile.open(fileName.c_str());

    if(!inFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(inFile.is_open())
    {
        while(! inFile.eof())
        {
            getline(inFile, getContent);
            output.append(getContent);
            output.append("\n");
        }
    }

    inFile.close();
    return output;
}

string * filetostringpoint(string fileName, string *arr, int &lngth){  /// Read a file and put it to an array string variable

    lngth = 0;

    string getContent;

    ifstream inFile;
    inFile.open(fileName.c_str());

    if(!inFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(inFile.is_open())
    {

        while(! inFile.eof())
        {
            getline(inFile, getContent);
            arr[lngth] = getContent;
            lngth++;
        }
    }

    inFile.close();
    return arr;

}

int * filetointpoint(string fileName, int *arr ,int &lngth){  /// Read a file and put it io a pointer <or an array variable>. REFER TO howtousefiletoint fx

    lngth = 0;

    string getContent;

    ifstream inFile;
    inFile.open(fileName.c_str());

    if(!inFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(inFile.is_open())
    {

        while(! inFile.eof())
        {
            getline(inFile, getContent);
            istringstream iss (getContent);
            iss >> arr[lngth];
            lngth++;
        }
    }

    inFile.close();
    return arr;
}

int * filetomultiarray(string fileName, string *sarr, int &slngth, int *iarr, int &ilngth ){  /// Reads a file and puts the data in accordance to respective array

    ilngth = slngth = 0;
    int savetype = 0;

    string getContent;

    ifstream inFile;
    inFile.open(fileName.c_str());

    if(!inFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(inFile.is_open())
    {

        while(! inFile.eof())
        {
            if(savetype == 0){
            getline(inFile, getContent);
            if(getContent == "ENDSTRING"){
                savetype = 1;}
            else{
                sarr[slngth] = getContent;
                slngth++;}}

            if(savetype == 1){
            getline(inFile, getContent);
            istringstream iss (getContent);
            iss >> iarr[ilngth];
            ilngth++;
            }
        }
    }

    inFile.close();
    return iarr;

}

void howtousefiletoint(int i){ /// Refer to this on how to implement filetoint fx.

    int *p;
    int l = 10;
    //p = filetointpoint("save.txt", l);

    //p = filetostringpoint();
    //stringpointtofile(p, 4);

    //setcolor(14); cout << p[i];

}

//////////////////////////////////// File Exporting

void stringtofile(string textz, string fileName = "save.txt"){  /// Take a string and put it into a file

    ofstream outFile;
    outFile.open(fileName.c_str());

    if(!outFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(outFile.is_open())
    {
        outFile << textz;
    }

    outFile.close();
}

void stringpointtofile(string *p, int pnum = 100, string fileName = "save.txt") {  /// Take an array of string and put it into a file

    ofstream outFile;
    outFile.open(fileName.c_str());

    if(!outFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(outFile.is_open())
    {
        for(int i = 0; i < pnum; i++) outFile << p[i] << ((i >= (pnum - 1)) ? "" : "\n");
    }

    outFile.close();

}

void intpointtofile(int *p, int pnum = 100, string fileName = "save.txt"){  /// Take an array of int and put it into a file list

    string pc = "";
    string pc2 = "";

    for(int i = 0; i < pnum; i++){
        stringstream ss;
        ss << *(p+i);
        pc2 = ss.str();
        pc.append(pc2);
        (i != (pnum - 1)) ? pc.append("\n") : pc.append("");
    }

    ofstream outFile;
    outFile.open(fileName.c_str());

    if(!outFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(outFile.is_open())
    {
        outFile << pc;
    }

    outFile.close();

}

void multiarraytofiole(string *sarr, int &slngth, int *iarr, int &ilngth, string fileName = "save.txt"){  /// Take an array of int and put it into a file list

    ofstream outFile;
    outFile.open(fileName.c_str());

    string pc = "";
    string pc2 = "";

    for(int i = 0; i < ilngth; i++){
        stringstream ss;
        ss << *(iarr+i);
        pc2 = ss.str();
        if(pc2 != " "){
        pc.append(pc2);
        (i != (ilngth - 1)) ? pc.append("\n") : pc.append("");}
    }

    if(!outFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(outFile.is_open())
    {
        for(int i = 0; i < slngth; i++) outFile << sarr[i] << ((i >= (slngth - 1)) ? "\nENDSTRING\n" : "\n");
        outFile << pc;

    }

    outFile.close();





}

//////////////////////////////////// File Creation

void createtextfile(string name = "save.txt", string incr = ""){  /// Creates a textfile on the folder this code belongs. Can also put text inside.
    ofstream outfile (name.c_str());

    outfile << incr;

    outfile.close();
}

//////////////////////////////////// Utility Functions

void colorcodes(){  /// Shows the color codes useable for setcolor() function along with their bg color and text color
    system("cls");
    system("Color 0F");
    resizewindow(1, -6, -6);
    resizewindow(1, -6, -6, getresolution('r'), getresolution('b'));
    Sleep(500);
    font("Consolas", 25);
    for(int i = 0; i < 256; i++){
        setcolor(i); cout << i << "\t";
        if(i % 16 == 15) cout << endl;
    }
}

void asciitable(string fontName = "Terminal", int fontSize = 20, int fontWeight = 400, int Stretch = 0){  /// Shows the conversion of char into int
    system("cls");
    system("Color F0");
    resizewindow(1, -6, -6);
    resizewindow(1, -6, -6, getresolution('r'), getresolution('b'));
    Sleep(500);font(fontName, fontSize, fontWeight, Stretch);
    int k = 0;
    cout << "Integer -> Character";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 27; j++, k++){
        gotoxy((12*i),(j+1)); cout << k << " -> " << char(k) << "\n";
        if(k == 256) break;
    }
    }
}

void coordfinderkb(int type = 0){     ///Calls the coord finder but uses keyboard

    char inp = ' ';
    string filename, fontname;
    int x1,y1,x2,y2;
    int fsz,fw,fst;

    filename = "xy.txt";

    if (inp == 1){  // Clears and sets the console to full screen.
        say "Full Screen. Consolas. Fontsize 18. No stretch. Will be saved as 'xy.txt'";
        system("cls");
        system("Color 0F");
        filename = "xy.txt";
        font("Consolas", 18, 400);
        Sleep(500);
        resizewindow(1, -6, -3);
        resizewindow(1,-6,-3,getresolution('r')+20, getresolution('b')+20);
    }

    if (inp == 2){ // Sets parameters of screen before proceeding
        system("cls");
        system("Color 0F");
        say "\nWhere to save *must end in .txt: "; input filename;
        say "\n\nScreen Size";
        say "\n  |X: "; input x1;
        say "  |Y: "; input y1;
        say "  |Width: "; input x2;
        say "  |Height: "; input y2;
        say "\n\nFont";
        say "\n  |Font Name: ";
        cin.ignore(100, '\n');
        getline(cin, fontname);
        say "  |Font Size: "; input fsz;
        say "  |Font Weight: "; input fw;
        font(fontname, fsz, fw);
        Sleep(500);
        resizewindow(1, x1, y1);
        resizewindow(1,x1,y1,x2,y2);
    }

    int run = 1;
    char below;
    int belowcolor;
    int x = 0;
    int y = 0;

    int coords[100][2];

    int counter = 0;

    if (type != 0) clean;

    while(run){

        gotoxy(0,0); printf("%3i - %3i | Coord Finder", x, y);

        gotoxy(x,y); below = getcursorchar(); getcolor(belowcolor);
        say char(43);
        //gotoxy(x + 1, y + 1); printf("x:%3i y:%3i", x, y);

        inp = getch();
        gotoxy(x,y); say below; setcolor(belowcolor);
        //gotoxy(x + 1, y + 1); say "           ";

        switch(inp){
            case 'w': if(y > 0) y--; break;
            case 's': y++; break;
            case 'a': if(x > 0) x--; break;
            case 'd': x++; break;
            case ' ': {
                gotoxy(x,y); say counter;
                coords[counter][0] = x;
                coords[counter][1] = y;
                counter++;
                break;}
            case '\r': run = 0; break;
        }

    }

    string pc, pc2;


    for(int i = 0; i < counter; i++){

            stringstream ss;
            ss << i+1 << ". " << coords[i][0] << " " << coords[i][1];
            pc2 = ss.str();
            pc.append(pc2);
            (i != (counter - 1)) ? pc.append("\n") : pc.append("");}

    ofstream outFile;
    outFile.open(filename.c_str());

    if(!outFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(outFile.is_open())
    {
        outFile << pc;
    }

    outFile.close();


}

void coordfindermouse(int type = 0){    ///Calls the coords finder but uses mouse

    activatemouse();

    char inp = ' ';
    string filename, fontname;
    int x1,y1,x2,y2;
    int fsz,fw,fst;

    filename = "xy.txt";

    if (inp == 1){  // Clears and sets the console to full screen.
        say "Full Screen. Consolas. Fontsize 18. No stretch. Will be saved as 'xy.txt'";
        system("cls");
        system("Color 0F");
        filename = "xy.txt";
        font("Consolas", 18, 400);
        Sleep(500);
        resizewindow(1, -6, -3);
        resizewindow(1,-6,-3,getresolution('r')+20, getresolution('b')+20);
    }

    if (inp == 2){ // Sets parameters of screen before proceeding
        system("cls");
        system("Color 0F");
        say "\nWhere to save *must end in .txt: "; input filename;
        say "\n\nScreen Size";
        say "\n  |X: "; input x1;
        say "  |Y: "; input y1;
        say "  |Width: "; input x2;
        say "  |Height: "; input y2;
        say "\n\nFont";
        say "\n  |Font Name: ";
        cin.ignore(100, '\n');
        getline(cin, fontname);
        say "  |Font Size: "; input fsz;
        say "  |Font Weight: "; input fw;
        font(fontname, fsz, fw);
        Sleep(500);
        resizewindow(1, x1, y1);
        resizewindow(1,x1,y1,x2,y2);
    }

    int run = 1;
    char below;
    int belowcolor;
    int x = 0;
    int y = 0;

    int coords[100][2];

    int counter = 0;

    if (type != 0) clean;

    COORD mouse;


    while(run){

        mouse = mouseloc();

        gotoxy(0,0); printf("%3i - %3i | Coord Finder", mouse.X, mouse.Y);

        if(mouseclick() == 1){
            coords[counter][0] = mouse.X;
            coords[counter][1] = mouse.Y;
            gotoxy(mouse.X, mouse.Y); say counter;
            counter++;
        }

        if(mouseclick() == 2){
            run = 0;
        }

    }

    string pc, pc2;


    for(int i = 0; i < counter; i++){

            stringstream ss;
            ss << i+1 << ". " << coords[i][0] << " " << coords[i][1];
            pc2 = ss.str();
            pc.append(pc2);
            (i != (counter - 1)) ? pc.append("\n") : pc.append("");}

    ofstream outFile;
    outFile.open(filename.c_str());

    if(!outFile.is_open()){
        cout << "Error reading. Try renaming.";
    }

    if(outFile.is_open())
    {
        outFile << pc;
    }

    outFile.close();

}

//////////////////////////////////// Graphical Manipulations

void cleanarea(int x, int y, int width, int height, int color){   ///Alternative and more friendly console screen cleaner

    setcolor(color);

    for(int i = y, j = x; i < height + y; i++){
        gotoxy(j, i); qfill(' ', width + x);
        }

}

void boxfill(int color = -1, int width = 20, int height = 20, int x = -1, int y = -1, char filltext = ' '){  ///Creates a box of color in a range

    int ret;

    getcolor(ret);

    if(color == -1) {getcolor(color);}
    if(x == -1) {x = getxy().X;}
    if(y == -1) {y = getxy().Y;}

    setcolor(color);
    for(int y2 = 0, x2 = 0; y2 < height; y2++){
        gotoxy(x, y+y2); qfill(filltext, width);
    }

    setcolor(ret);

}

void boxborder(int GetType = 0, int width = 20, int height = 20, int color = -1, int linetype = 0 ,int x = -1, int y = -1){ /// Creates a border
    int ret;
    getcolor(ret);

    if(color == -1) {getcolor(color);}
    if(x == -1) {x = getxy().X;}
    if(y == -1) {y = getxy().Y;}

    setcolor(color);

    if(GetType == 1){
        width = getbuffersize().X+1;
        height = getbuffersize().Y+1;
        for(int y2 = 0; y2 < height; y2++){
            for(int x2 = 0; x2 < width; x2++){
                if(y2 == 0 && x2 == 0) {gotoxy(x+x2, y+y2); qfill((linetype == 0) ? char(201) : char(218));}
                else if((y2 == height - 1) && (x2 == width -1)) {gotoxy(x+x2, y+y2); qfill((linetype == 0) ? char(188) : char(217));}
                else if((y2 == height - 1) && (x2 == 0)) {gotoxy(x+x2, y+y2); qfill((linetype == 0) ? char(200) : char(192));}
                else if((y2 == 0) && (x2 == width - 1)) {gotoxy(x+x2, y+y2); qfill((linetype == 0) ? char(187) : char(191));}
                else if(((y2 == 0)||(y2 == height - 1)) && (x2 != width - 1) && (x2 != 0)) {gotoxy(x+x2, y+y2); qfill((linetype == 0) ? char(205) : char(196));}
                else if(((x2 == 0)||(x2 == width - 1)) && (y2 != height - 1) && (y2 != 0)) {gotoxy(x+x2, y+y2); qfill((linetype == 0) ? char(186) : char(179));}
            }
        }
    }

    else if(GetType == 0){
        for(int y2 = 0; y2 < height; y2++){
            for(int x2 = 0; x2 < width; x2++){
                if(y2 == 0 && x2 == 0) {gotoxy(x+x2, y+y2); say ((linetype == 0) ? char(201) : char(218));}
                else if((y2 == height - 1) && (x2 == width -1)) {gotoxy(x+x2, y+y2); say ((linetype == 0) ? char(188) : char(217));}
                else if((y2 == height - 1) && (x2 == 0)) {gotoxy(x+x2, y+y2); say ((linetype == 0) ? char(200) : char(192));}
                else if((y2 == 0) && (x2 == width - 1)) {gotoxy(x+x2, y+y2); say ((linetype == 0) ? char(187) : char(191));}
                else if(((y2 == 0)||(y2 == height - 1)) && (x2 != width - 1) && (x2 != 0)) {gotoxy(x+x2, y+y2); say ((linetype == 0) ? char(205) : char(196));}
                else if(((x2 == 0)||(x2 == width - 1)) && (y2 != height - 1) && (y2 != 0)) {gotoxy(x+x2, y+y2); say ((linetype == 0) ? char(186) : char(179));}
            }
        }
    }
    setcolor(ret);
}

void changecolor(int color = -1, int width = 20, int height = 20, int x = -1, int y = -1){   ///Changes color of characters. Does not work with space

    if(color == -1) {getcolor(color);}
    if(x == -1) {x = getxy().X;}
    if(y == -1) {y = getxy().Y;}

    COORD spot = {short(x),short(y)};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD Written;

    for(int i = 0; i < height; i++){
        FillConsoleOutputAttribute(hOut, color, width, spot, &Written);
        spot.Y++;
    }
}

//////////////////////////////////// Sample Functions

void time(){ ///More like a reference rather than an actual function
    clock_t tick;

    tick = clock();
}

void dice(){  ///More like a reference rather than an actual function
    srand(time(0));

    gotoxy(10,10); int x = rand();

    cout << x << "s";
}

void fillarray(){   ///More like a reference rather than an actual function

    char box[20][10];

    //start of box, end of box, number of char to be incremented
    fill(&box[0][0], &box[0][0] + sizeof(box), 65);
}

////////////////////////////////////}

int cppboost(){

    title("C++ Swiss Knife *yeah*");
    system("color 0F");
    font();
    resizewindow(0);
    Sleep(500);

    string codes[] = {
        "colorcodes - show the table of color codes",
        "asciitable - shows the table of ascii characters",
        "coordfinder - takes the coordinate of a cursor, then saves it to a text file",
        "----------------",
        "getxy - gets the x and y coordinate of the type point",
        "gotoxy - positions your type point",
        "setcolor - changes the following text cells color",
        "getcolor - gets the current cursor's color code",
        "getcursorchar - gets the current cursor's current character",
        "getresolution - gets the size of either the display screen or the console",
        "resizewindow - can move or resize the console",
        "title - changes the title of the console",
        "font - changes the font style of the console",
        "padtext - writes a string with a margin and padding",
        "dialoguetext - works like padtext, but dialogue text allows string longer than margin and can be worked with animation",
        "filetostring - reads a file and transfers it into a single string variable",
        "filetostringpoint - reads a file and transfers it into an array of string variable",
        "filetointpoint - reads a file and transfers it into a array of integer variable",
        "stringtofile - outputs a single string to a file",
        "stringpointtofile - outputs an array of string to a file",
        "intpointtofile - outputs an array of integer to a file",
        "createtextfile - creates a new textfile",
        "getbuffersize - gets the available row and column of the console",
        "fitbufferscreen - resizes the buffer coordinates according to font and window size",
        "boxfill - fills a range with specific color and character",
        "boxborder - creates a border based on user parameters",
        "changecolor - changes the text attribute of a range. Works at all characters except space and newline.",
        "clean - cleans the entire screen out of text",
        "cleanarea- cleans a specific area of the console",
        "activatemouse - function that activates the mouse useability",
        "mouseloc - gets the coordinate of the mouse cursor relative to console rows and column",
        "mouseclick - gets the click state of the mouse"
    };

    cout << "\n\n  This is a compilation of all the cosole modifying function of C++\n";
    cout << "  Codes by Leo Mark && internet\n\n";
    cout << "  Codes Available: \n" << endl;
    for(int i = 0; i < 32; i++) cout << "  " << i+1 << ". " << codes[i] << endl;

    boxborder(1, getbuffersize().X, getbuffersize().Y, -1, 0, 0, 0);

    getch();
    setcolor(F_BLACK);

    return 0;
}

///REMOVE MAIN BEFORE USING THIS AS A HEADER FILE!!!
