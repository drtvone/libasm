extern _ft_strlen
extern _malloc
; need to make error
section .text
        global _ft_strdup
_ft_strdup:
        call _ft_strlen ; calc string len
        push rdi ; save string
        mov rdi, rax ; move len for malloc
        inc rdi
        call _malloc ; allocare memory to rax
        pop rdi ; return rdi from stack
        mov rax, rdi ; return new string
        ret