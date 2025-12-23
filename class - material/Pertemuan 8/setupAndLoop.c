#include <stdio.h>
#include <conio.h>


void setup();
void loop();

int main(){
   setup();
   while(1){
      loop();
   }
   return 0;
}



void setup(){
   printf("ini setup\n\n\n");
}


void loop(){
   printf("ini loop");
}
