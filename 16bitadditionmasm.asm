ASSUME DS:DATA,CS:CODE

DATA SEGMENT
    MSG1 DB 10,13,"ENTER THE FIRST NUMBER:$"
    MSG2 DB 10,13,"ENTER THE SECOND NUMBER:$"
    MSG3 DB 10,13,"SUM IS:$"
DATA ENDS

CODE SEGMENT
    
START:
    MOV AX,DATA
    MOV DS,AX
    
    LEA DX,MSG1
    MOV AH,09H
    INT 21H
    
    MOV AH,01H
    INT 21H
    
    MOV BH,AL
    
    MOV AH,01H
    INT 21H
    
    MOV BL,AL
    
    LEA DX,MSG2
    MOV AH,09H
    INT 21H
    
    MOV AH,01H
    INT 21H
    
    MOV CH,AL
    
    MOV AH,01H
    INT 21H
    
    MOV CL,AL 
    
    MOV AL,BL
    MOV AH,00H
    
    ADD AL,CL
    AAA
    
    ADD AX,3030H
    MOV BL,AL
    
    MOV AL,AH
    MOV AH,00H
    
    ADD AL,BH
    ADD AL,CH
    AAA
    
    ADD AX,3030H
    
    MOV BH,AL
    MOV CL,AH
    
    LEA DX,MSG3
    MOV AH,09H
    INT 21H
    
    MOV DL,CL
    MOV AH,02H
    INT 21H
    
    MOV DL,BH
    MOV AH,02H
    INT 21H
    
    MOV DL,BL
    MOV AH,02H
    INT 21H
    
    MOV AH,4CH
    INT 21H

CODE ENDS
END START