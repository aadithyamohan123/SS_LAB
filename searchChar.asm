ASSUME CS:CODE, DS:DATA

DATA SEGMENT 
    TEXT_PROMPT DB 10,13, "Enter text: $"
    SEARCH_PROMPT DB 10,13, "Enter character to search for: $"
    TEXT DB 100 DUP('$')      
    COUNT DW ?               
    SEARCH DB ?               
    FOUND DB 10,13, "FOUND$"
    NOTFOUND DB 10,13, "NOT FOUND$"
DATA ENDS

CODE SEGMENT
START:
    MOV AX, DATA
    MOV DS, AX
    MOV ES, AX

    MOV DX, OFFSET TEXT_PROMPT
    MOV AH, 09H
    INT 21H

    MOV DX, OFFSET TEXT
    MOV AH, 0AH            
    INT 21H

    MOV CL, [TEXT+1]
    MOV CH, 0        
    MOV COUNT, CX    


    MOV DX, OFFSET SEARCH_PROMPT
    MOV AH, 09H
    INT 21H

    MOV AH, 01H            
    INT 21H
    MOV SEARCH, AL        

    MOV CX, COUNT
    MOV DI, OFFSET TEXT+2 
    MOV AL, SEARCH

    REPNE SCASB            

    JZ YES                 


    MOV DX, OFFSET NOTFOUND
    MOV AH, 09H
    INT 21H
    JMP EXIT

YES:
    MOV DX, OFFSET FOUND
    MOV AH, 09H
    INT 21H

EXIT:
    MOV AH, 4CH
    INT 21H


CODE ENDS
END START
