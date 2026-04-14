#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

enum enQuestionLevel{Easy=1,Medium=2,Hard=3,Mix=4};
enum enOperationType{Add=1,Sub=2,Mult=3,Div=4,MixOp=5};
struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enOperationType OperatioType;
	enQuestionLevel QuestionLevel;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};
struct stQuiz
{
	stQuestion QuestionsList[100];
	short NumberOfQuestions;
	enQuestionLevel QuestionLevel;
	enOperationType OpType;
	short NumberOfWrongAnswers=0;
	short NumberOfRightAnswers=0;
	bool isPass = false;
};
string GetOpType(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
	case enOperationType::Div:
		return "/";
	case enOperationType::Mult:
		return "*";
	case enOperationType::Sub:
		return "-";
	default:
		return "Mix";

	}
}
void SetScreenColor(bool Right)
{
	if (Right)
		system("color 2F"); // Green for correct answers.
	else
	{
		system("color 4F"); // Red for incorrect answers.
		cout << "\a"; // Plays an alert sound.
	}
}
int RandomNumber(int from, int to)
{
	int randum = rand() % (to - from + 1) + from;
	return randum;
}
short ReadHowManyQuestions()
{
	short NumberOfQuestions;
	do
	{
		cout << "How many questions do you want to answer? \n";
		cin >> NumberOfQuestions;

	} while (NumberOfQuestions < 1 || NumberOfQuestions>10);
	return NumberOfQuestions;
}
string GetQuestionLevelText(enQuestionLevel QuestionLevel)
{
	string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mix" };
	return arrQuestionLevelText[QuestionLevel - 1];
}
enQuestionLevel ReadQuestionsLevel()
{
	short QuestionLevel = 0;
	do
	{
		cout << " Enter Q uestion Level Easy[1],  Medium[2],  Hard[3],   Mix[4] \n";
		cin >> QuestionLevel;

	} while (QuestionLevel < 1 || QuestionLevel>4);
	return (enQuestionLevel)QuestionLevel;
}
enOperationType ReadOperationType()
{
	short OperationType = 0;
	do
	{
		cout << "Enter Operation Type  Add[1],   Sub[2],   Mult[3],    Div[4],    MixOp[5] ? \n";
		cin >> OperationType;

	} while (OperationType < 1 || OperationType>5);
	return (enOperationType)OperationType;
}
enOperationType GetRandomOperationType()
{
	int Op = RandomNumber(1, 4);
	return (enOperationType)Op;

}
int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
	case enOperationType::Sub:
		return Number1 - Number2;
	case enOperationType::Div:
		return Number1 / Number2;
	case enOperationType::Mult:
		return Number1 * Number2;
	default:
			return Number1 + Number2;
	}
}
stQuestion GenerateQuestion(enQuestionLevel QuestionLevel,enOperationType OpType)
{
	stQuestion Question;

	if (QuestionLevel == enQuestionLevel::Mix)
	{
		QuestionLevel = (enQuestionLevel)RandomNumber(1, 3);
	}
	if (OpType == enOperationType::MixOp)
	{
		OpType=(enOperationType)RandomNumber(1,4);
	}
	Question.OperatioType = OpType;

	switch (QuestionLevel)
	{
	case enQuestionLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperatioType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::Medium:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperatioType);
		Question.QuestionLevel = QuestionLevel;
		return Question;

	case enQuestionLevel::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OperatioType);
		Question.QuestionLevel = QuestionLevel;
		return Question;
	}
	return Question;
}
void GenerateQuizzQuestions(stQuiz& Quiz)
{
	for (short Question = 0; Question <= Quiz.NumberOfQuestions; Question++)
	{
		Quiz.QuestionsList[Question] = GenerateQuestion(Quiz.QuestionLevel, Quiz.OpType);
	}
}
int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}
void PrintQuestions(stQuiz &Quiz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [" << QuestionNumber + 1 << " / " << Quiz.NumberOfQuestions << " ] \n\n";
	cout << Quiz.QuestionsList[QuestionNumber].Number1 << endl;
	cout << Quiz.QuestionsList[QuestionNumber].Number2 << " \n";
	cout << GetOpType(Quiz.QuestionsList[QuestionNumber].OperatioType);
	cout << "\n_______________" << endl;
}
void CorrectTheQuestionAnswer(stQuiz& Quiz,short QuestionNumber)
{
	if (Quiz.QuestionsList[QuestionNumber].PlayerAnswer != Quiz.QuestionsList[QuestionNumber].CorrectAnswer)
	{
		Quiz.QuestionsList[QuestionNumber].AnswerResult = false;
		Quiz.NumberOfWrongAnswers++;

		cout << "Wrong Answer :(\n";
		cout << "The Wright Answer is: ";
		cout<<Quiz.QuestionsList[QuestionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quiz.QuestionsList[QuestionNumber].AnswerResult = true;
		Quiz.NumberOfRightAnswers++;

		cout << "Right Answer :))\n";
	}
	cout << endl;

	SetScreenColor(Quiz.QuestionsList[QuestionNumber].AnswerResult);

}
void AskAndCorrectQuestionsListAnswers(stQuiz& Quiz)
{
	for (short QuestionNumber = 0; QuestionNumber < Quiz.NumberOfQuestions; QuestionNumber++)
	{
		PrintQuestions(Quiz,QuestionNumber);
		Quiz.QuestionsList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();
		CorrectTheQuestionAnswer(Quiz, QuestionNumber);

	}

	Quiz.isPass = (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers);
	/*
	if (Quiz.NumberOfRightAnswers >= Quiz.NumberOfWrongAnswers)
		Quiz.isPass = true;
	else
		Quiz.isPass = false;
		*/
}
string GetFinalResultText(bool Pass)
{
	if (Pass)
		return "PASS :))";
	else
		return "FAIL :((";
}
void PrintQuizResult(stQuiz Quiz)
{
	cout<<"\n";
	cout << "_____________________________________\n\n";
	cout << "Final Result is: " << GetFinalResultText(Quiz.isPass) ;
	cout << "_______________________________\n";

	cout << "Number Of Questions: " << Quiz.NumberOfQuestions << endl;
	cout << "Question Level     : " << GetQuestionLevelText(Quiz.QuestionLevel) << endl;
	cout << "OpType:     " << GetOpType(Quiz.OpType) << endl;
	cout << "Number Of right Answers:  " << Quiz.NumberOfRightAnswers << endl;
	cout << " Number Of Wrong Answers:  " << Quiz.NumberOfWrongAnswers << endl;
	cout << "______________________________________________\n";

}
void PlayGameMath()
{
	stQuiz Quizz;
	Quizz.NumberOfQuestions = ReadHowManyQuestions();
	Quizz.QuestionLevel = ReadQuestionsLevel();
	Quizz.OpType = ReadOperationType();

	GenerateQuizzQuestions(Quizz);
	AskAndCorrectQuestionsListAnswers(Quizz);

	PrintQuizResult(Quizz);
}
void ResetScreen()
{
	system("cls");
	system("color 0F");
}
void StartGame()
{
	char Playagain = 'Y';
	do
	{
		ResetScreen();
		PlayGameMath();

		cout << endl << "DO You Want To Play Again N/Y: " << endl;
		cin >> Playagain;

	} while (Playagain == 'Y' || Playagain == 'y');

}


int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
