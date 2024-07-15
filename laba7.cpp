#include <iostream>
#include <limits>

struct element {
	double k;
	element* left;
	element* right;
};

element* tree = NULL, * P, * Q;

void makeTree(double a) {
	if (!tree) {
		tree = new element;
		tree->k = a;
		tree->right = tree->left = NULL;
		P = tree;
		Q = NULL;
		return;
	}

	P = Q = tree;

	while (P != NULL) {
		Q = P;

		if (a < P->k) P = P->left;
		else P = P->right;
	}

	if (a < Q->k) {
		Q->left = new element;
		Q->left->k = a;
		Q->left->left = Q->left->right = NULL;
	}
	else {
		Q->right = new element;
		Q->right->k = a;
		Q->right->left = Q->right->right = NULL;
	}
}

void printTree(element* tree) {
	if (tree) {
		printTree(tree->left);
		std::cout << tree->k << " ";
		printTree(tree->right);
	}
}

double findMin(element* tree) {
	if (!tree) return std::numeric_limits<double>::infinity();
	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree->k;
}

double findMax(element* tree) {
	if (!tree) return -std::numeric_limits<double>::infinity();
	while (tree->right != NULL) {
		tree = tree->right;
	}
	return tree->k;
}

void printLeaves(element* tree) {
	if (!tree) return;
	if (!tree->left && !tree->right) {
		std::cout << tree->k << " ";
		return;
	}
	if (tree->left) printLeaves(tree->left);
	if (tree->right) printLeaves(tree->right);
}

int main() {
	makeTree(5);
	makeTree(3);
	makeTree(7);
	makeTree(1);
	makeTree(4);

	std::cout << "General view of the tree: " << 
		"\n      5"
		"\n     / \\"
		"\n    3   7"
		"\n   / \\"
		"\n  1   4"
		<< std::endl;

	std::cout << "The tree is in ascending order: ";
	printTree(tree);
	std::cout << std::endl;

	std::cout << "Minimum value: " << findMin(tree) << std::endl;
	std::cout << "Maximum value: " << findMax(tree) << std::endl;

	std::cout << "Tree leaves: ";
	printLeaves(tree);
	std::cout << std::endl;

	return 0;
}
