#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = 200;
  c.green = 100;
  c.blue = 100;

  struct matrix *edges;
  struct matrix *transform;


  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  add_edge(edges, 100, 400, 0, 400, 400, 0);

  int i;
  for (i = 100; i <= 300; i+= 25) { 
    add_edge(edges, 250, 50, 0, i, 400, 0);
  }

  draw_lines(edges, s, c);

  c.red = 325;

  scalar_mult(0.5, edges);
  
  int j;
  for (j = 0; j < 360; j += 36) {
    matrix_mult(rotX(i), edges);
    matrix_mult(rotY(i), edges);
    draw_lines(edges, s, c);
  }


  save_ppm( s, "img.ppm");
  save_extension(s, "img.png"); 
  display(s);
  
  free_matrix( transform );
  free_matrix( edges );
}  
