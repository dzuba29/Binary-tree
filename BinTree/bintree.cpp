#include "bintree.h"
#include <iostream>
#include <iomanip>
bin_tree *push_tree(bin_tree *&root, int element){

	if (!root)
	{
		root = new bin_tree;
		root->left = 0;
		root->right = 0;
		root->data = element;
		return root;
	}
	if (element == root->data)
	{
		return root;
	}
	if (element < root->data)
	{
		root->left = push_tree(root->left, element);
		return root;
	}
	else if (element > root->data)
	{
		root->right = push_tree(root->right, element);
		return root;
	}

}

void print_tree(bin_tree *&root, int deep){

	if (root)
	{
		print_tree(root->left, deep + 1);
		for (int i = 0; i < deep; i++)
			std::cout << " ";
		std::cout << std::setw(deep) << ">" << root->data << std::endl;
		std::cout << " " << std::endl;
		print_tree(root->right, deep + 1);
	}
	else return;
}

int search_element(bin_tree *&root, int element){

	if (!root) return 0;
	if (element == root->data) return 1;
	if (element < root->data) return search_element(root->left, element);
	else return search_element(root->right, element);
}

int node_counter(bin_tree *&root){

	if (!root) return 0;
	else
	{
		int counter = 1;
		return counter = node_counter(root->right) + node_counter(root->left) + 1;
	}

}

int leaf_counter(bin_tree *&root){

	if (!root) return 0;
	int counter = 0;
	if ((root->left == 0) && (root->right == 0))
		counter++;
	else
	{
		if (root->left) counter += leaf_counter(root->left);
		if (root->right) counter += leaf_counter(root->right);
	}
	return counter;
}

int pow_node(bin_tree *&root, int element){

	if (element == root->data)
	{
		if (root->left == 0 && root->right == 0) return 0;
		if (root->left != 0 && root->right != 0) return 2;
		else return 1;
	}
	if (element <= root->data) { if (root->left != 0)  return pow_node(root->left, element); }
	else if (root->right != 0) return pow_node(root->right, element);
}

int node_level(bin_tree *&root, int element){

	int level = 0;
	if (element == root->data) return level;
	if (element <= root->data) return node_level(root->left, element) + 1;
	else return node_level(root->right, element) + 1;

}

int height_tree(bin_tree*&root){

	if (!root) return 0;
	else
	{
		int counter = 0;
		return counter = node_counter(root->right) + node_counter(root->left) + 1;
	}
}

int non_search(bin_tree*&root, int element){ //all branches search

	if (!root) return 0;
	else
	{
		int temp = 0;
		if (element == root->data) return 1;
		else
		{

			if (root->left) temp = non_search(root->left, element);
			if (root->right) temp = non_search(root->right, element);
		}
		return temp;

	}

}

bin_tree*node_remove(bin_tree *&root, int element){

	bin_tree *temp1, *temp2;

	if (!root) return root;

	if (root->data == element)
	{

		if (root->left == root->right)
		{
			delete(root);
			return 0;
		}

		else if (root->left == 0)
		{
			temp1 = root->right;
			delete root;
			return temp1;
		}
		else if (root->right == 0)
		{
			temp1 = root->left;
			delete root;
			return temp1;
		}

		else {
			temp2 = root->right;
			temp1 = root->right;
			while (temp1->left) temp1 = temp1->left;
			temp1->left = root->left;
			delete root;
			return temp2;
		}
	}
	if (root->data < element) root->right = node_remove(root->right, element);
	else root->left = node_remove(root->left, element);
	return root;
}
