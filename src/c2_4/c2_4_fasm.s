section .text

global add_sub_i64_a_a
add_sub_i64_a_a:
    ; Calculate (a + b) - (c + d) + 7
    add rdi, rsi
    add rdx, rcx
    sub rdi, rdx
    add rdi, 7
    
    mov rax, rdi

    ret

section

global add_sub_i64_b_a
add_sub_i64_b_a:
    ; Calculate (a + b) - (c + d) + 12345678900
    add rdi, rsi
    add rdx, rcx
    sub rdi, rdx

    mov rax, 12345678900
    add rax, rdi

    ret
