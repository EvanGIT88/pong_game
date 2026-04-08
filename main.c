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

//int* canvas_size_addr, int* virtual_coord_addr, int* matrix_arr_addr

bool setup(int *player_coord_addr, int *canvas_size_addr, int *virtual_coord_addr, char *matrix_arr_addr) {

  player_coord_addr = create_arr_int(2);
  canvas_size_addr = create_arr_int(2);
  virtual_coord_addr = create_arr_int(2);

   if (player_coord_addr == NULL || canvas_size_addr == NULL || virtual_coord_addr == NULL) {
     return false;
   }

  player_coord_addr[0] = 1;
  player_coord_addr[1] = 1;

  canvas_size_addr[0] = 32;
  canvas_size_addr[1] = 16;

  virtual_coord_addr[0] = 0;
  virtual_coord_addr[1] = 0;

  matrix_arr_addr = malloc(canvas_size_addr[0] * canvas_size_addr[1] * sizeof(char));

  printf("w: %d, h: %d \n", canvas_size_addr[0], canvas_size_addr[1]);
  printf("vx: %d, vy: %d \n", virtual_coord_addr[0], virtual_coord_addr[1]);
  printf("px: %d, py: %d \n", player_coord_addr[0], player_coord_addr[1]);

   if (matrix_arr_addr == NULL) {
    return false;
   }

   return true;
}

void render(int *canvas_size_addr, char *matrix_arr_addr, int *virtual_coord_addr, int *player_coord_addr) {
  //int limit = canvas_size_addr[0] * canvas_size_addr[1];
  printf("%d", canvas_size_addr[0]);
  for (int i = 0; i < canvas_size_addr[0] * canvas_size_addr[1]; i++) {
    *(matrix_arr_addr + i) = '|';
    printf("%d\n", i);
  }
       
     // printf("matrix: %s \n", *(matrix_arr_addr + (*(canvas_size_addr) * *(canvas_size_addr + 1))));

  /*
  for (int i = 0; i < (canvas_size_addr[0] * canvas_size_addr[1]); i++) {
      matrix_arr_addr[i] = ' ';
      if (i >= canvas_size_addr[0]) {
        virtual_coord_addr[1] = virtual_coord_addr[1] + 1;
        virtual_coord_addr[0] = 0;
      }

      if (virtual_coord_addr[0] == player_coord_addr[0] && virtual_coord_addr[1] == player_coord_addr[1]) {
          matrix_arr_addr[i] = '|';
      }

      printf("x: %d, y: %d \n", virtual_coord_addr[0], virtual_coord_addr[1]);
      printf("player_x: %d, player_y: %d \n", player_coord_addr[0], player_coord_addr[1]);
      printf("matrix: %d \n", matrix_arr_addr[i]);
      printf("canvas_w: %d, canvas_h: %d \n", canvas_size_addr[0], canvas_size_addr[1]);
      
      virtual_coord_addr[0] = virtual_coord_addr[0] + 1;
  }
      */
        
}

int main () {
  int* player_coord;   //(x, y)
  int* canvas_size;   //(w, h)
  int* virtual_coord; //(x, y)
  char* matrix_arr;

  if(!setup(player_coord, canvas_size, virtual_coord, matrix_arr)) {
    printf("Alloc failed!");
    getchar();
    return 1;
  }

  render(canvas_size, matrix_arr, virtual_coord, player_coord);
  getchar();

  return 0;
}