# Data Structures

## Array/Matrix

## 2D-array

### Element index in a 2D-array: transformation between 2D-expression and 1D-expression

1. 2D to 1D:
   `[i,j]` in an array of `mxn` size:
   ```
      1D-index = i*n+j;
   ```
2. 1D to 2D (!useful):
   ```
      i = index / n;
      j = index % n;
      [i,j] = [index/n, index%n];
   ```
