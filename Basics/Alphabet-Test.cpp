#define WINVER 0x0500
#include <windows.h>

void keyboard(int keyCode) {
    // This structure for input event.
    INPUT ip;
 
    // Delay
    Sleep(20);
 
    // Set up a generic keyboard event.
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;
 
    // Press key
    ip.ki.wVk = keyCode; // virtual-key code for the "a" key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
 
    // Release key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

int main() {
    for (int i = 0; i < 26; i++)
        keyboard(0x41 + i);

    return 0;
}