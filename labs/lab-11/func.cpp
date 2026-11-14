#include <iostream>
#include <cstring>
#include <iomanip>

#ifdef _WIN32
#include <windows.h>
#endif

int myStrLen(const char s[]) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void myStrCpy(char dst[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

bool myStrEqual(const char a[], const  char b[]) {
    int i = 0;
    while (a[i] == b[i]) {
        if (a[i] == '\0') {
            return true;
        }
        i++;
    }
    return false;
}

void myStrReverse(char s[]) {
    int left = 0;
    int right = myStrLen(s) - 1;

    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}



int main() {
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

}