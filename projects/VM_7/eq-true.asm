@256
D=A
@SP
M=D
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
(APP_START)
@8
D=A
@SP
A=M
M=D
@SP
M=M+1
@8
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
M=D-M
@RET_ADDRESS_CALL0
D=A
@EQUALITY_TRUE
0;JMP
(RET_ADDRESS_CALL0)
