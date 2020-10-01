
// A Stack based C++ program to find next
// greater element for all array elements.
#include <bits/stdc++.h>
using namespace std;

/* prints element and NGE pair for all
elements of arr[] of size n */
void printNGE(int arr[], int n) {
stack < int > s;

/* push the first element to stack */
s.push(arr[0]);

// iterate for rest of the elements
for (int i = 1; i < n; i++) {

	if (s.empty()) {
	s.push(arr[i]);
	continue;
	}

	/* if stack is not empty, then
	pop an element from stack.
	If the popped element is smaller
	than next, then
	a) print the pair
	b) keep popping while elements are
	smaller and stack is not empty */
	while (s.empty() == false && s.top() < arr[i])
	{
		cout << s.top() << " --> " << arr[i] << endl;
		s.pop();
	}

	/* push next to stack so that we can find
	next greater for it */
	s.push(arr[i]);
}

/* After iterating over the loop, the remaining
elements in stack do not have the next greater
element, so print -1 for them */
while (s.empty() == false) {
	cout << s.top() << " --> " << -1 << endl;
	s.pop();
}
}

/* Driver program to test above functions */
int main() {
int arr[] = {11, 13, 21, 3};
int n = sizeof(arr) / sizeof(arr[0]);
printNGE(arr, n);
return 0;
}

*/

/*
// Simple C++ program to print next greater elements in a given array

#include<iostream>
using namespace std;

/* prints element and NGE pair
//for all elements of arr[] of size n
void printNGE(int arr[], int n)
{
	int next, i, j;
	for (i = 0; i < n; i++)
	{
		next = -1;
		for (j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}
		cout << arr[i] <<" -- "<< next << endl;
	}
}

// Driver Code
int main()
{
	int arr[] = {11, 13, 21, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	printNGE(arr, n);
	return 0;
}

*/
