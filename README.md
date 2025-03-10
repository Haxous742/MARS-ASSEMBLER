# MARS-ASSEMBLER
A python assembler that converts the assembly code written in MARS to machine code

## Contents
- **Assembler.py**: Assembles the MIPS code.
- **Machine_code.txt**: Stores the output from the assembler.
- **Binary_search.asm**
- **GCD.asm**
- **GCD Folder**:
  - **GCD.cpp**: Code for GCD.
  - **GCD.asm**: Assembler code for GCD.
  - **GCD_MARS.bin**: Machine code generated from MARS.
  - **GCD_mc.bin**: Machine code generated from my assembler.
- **Binary Search Folder**:
  - **Binary_search.cpp**: Code for Binary Search.
  - **Binary_search.asm**: Assembly code for Binary Search.
  - **Binary_search_MARS.bin**: Machine code generated from MARS.
  - **Binary_search_mc.bin**: Machine code generated from my assembler.
- **Comparator Folder**:
  - **Assembled.txt**: Assembled code.
  - **Original.txt**: MARS code.
  - **Compare.py**: Compares the codes in Assembled.txt and Original.txt to find discrepancies.

## GCD MIPS Code
The code implements the Recursive Stein’s Algorithm to compute the GCD of two numbers. After assembling, it will prompt for two numbers and display the result.

![image](https://github.com/user-attachments/assets/5cee9afa-7421-4acf-92ad-db1c103482e8)

## Binary Search Code
After assembling, the program will:
1. Ask for the number of integers in the array.

![image](https://github.com/user-attachments/assets/f99f97d4-256f-4265-a579-60fc8b5040cb)

2. Prompt for the starting address of the array (e.g., 268501216).

![image](https://github.com/user-attachments/assets/3ab7a5f3-dfd1-4e68-af82-ef2c77d095de)

3. Require input of the sorted numbers one by one.

![image](https://github.com/user-attachments/assets/0dc0d278-764a-4f1f-a81e-4e41ae5ecb0e)

4. Ask for the target number to search.

![image](https://github.com/user-attachments/assets/cad5ab75-7020-470a-ad76-d0c632261d71)

If the number is found, the output will display its index (0-indexed); otherwise, it will state that the number was not found.

![image](https://github.com/user-attachments/assets/5ce2c7e5-99de-4cc3-95d6-93f9046699f9)

## Assembler
The assembler takes an `.asm` or `.txt` file as input and writes the machine code to **Machine_code.txt**.

For giving the input file, we have to put the file name at this location 
and compile the code:

![image](https://github.com/user-attachments/assets/6948c050-67db-4836-945d-c6ce58a6a5a3)

Output file:

![image](https://github.com/user-attachments/assets/5a2923bf-c8b4-4c0b-a65b-17036f977113)

After compiling, the machine code will be available in the output file 
and the process the assembler went with will be displayed in the cmd 
lines:

![image](https://github.com/user-attachments/assets/229ded52-036b-42db-8cb1-87aba09a54fd)

![image](https://github.com/user-attachments/assets/d7e92d33-7f1d-48f4-a45c-a19deb3aaf53)

![image](https://github.com/user-attachments/assets/b165b4ab-fa17-46d0-8a48-09a48821463e)

![image](https://github.com/user-attachments/assets/8c2412be-d822-49ed-91a1-ff86c9c50957)

## Comparator
This tool checks two text files: **Assembled.txt** and **Original.txt**. It confirms if the files are identical or displays the lines with mismatches.

![image](https://github.com/user-attachments/assets/5e97991d-5c98-4fdb-bc37-0ae2a48a46a5)

![image](https://github.com/user-attachments/assets/c8471ee4-675a-4eff-bf18-3e99bd6edbfa)

### How to Run the Comparator:
```bash
python Compare.py Original.txt Assembled.txt
```

## DISCLAIMER-
While giving the input to the assembler, we have to give the entire 
file including the .data segment as well, as it will use that to make 
address references for the data segments as well, and when we 
compare the assembled text with the MARS machine code, the 
mismatches shown are all address mis-matches of the .data segment 
as the assembler is not able to precisely calculate the address of all 
the .data segments as the MARS simulator, apart from that 
everything else should match. 

##  The instruction included in the assembler are:
  ### R-Type Instructions (Register-based operations)

| Instruction | Opcode (6 bits) | rs (5 bits) | rt (5 bits) | rd (5 bits) | shamt (5 bits) | funct (6 bits) | Description                                             |
|-------------|-----------------|-------------|-------------|------------|----------------|----------------|---------------------------------------------------------|
| **and**     | 000000         | rs          | rt          | rd         | 00000          | 100100         | Bitwise AND (`rd = rs & rt`)                            |
| **or**      | 000000         | rs          | rt          | rd         | 00000          | 100101         | Bitwise OR (`rd = rs \| rt`)                            |
| **sub**     | 000000         | rs          | rt          | rd         | 00000          | 100010         | Subtract (`rd = rs - rt`)                               |
| **sll**     | 000000         | 00000       | rt          | rd         | shamt          | 000000         | Shift Left Logical (`rd = rt << shamt`)                |
| **sllv**    | 000000         | rs          | rt          | rd         | 00000          | 000100         | Shift Left Logical Variable (`rd = rt << rs`)          |
| **srl**     | 000000         | 00000       | rt          | rd         | shamt          | 000010         | Shift Right Logical (`rd = rt >> shamt`)               |
| **slt**     | 000000         | rs          | rt          | rd         | 00000          | 101010         | Set on Less Than (`rd = 1 if rs < rt else 0`)           |
| **jr**      | 000000         | rs          | 00000       | 00000      | 00000          | 001000         | Jump Register (PC ← rs)                                 |
| **syscall** | 000000         | (unused)    | (unused)    | (unused)   | 00000          | 001100         | System call                                             |

---

### I-Type Instructions (Immediate-based operations)

| Instruction  | Opcode (6 bits) | rs (5 bits) | rt (5 bits) | Immediate (16 bits) | Description                                                        |
|--------------|-----------------|-------------|-------------|----------------------|--------------------------------------------------------------------|
| **addi**     | 001000         | rs          | rt          | imm                 | Add Immediate (`rt = rs + imm`)                                    |
| **andi**     | 001100         | rs          | rt          | imm                 | Bitwise AND Immediate (`rt = rs & imm`)                            |
| **beq**      | 000100         | rs          | rt          | offset              | Branch if Equal (if rs == rt then PC ← PC + (offset << 2))         |
| **bne**      | 000101         | rs          | rt          | offset              | Branch if Not Equal (if rs != rt then PC ← PC + (offset << 2))     |
| **lw**       | 100011         | base        | rt          | offset              | Load Word (`rt = MEM[base + offset]`)                              |
| **sw**       | 101011         | base        | rt          | offset              | Store Word (`MEM[base + offset] = rt`)                             |
| **ble** (pseudo) | -         | -           | -           | -                    | Branch if Less or Equal (pseudo-instruction, expands to other ops) |
| **la** (pseudo)  | -         | -           | -           | -                    | Load Address (pseudo-instruction)                                  |
| **li** (pseudo)  | -         | -           | -           | -                    | Load Immediate (pseudo-instruction)                                |

---

### J-Type Instructions (Jump-based operations)

| Instruction | Opcode (6 bits) | Target (26 bits) | Description                                                               |
|-------------|-----------------|------------------|---------------------------------------------------------------------------|
| **j**       | 000010         | target           | Jump (PC[31..28] stays same, PC[27..2] = target, PC[1..0] = 0)            |
| **jal**     | 000011         | target           | Jump and Link (`$ra = PC + 4` then jump to target)                        |

