ENTRY(main);

PHDRS {
    headers PT_LOAD FILEHDR PHDRS;
    code PT_LOAD FLAGS(0x05);
}

/* The kernel is loaded at 0x7e00 */
SECTIONS {
    .text 0x7F00 : ALIGN(0x100) {
        *(.text)
    } : code

    .data : {
        *(.data)
    }

    .bss : {
        *(.bss)
    }

    /DISCARD/ : {
        *(.eh_frame)
    }
}