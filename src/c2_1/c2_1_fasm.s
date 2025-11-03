section .text

global add_sub_i32_a

add_sub_i32_a:
    ; Calculate (a + b) - (c + d) + 7

    ; This is System V calling convention ABI
    ; RDI, RSI, RDX, RCX, R8, R9
    ; return is stored at RAX
    add edi, esi
    add edx, ecx
    sub edi, edx
    add edi, 7

    mov eax, edi

    ret
