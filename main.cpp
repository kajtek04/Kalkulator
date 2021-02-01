#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include<string>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

HWND liczba;
HWND button1, button2, button3, button4, button5, button6, button7, button8, button9, button0;
HWND buttonClear, buttonPlus, buttonEqual, buttonMinus, buttonMulti, buttonDivis, buttonDot, buttonErase, buttonSquare, buttonsqrt;
std::string text1, text2;
long double num1, num2;
bool des, IsSwapped=false;
char op;


/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Kalkulator"),       /* Title Text */
           WS_MINIMIZEBOX | WS_SYSMENU, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           290,                 /* The programs width */
           420,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

void operation(char oper){
    IsSwapped=false;
    text2=text1;
    text1.clear();
    op=oper;
}



/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {

        case WM_CREATE:

            liczba = CreateWindow("STATIC",
                        text1.c_str(),
                        WS_VISIBLE | WS_CHILD | WS_BORDER,
                        20, 20, 230, 20,
                        hwnd, NULL, NULL, NULL);
            button0 = CreateWindow("BUTTON",
                            "0",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            80, 310, 50, 50,
                            hwnd, (HMENU) 0, NULL, NULL);
            button1 = CreateWindow("BUTTON",
                            "1",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 250, 50, 50,
                            hwnd, (HMENU) 1, NULL, NULL);
            button2 = CreateWindow("BUTTON",
                            "2",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            80, 250, 50, 50,
                            hwnd, (HMENU) 2, NULL, NULL);
            button3 = CreateWindow("BUTTON",
                            "3",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            140, 250, 50, 50,
                            hwnd, (HMENU) 3, NULL, NULL);
            button4 = CreateWindow("BUTTON",
                            "4",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 190, 50, 50,
                            hwnd, (HMENU) 4, NULL, NULL);
            button5 = CreateWindow("BUTTON",
                            "5",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            80, 190, 50, 50,
                            hwnd, (HMENU) 5, NULL, NULL);
            button6 = CreateWindow("BUTTON",
                            "6",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            140, 190, 50, 50,
                            hwnd, (HMENU) 6, NULL, NULL);
            button7 = CreateWindow("BUTTON",
                            "7  ",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 130, 50, 50,
                            hwnd, (HMENU) 7, NULL, NULL);
            button8 = CreateWindow("BUTTON",
                            "8",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            80, 130, 50, 50,
                            hwnd, (HMENU) 8, NULL, NULL);
            button9 = CreateWindow("BUTTON",
                            "9",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            140, 130, 50, 50,
                            hwnd, (HMENU) 9, NULL, NULL);
            buttonClear = CreateWindow("BUTTON",
                            "C",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 310, 50, 50,
                            hwnd, (HMENU) 10, NULL, NULL);
            buttonEqual = CreateWindow("BUTTON",
                            "=",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            200, 310, 50, 50,
                            hwnd, (HMENU) 11, NULL, NULL);
            buttonPlus = CreateWindow("BUTTON",
                            "+",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            200, 70, 50, 50,
                            hwnd, (HMENU) 12, NULL, NULL);
            buttonMinus = CreateWindow("BUTTON",
                            "-",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            200, 130, 50, 50,
                            hwnd, (HMENU) 13, NULL, NULL);
            buttonMulti=CreateWindow("BUTTON",
                            "x",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            200, 190, 50, 50,
                            hwnd, (HMENU) 14, NULL, NULL);
            buttonDivis=CreateWindow("BUTTON",
                            "÷",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            200, 250, 50, 50,
                            hwnd, (HMENU) 15, NULL, NULL);
            buttonDot=CreateWindow("BUTTON",
                            ".",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            140, 310, 50, 50,
                            hwnd, (HMENU) 16, NULL, NULL);
            buttonErase=CreateWindow("BUTTON",
                            "<-",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            140, 70, 50, 50,
                            hwnd, (HMENU) 17, NULL, NULL);
            buttonSquare=CreateWindow("BUTTON",
                            "CA",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            80, 70, 50, 50,
                            hwnd, (HMENU) 18, NULL, NULL);
            buttonsqrt=CreateWindow("BUTTON",
                            "+/-",
                            WS_VISIBLE | WS_CHILD | WS_BORDER,
                            20, 70, 50, 50,
                            hwnd, (HMENU) 19, NULL, NULL);

        break;

        case WM_COMMAND:

            des=DestroyWindow(liczba);

            switch(LOWORD(wParam)){

                case 0: text1.push_back('0'); break;
                case 1: text1.push_back('1'); break;
                case 2: text1.push_back('2'); break;
                case 3: text1.push_back('3'); break;
                case 4: text1.push_back('4'); break;
                case 5: text1.push_back('5'); break;
                case 6: text1.push_back('6'); break;
                case 7: text1.push_back('7'); break;
                case 8: text1.push_back('8'); break;
                case 9: text1.push_back('9'); break;

                case 16: if(text1[text1.size()-1]!='.')text1.push_back('.'); break;

                case 10: text1.clear(); break;// czyszczenie C
                case 17: if(text1.size()>0)text1.pop_back(); break;
                case 18: text1.clear(); text2.clear(); break;

                case 11:

                    if(text2.size()!=0){
                        if(!IsSwapped) {
                            swap(text1, text2);
                            IsSwapped=true;
                        }
                        num1=stold(text1);
                        num2=stold(text2);

                        switch(op){
                            case '+': num1+=num2; break;
                            case '-': num1-=num2; break;
                            case 'x': num1*=num2; break;
                            case 'd': num1/=num2; break;
                        }
                        text1=std::to_string(num1);
                        while(text1[text1.size()-1]==48) text1.pop_back();
                        if(text1[text1.size()-1]=='.')text1.pop_back();
                    }

                break;

                case 12: operation('+'); break;
                case 13: operation('-'); break;
                case 14: operation('x'); break;
                case 15: operation('d'); break;

                case 19:
                    if(text1[0]=='-') text1.erase(0, 1);
                    else text1.insert(0, "-");

                break;

            }

            liczba =CreateWindow("STATIC",
                    text1.c_str(),
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    20, 20, 230, 20,
                    hwnd, NULL, NULL, NULL);


        break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
