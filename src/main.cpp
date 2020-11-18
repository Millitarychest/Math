#include <fxcg/display.h>
#include <fxcg/keyboard.h>

int main() {
    PrintXY(3, 8, "--Hello World!", TEXT_MODE_NORMAL, TEXT_COLOR_RED); // Place it somewhere on the screen
    int key;
    while (1)
        GetKey(&key); // Loop forever

    return 0;
}

string derivativeNorm() {
    char* buffer = (char*)malloc(256); // Some string length
    int start = 0; // Used for scrolling left and right
    int cursor = 0; // Cursor position

    buffer[0] = '\0'; // This sets the first character to \0, also represented by "", an empty string

    DisplayMBString((unsigned char*)buffer, start, cursor, 1, 1); // Last to parameters are X,Y coords (not in pixels)

    int key;
    while (1)
    {
        GetKey(&key); // Blocking is GOOD.  This gets standard keys processed and, possibly, powers down the CPU while waiting

        if (key == KEY_CTRL_EXE)
        {
            // Ok
            break;
        }
        else if (key == KEY_CTRL_EXIT)
        {
            // Aborted
            break;
        }
        if (key && key < 30000)
        {
            cursor = EditMBStringChar((unsigned char*)buffer, 256, cursor, key);
            DisplayMBString((unsigned char*)buffer, start, cursor, 1, 1);
        }
        else
        {
            EditMBStringCtrl((unsigned char*)buffer, 256, &start, &cursor, &key, 1, 1);
        }
    }
}

