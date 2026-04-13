// Source - https://stackoverflow.com/a/60270473
// Posted by Weather Vane
// Retrieved 2026-04-10, License - CC BY-SA 4.0

#include <conio.h>
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int key = 0;
    while(1) {
        if (kbhit()) {
            key = getch();
        }

        switch (key)
        {
        case 35:
            printf("# Pressed \n");
            break;
        case 72:
            printf("Up arrow pressed \n");
            break;
        case 75:
            printf("Left arrow pressed \n");
            break;
        case 77:
            printf("Right arrow pressed \n");
            break;
        case 80:
            printf("Down arrow pressed \n");
            break;
        default:
            break;
        }
    key = 0;
    }
}
