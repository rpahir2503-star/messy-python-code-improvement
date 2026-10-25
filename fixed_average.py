"""
Bug Fixing using Cursor AI - Python Implementation
Corrected Version
"""

from typing import Sequence

def calculate_average(data: Sequence[float]) -> float:
    """Calculate the arithmetic mean of a sequence of numbers safely.
    
    Args:
        data: A non-empty sequence of numeric values.
        
    Returns:
        The exact arithmetic mean as a float.
        
    Raises:
        ValueError: If the input sequence is empty.
    """
    if not data:
        raise ValueError("Cannot calculate average of an empty dataset.")
    
    total = 0.0  # Fix 1: Properly initialized accumulator
    for val in data:  # Fix 2: Clean iteration without off-by-one indexing
        total += val
        
    return total / len(data)  # Fix 3: Standard float division

def run_tests():
    test_cases = [
        ([10, 20, 30, 40, 51], 30.2),
        ([5, 5, 5, 5], 5.0),
        ([0, 100], 50.0),
        ([-10, 10], 0.0),
    ]
    
    print("Running verification tests...")
    for nums, expected in test_cases:
        result = calculate_average(nums)
        assert abs(result - expected) < 1e-6, f"Failed for {nums}: expected {expected}, got {result}"
        print(f" PASS: Dataset {nums} -> Average = {result:.2f} (Expected: {expected})")
    print("All verification tests passed successfully!")

if __name__ == "__main__":
    nums = [10, 20, 30, 40, 51]
    avg = calculate_average(nums)
    print(f"Dataset: {nums}")
    print(f"Corrected Average: {avg:.2f}")
    print()
    run_tests()
