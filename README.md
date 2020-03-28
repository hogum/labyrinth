## Labyrinth
Solution to tracing the largest path in a labyrinth


### Setup
##### 1. Clone the repository and change to the working directory
```
  git clone https://github.com/hogum/labyrinth && cd labyrinth
```

##### 2. Build using Cmake
```
  mkdir build && cd build
```

```
  cmake ../
```

```
cmake --build .
```
- The above steps should create an executable `labyrinth` in the current directory

##### Running

```
 $ ./labyrinth path_to_input_maze_file.txt output_file.txt
```
 **example**: To use the example file provided -> `./labyrinth example_maze output.txt`
