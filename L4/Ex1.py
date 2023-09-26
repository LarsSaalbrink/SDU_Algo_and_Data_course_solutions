from fill_tree_from_array import draw_heap
import heapq

print("H_1 after deleteMax operation:")
arr = [42,41,23,3,9,17,6]
# heapq._heapify_max(arr) # Build max heap "arr"
# draw_heap(arr, "max")

# Deletemax heap "arr"
heapq._heappop_max(arr)
draw_heap(arr, "max")

print("H_2 after an insert operation with key 35:")
arr = [42,33,37,3,18,17,4]
heapq._heapify_max(arr) # Build max heap "arr"

# Insert key 35 into max heap "arr"
heapq.heappush(arr, 35)
heapq._heapify_max(arr)
draw_heap(arr, "max")


