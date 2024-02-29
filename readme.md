# Secret Agent Crackme

Use your super secret pass phrase to gain access. Thats it.

## How to compile

'gcc -g source.c -o crackme.elf'

## Idea

This is x86 ELF file


### SPOILERS AHEAD





pass phrase structure:
'(xxxx-xxxx-xxxx-xxxx)'

there are total of 4 block checks
**1)** Requires an specific combination of symbols ('nmbr')

**2)** Is purely numerical (any combination of 4 numbers)

**3)** Requires an specific combination of symbols, which will be xored and checked to match control symbols ('prtk')

**4)** Uses two hex numbers, shifts their bits around and combines them to be an printable symbol and compares with input symbol ('mVZ+')