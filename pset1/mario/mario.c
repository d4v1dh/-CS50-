#include <cs50.h>
#include <stdio.h>

int        main(void) {
     int height;
     int height_counter;
     int sharp_counter;
     int point_needed;

     height = get_int("Height: ");
     while (height < 1 || height > 8) {
         height = get_int("Height: ");
     }
     height_counter = 1;
     sharp_counter = 1;
     while (height_counter <= height) {
         int test;
         test = height - height_counter;
         printf("%d", test);
         while (sharp_counter <= height_counter) {
          
             printf("#");
             sharp_counter++;
         }
         sharp_counter = 1;
         printf("\n");
         height_counter++;
     }

}