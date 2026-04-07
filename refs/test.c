// Source - https://stackoverflow.com/a/75499310
// Posted by Scott, modified by community. See post 'Timeline' for change history
// Retrieved 2026-04-05, License - CC BY-SA 4.0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
   int ch;

   printf("Press # to Exit\n");

   while ((ch = getch()) != '#'){
    printf("%d", getch());
      if (ch == 0 || ch == 224) {
         switch (getch()) {
            case 72:
               printf("\nUp Arrow");
               break;
            case 80:
               printf("\nDown Arrow");
               break;
            case 77:
               printf("\nRight Arrow");
               break;
            case 75:
               printf("\nLeft Arrow");
               break;
         }
      }
   }

   return 0;
}
