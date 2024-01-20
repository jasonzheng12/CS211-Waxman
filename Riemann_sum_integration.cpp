#include <iostream>
using namespace std;

typedef double (FUNC)(double); // This is a function pointer

double integrate(FUNC f, double a, double b) {

   double sum = 0, increment = .0001; 
   // The x represents the horizontal position of the rectangle
   // The f(x) is the height of it and the increment would be the width
   // The x is initialized to a + increment/2 because I want to use the midpoint and use that to find a more accurate answer
   // To use the left of the endpoint we would just have to initialize x to a, since a is the starting #
   for (double x = a + increment/2; x < b; x += increment) // For each rectangle,
      sum += f(x) * increment;                              // calculate the area and add it to the sum
   return sum;

}

double line(double x){
   return x;
}

double square(double x){
   return x * x;
}

double cube(double x){
   return x * x * x;
}

int main() {
   cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
   cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
   cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
   return 0;
}
