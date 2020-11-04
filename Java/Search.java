public class Search {
    
	///////////// MAIN METHODS ///////////////

    public int binarySearch(int arr[], int k) {
        int l = 0;
        int r = arr.length - 1;
        int m, resp = -1;
        while(l <= r) {
            m = (l + r) / 2;
            if(k == arr[m]) resp = m;
            if(k <= arr[m]) r = m - 1;
            else l = m + 1;
        }
        return resp;
    }
	
	//////////// AUX METHODS //////////////////
	
}


