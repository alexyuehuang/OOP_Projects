Alex Huang 465329 Lab2
test cases: 
first tested with tictactoe and gomoku files, both readed completely and successfully printed;
tested with only one input, printed error message;
changed a few lines of tictactoe, the programs is able to ignore irregular lines.
errors:
had couples of LNK errors, solved then with professor; also encountered vector out of bounds, then I fixed the 
bounds of the vector.
note: I treated blue as a valid color

extra credit:
how I designed: I iterated through the vector and printed out the member of the vector. Then I checked the boundary
conditions, and if there is element on it side, print it.
how I implement it: using 2 for loops and a bunch of if to recognize boundary conditions;
how I tested it: using test2.txt and ttt.txt. Both works well since my main func prints out the correct output and
does not crash. 