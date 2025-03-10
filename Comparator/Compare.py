import sys

def compare_files(file1, file2):
    with open(file1, "r") as f1, open(file2, "r") as f2:
        lines1 = [line.strip() for line in f1 if line.strip()]
        lines2 = [line.strip() for line in f2 if line.strip()]
    
    max_lines = max(len(lines1), len(lines2))
    match = True
    for i in range(max_lines):
        l1 = lines1[i] if i < len(lines1) else ""
        l2 = lines2[i] if i < len(lines2) else ""
        if l1 != l2:
            print(f"Mismatch at line {i+1}:")
            print(f"File1: {l1}")
            print(f"File2: {l2}\n")
            match = False

    if match:
        print("All lines match.")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python compare_machine_codes.py file1 file2")
        sys.exit(1)
    compare_files(sys.argv[1], sys.argv[2])