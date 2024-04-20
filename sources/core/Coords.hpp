/*
-
  -
    -
  -
-
Uria - 2024

Thomas ROUSTAN
-
  -
    -
  -
-
*/

#ifndef COORDS_HPP_
#define COORDS_HPP_


typedef struct screenCoords {
  int size_x;
  int size_y;
  int menu_origin_x;
  int menu_origin_y;
  int menu_end_x;
  int menu_end_y;
  int tool_origin_x_menu_active, tool_origin_y_menu_active, tool_end_x_menu_active, tool_end_y_menu_active;
  int tool_origin_x_menu_unactive, tool_origin_y_menu_unactive, tool_end_x_menu_unactive, tool_end_y_menu_unactive;
} screenCoords_t;

#endif