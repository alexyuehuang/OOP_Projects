Eventually I got rid of all errors, but I used to have some LNK error, then I realized it is because I should quit 
the cmd before rebuilding my app. I also got errors on syntax, mostly because I forgot ";".

Extra credit: I designed the auto player so that it detects the next winning move, if no winning moves are possible
I check if the opponent has a winning move. If both doesn't exist, I pick the center node. Then I added another part
in turn() so that it calls the autoplayer if the program is in auto mode and it is auto's turn. I tried autoplayer for
several rounds and it worked great. It actually beat me. 

Output:
4
3
2
1
0
 01234
X turn
please enter a valid coordinate or quit
1,1
4
3
2
1 X
0
 01234

Player X: 1, 1;

O turn
4
3
2  O
1 X
0
 01234

Player O: 2, 2;

X turn
please enter a valid coordinate or quit
2,1
4
3
2  O
1 XX
0
 01234

Player X: 1, 1; 2, 1;

O turn
4
3
2  O
1 XXO
0
 01234

Player O: 2, 2; 3, 1;

X turn
please enter a valid coordinate or quit
1,2
4
3
2 XO
1 XXO
0
 01234

Player X: 1, 1; 2, 1; 1, 2;

O turn
4
3 O
2 XO
1 XXO
0
 01234

Player O: 2, 2; 3, 1; 1, 3;

O won!