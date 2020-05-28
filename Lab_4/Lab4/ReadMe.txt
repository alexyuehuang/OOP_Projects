Group Name : YuHuangDaDi
Group Member:
1. Xuyan Qin 449694
2. Alex Huang 465329
3. Alice Wang 465349

No error or warning occured.
The default winning number for Gomoku is 5
We have done extra credit part.

Test Run:
1. Input correct TicTacToe and correct board for the game printed
Lab4.exe TicTacToe
3
2
1
X 1 2 3

Please either enter a valid cordinate(in the form of: col#,row#) or enter quit

2. Input wrong String
Lab4.exe TicTac
usage: Lab4.exe String or String Number not correct!

3. Wrong number of input
Lab4.exe
usage: Lab4.exe String or String Number not correct!

4. User able to quit and number of rounds played were printed.
Lab4.exe TicTacToe
3
2
1
X 1 2 3

Please either enter a valid cordinate(in the form of: col#,row#) or enter quit
quit
0 turns were played. The user quit!

5. Correct input Gomoku
Lab4.exe Gomoku
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5
4
3
2
1
X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Please either enter a valid cordinate(in the form of: col#,row#) or enter quit

6. user able to quit gomoku game with number of rounds displayed
Please either enter a valid cordinate(in the form of: col#,row#) or enter quit
quit
0 turns were played. The user quit!

7. If not valid coordinate, reprompt user to enter the valid coordinate
Please either enter a valid cordinate(in the form of: col#,row#) or enter quit
0,0
Please Re-enter a valid coordinate within the range that has not been occupied
Please either enter a valid cordinate(in the form of: col#,row#) or enter quit

8. Able to make the move with each turn recorded.
Please either enter a valid cordinate(in the form of: col#,row#) or enter quit
1,1
PlayerO starts first
3
2
1 O
X 1 2 3

PlayerO: 1,1;

9. Player able to win and the exe automatically quit after the player wins.
It's playerO's turn
3
2 X X
1 O O O
X 1 2 3

PlayerO: 1,1;2,1;3,1;
PlayerO wins!

10. If draw, ouput message indicate draw and automatically quit after.
It's playerO's turn
3 X O X
2 O X O
1 O X O
X 1 2 3

PlayerO: 1,1;1,2;2,3;3,1;3,2;
9 turns were played. This is a Draw!

11. Gomoku able to win with all the moves recorded and printed out.
,5
It's playerB's turn
19
18
17
16
15
14
13
12
11
10
9
8
7
6
5 B       W
4 B     W
3 B   W
2 B W
1 B
X 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

PlayerB: 1,1;1,2;1,3;1,4;1,5;
PlayerB wins!

12. The default win is 5 therefore if the gameboard is 3*3, no player can win. It will always draw.
It's playerB's turn
3 W B W
2 B B W
1 B W B
X 1 2 3

PlayerB: 1,1;1,2;2,2;2,3;3,1;
9 turns were played. This is a Draw!

13. User able specify the board dimension and number of connected move to win.
Lab4.exe Gomoku 12 4
12
11
10
9
8
7
6
5
4
3
2
1
X 1 2 3 4 5 6 7 8 9 10 11 12

Please either enter a valid cordinate(in the form of: col#,row#) or enter quit

It's playerW's turn
12
11
10
9
8
7
6
5
4   W B B
3   W B
2   W
1 B W
X 1 2 3 4 5 6 7 8 9 10 11 12

PlayerW: 2,1;2,2;2,3;2,4;
PlayerW wins!

14. If numWin greater than board dimension. Print an error message.
Lab4.exe Gomoku 12 13
usage: Lab4.exe String or String Number not correct!

15. If numWin smaller than 3. Print an error message.
Lab4.exe Gomoku 12 2
usage: Lab4.exe String or String Number not correct!

16. If board dimension is 0 or numWin is 0.
Lab4.exe Gomoku 0 0
usage: Lab4.exe String or String Number not correct!
