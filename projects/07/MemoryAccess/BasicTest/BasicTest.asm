@APP_START
0;JMP
(EQUALITY_TRUE)
@R13
M=D
@SP
A=M
D=M
@EQUALITY_FALSE
D;JNE
@SP
A=M
M=-1
@SP
M=M+1
@R13
A=M
0;JMP
(EQUALITY_FALSE)
@SP
A=M
M=0
@SP
M=M+1
@R13
A=M
0;JMP
(GREATER_FALSE)
@R13
M=D
@SP
A=M
D=M
@GREATER_TRUE
D;JGT
@SP
A=M
M=0
@SP
M=M+1
@R13
A=M
0;JMP
(GREATER_TRUE)
@SP
A=M
M=-1
@SP
M=M+1
@R13
A=M
0;JMP
(LESS_TRUE)
@R13
M=D
@SP
A=M
D=M
@LESS_FALSE
D;JLE
@SP
A=M
M=-1
@SP
M=M+1
@R13
A=M
0;JMP
(LESS_FALSE)
@SP
A=M
M=0
@SP
M=M+1
@R13
A=M
0;JMP
(APP_START)
@10
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@0
D=A
@LCL
A=M
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@21
D=A
@SP
A=M
M=D
@SP
M=M+1
@22
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@2
D=A
@ARG
A=M
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@1
D=A
@ARG
A=M
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@36
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@6
D=A
@THIS
A=M
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@42
D=A
@SP
A=M
M=D
@SP
M=M+1
@45
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@5
D=A
@THAT
A=M
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@2
D=A
@THAT
A=M
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@510
D=A
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@6
D=A
@R5
D=D+A
@R14
M=D
@R13
D=M
@R14
A=M
M=D
@0
D=A
@LCL
A=M
A=D+A
D=M
@SP
A=M
M=D
@SP
A=M
M=D
@SP
M=M+1
@5
D=A
@THAT
A=M
A=D+A
D=M
@SP
A=M
M=D
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
M=M-1
@SP
A=M
M=D+M
@SP
M=M+1
@1
D=A
@ARG
A=M
A=D+A
D=M
@SP
A=M
M=D
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
M=M-1
@SP
A=M
M=M-D
@SP
M=M+1
@6
D=A
@THIS
A=M
A=D+A
D=M
@SP
A=M
M=D
@SP
A=M
M=D
@SP
M=M+1
@6
D=A
@THIS
A=M
A=D+A
D=M
@SP
A=M
M=D
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
M=M-1
@SP
A=M
M=D+M
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
M=M-1
@SP
A=M
M=M-D
@SP
M=M+1
@6
D=A
@R5
A=D+A
D=M
@SP
A=M
M=D
@SP
A=M
M=D
@SP
M=M+1
@SP
M=M-1
A=M
D=M
@SP
M=M-1
@SP
A=M
M=D+M
@SP
M=M+1
