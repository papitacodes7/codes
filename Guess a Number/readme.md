# Number Guessing Game

This is a simple number guessing game where the user tries to guess a random number between 1 and 100. The user has 10 attempts to guess the correct number. After each guess, the game provides feedback on whether the guess was too high or too low. If the user guesses the correct number or runs out of attempts, the game ends and provides an option to start a new game.

## Features

- Random number generation between 1 and 100
- User input for guessing the number
- Feedback on whether the guess is too high or too low
- Display of previous guesses and remaining attempts
- Option to start a new game after the game ends

## Files

- `index.html`: The HTML file that contains the structure of the game.
- `style.css`: The CSS file that contains the styling for the game.
- `script.js`: The JavaScript file that contains the logic for the game.

## How to Play

1. Open `index.html` in a web browser.
2. Enter a guess in the input field and click the "Submit guess" button.
3. The game will provide feedback on whether the guess is too high or too low.
4. The game will display the previous guesses and the number of remaining attempts.
5. If the guess is correct or the user runs out of attempts, the game will end.
6. Click the "Start New Game" button to start a new game.

## JavaScript Code Explanation

### Variables

- `randomNumber`: Stores the random number to be guessed.
- `userInput`: Reference to the input field where the user enters their guess.
- `guessSlot`: Reference to the element that displays the previous guesses.
- `numGuess`: Counter for the number of guesses made.
- `remaining`: Reference to the element that displays the remaining attempts.
- `lowOrHi`: Reference to the element that displays feedback messages.
- `startOver`: Reference to the container for the "Start New Game" button.
- `playGame`: Boolean to track whether the game is active.
- `p`: Paragraph element for the "Start New Game" button.

### Functions

- `checkGuess(guess)`: Checks if the user's guess is correct, too high, or too low, and displays the appropriate message. Ends the game if the guess is correct.
- `displayGuess(guess)`: Updates the display with the user's guess and the remaining attempts.
- `displayMessage(message)`: Displays a message in the feedback area.
- `endGame()`: Ends the game, disables the input field, and displays the "Start New Game" button.
- `newGame()`: Starts a new game by resetting the variables and enabling the input field.

## Example Code

```javascript
function checkGuess(guess) {
  if (guess === randomNumber) {
    displayMessage(`You guessed it right! 🎉`);
    endGame();
  } else if (guess < randomNumber) {
    displayMessage(`Number is TOO low ⬆️`);
  } else if (guess > randomNumber) {
    displayMessage(`Number is TOO high ⬇️`);
  }
}

function displayGuess(guess) {
  userInput.value = '';
  guessSlot.innerHTML += `${guess}, `;
  numGuess++;
  remaining.innerHTML = `${11 - numGuess} `;
}

function displayMessage(message) {
  lowOrHi.innerHTML = `<h2>${message}</h2>`;
}

function endGame() {
  userInput.setAttribute('disabled', '');
  p.classList.add('button');
  p.innerHTML = `<button id="newGame">Start New Game</button>`;
  startOver.appendChild(p);
  playGame = false;
  newGame();
}

function newGame() {
  const newGameButton = document.querySelector('#newGame');
  newGameButton.addEventListener('click', function () {
    randomNumber = parseInt(Math.random() * 100 + 1);
    prevGuess = [];
    numGuess = 1;
    guessSlot.innerHTML = '';
    remaining.innerHTML = `${11 - numGuess} `;
    userInput.removeAttribute('disabled');
    startOver.removeChild(p);
    lowOrHi.innerHTML = '';
    playGame = true;
  });
}