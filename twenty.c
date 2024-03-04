/*
 * twenty.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//Function to create a game tree with predefined questions and guesses
struct node* createGameTree(){
	struct node* gameTreeRoot = NULL; //Initializes a pointer to the game tree's root

	//Inserts all the predefined questions and guesses into the tree
	gameTreeRoot = insert(gameTreeRoot, 100, "Does it grow underground?", "");
	insert(gameTreeRoot, 50, "Is it long in shape?", "");
	insert(gameTreeRoot, 25, "Is it orange in color?", "");
	insert(gameTreeRoot, 15, "", "It's a carrot!");
	insert(gameTreeRoot, 35, "", "It's a parsnip!");
	insert(gameTreeRoot, 75, "Is it red in color?", "");
	insert(gameTreeRoot, 65, "", "It's a radish!");
	insert(gameTreeRoot, 85, "", "It's a potato!");
	insert(gameTreeRoot, 150, "Does it grow on a tree?", "");
	insert(gameTreeRoot, 125, "Is it red in color?", "");
	insert(gameTreeRoot, 115, "", "It's an apple!");
	insert(gameTreeRoot, 135, "", "It's a peach!");
	insert(gameTreeRoot, 175, "Is it red in color?", "");
	insert(gameTreeRoot, 165, "", "It's a tomato!");
	insert(gameTreeRoot, 185, "", "It's a pea!");

	return gameTreeRoot; //Returns the pointer to the created game tree's root
}

//Function to play the game recursively
void playGame(struct node* currentNode) {
    char response;

    if (currentNode->guess[0] != '\0') { //If it's a guess node, ask if it's correct
        printf("%s\ny/n: ", currentNode->guess);
        scanf(" %c", &response);
        if (response == 'y') { //The game guesses correctly
            printf("I win!\n");
        } else { //When the game is not able to guess the correct answer
            printf("You win!\n");

            //Prompt the user for the correct answer and a distinguishing question if the game did not guess the answer correctly
            char new_guess[100];
            char new_question[100];
            printf("What is it? ");
            scanf(" %[^\n]", new_guess);
            printf("Please enter a yes/no question that would have helped guess %s correctly: ", new_guess);
            scanf(" %[^\n]", new_question);

            //Updates the tree with the new question and answer given by the user
            free(currentNode->guess);
            currentNode->guess = strdup(new_guess);
            currentNode->question = strdup(new_question);
        }
    } else { //If it is a question node, ask the question
        printf("%s\ny/n: ", currentNode->question);
        scanf(" %c", &response);
        if (response == 'y') { //The user responds 'yes'
            playGame(currentNode->left); //Continues with the left child
        } else { //The user responds 'no'
            playGame(currentNode->right); //Continues with the right child
        }
    }
}

//The main method
int main() {
	struct node* gameTreeRoot = createGameTree(); //Creates the game tree with all the predefined questions and guesses
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    char userInput = 0; //Initialize a character variable for user input

    //To continue playing the game until the user wants to quit
    while (1) {
        scanf(" %c", &userInput);

        if (userInput == 'q') //The user wants to quit
        	break;
        printf("You think of a fruit or vegetable and I will try to guess it!\n");
        playGame(gameTreeRoot); //Starts playing the game using the created game tree
        printf("Press 'q' to quit or any other key to continue:\n");
    }

    printf("Bye Bye!\n"); //Displays the goodbye message on quitting the game
    return 0;
}
