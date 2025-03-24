# Parallel and Distributed Programming Coursework
1. This repository contains the code for the coursework of parallel and distributed programming subject (6004CEM).
2. The parallel programming part uses Open MP by importing the library "omp.h".
3. The distributed programming part uses MPI by importing the library "mpi.h".

# User Guide
1. For Windows user, these files are intended to be run in Ubuntu virtual machine running using Oracle Virtual Box.
2. For ParallelPartA_a.c, ParallelPartA_b.c ParallelPartB_b.c and ParallelPartB_b.c, run "gcc -fopenmp -o {object_name} {source_code_file_name}" in the terminal to compile the code. Then, run the code by running "./{object_name}" in the terminal.
3. For ParallelPartA_b.c, before running the code, the number of threads can be specified by running "export OMP NUM_THREADS={number_of_threads}" in the terminal.
4. For ParallelPartC_a.cpp, ParallelPartC_b.cpp and ParallelPartC_c.cpp, run "g++ -fopenmp -o {object_name} {source_code_file_name}" in the terminal to compile the code. Then, run the code by running "./{object_name}" in the terminal.
5. For distributed programming part, before compiling the code, run "sudo apt install openmpi" and "sudo apt install libopenmpi-dev" in the terminal.
6. For DistributedPartA.c, DistributedPartB_a.c, DistributedPartB_b.c, DistributedPartC_a.c and DistributedPartC_b.c, run "mpicc -o {object_name} {source_code_file_name}" in the terminal to compile the code. Then specify the number of processes and run the code by running "mpirun -np {number_of_processes} {object_name}" in the terminal. The number of processes cannot be more than the number of cores. For DistributedPartB_a.c, DistributedPartB_b.c, DistributedPartC_a.c and DistributedPartC_b.c, the code is intended to run in an environment with 4 processes (1 master process and 3 slave processes).

