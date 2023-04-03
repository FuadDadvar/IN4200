#include <stdlib.h>


void allocate_2D_array(double ***array, int nx, int ny) {
    // Allocate memory for the row pointers.
    *array = (double **) malloc(ny * sizeof(double *));
    if (*array == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    // Allocate memory for the array data.
    double *data = (double *) malloc(nx * ny * sizeof(double));
    if (data == NULL) {
        printf("Error: memory allocation failed.\n");
        exit(1);
    }

    // Assign the row pointers to the array data.
    for (int i = 0; i < ny; i++) {
        (*array)[i] = &data[i * nx];
    }

    
}
