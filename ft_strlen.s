section .text
        global _ft_strlen
_ft_strlen:
        mov     rax, -1 ; i = -1
again:  inc rax ; i++
        cmp rdi, 0
        je end
        cmp  byte[rdi + rax], 0 ; i ? 0
        jne again ; while (i != 0)
        ret
end:
        mov rax, 0
        ret