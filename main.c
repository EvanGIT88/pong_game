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

bool setup(int* player_coord_addr, int* canvas_size_addr, int* virtual_coord_addr, char* matrix_arr_addr) {
   player_coord_addr = create_arr_int(2);
   canvas_size_addr = create_arr_int(2);
   virtual_coord_addr = create_arr_int(2);

   if (player_coord_addr == NULL || canvas_size_addr == NULL || virtual_coord_addr == NULL ) {
     return false;
   }

   *player_coord_addr[0] = 1;
   *player_coord_addr[1] = 1;
   
   *canvas_size_addr[0] = 32;
   *canvas_size_addr[1] = 16;

   *virtual_coord_addr[0] = 0;
   *virtual_coord_addr[1] = 0;

   matrix_arr_addr = malloc(canvas_size_addr[0] * canvas_size_addr[1] * sizeof(char));
   return true;
}

void render(int* canvas_size_addr, char* matrix_arr_addr, int* virtual_coord_addr, int* player_coord_addr) {
  for (int i = 0; i < (canvas_size_addr[0] * canvas_size_addr[1]); i++) {
      matrix_arr_addr[i] = ' ';
      if (i >= canvas_size_addr[0]) {
        virtual_coord_addr[1] = virtual_coord_addr[1] + 1;
        virtual_coord_addr[0] = 0;
      }

      if (virtual_coord_addr[0] == player_coord_addr[0] && virtual_coord_addr[1] == player_coord_addr[1]) {
          matrix_arr_addr[i] = '|';
      }
      
      virtual_coord_addr[0] = virtual_coord_addr[0] + 1;
  }
        
}

int main () {
  int player_coord;   //(x, y)
  int canvas_size;   //(w, h)
  int virtual_coord; //(x, y)
  char matrix_arr;

  if(!setup(&player_coord, &canvas_size, &virtual_coord, &matrix_arr)) {
    printf("Alloc failed!");
    getchar();
    return 1;
  }

  render(&canvas_size, &matrix_arr, &virtual_coord, &player_coord);

  getchar();

  return 0;
}


  /*
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
*/
