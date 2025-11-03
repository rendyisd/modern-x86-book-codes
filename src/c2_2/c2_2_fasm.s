section .text

global bitops_u32_a

bitops_u32_a:
    ; Calculate ~(((a & b) | c ) ^ d)

    ; This is System V calling convention ABI
    ; RDI, RSI, RDX, RCX, R8, R9
    ; return is stored at RAX
    and edi, esi
    or edi, edx
    xor edi, ecx
    not edi

    mov eax, edi

    ret
