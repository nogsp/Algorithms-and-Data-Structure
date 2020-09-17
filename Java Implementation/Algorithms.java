public class Algorithms {
	///////////// MAIN METHODS ///////////////
	public int binarySearch(int arr[], int k) {
		int l = 0;
		int r = arr.length - 1;
		int m;
		while(l <= r) {
			m = (l + r) / 2;
			if(k == arr[m]) return m;
			else if (k < arr[m]) r = m - 1;
			else l = m + 1;
		}
		return -1;
	}
	public void mergeSort(int arr[], int l, int r) {
		_mergeSort(arr, 0, r - 1);
	}
	//////////// AUX METHODS //////////////////
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
	private void _mergeSort(int arr[], int l, int r) {
		if(l < r) {
			int m = (l + r) / 2;
			_mergeSort(arr, l, m);
			_mergeSort(arr, m + 1, r);
			merge(arr, l, r);
		} 
	}
}
