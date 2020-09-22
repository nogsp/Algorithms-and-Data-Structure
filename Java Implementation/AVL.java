public class AVL<Key extends Comparable<Key>, E> {
	private BSTNode root;
	public int length;
	public AVL() {
		this.root = null;
		this.length = 0;
	}
	public E find(Key k) {
		return findHelp(root, k);
	}
	public void insert(Key k, E e) {
		root = insertHelp(root, k, e);
		length++;
	}
	public void preorder() {
		_preorder(root);
	}
	public void inorder() {
		_inorder(root);
	}
	public void posorder() {
		_posorder(root);
	}
	private class BSTNode {
		Key key;
		E element;
		BSTNode left, right;
		private int height;
		BSTNode(Key key, E element) {
			this.key = key;
			this.element = element;
			this.left = this.right = null;
			this.height = 0;
		}
	}
	private E findHelp(BSTNode rt, Key k) {
		if(rt == null) {
			return null;
		}
		Integer cmp = rt.key.compareTo(k);
		if(cmp > 0) {
			return findHelp(rt.left, k);
		} else if(cmp == 0) {
			return rt.element;
		} else {
			return findHelp(rt.right, k);
		}
	}
	private BSTNode insertHelp(BSTNode rt, Key k, E e) {
		if(rt == null) {
			return new BSTNode(k, e);
		}
		Integer cmp = rt.key.compareTo(k);
		if(cmp > 0) {
			rt.left = insertHelp(rt.left, k, e);
		} else {
			rt.right = insertHelp(rt.right, k, e);
		}
		rt.height = 1 + max(height(rt.left), height(rt.right));
		int balance = getBalance(rt);
		
		if(balance > 1 && rt.left.key.compareTo(k) > 0) {
			return rightRotate(rt);
		}
		
		if(balance < -1 && rt.right.key.compareTo(k) <= 0) {
			return leftRotate(rt);
		}
		
		if(balance > 1 && rt.left.key.compareTo(k) <= 0) {
			rt.left = leftRotate(rt.left);
			return rightRotate(rt);
		}
		
		if(balance < -1 && rt.right.key.compareTo(k) > 0) {
			rt.right = rightRotate(rt.right);
			return leftRotate(rt);
		}
		return rt;
	}
	private Integer height(BSTNode rt) {
		if(rt == null) return -1;
		return rt.height;
	}
	private Integer getBalance(BSTNode rt) {
		if(rt == null) return 0;
		return height(rt.left) - height(rt.right);
	}
	
	private BSTNode rightRotate(BSTNode rt) {
		BSTNode l = rt.left;
		BSTNode lr = l.right;
		l.right = rt;
		rt.left = lr;
		rt.height = 1 + max(height(rt.left), height(rt.right));
		l.height = 1 + max(height(l.left), height(l.right));
		return l;
	}
	private BSTNode leftRotate(BSTNode rt) {
		BSTNode r = rt.right;
		BSTNode rl = r.left;
		r.left = rt;
		rt.right = rl;
		rt.height = 1 + max(height(rt.left), height(rt.right));
		r.height = 1 + max(height(r.left), height(r.right));
		return r;
	}
	
	private void _preorder(BSTNode rt) {
		if(rt == null) return;
		System.out.print(rt.key + " ");
		_preorder(rt.left);
		_preorder(rt.right);
	}
	private void _inorder(BSTNode rt) {
		if(rt == null) return;
		_inorder(rt.left);
		System.out.print(rt.key + " ");
		_inorder(rt.right);
	}
	private void _posorder(BSTNode rt) {
		if(rt == null) return;
		_posorder(rt.left);
		_posorder(rt.right);
		System.out.print(rt.key + " ");
	}
	private Integer max(Integer a, Integer b) {
		if(a >= b) return a;
		return b;
	}
}
