#include <stdio.h>
int main() {
    //indien afgeteld moet worden van een andere startwaarde, moet die 2 maal veranderd worden
     for(int i=10; i>0; i--) {
          if(i==10) {
               printf("Hello world!\n");
          }
          printf("%d ",i);
          if(i==1) {
               printf("\nSTART");
          }
     }
     return 0;
}