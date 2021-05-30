section .text
		global _ft_strcmp
_ft_strcmp:
		mov rcx, -1 ; i = -1

again:  inc rcx ; i++
		mov al, byte[rsi + rcx] ;s[i]
		mov bl, byte[rdi + rcx] ;s1[i]
		cmp al, 0 ; if s[i] == 0
		je end
		cmp bl, 0 ; if s1[i] == 0
		je end
		cmp al, bl ; if s[i] == s1[i]
		je again ; then again
		jmp exit ; else return
exit:
		movzx rax, byte[rdi + rcx]
		movzx rbx, byte[rsi + rcx]
		sub rax, rbx ; s1[i] - s[i]
		ret
end:
		cmp bl, 0 ; if s < s1
		jne checkbl
		cmp al, 0 ; if s1 < s
		jne checkal
		mov rax, 0 ; if s1 == s
		ret
checkbl:
		movzx rax, bl ; return s1
		ret
checkal:
		movzx rax, al ; return s
		neg rax
		ret