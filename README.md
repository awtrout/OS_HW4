# OS_HW4: Page Replacement Algorithm Simulation

This program simulates various page replacement algorithms such as Least Recently Used (LRU), Optimal, and First In First Out (FIFO) in a demand-paging scenario. It analyzes their performance in terms of the number of page faults.

## Functionality

- Implements the following page replacement algorithms: LRU, Optimal, and FIFO.
- Accepts a page reference string and the specified number of frames as input to simulate page replacement.
- Simulates page replacement and calculates the number of page faults that occur during the simulation for each implemented algorithm.
- Provides clear and structured output displaying the number of page faults that occurred at each step of the simulation.

## Instructions for Execution

1. Ensure you have a C compiler installed on your system, such as GCC.
2. Download or clone the source code repository.
3. Open a terminal or command prompt and navigate to the directory containing the source code files.
4. Compile the program using the following command: gcc -o page_replacement_simulator main.c
5. After successful compilation, execute the program by running the generated executable: ./page_replacement_simulator
6. The program will run simulations for each page replacement algorithm using the provided sample input (page reference string and number of frames).
7. Review the output displayed in the terminal, which includes the step-wise simulation details and total page faults for each algorithm.

## Sample Input

Page reference string: 1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5
Number of frames: 4

## Sample Output

For LRU Algorithm:
- Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
- Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
- Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
- ... (continue until end of page reference string)
- Total Page Faults: [Total Faults]

For Optimal Algorithm:
- Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
- Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
- Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
- ... (continue until end of page reference string)
- Total Page Faults: [Total Faults]

For FIFO Algorithm:
- Step 1: Page fault (1) - Page Table: {1}, Frames: [1], Faults: 1
- Step 2: Page fault (2) - Page Table: {1, 2}, Frames: [1, 2], Faults: 2
- Step 3: Page fault (3) - Page Table: {1, 2, 3}, Frames: [1, 2, 3], Faults: 3
- ... (continue until end of page reference string)
- Total Page Faults: [Total Faults]








