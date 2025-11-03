section .text

; extern void mul_i32_a(int* prod1, long long* prod2, int a, int b);
; extern int div_i32_a(int* quo, int* rem, int a, int b);

; So in short:
; If you really need 128-bit multiplication result
; you mush use the 1-operand imul.
;
; 1-operand imul is basically whatever register you pass (explicit register operand)
; multiplied by whatever it is in RAX (implicit register operand)
;
; the result of 1-operand is stored in RDX:RAX high and low 64-bit respectively

global mul_i32_a
mul_i32_a:
    mov eax, edx                ; eax = a
    imul edx, ecx               ; edx = a * b (32-bit product)
    mov [rdi], edx              ; save a * b to prod1

    movsxd rax, eax             ; rax = a (sign-extended)
    movsxd rcx, ecx             ; rcx = b (sign-extended)
    imul rcx                    ; rdx:rax = a * b (128-bit product)
    mov [rsi], rax              ; save low-order qword to prod2

    ret

global div_i32_a
div_i32_a:
    or ecx, ecx                 ; is b == 0?
    jz division_by_zero         ; jump if yes

    mov eax, edx                ; eax = a
    cdq                         ; sign-extend a to 64-bits (edx:eax)
    idiv ecx                    ; eax = quotient, edx = remainder

    mov [rdi], eax
    mov [rsi], edx
    
    mov eax, 1
    ret

division_by_zero:
    xor eax, eax
    ret
