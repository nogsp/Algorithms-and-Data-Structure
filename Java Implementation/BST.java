public class BST<Key extends Comparable<Key>, E> {
	private BSTNode root;
	public int length;
	public BST() {
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
	public E remove(Key k) {
		E temp = findHelp(root, k);
		if(temp != null) {
			root = removeHelp(root, k);
			length--;
		}
		return temp;
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
		BSTNode(Key key, E element) {
			this.key = key;
			this.element = element;
			this.left = this.right = null;
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
		return rt;
	}
	private BSTNode getMin(BSTNode rt) {
		if(rt.left == null) return rt;
		return getMin(rt.left);
	}
	private BSTNode deleteMin(BSTNode rt) {
		if(rt.left == null) return rt.right;
		rt.left = deleteMin(rt.left);
		return rt;
	}
	private BSTNode removeHelp(BSTNode rt, Key k) {
		if(rt == null) return null;
		if(rt.key.compareTo(k) > 0) {
			rt.left = removeHelp(rt.left, k);
		} else if(rt.key.compareTo(k) < 0) {
			rt.right = removeHelp(rt.right, k);
		} else {
			if(rt.left == null) return rt.right;
			else if(rt.right == null) return rt.left;
			BSTNode temp = getMin(rt.right);
			rt.element = temp.element;
			rt.key = temp.key;
			rt.right = deleteMin(rt.right);
		}
		return rt;
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
}
