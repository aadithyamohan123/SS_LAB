ASSUME CS:CODE, DS:DATA

DATA SEGMENT
ARRAY DW 5, 10, 15, 20, 25
SIZE DW 5
SUM DW 0
RESULT_MSG DB 10,13, "Sum of array elements is: $"
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX
    MOV ES, AX

    MOV CX, SIZE
    MOV SI, OFFSET ARRAY
    MOV BX, 0

SUM_LOOP:
    MOV AX, [SI]
    ADD BX, AX
    ADD SI, 2
    LOOP SUM_LOOP

    MOV SUM, BX

    MOV DX, OFFSET RESULT_MSG
    MOV AH, 09H
    INT 21H

    MOV AX, SUM
    CALL PRINT_NUMBER

    MOV AH, 4CH
    INT 21H

PRINT_NUMBER PROC
    MOV CX, 0
    MOV BX, 10

CONVERT_LOOP:
    XOR DX, DX
    DIV BX
    PUSH DX
    INC CX
    CMP AX, 0
    JNE CONVERT_LOOP

PRINT_DIGITS:
    POP DX
    ADD DL, '0'
    MOV AH, 02H
    INT 21H
    LOOP PRINT_DIGITS
    RET
PRINT_NUMBER ENDP

CODE ENDS
END START
