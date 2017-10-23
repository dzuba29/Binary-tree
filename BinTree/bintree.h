#ifndef BIN_TREE_H
#define BIN_TREE_H

struct bin_tree{

	int data;
	bin_tree *left, *right;
};

bin_tree *push_tree(bin_tree *&root, int element);

void print_tree(bin_tree *&root, int deep);

int search_element(bin_tree *&root, int element);

int node_counter(bin_tree *&root);

int leaf_counter(bin_tree *&root);

int pow_node(bin_tree *&root, int element);

int node_level(bin_tree *&root, int element);

int height_tree(bin_tree*&root);

int non_search(bin_tree*&root, int element);

bin_tree*node_remove(bin_tree *&root, int element);

#endif
