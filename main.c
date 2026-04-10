#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

  /*
    Display mechanism:
    1. Idenfity 1d array as 2d using h and w var (matrix)
    2. Convert x,y input to identified 2d array index
    3. Convert width and height to identified 2d index array corresponding to the x,y
  */
int* create_arr_int(int n)
{
    int* arr = (int*)(malloc(n * sizeof(int)));
    return arr;
}

int main () {
  int* player_coord = create_arr_int(4);   //(x, y)
  int* player_pad = create_arr_int(4); //(w, h, counter_w, counter_h)
  int* canvas_size = create_arr_int(2);   //(w, h)
  int* virtual_coord = create_arr_int(2); //(x, y)
  char* matrix_arr;

  if (player_coord == NULL || canvas_size == NULL || virtual_coord == NULL) {
    return false;
  }

  player_coord[0] = 2;
  player_coord[1] = 1;
    player_coord[2] = player_coord[0];
  player_coord[3] = player_coord[1];

  player_pad[0] = 30;
  player_pad[1] = 5;
  player_pad[2] = 0;
  player_pad[3] = 0;

  canvas_size[0] = 64;
  canvas_size[1] = 16;

  virtual_coord[0] = 0;
  virtual_coord[1] = 0;
  
  matrix_arr = malloc(canvas_size[0] * canvas_size[1] * sizeof(char));

  if (matrix_arr == NULL) {
    return false;
  }

  printf("w: %d, h: %d \n", canvas_size[0], canvas_size[1]);
  printf("vx: %d, vy: %d \n", virtual_coord[0], virtual_coord[1]);
  printf("px: %d, py: %d \n", player_coord[0], player_coord[1]);

  for (int i = 0; i < canvas_size[0] * canvas_size[1]; i++) {

      matrix_arr[i] = '@';

      if (i >= canvas_size[0] * virtual_coord[1]) {
        virtual_coord[1]++;
        virtual_coord[0] = 0;
        player_pad[2] = 0;
       printf("\n");
      }

      if (virtual_coord[0] == player_coord[2] && virtual_coord[1] - 1  == player_coord[1]) {
          matrix_arr[i] = ' ';
          player_pad[2]++;

          if (player_pad[0] > player_pad[2]) {
            player_coord[2]++;
          } else if(player_pad[1] - 1 > player_pad[3]) {
            player_pad[3]++;
            player_coord[1]++;
            player_coord[2] = player_coord[0];
          }
      }

     //printf("%d \n", player_coord[0]);

      virtual_coord[0]++;

      printf("%c", matrix_arr[i]);
  }

  getchar();

  return 0;
}