#include<iostream>
#include<string>
#include<cctype>
#include<fstream>
#include<vector>
#include<algorithm>
#include<sstream>
#include"BinarySearchTree.h"

using namespace std;

const int ALPHABET_SIZE = 26; //const

void readingFile(BST stringBST[]);
void display(BST stringBST[]);

int main() 
{
	BST tree[ALPHABET_SIZE]; //for passing function calls

	readingFile( tree); //passing bst tree
	display(tree);

	system("pause");
	return 0;
}
/*---------------------------------------------------------
Name: readingFile()

Precondition: passing BST array into a function.

Postcondition: this function will read the texfile then will
impletement line counts, making textfile all uppercase,
remove all non alphabet characters and will be stored into BST
array in alphabetical order.
-----------------------------------------------------------*/
void readingFile(BST stringBST[])
{
	ifstream infile;
	string word;
	char stringChar;
	int lines = 1;


	infile.open("test.txt"); //open the file.
	if (!infile) //file check if open successfully then display positive if not then output unsuccessful
	{
		cout << "File is not be open . . ." << endl;
		exit(1107);
	}
	else
		cout << "File is open successfully . . ." << endl;

	while (getline(infile, word)) { //reading text in file

		istringstream ss(word); //this will help create a better '/n' for our line incremetation
		while (ss >> word) {

			for (int i = 0; i < word.size(); i++) { //loop each string[i]
				if (!isalpha(word[i])) { //if the word[i] is not a alphabet character
					word.erase(i, 1); //remove that character
					i--;
				}
			}

			transform(word.begin(), word.end(), word.begin(), ::toupper); //turn string to upper
			char front = word.at(0); //grabbing the first letter of each string
			int index = (int)((toupper(front) - 'A')); //subtract first letter of string to 'A' to get index for array
			stringBST[index].insert(word, lines); //insert into our BST insert method with passing text and line num
		}
		++lines; //line incrementing
	}
	infile.close();

}

void display(BST stringBST[])
{
	char letters;
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		letters = i + 'A';  // char letter is converting what array BST[i] adding A 
		cout << "Concord[" << letters << "]" << endl;
		cout << "----------------" << endl;//display Concord[leter]
		stringBST[i].inorder(cout); //displaying the array in BST in inorder
		cout << endl; //showing spacing for cleaness
		cout << endl;
	}


}
