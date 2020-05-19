// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
@i 
M=0 // i = 0
@product
M=0 // product = 0

(LOOP)
    @i
    D=M // D = i
    @1
    D=M-D // D = R1 - i 
    @END
    D;JLE // if D <= 0 goto END
    
    @i
    M=M+1 // i = i + 1
    @0
    D=M // D = R0
    @product
    M=D+M // product = product + R0

    @LOOP
    0;JMP // goto LOOP

(END)

@product
D=M // D = product

@2
M=D // R2 = D