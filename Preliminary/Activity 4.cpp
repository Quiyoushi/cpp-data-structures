 #include <iostream>
using namespace std;

// Constant function to return Pi
const double& pi() {
    static const double PI = 3.14159;
    return PI;
}

// Function to calculate the radius from the diameter using a pointer
double radius(double* diameter) {
    return *diameter / 2;  
}

// Function to calculate the area of the circle using a pointer
double area(double* diameter) {
    double r = radius(diameter);  
    return pi() * (r * r); 
}

// Function to calculate the circumference of the circle using a pointer
double circumference(double* diameter) {
    double r = radius(diameter);
    return 2 * pi() * r;  
}

// Function to calculate the circumference of the ellipse using a pointer
double ellipseCircum(double* diameter) {
    double a = *diameter ;  // Semi-major axis
    double b = a /2;          // Semi-minor axis (example, you can define this differently)
    return pi() * (3 * (a + b) - ((a - b) * (a - b)) / (a + b));
}


// Function to calculate the area of the ellipse using a pointer
double ellipseArea(double* diameter) {
    double a = *diameter / 2; 
    double b = (*diameter / 2) * 2; 
    return pi() * a * b;
}
	
int main() {
    // Dynamically allocate memory for the circle's diameter
    double* circleDiameter = new double;

    // Input the circle's diameter
    cout << "Enter the circle's diameter: ";
    cin >> *circleDiameter;

    cout << "\nFor Circle:" << endl;
    // Call the area function and print the result
    double circleArea = area(circleDiameter);
    cout << "Circle Area: " << circleArea << endl;

    // Call the circumference function and print the result
    double circleCircumference = circumference(circleDiameter);
    cout << "Circle Circumference: " << circleCircumference << endl;

    cout << "\nFor Ellipse:" << endl;
    double ellipseA = ellipseArea(circleDiameter);
    cout << "Ellipse Area: " << ellipseA << endl;

    double ellipseCircumference = ellipseCircum(circleDiameter);
    cout << "Ellipse Circumference (Approximate): " << ellipseCircumference << endl;

  	//delete allocated memory
    delete circleDiameter;

    return 0;
}
