//TUI Text-File reader [fread]
//Coded by v3l0r3k
//Date: August 2025

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "fileb.h"
#include "global.h"
#include "rterm.h"
#include "listc.h"
#include "keyb.h"
#include "vmenu.h"
#include "viewer.h"

int main(){
    const char *path = "docs";  // directory where docs are found

    if (chdir(path) != 0) {
       fprintf(stderr, "Docs not found. Make sure to place them in %s\n", path);
        return 1;
    }


   int exitsignal = 0;
   int ok =0;
   int ret = 0;
   int vret = 0;
   char ch = 0;
   get_terminal_dimensions (&new_rows,&new_columns);
   old_rows = new_rows;
   old_columns = new_columns;
   init_term();
   hidecursor();  
   //check arguments
   
  do{
     get_terminal_dimensions (&new_rows,&new_columns);
    //No arguments were given open file dialog loop
    ok=menu();

    switch (ok){
	  case 0: ret=vmenu0(); break;
    } 
 
 
     //strcpy(fileName,"asm0.txt");
    if (ret == 3) break;
    if (scrollData.lastch == K_ESCAPE) break; 
    if (file_exists(fileDocs0[ret])) {
      vret=viewFile(fileDocs0[ret]);
    } 
    if (vret == 0) break;
     } while (exitsignal != 1);

   //credits
   showcursor();   
   close_term();
   return 0;
}
