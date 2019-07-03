# Alphabetical-bts-word-finder-prog
\
A text concordance is an alphabetical listing of all distinct words in a piece of text. You are to write a program to construct a concordance for a document stored in a file. The words are to be stored in an array/vector of 26 binary search trees. Part of each node of the BST will have a circular linked list Queue. 
 
Your program should do the following: 
 
1.	Declares an array/vector of 26 BST’s, one for each letter of the alphabet. Words that begin with an ‘a’ or ‘A’ will be stored in the BST at location zero of the array. Words that begin with ‘b’ or ‘B’ will be stored in the BST at location one. The pattern continues for the remaining letters of the alphabet.  
 
In general, words that begin with character ch will be stored in the array at location upch – ‘A’, where upch is the uppercase equivalent of ch. 
 
2.	Read strings from a file and for each string: 
 
a.	Removes all characters from it that are not letters and converts all letters to uppercase. 
b.	If the string isn’t empty: 
i. Searches the appropriate BST for the string 
 
1.	If the word already is in the BST, insert the line number where the word occurred into the Queue that is part of the node of the BST. 
2.	If the word is not in the BST, insert the word and insert the line number where the word occurred into the Queue that is part of the node of the BST. 
 
3.	When the concordance is output, the words should be in alphabetical order, and for each word the line numbers will be displayed in ascending order. 
