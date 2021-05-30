section .text
        global _ft_strcpy
_ft_strcpy:
        mov rcx, -1 ; i = -1

again:  inc rcx ; i++
        mov al, byte[rsi + rcx] ; src[i]
        mov byte[rdi + rcx], al ; dst[i] = src[i]
        cmp al, 0 ; if src[i] == 0
        je exit ; then return
        jmp again ; while (src[i])
        mov rax, rdi ; return dst
        ret
exit:
        mov rax, rdi ; return dst
        ret
