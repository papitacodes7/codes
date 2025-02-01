// Ek random number generate kar rahe hain jo 1 se 100 ke beech hoga
let randomNumber = parseInt(Math.random() * 100 + 1);

// HTML elements ko select kar rahe hain
const submit = document.querySelector('#subt');
const userInput = document.querySelector('#guessField');
const guessSlot = document.querySelector('.guesses');
const remaining = document.querySelector('.lastResult');
const lowOrHi = document.querySelector('.lowOrHi');
const startOver = document.querySelector('.resultParas');

// Naya paragraph element create kar rahe hain
const p = document.createElement('p');

// Pichle guesses store karne ke liye array aur guess count
let prevGuess = [];
let numGuess = 1;

// Game chal raha hai ya nahi, ye track karne ke liye
let playGame = true;

// Agar game chal raha hai to button par event listener lagayenge
// Jab user "submit" button dabayega, yeh function chalega
if (playGame) {
  submit.addEventListener('click', function (e) {
    e.preventDefault(); // Form submit hone se rok raha hai
    const guess = parseInt(userInput.value);
    console.log(guess); // Console me guess print karne ke liye
    validateGuess(guess); // Guess ko validate karna
  });
}

// User ke guess ko validate karne ka function
function validateGuess(guess) {
  if (isNaN(guess)) {
    alert('Please enter a valid number'); // Agar number nahi hai to alert
  } else if (guess < 1) {
    alert('Please enter a number more than 1'); // 1 se chhota number nahi chalega
  } else if (guess > 100) {
    alert('Please enter a number less than 100'); // 100 se bada number nahi chalega
  } else {
    prevGuess.push(guess); // Guess list me add kar rahe hain
    if (numGuess === 11) { // 10 guesses ho gaye to game over
      displayGuess(guess);
      displayMessage(`Game Over. Random number was ${randomNumber}`);
      endGame(); // Game ko khatam karna
    } else {
      displayGuess(guess);
      checkGuess(guess); // Guess ko check karna
    }
  }
}

// Check kar raha hai ki guess sahi hai ya nahi
function checkGuess(guess) {
  if (guess === randomNumber) {
    displayMessage(`You guessed it right! 🎉`); // Agar sahi guess kiya to message
    endGame(); // Game khatam karna
  } else if (guess < randomNumber) {
    displayMessage(`Number is TOO low ⬆️`); // Agar guess chhota hai to message
  } else if (guess > randomNumber) {
    displayMessage(`Number is TOO high ⬇️`); // Agar guess bada hai to message
  }
}

// User ke guesses aur remaining guesses ko update kar raha hai
function displayGuess(guess) {
  userInput.value = ''; // Input field clear kar rahe hain
  guessSlot.innerHTML += `${guess}, `; // Pichle guesses dikhane ke liye
  numGuess++;
  remaining.innerHTML = `${11 - numGuess} `; // Remaining guesses update kar rahe hain
}

// Message display karne ka function
function displayMessage(message) {
  lowOrHi.innerHTML = `<p class="game-over">${message}</p>`;
}


// Game over hone par input disable karega aur "New Game" button dikhayega
function endGame() {
  userInput.value = ''; // Input clear kar dena
  userInput.setAttribute('disabled', ''); // Input disable kar diya
  p.classList.add('button');
  p.innerHTML = `<h2 id="newGame">Start New Game</h2>`; // New game button add kar raha hai
  startOver.appendChild(p); // Button ko page par dikhana
  playGame = false; // Game stop kar dena
  newGame(); // Naya game start karne ka function call karna
}

function newGame() {
  const newGameButton = document.querySelector('#newGame');
  newGameButton.addEventListener('click', function () {
      // Generate new random number
      randomNumber = parseInt(Math.random() * 100 + 1);
      
      // Reset previous guesses and count
      prevGuess = [];
      numGuess = 1;
      
      // Clear previous guesses and remaining attempts
      guessSlot.innerHTML = '';
      remaining.innerHTML = `${11 - numGuess} `;
      
      // Enable input field
      userInput.removeAttribute('disabled');
      
      // Remove the "Start New Game" button
      startOver.removeChild(p);
      
      // ✅ Clear the Game Over message
      lowOrHi.innerHTML = '';
      
      // Allow the game to restart
      playGame = true;
  });
}