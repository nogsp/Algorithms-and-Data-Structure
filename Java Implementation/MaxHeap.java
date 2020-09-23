class MaxHeap {
	
  private Integer[] heap;
	private Integer iterator;
	private Integer allocated;
	
	public MaxHeap (Integer allocated) {
		this.allocated = allocated + 1;
		this.iterator = 0;
		this.heap = new Integer[allocated + 1];
		this.heap[0] = null;
	}
	
	public void push(Integer val) {
		if(iterator == allocated) {
			System.out.println("Heap is already full");
			return;
		}
		heap[++iterator] = val;
		int it = iterator;
		while(heap[parent(it)] != null && heap[it] > heap[parent(it)]) {
			swap(it, parent(it));
			it = parent(it);
		}
	}
	
	public Integer pop() {
		int deleted = heap[1];
		heap[1] = heap[iterator--];
		bottomUp(1);
		return deleted;
	}
	
	public Integer top() {
		return heap[1];
	}
	
	public Integer length() {
		return iterator;
	}
	
	public void bottomUp() {
		for(int i = iterator / 2; i >= 1; i--) {
			int k = i;
			int v = heap[k];
			boolean key = false;
			while(!key && 2 * k <= iterator) {
				int j = 2 * k;
				if(j < iterator && heap[j] < heap[j + 1]) {
					j++;
				}
				if(v >= heap[j]) {
					key = true;
				} else {
					heap[k] = heap[j];
					k = j;
				}
			}
			heap[k] = v;
		}
	}
	
	private void bottomUp(int pos) {
		int i = pos;
		int k = i;
		int v = heap[k];
		boolean key = false;
		while(!key && 2 * k <= iterator) {
			int j = 2 * k;
			if(j < iterator && heap[j] < heap[j + 1]) {
				j++;
			}
			if(v >= heap[j]) {
				key = true;
			} else {
				heap[k] = heap[j];
				k = j;
			}
		}
		heap[k] = v;
	}
	
	private Integer parent(Integer son) {
		return son / 2;
	}
	
	private void swap(Integer it1, Integer it2) {
		int temp = heap[it1];
		heap[it1] = heap[it2];
		heap[it2] = temp;
	}
}
