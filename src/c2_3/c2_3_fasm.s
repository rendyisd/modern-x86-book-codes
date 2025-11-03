section .text

global shift_u32_a

; extern int shift_u32_a(unsigned int *a_shl,
;                        unsigned int *a_shr,
;                        unsigned int a,
;                        unsigned int count);

shift_u32_a:
    cmp ecx, 32                     ; is count >= 32
    jae bad_count                   ; jump to bad_count if count >= 32

    mov eax, edx                    ; eax = a 
    shl eax, cl                     ; shift left
    mov [rdi], eax                  ; save result to a_shl

    shr edx, cl                     ; same thing as above
    mov [rsi], edx

    mov eax, 1                      ; valid shift count return code

    ret

bad_count:
    xor eax, eax                    ; apparently this is better than just mov eax, 0
    ret
