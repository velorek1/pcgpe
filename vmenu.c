/*====================================================================*/
/* OPEN FILE MODULE
   +ListFiles with double linked list and selection menu in C.
   +Scroll function added.
   +Integrated with fread
   A window is drawn to the buffer and all of the scroll animations
   are drawn to the terminal on raw mode to have a better scrolling
   animation. Once the file is selected, the window is closed and the
   previous screen is painted to the terminal again.
   Last modified : August 2025 - Adapted from c-edit to fread
   Coded by Velorek.
   Target OS: Linux.                                                  */
/*====================================================================*/
/*====================================================================*/
/* COMPILER DIRECTIVES AND INCLUDES */
/*====================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rterm.h"
#include "listc.h"
#include "keyb.h"
#include "vmenu.h"
#include "global.h"

#define HORMENUSIZE 8
#define MENU0SIZE 4
/*====================================================================*/
/* GLOBAL VARIABLES */
/*====================================================================*/

int window_x1 = 0, window_y1 = 0, window_x2 = 0, window_y2 = 0;
int bcol = BACKGROUNDCOLOR;
int fcol = FOREGROUNDCOLOR;
int titleB = TITLEBCOLOR;
int titleF = TITLEFCOLOR;


char hormenu[HORMENUSIZE][MAXLINE] =
    { "PC-GPE", "Asm", "Graphics", "Sound", "Input", "Devices", "Memory", "Misc" };

char menu0[MENU0SIZE][MAXLINE] =
    { " Read Me \0", " Ftp Sites \0", " About PCGPE \0", " Exit \0"};


/*====================================================================*/
/* CODE */
/*====================================================================*/


int menu(){
char ch=0;
int i=0, j=0;
int shiftI=1;
    //setselectorLimit(8);
    old_rows = new_rows;
    old_columns = new_columns; 
    if (listBox1 != NULL) removeList(&listBox1);
    for (i=0; i<8; i++){
		listBox1 = addatend(listBox1, newitem(hormenu[i],i+shiftI,0,-1,-1));
		shiftI = shiftI + strlen(hormenu[i]) + 2;
     }
    for (i=0; i<new_columns;i++){
       write_ch(i,0,' ',B_WHITE,F_WHITE);
       write_ch(i,new_rows,' ',B_WHITE,F_WHITE);
    }
    for (i=0; i<new_columns;i++)
	 for(j=1;j<new_rows-1;j++)
       write_ch(i,j,0x2591,B_WHITE,F_BLUE);
    write_str(1,new_rows, "ESC: EXIT | ", B_WHITE, F_BLACK);
    ch=listBox(listBox1, 0,0, &scrollData, B_WHITE, F_BLACK,B_GREEN, F_BLACK, 8, HORIZONTAL,0,LOCKED);
    gotoxy(0,0);
    return scrollData.itemIndex;
}

int vmenu0(){
   char ch=0;
   int h = 0;
   setselectorLimit(14);
   draw_window(0,1,15,8,B_WHITE,F_BLACK,F_BLACK,1,0,1);
   for (h=0; h<14; h++){
	   write_ch(1+h,4,0x2500,B_WHITE,F_BLACK);
	   write_ch(1+h,6,0x2500,B_WHITE,F_BLACK);
   }
   if (listBox1 != NULL) removeList(&listBox1);
   for (h = 0; h < MENU0SIZE-2; h++) {
		listBox1 = addatend(listBox1, newitem(menu0[h],-1,-1,-1,-1));
    }
		listBox1 = addatend(listBox1, newitem(menu0[MENU0SIZE-2],2,6,-1,-1));
		listBox1 = addatend(listBox1, newitem(menu0[MENU0SIZE-1],2,8,-1,-1));
   ch=listBox(listBox1, 2,3, &scrollData, B_WHITE, F_BLACK,B_GREEN, F_BLACK, MENU0SIZE, VERTICALWITHBREAK,0,LOCKED);
   return scrollData.itemIndex;
}

