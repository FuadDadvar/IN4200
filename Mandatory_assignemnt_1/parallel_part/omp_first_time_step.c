#include <math.h>
#include <omp.h>

// Function that computes the first time step (l=1) for a 2D wave equation solver using finite-difference method
void first_time_step(int nx, int ny, double dx, double dy, double dt, double **u, double **u_prev) {
    int i, j;
    double term_x, term_y;
    double u_left, u_right, u_above, u_below;
    double dt2, dx2, dy2;
    double coef_x, coef_y;
    
    // Calculates the dx^2, dy^2 and dt^2 for the first time step l = 1
    dt2 = dt * dt;
    dx2 = dx * dx;
    dy2 = dy * dy;
    
    // Calculates the coefficients for the x and y terms in the equation
    coef_x = dt2 / (16* dx2);
    coef_y = dt2 / (16* dy2);

    // Iterating throught the 2D grid, excluding the boundaries. 
    // The function addition of the OpenMP directive #pragma omp parallel for included
    #pragma omp parallel for private(i, j, term_x, term_y, u_left, u_right, u_above, u_below)
    for (i = 1; i < nx - 1; i++) {
        for (j = 1; j < ny - 1; j++) {
            if (j == 0) {
              u_left = u[i][1];
          } else {
              u_left = u[i][j - 1];
          }

          if (j == nx - 1) {
              u_right = u[i][nx - 2];
          } else {
              u_right = u[i][j + 1];
          }

          if (i == 0) {
              u_below = u[1][j];
          } else {
              u_below = u[i - 1][j];
          }

          if (i == ny - 1) {
              u_above = u[ny - 2][j];
          } else {
              u_above = u[i + 1][j];
          }
          
          // Update the x and y terms with the boundary conditions
          term_x = (u_left - 2 * u_prev[i][j] + u_right);
          term_y = (u_below - 2 * u_prev[i][j] + u_above);

          // Compute the updated value for u[i][j] using the provided formula.
          u[i][j] = u_prev[i][j] + coef_x * term_x + coef_y * term_y;
        }
    }
}


