#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <ctype.h>






int exit_status(char *seedPtr, char *fileNamePtr){

        while(*seedPtr != '\0'){
                if(!isdigit(*seedPtr)){
                        fprintf(stderr, "Expected Integer seed, but got %s\n", seedPtr);
                        exit(2);

                }
                seedPtr++;

        }//while

        FILE *file;
        if(!(file = fopen(fileNamePtr, "r"))){
                fprintf(stderr, "%s is nonexistent or unreadable\n", fileNamePtr);
                exit(3);

        }

        char line[256];
        int size;
        int lines = 0;
        int characters = 0;
        int array[25];
        int i = 0;

        while(fgets(line, sizeof(line), file)){

                size = strlen(line);

                if(size != 15){
                        fprintf(stderr, "%s has bad format\n", fileNamePtr);
                        exit(4);

                }//if
                for(int i = 0;i < strlen(line);i++){



                        if(!(isdigit(line[i])) && line[i] != ' ' && line[i] != '\n'){
                                fprintf(stderr, "%s has bad format\n", fileNamePtr);
                                exit(4);

                        }//if

                }//for

                characters = characters + size;
                lines++;

                char* token = strtok(line, " ");//splitting lines into seperate numbers
								while(token){
                        int number;
                if(sscanf(token, "%d", &number) == 1){
                        array[i] = number;//adding numbers to a list
                        i++;
                }//if
                token = strtok(NULL, " ");
                }//while


        }//while



        if(array[12] != 0){
                fprintf(stderr, "%s has bad format\n", fileNamePtr);
                exit(4);


        }//if
        int min, max;
        for(int m = 0;m < 5;m++){//checking range of numbers in coloumns

                switch(m){
                        case 0:
                                min = 1;
                                max = 15;
                                break;
                        case 1:
                                min = 16;
                                max = 30;
                                break;

                        case 2:
                                min = 31;
                                max = 45;
                                break;
                        case 3:
                                min = 46;
                                max = 60;
                                break;
                        case 4:
                                min = 61;
                                max = 75;
                                break;

                }//switch

                for(int n = 0; n <= 20;n = n + 5){

                        if((array[m + n] < min || array[m + n] > max) && (m + n) != 12){

                                fprintf(stderr, "%s has bad format\n", fileNamePtr);
                                exit(4);

                        }//if

                }//for
        }//for


        for(int m = 0; m < 25; m++){
                for(int n = m + 1; n < 25;n++){

                        if(array[m] == array[n]){
                                fprintf(stderr, "%s has bad format\n", fileNamePtr);
                                exit(4);

                        }//if

                }//for
        }//for

        //line check

        if(lines != 5){
                fprintf(stderr, "%s has bad format\n",fileNamePtr);

        }//if

        return 0;

}//exit_status



int check_winner(char *str[25]) {

        int i, flag, z, f;
        int count;
        char *s;


// LOOP to loop through the rows to check winner


        for (i = 0; i < 25; i = i + 5) {
                z = 0;
                flag = 1;
                count = 0;
                while (flag != 0) {
                        s = strchr(str[i + z], 'm');

                        if (s != '\0') {
                                count++;}
                        else if (s == '\0') {
                                flag = 0;
                                }
                        if (count == 5) {
                                return 1;}


                        z++;


                        }





}




//LOOP to loop through the coloumns to check winner


  for (i = 0; i < 5; i++) {
                z = 0;
                flag = 1;
                count = 0;
                while (flag != 0) {
                        s = strchr(str[i + z], 'm');

                        if (s != '\0') {
                                count++;}
                        else if (s == '\0') {
                                flag = 0;
                                }

                        if (count == 5) {
                                return 1;}

                        z = z + 5;


                        }


}


//Checking all 4 corners of the matrix to check winner

char *q, *w, *e, *r;
for (i = 0; i < 25; i++) {
        q = strchr(str[0], 'm');
        w = strchr(str[4], 'm');
        e = strchr(str[20], 'm');
        r = strchr(str[24], 'm');

        if (q != '\0') {
                if (w != '\0') {
                        if (e != '\0') {
                                if (r != '\0') {
                                        return 1;
                                        }
                                }
                        }

                }


        }



 }




int mark_card(char *str[25], int num, char let) {

        int i;

				for (i = 0; i < 25; i++ ) {
         
				        int temp = atoi(str[i]);
								if (temp == 0) str[i]="00m";
								int t = 0;
                char ch = 'm';
                char result[50];
								
								switch(let)// marking card according to coloumns
								{
												case 'L':
															if(i == 0 || i == 5 || i == 10 || i == 15 || i == 20) t = 1;
															else t = 0;
															break;
												case 'I':
                              if(i == 1 || i == 6 || i == 11 || i == 16 || i == 21) t = 1;
                              else t = 0;
                              break;
												case 'N':
                              if(i == 2 || i == 7 || i == 12 || i == 17 || i == 22) t = 1;
                              else t = 0;
                              break;
												case 'U':
                              if(i == 3 || i == 8 || i == 13 || i == 18 || i == 23) t = 1;
                              else t = 0;
                              break;
												case 'X':
                              if(i == 4 || i == 9 || i == 14 || i == 19 || i == 24) t = 1;
                              else t = 0;
                              break;
								} 
								
								if (t == 1){
                if (num < 10) {
                          sprintf(result, "0%d%c", num, ch);
                          }
                else {
                        sprintf(result, "%d%c", num, ch);
                        }
							//this block of code enters a number into a string list					
              int length = snprintf( NULL, 0, "%s", result ); 
              char* strt = malloc( length + 1 );
              snprintf( strt, length + 1, "%s", result);




                if (temp == num) {

                         str[i] = strt;


                        }
									}
                }

        int j;
				printf("L   I   N   U   X\n");
        for (j = 0; j < 25; j += 5) {
                printf("%s %s %s %s %s\n", str[j], str[j + 1], str[j + 2], str[j + 3], str[j + 4]);

                }

	}








int main(int argc, char **argv) {
					
				 char fileName[20];
         char seedp[20];

				if(argc != 3){

                fprintf(stderr, "Usage: %s seed cardFile\n", argv[0]);
                exit(1);

        }
        else{
                strcpy(seedp, argv[1]);
                strcpy(fileName, argv[2]);
                exit_status(seedp, fileName);

        }


        char *str1[25];
        int i, j, k, q, cn, seed, a, num;
				char e, pref;
				FILE *fp;
				int array[25];


        List * x = malloc(sizeof(List));
				seed = atoi(seedp);
				fp = fopen(fileName, "r");
				fscanf (fp, "%d", &num);

        while (!feof (fp))//loop to put numbers from file into arrray
        {
          array[k] = num;
          k++;
          fscanf (fp, "%d", &num);
        }




				for (i = 0; i < 25; i++) //loop to add numbers from nume ber list to string list
				{
							int zer = 0;
              num = array[i];
              int length = snprintf( NULL, 0, "%d%d ", zer, num );
              char* strt = malloc( length + 1 );
              
							if (num < 10) {
											snprintf( strt, length + 1, "%d%d ", zer, num);
											}
              else {
											snprintf( strt, length + 1, "%d ", num );
											}
              str1[i] = strt;

				}





				system("clear");
				printf("CALL LIST: \n");
				printf("L   I   N   U   X\n");
				for (j = 0; j < 25; j += 5) {
                printf("%s %s %s %s %s\n", str1[j], str1[j + 1], str1[j + 2], str1[j + 3], str1[j + 4]);

                }
				
				printf("Enter a non enter key or q to quit: ");
				scanf(" %c", &e);



				a = -1;
				initlist(x,seed);
				//main while loop to run the game
        while (a != 0 && e != 'q') {
                system("clear");
								printf("CALL LIST: ");
								prinl(x);
								cn = checknum(x);
								pref = checklet(x);
                mark_card(str1, cn, pref);
                q = check_winner(str1);
                if (q == 1) {
                        printf("WINNER\n");
                        a = 0;
												continue;}
								addl(x);
								printf("Enter an non enter key or q to quit: ");
								scanf(" %c", &e);
								printf("\n");
								system("clear");

        }

        return 0;



}
