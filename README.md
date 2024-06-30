# Website Analytics

## Overview

This application analyzes user visits to different product pages across two days. It identifies users who visited on both days and users who visited new pages on the second day.

## Project Structure

- `main.cpp` - Main program file containing the logic for reading CSV files and analyzing user visits.
- `day1.csv` - CSV file containing visit data for the first day.
- `day2.csv` - CSV file containing visit data for the second day.
- `Makefile` - File to automate the compilation process.

## Efficiency

### Time Complexity

- **Reading CSV files**: O(n), where n is the number of lines in the file. This is because each line is read once.
- **Processing Data**: O(n + m), where n is the number of visits on the first day and m is the number of visits on the second day. This includes inserting each visit into a hash table and checking for new visits.
- **Total Complexity**: O(n + m), which is linear with respect to the number of visits in the input files.

### Why This Solution is Efficient

- The use of `unordered_map` and `unordered_set` allows for average O(1) time complexity for insertions and lookups.
- Reading the files and processing each visit only once ensures that the solution is efficient and scalable for large datasets.

## How to Compile

1. Ensure you have `g++` compiler and `make` utility installed.

2. Open your terminal or command prompt.

3. Navigate to the directory where your project files ( main.cpp, day1.csv, day2.csv, and Makefile) are located.

4. Run the following commands in your terminal:
    ```sh
    make

## How to Run

1. Ensure you have `day1.csv` and `day2.csv` in the same directory.

2. After compiling, execute the following command:
    ```sh
    ./website_analytics

This will output:
- Users who visited pages on both days.
- Users who visited new pages on the second day.

## Additional Information

- The `Makefile` automates the build process and ensures all `.cpp` files are compiled correctly.
- You can clean the build files using:
    ```sh
    make clean

- Rebuild the project using:
    ```sh
    make rebuild

This project demonstrates efficient handling of user visit analysis using C++ standard libraries.
