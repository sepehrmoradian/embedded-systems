//(C) Dimitrios Pokkias, Sepehr Moradian, Shahd Metwally; Group: 22
//Work package 2
//Submission number: 0267702620

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
//#### Constants ##### 
#define MAX 5
 
// ##### typedefs          #### 
typedef struct q{ 
        int number; 
        struct q *next; 
        struct q *prev; 
} REGTYPE; 
 
// ##### Function declarations   ##### 
 
REGTYPE* random_list(void); 
REGTYPE* add_first(REGTYPE* temp, int data); 
 
 
//###### Main program ####### 
int main(int argc, char *argv[]) 
{ 
    int nr=0; 
    int data = 0;
 
    REGTYPE *act_post , *head=NULL; 

        srand(time(0));  //   Random seed  
        head=random_list(); 
        if (head == NULL){
            return 1;
        }
        act_post=head; 
        while( act_post!=NULL){ 
           printf("\n Post nr %d : %d" , nr++, act_post->number); 
           act_post=act_post->next; 
        }


    
    printf("\n Add a new record: "); //asking the user to give an input
    scanf("%d", &data); //scanning the input and assigning it to the data variable

    head = add_first(head, data); //tests the add_first function
    act_post=head; //set act_post to head
    nr=0; ///sets element value to 0 so that the user's input gets added to the first element

    //prints the linked list with the new record
    while( act_post!=NULL){ 
        printf("\n Post nr %d : %d" , nr++, act_post->number); 
        act_post=act_post->next; 
    }
       
 // --- Free the allocated memory  --- 
 
  while((act_post=head)!=NULL){ 
     head=act_post->next; 
     free(act_post); 
  } 
   
  return 0; 
} 
 
// ====     End of main   ====================================== 
 
REGTYPE* random_list(void){ 
    int nr, i=0; 
    REGTYPE *top = NULL, *old = NULL, *item = NULL;

    //iterating through list
    for(i = 0; i < MAX; i++){
        item = (REGTYPE *)malloc(20 * sizeof(REGTYPE)); //allocating memory

        //terminate program if memory not allocated
        if(item == NULL){
            printf("Unable to allocate memory.");
            return NULL;
        }

        nr = rand() % 101; //nr is now a random number generator from 0-100
        item->number = nr; //link item to number and make equal to nr
        item->next = NULL; //link next with null

        if(top == NULL){ //if value has no top
            //make top equal the item because this means that the list is empty
            top = item;
            old = item;
        }
        else{ //else update old to be item 
            old->next = item;
            old = item;
        }
    }
    return top; 
} 
 
//==========================================================                 
 
REGTYPE* add_first(REGTYPE* temp, int data){ 
    //new first entry in the list variable definition
    REGTYPE *item =NULL;
    item = (REGTYPE *)malloc(20 * sizeof(REGTYPE)); //allocating memory

    item->number = data; //link number with the input the user gave (ie. data)
    item->next = temp; //link the next value to temp
    temp = item; //make temp (ie. the first element) equal to the new item

    //returns a pointer to the new first entry
    return temp;
} 