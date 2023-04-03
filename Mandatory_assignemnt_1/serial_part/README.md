
## README file for **serial_main**
To run the code, simply type "make all" in the terminal. 
The makefile contains as following: 

```
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

SERIAL_SRC = serial_part/allocate_2D_array.c serial_part/compute_numerical_error.c serial_part/deallocate_2D_array.c serial_part/first_time_step.c serial_part/one_regular_time_step.c serial_part/one_fast_time_step.c serial_part/serial_main.c
PARALLEL_SRC = parallel_part/omp_allocate_2D_array.c parallel_part/omp_compute_numerical_error.c parallel_part/omp_deallocate_2D_array.c parallel_part/omp_first_time_step.c parallel_part/omp_one_regular_time_step.c parallel_part/omp_one_fast_time_step.c parallel_part/para_main.c
COMMON_HEADERS = serial_part/functions.h parallel_part/para_functions.h

SERIAL_OBJ = $(patsubst %.c, %.o, $(SERIAL_SRC))
PARALLEL_OBJ = $(patsubst %.c, %.o, $(PARALLEL_SRC))

serial_program: $(SERIAL_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

parallel_program: $(PARALLEL_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -fopenmp

%.o: %.c $(COMMON_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -fopenmp

.PHONY: clean

clean:
	rm -f serial_program parallel_program $(SERIAL_OBJ) $(PARALLEL_OBJ)
```


#### first_time_step.c


In this code we simply compute the first time step l = 1 for the 2D wave equation solver, using the finite-difference method which is given in the assignment report, eq(2). 

1. We define our variables, so on we calculate the derivatives for l = 1

2. We calculate the coefficients for the x and y terms in the equation.

3. We iterate through the 2D grid. So on we code the boundaries sequentially which is given in the assignment report eq(3) and eq(4).

4. After we've iterated through the boundaries we update the x and y terms with the boundary conditions.

5. Finally we compute the value for u[i][j] using provided eq(2).


#### one_regular_time_step.c

In this code we simply compute one regular time step, which is set to l => 2 for the 2D wave equation solver, using finite-difference method which is given in the assignment report, eq(5).

We follow the same steps 1-4 as in first_time_step.c, only difference is that we use a eq(5) instead of eq(2) since we're examining for l => 2. 


#### one_fast_time_step.c

In this code we compute one regular time step for l => 2, for the 2D wave equation solver, using the finite-difference method which is given in the assignment report, eq(5). But this time we switch out the if test with a more effiecient if test, we call these ternary operators. Once the program has ran through the ternary operators we evaluate the equation as we did in __one_regular_time_step.c__.

#### compute_numerical_error.c

In this code we compute the numerical error of the wave equation solver using eq(6) and eq(7). Where eq(6) is the exact solution and eq(7) given to be the quantified error of the numerical solution at a certain time point $t = l\Deltat$. 

#### allocate_2D_array.c

In this code we allocate the memory of 2D array of a double type. It first allocates the memory for the row pointers, secondly it allocaltes the memory for the array data, lastly the code assigns the row pointers to the array data. 

#### deallocate_2D_array.c

In this code we simply deallocate the memory by using 

```
free()
```


























