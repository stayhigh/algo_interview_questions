#include <iostream>
#include <cmath>

using namespace std;

float target_function(float x){
    return log(pow(x,4)) - 0.7;
}

float bisection_method(float (*func)(float), float x_left, float x_right, float eplison, int num_of_iterations){

    int i = 0;
    float x;
    float y; 
    float y_left;
    float y_right;

    while ((x_right - x_left) / 2 > eplison && i++ < num_of_iterations){
        x = ( x_left + x_right ) / 2;
        if (func(x) == 0){
            break;
        }

        y_left = func(x_left);
        y_right = func(x_right);

        if (y_left * y_right < 0){
            x_right = x;
        }else{
            x_left = x;
        }
    }
    
    return x;
}

int main(void){

    /* Use bisection method to find the positive real roots of ln(x^4) = 0.7 */
    float x_left = 0.5;
    float x_right = 2;
    float eplison = 0.01;
    float relative_error_threshold = 0.02;
    int num_of_iterations = 20;

    cout << "find root by bisection method:" << bisection_method(&target_function, 0, 2, 0.01, 20) << endl;
    return 0;
}
