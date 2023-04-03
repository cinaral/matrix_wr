# matrix_rw
Simple header-only C++ library to write/read matrices to/from files, basically a .csv reader. This library is used for testing and verification using MATLAB in my other projects.

# Installation

Include the headers in ```include/``` into your project.

Alternatively, you can use [FetchContent()](https://cmake.org/cmake/help/latest/module/FetchContent.html) in your ```CMakeLists.txt```:
```CMake
FetchContent_Declare(matrix_rw URL https://github.com/cinaral/matrix_rw/releases/download/<RELEASE_TAG>/src.zip)
FetchContent_MakeAvailable(matrix_rw)
```
Use the MATLAB test and CTest to test the library before using. 

# Usage:

## Read:
```Cpp
/** if you know both the row and column size */
Real_T matrix[n_dim][m_dim];
matrix_rw::read(file, matrix);

/** if you only know the column size */
std::vector<std::array<Real_T, m_dim>> matrix;
matrix_rw::read(file, matrix);
```

## Write:
```Cpp
/** if you know both the row and column size */
Real_T matrix[n_dim][m_dim];
// ...
matrix_rw::write(file, matrix);

/** if you only know the column size */
std::vector<std::array<Real_T, m_dim>> matrix;
// ...
matrix_rw::write(file, matrix);
```

See the [test](./test/test-matrix_rw.cpp) for an example.

The input and output files are comma and newline delimited, and their extension is ```*.dat``` by default. The formatting is compatible with MATLAB's ```writematrix``` and ```readmatrix```. Each row in the file corresponds to a matrix row. The file should contain ```N``` lines and ```M``` comma-separated numbers in each line for a ```N``` by ```M``` matrix.
```MATLAB
writematrix(matrix, file, 'Delimiter', ',');  
matrix = readmatrix(file);  
```

# To do:
- 1D array rw