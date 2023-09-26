from fill_tree_from_array import draw_heap
import heapq

arr = [4,17,12,20,25,15,38,22,30,24,45,67,18,40,42,36,56]

# Build min heap "arr"
# draw_heap(arr, "min") # This fails, heap is invalid

print("Drawing invalid heap for error spotting:  ")
draw_heap(arr, "min", "No_safety")