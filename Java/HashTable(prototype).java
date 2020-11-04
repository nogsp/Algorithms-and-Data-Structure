public class HashTable <E, T> {
	private class Content<E1, T1> {
		E1 header;
		T1 element;
		boolean deleted;
		Content(E1 header, T1 element) {
			this.header = header;
			this.element = element;
			this.deleted = false;
		} 
	}
	private int size;
	private int cnt;
	public Content<E, T>[] table;
	
	public HashTable(int size) {
		this.size = size;
		this.cnt = 0;
		this.table = new Content[size];
		for(int i = 0; i < size; i++) 
			this.table[i] = new Content<E, T>(null, null);
	}
	
	public void clear() {
		this.size = 0;
		this.cnt = 0;
		this.table = null;
	}
	
	public void resize(int size) {
		this.size = size;
		this.cnt = 0;
		this.table = new Content[size];
		for(int i = 0; i < size; i++)
			this.table[i] = new Content<E, T>(null, null);
	}
	
	private int h(String key) {
		int i, valor=7, str;
	    str = key.length();
	    for(i = 0; i < str; i++){
	        valor = (valor*31) + (int) key.charAt(i);
	    }
	    return valor;
	}
	
	private int h(int key) {
		return key % size;
	}
	private int hash(String key) {
		return (h(key) & 0x7FFFFFFF) % size;
	}
	private int hash(char key) {
		return (h((int)key - '0') & 0x7FFFFFFF) % size;
	}
	private int hash(int key) {
		return (h(key) & 0x7FFFFFFF) % size;
	}

	private int probing(int val, int i) {
		return ((val + i) & 0x7FFFFFFF) % size;
	}
	private int Hash(E key) {
		String op = key.getClass().getCanonicalName();
		if(op.equals("java.lang.String")) {
			return hash((String)key);
		} else if(op.equals("java.lang.Integer")) {
			return hash((Integer)key);
		} else if(op.equals("java.lang.Character")) {
			return hash((Character)key);
		} else {
			System.out.println("PRIMEIRO TIPO INCOMPATIVEL");
			return -1;
		}	
	}
	private int find(E key) { 
		int pos, start = 0;
		start = Hash(key);
		for(int i = 0; i < size; i++) {
			pos = probing(start, i);
			if(table[pos].header == null) {
				return -1;
			} else if(table[pos].header.equals(key) && table[pos].deleted == false) {
				return pos;
			}
		}
		return -1;
	}
	public Integer put(E key, T element) {
		int pos = find(key);
		if(pos != -1) {
			table[pos] = new Content<E, T>(key, element);
			return pos;
		}
		int start = Hash(key);
		for(int i = 0; i < size; i++) {
			pos = probing(start, i);
			if(table[pos].header == null || table[pos].deleted == true) {
				table[pos] = new Content<E, T>(key, element);
				cnt++;
				return pos;
			}
		}
		return null;
	}
	public T get(E key) {
		int pos = find(key);
		if(pos == -1) {
			return null;
		}
		return table[pos].element;
	}
	public Integer remove(E key) {
		int pos = find(key);
		if(pos == -1) {
			return null;
		}
		int start = Hash(key);
		for(int i = 0; i < size; i++) {
			pos = probing(start, i);
			if(table[pos].header.equals(key) && table[pos].deleted == false) {
				table[pos].deleted = true;
				cnt--;
				return pos;
			}
		}
		return null;
	}
	public Integer allocated() {
		return cnt;
	}
	
	public void showTable(FastIO IO) {
		for(int i = 0; i < size; i++) {
			if(table[i].header != null && table[i].deleted == false) {
				IO.out.append(table[i].header + " " + table[i].element + "\n");
			}
		}
	}

}
