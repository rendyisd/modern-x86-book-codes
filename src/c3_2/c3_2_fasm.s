section .text

; extern int64_t calc_result_i64_a(int8_t a, int16_t b, int32_t c, int64_t d,
;                                  int8_t e, int16_t f, int32_t g, int64_t h);
global calc_result_i64_a
calc_result_i64_a:
    ; Calculate (a * b * c * d) + (e * f * g * h)
    movsx rax, dil              ; rax = a (sign-extend)
    movsx r10, si               ; r10 = b (sign-extend)
    imul rax, r10               ; rax = a * b
    movsxd r10, edx             ; r10 = c (sign-extend)
    imul rax, r10               ; rax = a * b * c
    imul rax, rcx               ; rax = a * b * c * d

    movsx r10, r8b              ; r10 = e (sign-extend)
    movsx r11, r9w              ; r11 = f (sign-extend)
    imul r10, r11               ; r10 = e * f
    movsxd r11, dword [rsp+8]   ; r11 = g (sign-extend)
    imul r10, r11               ; r10 = e * f * g
    imul r10, [rsp+16]          ; r10 = e * f * g * h

    add rax, r10
    
    ret

; extern void calc_result_u64_a(uint8_t a, uint16_t b, uint32_t c, uint64_t d,
;                               uint8_t e, uint16_t f, uint32_t g, uint64_t h,
;                               uint64_t* quo, uint64_t* rem);
global calc_result_u64_a
calc_result_u64_a:
    ; Calculate quotient and remainder for (a + b + c + d) / (e + f + g + h)

    ; Calculate (a + b + c + d)
    movzx rax, dil
    movzx r10, si
    add rax, r10
    mov r11d, edx               ; So apparently in x86 if you set the lower 32-bits of a 64-bits register it will clear the higher 32-bits, so this works
    add r11, rcx
    add rax, r11

    ; Calculate (e + f + g + h)
    movzx r10, r8b
    movzx r11, r9w
    add r10, r11
    mov r11d, [rsp+8]
    add r11, [rsp+16]
    add r10, r11

    xor edx, edx                ; clear rdx (double-width dividend rule)
    div r10                     ; rdx:rax = rdx:rax / r10

    mov rcx, [rsp+24]
    mov [rcx], rax
    mov rcx, [rsp+32]
    mov [rcx], rdx
