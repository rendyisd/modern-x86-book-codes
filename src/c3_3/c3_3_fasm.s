; Simple LUT (section .rodata is read only)
section .rodata

prime_nums:     dd 2, 3, 5, 7, 11, 13, 17, 19, 23
                dd 29, 31, 37, 41, 43, 47, 53, 59
                dd 61, 67, 71, 73, 79, 83, 89, 97

global g_num_primes_a
g_num_primes_a: dd ($ - prime_nums) / 4


; Data section (section .data is read/write)
section .data

global g_sum_primes_a
g_sum_primes_a: dd -9999


; extern int mem_addressing_a(int32_t i,
;                             int32_t *v1, int32_t *v2,
;                             int32_t *v32, int32_t *v4);

section .text

global mem_addressing_a
mem_addressing_a:
    ; Make sure 'i' is valid
    cmp edi,-1
    jle invalid_index                   ;jump if i <= -1
    cmp edi,[g_num_primes_a]
    jge invalid_index                   ;jump if i >= g_num_primes_a

    ; Initialize
    movsxd r10,edi                      ;extend i to 64-bits
    lea r11,[prime_nums]                ;r11 = address of prime_nums

    ; Memory addressing - base register
    mov rdi,r10                         ;rdi = i
    shl rdi,2                           ;rdi = i * 4
    mov rax,r11                         ;rax = prime_nums
    add rax,rdi                         ;rax = prime_nums + i * 4
    mov eax,[rax]                       ;eax = prime_nums[i]
    mov [rsi],eax                       ;save to v1

    ; Memory addressing - base register + index register
    mov rdi,r10                         ;rdi = i
    shl rdi,2                           ;rdi = i * 4
    mov eax,[r11+rdi]                   ;eax = prime_nums[i]
    mov [rdx],eax                       ;save to v2

    ; Memory addressing - base register + index register * scale factor
    mov eax,[r11+r10*4]                 ;eax = prime_nums[i]
    mov [rcx],eax                       ;save to v3

    ; Memory addressing - base register + index register * scale factor + disp
    sub r11,42                          ;r11 = prime_nums - 42
    mov eax,[r11+r10*4+42]              ;eax = prime_nums[i]
    mov [r8],eax                        ;save to v4

    ; Memory addressing - RIP relative
    add [g_sum_primes_a],eax            ;update sum
    mov eax,1                           ;set success return code
    ret

invalid_index:
    xor eax, eax                        ; set return error code
    ret
