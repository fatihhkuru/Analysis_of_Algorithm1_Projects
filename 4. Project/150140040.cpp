#include<iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
using namespace std;
//fatih KURU 150140040
class Node{//Node Class
public:
	string name;//---Attributes---- variables
	string color;
	string age;
	string gender;

	Node *left;//-- pointers
	Node *right;
	Node *parent;

	int num_woman;//holding the how many woman or man under them
	int num_man;

	void add_name(string);//setter functions
	void add_age(string);
	void add_gender(string);
	void add_color(string);

	string get_name();//getter functions
	string get_age();
	string get_gender();
	string get_color();

	Node();//constructor
};

Node::Node(){//default constructor
	name = "";
	color = "";
	age = "";
	gender = "";
	num_man = 0;
	num_woman = 0;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}
string Node::get_color(){//return color
	return color;
}
string Node::get_name(){//return name
	return name;
}
string Node::get_age(){//return age
	return age;
}
string Node::get_gender(){//return gender
	return gender;
}
void Node::add_color(string newColor){//add color to node
	color = newColor;
}
void Node::add_name(string newName){//add name to node
	name = newName;
}
void Node::add_age(string newAge){//add age to node
	age = newAge;
}
void Node::add_gender(string newGender){//add gender to node
	gender = newGender;
}
void adding_size(Node*node){// adding size to node such as num_woman and num_man

	if (node == NULL)
		return;

	adding_size(node->left);//recursive approximation first left then right then middle (left-right-middle)
	adding_size(node->right);

	if (node->left == NULL && node->right != NULL){//left node is null and right node isnt null
		if (node->get_gender() == "M"){//if node is a male node , increase the num_man +1 and right node's num_man
			node->num_man = node->right->num_man + 1;
			node->num_woman = node->right->num_woman;//also include the num_woman because he has also woman under him
		}
		else if (node->get_gender() == "F"){//if node is a woman node , increase the num_woman +1 and right node's num_woman
			node->num_woman = node->right->num_woman + 1;
			node->num_man = node->right->num_man;//also including the num_man because she has also man under her
		}
	}
	else if (node->left != NULL && node->right == NULL){//left node isnt null and right node is null
		if (node->get_gender() == "M"){//if node is a male node , increase the num_man +1 and left node's num_man
			node->num_man = node->left->num_man + 1;
			node->num_woman = node->left->num_woman;//also include the num_woman because he has also woman under him
		}
		else if (node->get_gender() == "F"){//if node is a woman node , increase the num_woman +1 and left node's num_woman
			node->num_woman = node->left->num_woman + 1;
			node->num_man = node->left->num_man;//also including the num_man because she has also man under her
		}
	}
	else if (node->left == NULL && node->right == NULL){//left node is null and right node is null
		if (node->get_gender() == "M")
			node->num_man = 1;//he has only one node, it's himself
		else if (node->get_gender() == "F")
			node->num_woman = 1;//she has only one node, it's herself
	}
	else{//Both left node and right node isnt empty
		if (node->get_gender() == "M"){//if this node is man
			node->num_man = node->left->num_man + node->right->num_man + 1;
			node->num_woman = node->left->num_woman + node->right->num_woman;
		}
		else if (node->get_gender() == "F"){//if this node is woman
			node->num_man = node->left->num_man + node->right->num_man;
			node->num_woman = node->left->num_woman + node->right->num_woman + 1;
		}
	}
}
string nth_woman(Node*node, int i){//finding the i'th smallest key for node

	int r;//rank
	if (node->get_gender() == "F"){//if node is female
		if (node->left == NULL){//it means node has no female node  
			r = 1;//ranki da bu olur
		}
		else{//it means node has female node in the left side
			r = node->left->num_woman + 1;//this will be her rank. +1 meaning, she also included
		}
	}
	else if (node->get_gender() == "M"){//same process for man except +1
		if (node->left == NULL){
			r = 0;
		}
		else{
			r = node->left->num_woman;
		}
	}

	if ((i == r) && node->get_gender() == "F"){//if a node is we looking for
		return node->get_name();//return the name of the node
	}
	else if (i <= r){//if i smaller and equal than r 
		return nth_woman(node->left, i);
	}
	else{//if i is bigger than r
		return nth_woman(node->right, i - r);
	}

}

string nth_man(Node*node, int i){

	int r;//rank
	if (node->get_gender() == "M"){//if node is male
		if (node->left == NULL){//it means node has no male node 
			r = 1;//rank will be 1
		}
		else{//it means node has male node in the left side
			r = node->left->num_man + 1; // this will be his rank. + 1 meaning, he also included
		}
	}
	else if (node->get_gender() == "F"){//same process for woman except +1
		if (node->left == NULL){
			r = 0;
		}
		else{
			r = node->left->num_man;
		}
	}

	if ((i == r) && node->get_gender() == "M"){//if a node is we looking for
		return node->get_name();//return the name of the node
	}
	else if (i <= r){//if i smaller and equal than r 
		return nth_man(node->left, i);
	}
	else{//if i is bigger than r
		return nth_man(node->right, i - r);
	}

}

Node* root = new Node;//global root descrpition
void tree_insert(Node*);//prototype for tree-insert
void rb_insert(Node* x){
	tree_insert(x);//first adding node to binary tree
	x->add_color("R");//our added node always will be red, mayber later will change related to conditions
	Node*temp = new Node;//temp node
	while ((x->get_name() != root->get_name()) && (x->parent->get_color() == "R")){// x is a root? and parent is red?if the answer no for either them  

		if (x->parent == ((x->parent)->parent)->left){//parent left child? yes
			if (x->parent->parent->right != NULL){
				if ((((x->parent)->parent)->right)->get_color() == "R"){//case1:	uncle is red?-- yes
					x->parent->add_color("B");//color parent black
					x->parent->parent->right->add_color("B");//color uncle black
					x->parent->parent->add_color("R");//color grandparent red
					x = x->parent->parent;//x = Grandparent(x)
				}
			}
			else{//uncle is  red? no
				if (x == (x->parent)->right){//case 2 : X is a right child? --yes 

					x->parent->parent->add_color("R");//color grandparent red
					x->add_color("B");//color x black

					x->left = x->parent; //Left Rotate
					((x->parent)->parent)->left = x;
					(x->parent)->right = NULL;
					(x->parent) = x->parent->parent;
					(x->left)->parent = x;

					x = x->left;

					temp = x->parent->right;//Right rotate
					x->parent->right = x->parent->parent;
					x->parent->parent->left = temp;

					if (x->parent->parent->parent->right->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->right = x->parent;
					else if (x->parent->parent->parent->left->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->left = x->parent;

					x->parent->parent = x->parent->parent->parent;

					x->parent->right->parent = x->parent;

					break;
				}
				else{//case3: X is a right child? --no

					x->parent->add_color("B");//color parent black
					x->parent->parent->add_color("R");//color grandparent red

					temp = x->parent->right;//-----Right rotate-----
					x->parent->right = x->parent->parent;
					x->parent->parent->left = temp;

					if (x->parent->parent->parent->right->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->right = x->parent;
					else if (x->parent->parent->parent->left->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->left = x->parent;

					x->parent->parent = x->parent->parent->parent;

					x->parent->right->parent = x->parent;
					break;
				}
			}
		}
		else{//parent is right child left and right swapped
			if (x->parent->parent->left != NULL){
				if ((((x->parent)->parent)->left)->get_color() == "R"){//case1:	uncle is red?-- yes
					x->parent->add_color("B");//color parent black
					x->parent->parent->left->add_color("B");//color uncle black
					x->parent->parent->add_color("R");//color grandparent red
					x = x->parent->parent;//x = GrandParent(x)
				}
			}
			else{//uncle is  red? no
				if (x == (x->parent)->left){//case 2 : X is a left child? --yes 

					x->parent->parent->add_color("R");//color grandparent red
					x->add_color("B");//color x black

					x->right = x->parent; //----------Left Rotate
					((x->parent)->parent)->right = x;
					(x->parent)->left = NULL;
					(x->parent) = x->parent->parent;
					(x->right)->parent = x;

					x = x->right;

					temp = x->parent->left;//-----------Right rotate
					x->parent->left = x->parent->parent;
					x->parent->parent->right = temp;

					if (x->parent->parent->parent->left->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->left = x->parent;
					else if (x->parent->parent->parent->right->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->right = x->parent;

					x->parent->parent = x->parent->parent->parent;

					x->parent->left->parent = x->parent;

					break;
				}
				else{//case3: X is a left child? --no

					x->parent->add_color("B");//color parent black
					x->parent->parent->add_color("R");//color grandparent red

					temp = x->parent->left;//--------------Right rotate
					x->parent->left = x->parent->parent;
					x->parent->parent->right = temp;

					if (x->parent->parent->parent->left->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->left = x->parent;
					else if (x->parent->parent->parent->right->get_name() == x->parent->parent->get_name())
						x->parent->parent->parent->right = x->parent;

					x->parent->parent = x->parent->parent->parent;

					x->parent->left->parent = x->parent;
					break;
				}
			}
		}

	}
	root->add_color("B");//color X black 
}

void tree_insert(Node* insert){//I use the my old data structures homework's binary tree pseudo code 
	Node*traverse, *newNode;//traverse is traversing the tree, new Node is 
	traverse = root;//traverse is root
	newNode = new Node;//i keep dynamic
	newNode = insert;
	if (root == NULL){//checking the node is Null
		root = newNode;
		return;
	}
	while (traverse != NULL){//traversing process
		if ((newNode->get_name()) < traverse->get_name()){//traversing left
			if (traverse->left != NULL){
				traverse = traverse->left;
			}
			else{
				traverse->left = newNode;
				newNode->parent = traverse;//parent assignment
				return;
			}
		}
		else if ((newNode->get_name()) > traverse->get_name()){//traversing right
			if (traverse->right != NULL){
				traverse = traverse->right;
			}
			else{
				newNode->parent = traverse;//parent assignment
				traverse->right = newNode;
				return;
			}
		}
	}
	return;
}
int depth = 0;
void print_tree(Node* node)
{
	if (node == NULL)
		return;
	depth++;//depth increase every depth
	print_tree(node->left);//i use left-middle-right approximation 

	for (int i = 0; i < depth; i++){
		cout << "       ";//empty field 
	}
	if (node->parent == NULL){
		cout << "(" + node->get_color() + ")" + node->get_name() + "\u2500" + node->get_age() + "\u2500" + node->get_gender() << "\n";
	}
	else if (node == node->parent->left){
		cout << "\u250C";//char(218);
		cout << "(";
		cout << node->get_color();
		cout << ")";
		cout << node->get_name() + "\u2500" + node->get_age() + "\u2500" + node->get_gender() << "\n";
	}
	else if (node == node->parent->right){
		cout << "\u2514";//char(192);
		cout << "(";
		cout << node->get_color();
		cout << ")";
		cout << node->get_name() + "\u2500" + node->get_age() + "\u2500" + node->get_gender() << "\n";
	}
	else{
		cout << "(" + node->get_color() + ")" + node->get_name() + "\u2500" + node->get_age() + "\u2500" + node->get_gender() << "\n";
	}
	print_tree(node->right);
	depth--;

}
int main(int argc, char*argv[]){
	const char* open_file = argv[2];//reading file
	const char* mynumber = argv[1];//150140040

	ifstream myfile(open_file);//opening the file.

	root = NULL;//root for main tree is NULL

	int word_order = 0;//keep the order of number

	string line;//temp line

	while (getline(myfile, line, '\n')) {
		stringstream ss(line);//line spliting
		string temp;//temp string
		Node* templateNode = new Node;// template Node object
		while (getline(ss, temp, '\t')) {
			if (word_order == 0){//first one->> name
				templateNode->add_name(temp);
				word_order++;
			}
			else if (word_order == 1){//second one goes to gender
				templateNode->add_gender(temp);
				word_order++;
			}
			else if (word_order == 2){// third one goes to age
				templateNode->add_age(temp);
				word_order = 0;

			}

		}

		rb_insert(templateNode);// red black insertion
	}
	adding_size(root);//size is identified
	string thirth = nth_woman(root, 3);
	string fourth = nth_man(root, 4);
	print_tree(root);
	cout << "3rd woman: " << thirth << endl;
	cout << "4th man: " << fourth << endl;
	getchar();
}
