section .text

global sum_vals_i32_a
sum_vals_i32_a:
    ; Calculate a + b + c + d
    add edi, esi
    add edx, ecx
    add edi, edx

    ; Calculate e + f + g + h
    add r8d, r9d                    ; r8d = e + f
    mov eax, [rsp+8]                ; eax = g
    add eax, [rsp+16]               ; eax = g + h
    add eax, r8d                    ; eax = e + f + g + h

    ; Add both
    add eax, edi

    ret

global mul_vals_u64_a
mul_vals_u64_a:
    ; Calculate a * b * c * d * e * f * g * h
    mov r10, rdx                    ; Remember RDX:RAX, so we must save whatever is in RDX
    mov rax, rdi                    ; RAX = a
    mul rsi                         ; RAX = a * b
    mul r10                         ; RAX = a * b * c
    mul rcx                         ; RAX = a * b * c * d
    mul r8                          ; RAX = a * b * c * d * e
    mul r9                          ; RAX = a * b * c * d * e * f
    mul qword [rsp+8]               ; RAX = a * b * c * d * e * f * g
    mul qword [rsp+16]              ; RAX = a * b * c * d * e * f * g * h

    ret
