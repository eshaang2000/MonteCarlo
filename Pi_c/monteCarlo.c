#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void set(){
    srand(time(NULL));
}
//method that generates a pseudo-random number between 0 and 1. Return type - float
float r2()
{
    return (float)rand() / (float)RAND_MAX ;
}

//method that rounds float number
//example - round_float(4.836, 2) -> 4.830000
float round_float(float num, int precise){
    float tens = powf(10.0, precise);
    // float tens = 1;
    num = floor(tens*num)/tens;
    return num;
}

// arg[1] is the precision of the float numbers that will be used
int main(int argc, char *argv[]) {

    set();// So that random numbers are random - basically change the seed

    printf("This is the precision requested %s\n", argv[1]);
    int precise = atoi(argv[1]);// precision requested


    int iter = 0; // variable to store the number of iterations required for convergence
    int inside = 0;
    float x;
    float y;

    float estimated_pi = 0;
    float estimated_pi_p = 0;
    float higher = 3.15f;
    float lower = 3.139f;


    while(!(estimated_pi_p < higher && estimated_pi_p > lower)){ 


        //generate two random numbers
        x = r2();
        y = r2();
        float x_p = round_float(x, precise);
        float y_p = round_float(y, precise);

        //find distance from origin
        float distance = x_p*x_p+y_p*y_p;
        float distance_p = round_float(distance, precise);
        
    
        //if point within the unit quater circle in the first quadrant
        if(distance_p < 1){
            inside++;
        }

        iter++;

        estimated_pi = (float)inside/iter*4;
        estimated_pi_p = round_float(estimated_pi, precise);



        //prints the estimated value of pi every 10 iterations
        if(iter%10 == 0){
            printf("%f \n", estimated_pi_p);
        }
    }


    printf("%f \n", estimated_pi_p);
    printf("%f \n", M_PI);
    printf("The number of iterations needed - %d\n", iter);
    return 0;
}