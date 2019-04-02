#include<bits/stdc++.h>

using namespace std;

struct node{
	int val;
	int alt;
	node *left;
	node *right;
};

int find_alt(node* temp){
    if(temp==NULL) return -1;

    return temp->alt;
}


node *new_node(int value){
	node *temp = new node;
	temp->val = value;
	temp->alt = 1;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node *RR(node *y){
    node *x, *t;
    //meu x aponta pra esqueerda de y e ele vai ser o novo y
    //logo a direita dele deve ser y
    x = y->left;
    t = x->right;
    //hora de transformar x no pai
    x->right = y;
    y->left = t;
    //hora de redimensionalizar o tamanho
    y->alt = max(find_alt(y->left), find_alt(y->right))+1;
    x->alt = max(find_alt(x->right), find_alt(x->left))+1;
    //retorno meu novo papaizinho

    return x;
}

node *LL(node *x){
    node *y, *t;
    y = x->right;
    t = y->left;
    y->left = x;
    x->right = t;
    x->alt = max(find_alt(x->right), find_alt(x->left)) +1;
    y->alt = max(find_alt(y->right), find_alt(y->left)) +1;
    return y;
}

int balance(node *n){
    if(n==NULL)
        return 0;
    return find_alt(n->left) - find_alt(n->right);
}

node *insert(node *temp, int value){
	if(temp==NULL){
		return new_node(value);
	}
	if(temp->val > value){
		temp->left = insert(temp->left, value);
	}
	else if(temp->val <= value){
		temp->right = insert(temp->right, value);
	}
	else{
        return temp;
	}
    temp->alt = 1+max(find_alt(temp->left), find_alt(temp->right));
    int b = balance(temp);
    if(b>1 && value < temp->left->val){
        return RR(temp);
    }
    if(b < -1 && value > temp->right->val){
        return LL(temp);
    }
    if(b > 1 && value > temp->left->val){
        temp ->left = LL(temp->left);
        return RR(temp);
    }
    if(b <-1 && temp->right->val > value){
        temp->right = RR(temp->right);
        return LL(temp);
    }
    return temp;
}

node *find(node *temp, int value){
    if(temp==NULL){
        cout << "Nao encontrado" << endl;
    }
    else if(temp->val == value){
        cout << "Valor: " << temp->val << " encontrado" << endl;
    }
    else if(temp->val>value){
        temp->left = find(temp->left, value);
    }
    else{
        temp->right = find(temp->right, value);
    }
    return temp;
}

int main(void){
	node *root=NULL;
	int x, t=0, k;
	while(cin >> x){
		root = insert(root, x);
		t++;
	}
    
	return 0;
}
