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
@0
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
(LOOP_START)
@0
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
@0
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
@1
D=A
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
@SP
M=M-1
@SP
A=M
D=M
@R13
M=D
@0
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
@0
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
@SP
A=M
D=M
@LOOP_START
D;JNE
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
