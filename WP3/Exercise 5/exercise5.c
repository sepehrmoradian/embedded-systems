//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 3
//Submission code: 8777169671
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

//defining the max number of elements in the array
#define MAX 99

int main (void){
    int array[MAX], i;

    //to generate random numbers everytime
    srand(time(NULL));

    //loops through each element in the given array
    for (i = 0; i<MAX; i++){
        //assignes a random number from 1-99 to randNum integer variable
        int randNum = (rand() % 99 + 1);
        //makes every index in the array equal to the randomly generated number
        array[i] = randNum;
        //print each value of the array
        printf("%d = %d \n", i, array[i]);
        //print each value of the array and each value multiplied by 2
        printf("%d multiplied by 2 = %d\n", array[i], array[i] * 2);
    }
    printf("---------------------------------\n");
    //print the value of the address of the array
    printf("The value of the address of the array (pointer) is: %p \n", &array);
    //print the first integer in the array
    printf("The first integer in the array is: %d\n", array[0]);
    //print the last integer in the array
    printf("The last integer in the array is: %d\n", array[MAX-1]);
    //print the size of an integer in bytes
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));
    //assign the size of the array in bytes to arrayInBytes integer variable
    int arrayInBytes = sizeof(array);
    //prints the size of the whole array in bytes
    printf("The size of the whole array in bytes is: %d", arrayInBytes);
}