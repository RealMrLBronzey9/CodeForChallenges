#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*This program is for the hat problem where people in a circle table 
if they se the same hat number in their diametrically opposite chair then they see hat
then print people who see the same hat as their own 
*/ 


int main(){

    // Variables needed
    int N;
    int halfN;
    int sameHat = 0;
    int hInput;
    int *H; // So apparently in C you cant have arrays with variable length so pointer H using malloc works so thats cool

    while (true){
        
        printf("How many people are sitting in the table? (must be even number): \n");
        scanf("%d", &N);

        // Check if N is even or not
        if (!(N%2 == 1)){
            /*
                Note to self:
                malloc is essentially a function from stdlib.h
                it means memory allocation 
                you can basically dynamically allocate a chunk of memory with your specified size. 
                we cast the int* to malloc so the pointer is int?
                then the () in malloc is how many bytes I believe
                so sizeof(int) is 4 bytes then its multiplied by N so 4 bytes times the number N
                This is a way to get "arrays" of variable length
            */
            H = (int*)malloc(N*sizeof(int));

            // If allocation doesnt work then repeat
            if(H == NULL){
                printf("Something went wrong\n");
                continue;
            }
            // Break because N is even so it works
            break;
        }
        else{
            // Repeat this loop because N is not even
            printf("Must be an even number!!\n");
        }
    }   

    // Set elements of int* H (like setting the array's elements basically)
    for (int i = 0; i < N; i++){
        printf("Enter a number for the hat: \n");
        scanf("%d", &hInput);

        // Write input to memory via pointer
        H[i] = hInput;
    }

    
    // Get halfN value from N
    halfN = N/2;

    for (int i = 0; i < halfN; i++){
        // Get opposite of current seat
        int oppositeSeat = i + halfN;

        // Check if hats of both seats are the same
        if (H[i] == H[oppositeSeat]){
            // If yes then increase the counter by 2
            sameHat += 2;
        }
    }

    // Output the hats
    printf("\nPeople who have same hat: \n%d\n", sameHat);

    return 0;
}