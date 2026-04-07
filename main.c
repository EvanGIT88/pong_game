#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    //keypress input
    int ch;

    //canvas size
    int canvas_h;
    int canvas_w;

    //pad coordinate
    int player_x;
    int player_y;
    int pad_size;

        //identifier
    int x = 0;
    int y = 0;

    //matrices array
    char *matrix_ptr;

    //mllocation
    int *canvas_h_ptr = &canvas_h;
    int *canvas_w_ptr = &canvas_w;
    canvas_h_ptr = malloc(sizeof(int));
    canvas_w_ptr = malloc(sizeof(int));

    int *player_x_ptr = &player_x;
    int *player_y_ptr = &player_y;
    int *pad_size_ptr = &pad_size;
    player_x_ptr = malloc(sizeof(int));
    player_y_ptr = malloc(sizeof(int));
    pad_size_ptr = malloc(2 * sizeof(int));

    //set canvas size
    canvas_h = 16;
    canvas_w = 32;

    matrix_ptr = malloc((canvas_h * canvas_w) * sizeof(char));
    
    if (!canvas_h_ptr || !canvas_w_ptr || !player_x_ptr || !player_y_ptr || !pad_size_ptr || !matrix_ptr) {
      printf("Allocation failed");
      return 1;
    }

    //set starting coordinate
    player_x = 1;
    player_y = 1;
    pad_size_ptr[0] = 1; //width
    pad_size_ptr[1] = 5; //height

    /*
     1. Idenfity 1d array as 2d using h and w var (matrix)
     2. Convert x,y input to identified 2d array index
     3. Convert width and height to identified 2d index array corresponding to the x,y
    */

    while ((ch = getch()) != '#'){
        for (int i = 0; i < canvas_h * canvas_w; i++) {
          if (i >= canvas_w) {
            y++;
            x = 0;
          }

          if (x == player_x && y == player_y) {
             matrix_ptr[i] = '|';
          }
         
          x++;
          
          printf("%c", matrix_ptr[i]);
        }
            
    }

    return 0;
}