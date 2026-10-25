"""
Bug Fixing using Cursor AI - Python Implementation
Original Buggy Version
"""

def calculate_average(data):
    # Bug 1: Uninitialized accumulator conceptually
    # Bug 2: Off-by-one indexing error
    # Bug 3: Handling floating point division
    total = None
    for i in range(len(data) + 1):  # Index out of bounds error
        total += data[i]
    return total / len(data)

if __name__ == "__main__":
    nums = [10, 20, 30, 40, 51]
    try:
        avg = calculate_average(nums)
        print(f"Average: {avg}")
    except Exception as e:
        print(f"Runtime Error Encountered: {type(e).__name__} - {e}")
