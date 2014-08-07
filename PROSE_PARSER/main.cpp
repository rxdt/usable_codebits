/* 
 * @author Roxana del Toro
 *
 * Description: 
 * This program takes user input as a string of raw English prose. The program
 * removes single quotes but not apostrophes that are within a word. It then 
 * takes the string and tokenizes it into single words, or 'tokens' that have 
 * been removed of the common English delimiters (e.g. question marks). After 
 * formatting the tokens using delimiters, the words are sorted alphabetically 
 * and a struct is created for each unique word, but the word count of a struct of 
 * an already existing word is merely incremented.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * 
 * Upon running this program, a list of each unique word, 
 * and the count of each word, is printed out. 
 * 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <set>
#include <vector>
#include <algorithm>

#include "HW1_CSC340_PROSE_HEADER.h"

using namespace std;


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *      DECLARATIONS OF PROTOTYPES AND STRUCTURES
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// these structs will populate the data vector
struct myData
{
    string word;
    int count; 
};

vector<string> tokens; // vector contains ALL the raw words from prose
vector<myData> data; // a vector of the structs to count and track words

void cleanSingleQuotes(string&);
void Tokenize(const string& str,
              vector<string>& tokens,
              const string& delimiters);
void tallyWords(vector<string> tokens, vector<myData>& data);



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN    MAIN
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


int main()
{
  string prose;
  cout << "Enter your prose: \n"; 
  getline(cin, prose);
  cout << "You entered: \n" << prose << endl;
 
  cleanSingleQuotes(prose); 
  Tokenize(prose, tokens, " .,:;!?\"-");
  sort(tokens.begin(), tokens.end());  
  tallyWords(tokens, data);
  
  cout << "\nThe word count data is as follows:\n\n";
  cout << "WORD\t\t\t\t" << "COUNT\n";
  cout << "---------------------------------------\n";
  for (int i = 0; i < data.size(); i++)
  {   cout << data[i].word << "\t\t\t\t" << data[i].count << endl;
      cout << "---------------------------------------\n"; }
      
  
      return 0;
  
}




 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *     SUPPORTING FUNCTIONS
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */





/*
 * This function tokenizes the input string and inserts the tokens into a vector.
 * 
 * @pre {A string representing the input has been cleaned of single quotes and 
 * nothing else. Both vectors are empty.}
 * @post {The string has been tokenized into words, delimiters have been removed
 * and the tokens have been inserted into the vector of strings.} 
 * @param string& str: the user-input string sent from main.
 * @param vector<string>& tokens: the vector filled with the tokenized words
 * @param string& delimiters: a string that contains all the delimiters to eliminate
 * @return Void function. Populated string vector of tokens is returned. 
 */
void Tokenize(const string& str,
              vector<string>& tokens,
              const string& delimiters = " .,:;!?s\"-")
{
    // Skip delimiters at beginning.
    int lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    int pos = str.find_first_of(delimiters, lastPos);

    // while found a non-delimiter letter at start and end, consider it a word
    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector of strings.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}









/* This function cleans the user-input string of single quotes but not apostrophes.
 * @pre The string is in raw input form/ 
 * @post The string has been cleaned of all single quotes.
 * @param string& prose: the string to be cleaned.
 * @return A cleaned version of the string is returned. 
 */
void cleanSingleQuotes(string& prose)
{
    for(int i = 0; i < prose.size(); i++)
    {
        if(prose[i] == '\'' && prose[i+1] == ' ')
        {    prose.erase(i, 1); } 
        if(prose[i] == ' ' && prose[i+1] == '\'')
        {    prose.erase(i+1, 1); } 
        if(prose[i] == '\'' && prose[i+1] == '\0')
        {    prose.erase(i, 1); } 
    }
}









/* This function creates structs for each word/count to put into a data vector.
 * @pre The data vector is empty, the strings vector holds the cleaned tokens.
 * @post The data vector contains one struct for each unique word.
 * @param vector<string> tokens: vector containing delimiter-free word tokens
 * @param vector<myData>& data: vector containing structs for each unique word
 * @return The populated data vector that contains the structs and correct word counts.
 */
void tallyWords(vector<string> tokens, vector<myData>& data)
{
    myData temp; // a struct for the 1st word
    temp.word = tokens[0].substr(0, tokens[0].length());
    temp.count = 1;
    data.push_back(temp); // insert the first word struct into data vector
    
    // go through the vector of strings to count duplicates
    for(int i = 1; i < tokens.size(); i++)
    {   
        // if the word encountered is new/unique, create a new struct for it 
        if(tokens[i] != tokens[i-1])
        {
            myData temp; // initialize a struct of myData
            temp.word = tokens[i].substr(0, tokens[i].length());
            temp.count = 1;
            data.push_back(temp); // add the new struct to the vector of structs
        }
        if(tokens[i] == tokens[i-1])
        {
            data.back().count++;
        }
    }
}









