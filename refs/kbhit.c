// Source - https://stackoverflow.com/a/60270473
// Posted by Weather Vane
// Retrieved 2026-04-10, License - CC BY-SA 4.0

#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

#define TIMEOUT 0   // seconds

int main(void)
{
    clock_t tstart = clock();
    int v1 = 'y';                   // default key press
    while((clock() - tstart) / CLOCKS_PER_SEC < TIMEOUT) {
        if(kbhit()) {
            v1 = getch();
            break;
        }
    }
    if(tolower(v1) == 'y')
        printf("Example\n");
    return 0;
}
