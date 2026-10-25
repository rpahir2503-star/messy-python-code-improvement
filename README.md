# Bug Fixing Using Cursor AI

A practical software engineering and prompt engineering case study demonstrating how to identify, analyze, and fix critical program bugs using **Cursor AI** chain-prompting strategies.

- **Author**: Ayan Khan (Enrolment No: `25BCON1174`)
- **Institution**: JECRC University, Department of Computer Science & Engineering
- **GitHub Repository**: [https://github.com/ayankhanbebea-lgtm/bug-fixing-using-cursor-ai](https://github.com/ayankhanbebea-lgtm/bug-fixing-using-cursor-ai)

---

## 1. Problem Statement
The exercise evaluates an erroneous C/Python routine tasked with calculating the mathematical average of an integer array:

```c
#include <stdio.h>

float average(int arr[], int n) {
    int sum; 
    for(int i = 0; i <= n; i++) {
        sum += arr[i];
    } 
    return sum / n; 
} 

int main() {
    int data[5] = {10, 20, 30, 40, 51}; 
    printf("Average=%f\n", average(data, 5));
    return 0;
}
```

When compiled and executed, this program either crashes, produces unpredictable garbage numbers, or outputs an inaccurate truncated integer result.

---

## 2. Root Cause Bug Analysis

Through systematic review in Cursor AI, three distinct runtime bugs were identified:

| Bug # | Code Location | Nature of Bug | Runtime Impact | Fix Applied |
|:---:|:---|:---|:---|:---|
| **1** | `int sum;` | **Uninitialized Accumulator** | In C, local variables allocated on the stack hold indeterminate garbage values. Summing starts from an arbitrary non-zero number. | Initialized `int sum = 0;` (in Python: `total = 0.0`). |
| **2** | `for(int i = 0; i <= n; i++)` | **Off-By-One / Buffer Overflow** | For an array of size $n=5$, valid indexes are $0, 1, 2, 3, 4$. The condition `i <= n` attempts to read `arr[5]`, accessing out-of-bounds memory. | Updated loop boundary to `i < n`. |
| **3** | `return sum / n;` | **Integer Division Truncation** | Both `sum` and `n` are integers. Integer division truncates any fractional component before returning a `float`. | Cast accumulator before division: `(float)sum / n`. |

---

## 3. Single-Prompt vs. Chain-Prompting Methodology

In this study, two distinct prompt engineering strategies were tested:

### Approach A: Single-Prompt Strategy
- **Prompt**: `"Fix this code"`
- **Result**: The AI generated a quick fix, but lacked structured justification, failed to annotate which changed line addressed which defect, and did not systematically trace edge cases.

### Approach B: 3-Step Chain Prompting in Cursor AI
1. **Step 1 (Audit & Bug Enumeration)**:
   > *"You are a senior C language engineer reviewing code written by a second-year student. List every bug you find without fixing anything yet. Format as a numbered list with line numbers and one-line descriptions."*
2. **Step 2 (Runtime Impact & Trace Analysis)**:
   > *"For each bug you listed, explain in 2-3 lines what the program actually does at runtime because of it and what it was supposed to do. Do not give corrected code."*
3. **Step 3 (Targeted Refactoring with Verification)**:
   > *"Now provide the corrected version of the full program and add an inline comment on every line you change stating which bug number it fixes. Provide the exact expected output."*

### Empirical Comparison Matrix

| Evaluation Criteria | Single Prompt | Chain Prompting |
|:---|:---:|:---:|
| Bugs correctly identified | 5/5 | 5/5 |
| Quality of runtime explanations | 4/5 | 5/5 |
| Changed lines commented | 0/5 | 5/5 |
| Correct expected output verification | 3/5 | 5/5 |
| **Total Score** | **12/20** | **20/20** |

**Conclusion**: Chain prompting broke down complex reasoning into deterministic phases, ensuring each bug was verified before edits were made.

---

## 4. Verification & Testing

Expected output for dataset `{10, 20, 30, 40, 51}`:
$$\text{Sum} = 10 + 20 + 30 + 40 + 51 = 151$$
$$\text{Average} = \frac{151}{5} = 30.20$$

### Running the C Implementation:
```bash
gcc fixed_average.c -o fixed_average
./fixed_average
```

### Running the Python Implementation:
```bash
python fixed_average.py
```

Output:
```text
Dataset: [10, 20, 30, 40, 51]
Corrected Average: 30.20

Running verification tests...
 PASS: Dataset [10, 20, 30, 40, 51] -> Average = 30.20 (Expected: 30.2)
 PASS: Dataset [5, 5, 5, 5] -> Average = 5.00 (Expected: 5.0)
 PASS: Dataset [0, 100] -> Average = 50.00 (Expected: 50.0)
 PASS: Dataset [-10, 10] -> Average = 0.00 (Expected: 0.0)
All verification tests passed successfully!
```

---

## 5. Repository Structure
```text
.
├── buggy_average.c     # Original buggy C program
├── fixed_average.c     # Corrected C program with inline bug annotations
├── buggy_average.py    # Python representation of the buggy scenario
├── fixed_average.py    # Python implementation with automated test assertions
└── README.md           # Engineering documentation and comparison audit
```
