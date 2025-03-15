#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>

int main(){
    char* time = (char *)malloc(1024 * sizeof(char));
    scanf("%s",time);
    char *hour = (char*)malloc(12*sizeof(char));
    hour[0] = time[0];
    hour[1] = time[1];
    if(time[8] == 'P'){
        if(strcmp(hour, "01") == 0) strcpy(hour, "13");
        else if(strcmp(hour, "02") == 0) strcpy(hour, "14");
        else if(strcmp(hour, "03") == 0) strcpy(hour, "15");
        else if(strcmp(hour, "04") == 0) strcpy(hour, "16");
        else if(strcmp(hour, "05") == 0) strcpy(hour, "17");
        else if(strcmp(hour, "06") == 0) strcpy(hour, "18");
        else if(strcmp(hour, "07") == 0) strcpy(hour, "19");
        else if(strcmp(hour, "08") == 0) strcpy(hour, "20");
        else if(strcmp(hour, "09") == 0) strcpy(hour, "21");
        else if(strcmp(hour, "10") == 0) strcpy(hour, "22");
        else if(strcmp(hour, "11") == 0) strcpy(hour, "23");
    }
    else if((time[8] == 'A') && (strcmp(hour, "12")==0)) strcpy(hour, "00");
    time[0] = hour[0];
    time[1] = hour[1];
    time[8] = ' ';
    time[9] = ' ';
    printf("%s", time);
    return 0;
}
