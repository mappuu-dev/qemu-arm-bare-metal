.global _start

_start:
    ldr sp, =_stack_end
    bl main
    b .
