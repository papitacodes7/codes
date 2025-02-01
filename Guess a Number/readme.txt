1. Initialize variables:
    - randomNumber = random number between 1 and 100
    - userInput = reference to input field
    - guessSlot = reference to guess display area
    - numGuess = 0
    - remaining = reference to remaining guesses display
    - lowOrHi = reference to message display area
    - startOver = reference to new game button container
    - playGame = true
    - p = create a new paragraph element

2. Function checkGuess(guess):
    - If guess equals randomNumber:
        - Display "You guessed it right! 🎉"
        - Call endGame()
    - Else if guess is less than randomNumber:
        - Display "Number is TOO low ⬆️"
    - Else if guess is greater than randomNumber:
        - Display "Number is TOO high ⬇️"

3. Function displayGuess(guess):
    - Clear the input field
    - Add guess to guessSlot
    - Increment numGuess
    - Update remaining guesses display

4. Function displayMessage(message):
    - Show message in lowOrHi

5. Function endGame():
    - Disable the input field
    - Add "Start New Game" button to p
    - Add p to startOver
    - Set playGame to false
    - Call newGame()

6. Function newGame():
    - Add event listener to new game button
    - When new game button is clicked:
        - Generate new random number
        - Reset previous guesses
        - Reset numGuess to 1
        - Clear guessSlot
        - Reset remaining guesses display
        - Enable the input field
        - Remove new game button from startOver
        - Set playGame to true


Initialize Variables:
Generate a random number between 1 and 100.
Get references to various HTML elements (input field, guess display area, remaining guesses display, message display area, and new game button container).
Initialize variables to keep track of the number of guesses and whether the game is active.
Function to Check the User's Guess:

If the user's guess matches the random number:
Display a success message.
End the game.
If the user's guess is lower than the random number:
Display a message indicating the guess is too low.
If the user's guess is higher than the random number:
Display a message indicating the guess is too high.
Function to Display the User's Guess:

Clear the input field.
Add the user's guess to the list of previous guesses.
Increment the number of guesses.
Update the display of remaining guesses.
Function to Display a Message:

Show a message in the message display area.
Function to End the Game:

Disable the input field.
Create a new button for starting a new game.
Add the new game button to the page.
Set the game to inactive.
Call the function to start a new game.
Function to Start a New Game:

Add an event listener to the new game button.
When the new game button is clicked:
Generate a new random number.
Reset the list of previous guesses.
Reset the number of guesses.
Clear the previous guesses display.
Reset the remaining guesses display.
Enable the input field.
Remove the new game button from the page.
Set the game to active.