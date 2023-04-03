
## README file for **parallel_part**
To run the code, simply type "make all" in the terminal. 
The makefile contains as following: 

```
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

SERIAL_SRC = serial_part/allocate_2D_array.c serial_part/compute_numerical_error.c serial_part/deallocate_2D_array.c serial_part/first_time_step.c serial_part/one_regular_time_step.c s erial_part/one_fast_time_step.c serial_part/serial_main.c
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


### This code employs identical loops and algorithms as the serial_part, with the sole distinction being the utilization of OpenMP for the parallel program. Where in each C code, there exists a line of parallel code located above the for loop.

#### omp_first_time_step.c
In this parallization we use 
```
#pragma omp parallel for private()
```


#### omp_one_regular_time_step.c
In this parallization we use 
```
#pragma omp parallel for private()
```
which is explained in __omp_first_time_step.c__.



#### omp_one_fast_time_step.c
In this parallization we use 
```
#pragma omp parallel for private()
```
which is explained in __omp_first_time_step.c__.

#### omp_compute_numerical_error.c
In this parallization we use 
```
#pragma omp parallel for reduction()
```



























