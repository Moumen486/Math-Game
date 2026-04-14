## Math-Quiz-Game
A console-based Math Quiz game written in C++. Supports multiple difficulty levels, operation types, score tracking, colored feedback, and a final pass/fail result.

## ➕➖✖️➗ Math Quiz Game (C++)
This is an interactive console-based Math Quiz game written in C++.
The player answers a set of randomly generated math questions based on selected difficulty level and operation type, with instant feedback and a final result summary.

## 🎮 How It Works
The player chooses:
Number of questions (1–10)
Question difficulty:
Easy
Medium
Hard
Mixed
Operation type:
Addition
Subtraction
Multiplication
Division
Mixed
For each question:
Two random numbers are generated based on the difficulty level.
A math operation is applied.
The player enters their answer.
The program checks the answer and gives instant feedback:
🟢 Green → Correct answer
🔴 Red → Wrong answer (with correct result shown)
After all questions, the final results are displayed.
## 🔧 Features
Customizable number of questions (1–10).
Multiple difficulty levels (Easy, Medium, Hard, Mixed).
Multiple operation types (Add, Sub, Mul, Div, Mixed).
Random question generation.
Tracks correct and wrong answers.
Final PASS / FAIL result.
Color-based feedback for each answer.
Replay option after finishing the quiz.
## 🧠 Technical Concepts Used
Enumerations (enum): For question levels and operation types.
Structures (struct): To organize questions and quiz data.
Random number generation: For questions and mixed operations.
Functions: For modular design (generate questions, validate answers, show results).
Arrays: To store multiple questions.
Console color formatting: Using system("color") for visual feedback.
Input validation: Ensures correct user inputs.
## 🖥️ How to Compile and Run
Make sure you have a C++ compiler installed (e.g. g++).
Save the file as Math-Quiz-Game.cpp.
Compile and run:
