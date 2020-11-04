public class Sort {
	
	///////////// MAIN METHODS ///////////////

	public void mergeSort(int arr[], int l, int r) {
		_mergeSort(arr, 0, r - 1);
	}
	public void quickSort(int[] arr, int l, int r) {
		_quickSort(arr, 0, r - 1);
	}
	
	//////////// AUX METHODS //////////////////
	
	private void _quickSort(int arr[], int l, int r) {
		if(l < r) {
			int s = hoarePartition(arr, l, r);
			_quickSort(arr, l, s - 1);
			_quickSort(arr, s + 1, r);
		}
	}
	
	void swap(int[] arr, int i, int j) {
		int aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
	}
	
	private int hoarePartition(int arr[], int l, int r) {
		int p = arr[l];
		int i = l;
		int j = r + 1;
		do {
			do {
				i = i + 1;
			}while(!(arr[i] >= p || i >= r));
			do {
				j = j - 1;
			}while(!(arr[j] <= p));
			swap(arr, i, j);
		}while(!(i >= j));
		swap(arr, i, j);
		swap(arr, l, j);
		return j;
	}
	
	private void _mergeSort(int arr[], int l, int r) {
		if(l < r) {
			int m = (l + r) / 2;
			_mergeSort(arr, l, m);
			_mergeSort(arr, m + 1, r);
			merge(arr, l, r);
		} 
	}
	private void merge(int arr[], int l, int r) {
		int[] temp = new int[r+1];
		for(int i = l; i <= r; i++) {
			temp[i] = arr[i];
		}
		int m = (l + r) / 2;
		int i1 = l, i2 = m + 1;
		for(int curr = l; curr <= r; curr++) {
			if(i1 == m + 1) {
				arr[curr] = temp[i2++];
			} else if(i2 > r) {
				arr[curr] = temp[i1++];
			} else if(temp[i1] <= temp[i2]) {
				arr[curr] = temp[i1++];
			} else {
				arr[curr] = temp[i2++];
			}
			
		}
	}
}
