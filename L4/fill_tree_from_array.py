from binarytree import build

class HeapError(Exception):
    pass

def is_max_heap(arr):
    """
    Check if the input array represents a valid max heap.
    """
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        if 2 * i + 1 < n and arr[i] < arr[2 * i + 1]:
            return False
        if 2 * i + 2 < n and arr[i] < arr[2 * i + 2]:
            return False
    return True

def is_min_heap(arr):
    """
    Check if the input array represents a valid min heap.
    """
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        if 2 * i + 1 < n and arr[i] > arr[2 * i + 1]:
            return False
        if 2 * i + 2 < n and arr[i] > arr[2 * i + 2]:
            return False
    return True

def draw_heap(arr, heap_type, safety="Safety"):
    """
    Draw a heap from the input array and raise an error if the array
    does not represent a valid heap (max or min).
    """
    if safety == "Safety":
        if (not (heap_type == "max" and is_max_heap(arr))) and (not (heap_type == "min" and is_min_heap(arr))):
            raise HeapError("Input array does not represent a valid heap (max or min)")

    # Build the binary tree using the binarytree library
    root = build(arr)
    
    # Print the heap type and the binary tree
    print(heap_type + " heap: ")
    print(root)

