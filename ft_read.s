extern ___error

section .text
        global _ft_read
_ft_read:
        mov rax, 0x2000003 ; call read
        syscall
        jc exit ; if error 
        ret
exit:
        push rax ; save rax to stack
        call ___error ; check error
        pop r9 ; return rax from stack
        mov [rax], r9 ; move error to stack
        mov rax, -1 ; make error return flag -1
        ret