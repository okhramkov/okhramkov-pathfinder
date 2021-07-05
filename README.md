<p align="center"> Learn pathfinding algorithms</p>

##  Got skills

Reasoning & Argumentation, Creativity, Communication, Critical Thinking, Problem Solving, Analysis, Innovation Thinking, Agility & Adaptability, Initiative, Responsibility, Self-Management, UNIX, Git, Procedural Programming, Algorithms, C

<hr>

## Building the program
1. Download/Clone the source code
2. `cd` into the root directory
3. Run `make`

## Usage example

```
./pathfinder tests_file/file_name
```
## Examples

###  File (example)


6
A-B,11$
A-C,10$
B-D,5$
C-D,6$
C-E,15$
D-E,4$
###  Command
>./pathfinder example | cat -e
###  Output

''''
========================================
Path: A -> B
Route: A -> B$
Distance: 11$
========================================
========================================
Path: A -> C
Route: A -> C
Distance: 10
========================================
========================================
Path: A -> D
Route: A -> B -> D
Distance: 11 + 5 = 16
========================================
========================================
Path: A -> D
Route: A -> C -> D
Distance: 10 + 6 = 16
========================================
========================================
Path: A -> E
Route: A -> B -> D -> E
Distance: 11 + 5 + 4 = 20
========================================
========================================
Path: A -> E
Route: A -> C -> D -> E
Distance: 10 + 6 + 4 = 20
========================================
========================================
Path: B -> C
Route: B -> D -> C
Distance: 5 + 6 = 11
========================================
========================================
Path: B -> D
Route: B -> D
Distance: 5
========================================
========================================
Path: B -> E
Route: B -> D -> E
Distance: 5 + 4 = 9
========================================
========================================
Path: C -> D
Route: C -> D
Distance: 6
========================================
========================================
Path: C -> E
Route: C -> D -> E
Distance: 6 + 4 = 10
========================================
========================================
Path: D -> E
Route: D -> E
Distance: 4
========================================
''''

## Possible errors

1. Invalid number of command-line arguments.
2. The file does not exist.
3. The file is empty.
4. The first line contains something other than digits.
5. One of the remaining lines doesn't match the pattern ```str1-str2,n```.
6. The number received on the first line does not coincide with the number of islands.

## Author
1. <a href="https://github.com/okhramkov" target="_blank">Oleksii Khramkov</a>
