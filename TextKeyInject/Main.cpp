#include <iostream>
#include <map>
#include <string>
#include <iostream> 
#include <fstream>
#include <windows.h>

#define WINVER 0x0500

constexpr unsigned int SMALL_a = 0x41;
constexpr unsigned int SMALL_b = 0x42;
constexpr unsigned int SMALL_c = 0x43;
constexpr unsigned int SMALL_d = 0x44;
constexpr unsigned int SMALL_e = 0x45;
constexpr unsigned int SMALL_f = 0x46;
constexpr unsigned int SMALL_g = 0x47;
constexpr unsigned int SMALL_h = 0x48;
constexpr unsigned int SMALL_i = 0x49;
constexpr unsigned int SMALL_j = 0x4A;
constexpr unsigned int SMALL_k = 0x4B;
constexpr unsigned int SMALL_l = 0x4C;
constexpr unsigned int SMALL_m = 0x4D;
constexpr unsigned int SMALL_n = 0x4E;
constexpr unsigned int SMALL_o = 0x4F;
constexpr unsigned int SMALL_p = 0x50;
constexpr unsigned int SMALL_q = 0x51;
constexpr unsigned int SMALL_r = 0x52;
constexpr unsigned int SMALL_s = 0x53;
constexpr unsigned int SMALL_t = 0x54;
constexpr unsigned int SMALL_u = 0x55;
constexpr unsigned int SMALL_v = 0x56;
constexpr unsigned int SMALL_w = 0x57;
constexpr unsigned int SMALL_x = 0x58;
constexpr unsigned int SMALL_y = 0x59;
constexpr unsigned int SMALL_z = 0x5A;

std::map<char, unsigned int> smallAlphaLUT{
    {'a', SMALL_a},
    {'b', SMALL_b},
    {'c', SMALL_c},
    {'d', SMALL_d},
    {'e', SMALL_e},
    {'f', SMALL_f},
    {'g', SMALL_g},
    {'h', SMALL_h},
    {'i', SMALL_i},
    {'j', SMALL_j},
    {'k', SMALL_k},
    {'l', SMALL_l},
    {'m', SMALL_m},
    {'n', SMALL_n},
    {'o', SMALL_o},
    {'p', SMALL_p},
    {'q', SMALL_q},
    {'r', SMALL_r},
    {'s', SMALL_s},
    {'t', SMALL_t},
    {'u', SMALL_u},
    {'v', SMALL_v},
    {'w', SMALL_w},
    {'x', SMALL_x},
    {'y', SMALL_y},
    {'z', SMALL_z},
};

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
    char currChar;
    std::fstream fs{ "./Text/Test.txt" }; 

    while (fs >> currChar) { 
        keyboard(smallAlphaLUT[currChar]); 
    }
}