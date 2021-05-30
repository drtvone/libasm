extern ___error

section .text
    global _ft_write
_ft_write:
        mov rax, 0x2000004 ; call write
        syscall
        jc exit ; if error
        ret
exit:
        push rax ; save rax
        call ___error
        pop r9 ; return rax
        mov [rax], r9 ; push error to rax
        mov rax, -1 ; make error return flag -1
        ret