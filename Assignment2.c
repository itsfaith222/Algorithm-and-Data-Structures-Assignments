/************************************************************************************* 
* This file is the main driver which simulates the well-known move-to-front strategy 
* which is useful for caching, data compression, and many other applications where items 
* that have been recently accessed are more likely to be re-accessed.  
*
* Modified by:
* Date:
*************************************************************************************/
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "List.h"

int main() {
    int n;
    char filename[50] = "test_dat.txt";   //name of the file; default is provided file
    clock_t start;
    double executionTime;
    FILE *fp;
    //Of course, you may add more variables as needed

    printf("Please enter the name of the text file you wish to read from: ");   
    scanf("%s", filename);

    printf("Please enter the number the elements to be read from the text file: ");   
    scanf("%d", &n);
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
        }

    List s = initList();
    start = clock();

    //  Enter your code here for the moveToFront strategy
    int num;

    while(fscanf(fp, "%d", &num) == 1){
        if(isEmpty(s)){
            NodePtr node = search(s, num);
            if(node != NULL){
                removeFromList(s, node);
            }
        }
        insertAtFront(s, num);
    }

    
    executionTime = (double)(clock() - start) / CLOCKS_PER_SEC * 1000;
    printf("Time taken to insert %d numbers: %.4f seconds\n", n, executionTime);
    
    //comment out the following 2 lines when testing with large n
    printf("List after reading from the file:\n");
    displayList(s);   
    
    freeList(s);
    fclose(fp);
    return 0;   
}