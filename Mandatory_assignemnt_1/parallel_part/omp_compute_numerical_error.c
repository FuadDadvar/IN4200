#include <math.h>  
// Include the math library to use the sqrt() and cos() functions.

double omp_compute_numerical_error(int nx, int ny, double dx, double dy, double t_value, double **u) {
    double error = 0.0;  // Initialize the error variable to zero.
    double pi = 3.141592653589793;  // Define the constant pi.

    // Loop over all grid points in the 2D grid, except for the last row and column.
    #pragma omp parallel for reduction(+:error)
    for (int i = 0; i < ny - 1; ++i) {
        for (int j = 0; j < nx - 1; ++j) {
            double x = j * dx;  // Compute the x coordinate of the current grid point.
            double y = i * dy;  // Compute the y coordinate of the current grid point.
            double u_true = cos(2 * pi * x) * cos(2 * pi * y) * cos(pi * t_value);  // Compute the exact solution at the current grid point.
            double diff = u_true - u[i][j];  // Compute the difference between the exact solution and the numerical solution at the current grid point.
            error += diff * diff;  // Add the squared difference to the error variable.
        }
    }

    error = sqrt(dx * dy * error);  // Compute the L2 norm of the error using the grid spacings.
    return error;  // Return the numerical error.
}
