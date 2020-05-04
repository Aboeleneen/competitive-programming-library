E 300 05 00  // load 5 in memory loaction 300
A 100  // create machine executable code in memory begining at 100
MOV AX,1 // load 1 in register AX
MOV CX,[300] // load the value in memory loaction 300 in register CX
MUL CX   // (DX AX) = AX * CX
LOOP 107 // go to memory location 107 and loop untill CX equal zero
INT 3 // interput 


// problem two
E 400 0A 00 // load 0A in memory location 400
A 100  //  create machine executable code in memory begining at 100
MOV AX,0  // load zero in register AX
MOV BX,[400] // load the value in memory location 400 in register BX
CMP CX,BX // compare the value in CX with the value in BX
JA 112 // if CX greater than BX jump to memory loaction 112
ADD AX,CX // add the value in CX to AX
ADD CX,2  // add two the value in CX
JMP 107 // jump to memory location 107
INT 3 // interput--> end of thr program

A 200  // start
MOV CX,1 // load one in register cx
JMP 100 // jump to memory location 100

A 300
MOV CX,0 // load zero in register cx
JMP 100 // jump to memory location 100




//problem three 
E 300 10 20 40 50 80 90
A 100
MOV AX,0
MOV CX,6
MOV BX,300
MOV DL,[BX]
CMP DX,80 
JGE 118
CMP DX,20
JLE 118
ADD AL,DL
INC BX
LOOP 109
INT 3

//problem four 
E 300 32 05
A 100
MOV DL,[300]
MOV CL,[301]
MOV BX,200
CMP CX,0
JE 115
MOV [BX],DL
INC BX
LOOP 
INT 3





