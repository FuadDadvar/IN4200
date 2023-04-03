CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

SERIAL_SRC = serial_part/allocate_2D_array.c serial_part/compute_numerical_error.c serial_part/deallocate_2D_array.c serial_part/first_time_step.c serial_part/one_regular_time_step.c serial_part/one_fast_time_step.c serial_part/serial_main.c
PARALLEL_SRC = parallel_part/omp_allocate_2D_array.c parallel_part/omp_compute_numerical_error.c parallel_part/omp_deallocate_2D_array.c parallel_part/omp_first_time_step.c parallel_part/omp_one_regular_time_step.c parallel_part/omp_one_fast_time_step.c parallel_part/para_main.c
COMMON_HEADERS = serial_part/functions.h parallel_part/para_functions.h

SERIAL_OBJ = $(patsubst %.c, %.o, $(SERIAL_SRC))
PARALLEL_OBJ = $(patsubst %.c, %.o, $(PARALLEL_SRC))

.PHONY: all

all: serial_program parallel_program

serial_program: $(SERIAL_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

parallel_program: $(PARALLEL_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -fopenmp

%.o: %.c $(COMMON_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -fopenmp

.PHONY: clean

clean:
	rm -f serial_program parallel_program $(SERIAL_OBJ) $(PARALLEL_OBJ)
