from fill_tree_from_array import draw_heap
import heapq

print("H_1 after insert operation with key 12")
arr = [32,10,8,1,9,7,6]
heapq._heapify_max(arr)
heapq.heappush(arr, 12)
heapq._heapify_max(arr)
draw_heap(arr, "max")


print("H_2 after deleteMax operation:")
arr = [29,10,8,1,9,3,6]
heapq._heapify_max(arr)
heapq._heappop_max(arr)
heapq._heapify_max(arr)
draw_heap(arr, "max")