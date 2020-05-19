// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

// initialize color state
@colored
M=0

(LOOP)
// check keyboard input
@24576
D=M

@COLORSCREEN
D;JGT

@ERASESCREEN
D;JEQ

(COLORSCREEN)
// if colored, goto loop
@colored
D=M
@LOOP
D;JGT

@i
M=0

// if not, color screen
(COLORLOOP)
@i
D=M
@16384
A=A+D
M=-1

@i
M=M+1
D=M
@16384
D=D+A
@24576
D=A-D
@COLORLOOP
D;JGT

@colored
M=1

@LOOP
0;JMP

(ERASESCREEN)
// if not colored, goto loop
@colored
D=M
@LOOP
D;JEQ

@i
M=0

// if not, color screen
(ERASELOOP)
@i
D=M
@16384
A=A+D
M=0

@i
M=M+1
D=M
@16384
D=D+A
@24576
D=A-D
@ERASELOOP
D;JGT

@colored
M=0

@LOOP
0;JMP