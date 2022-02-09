#include <Windows.h>

// Move to right edge then down 
int main() {
    int curX = 0;
    int curY = 0;

    for (curX; curX < 1920; curX++) {
        SetCursorPos(curX, curY);
    }

    for (curY; curY < 1080; curY++) {
        SetCursorPos(curX, curY);
    }
    
    return 0;
}