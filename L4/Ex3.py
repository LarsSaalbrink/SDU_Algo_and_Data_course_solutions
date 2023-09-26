from fill_tree_from_array import draw_heap
import heapq

arr = [5,9,11,14,18,19,21,33,17,27]
heapq.heappush(arr, 7)
draw_heap(arr, "min")
heapq.heappush(arr, 15)
draw_heap(arr, "min")

# Delete min heap "arr"
heapq.heappop(arr)
draw_heap(arr, "min")


