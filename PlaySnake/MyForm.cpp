#include "MyForm.h"
#include "DataBank.h"

using namespace PlaySnake;
int DataBank::areaS = 800; //Размер поля по умолчанию
bool DataBank::PlayGame = true; //Цветовая палитра
bool DataBank::teleport = true; //Модификация игры: Телепорты
int DataBank::score = 0;
bool DataBank::die = false;
int DataBank::total_score = 0;
bool DataBank::loadGame = false;
int DataBank::cordX_snake = 0;
int DataBank::cordY_snake = 0;
int DataBank::cordX_fruit = 0;
int DataBank::cordY_fruit = 0;
int DataBank::directionX = 0;
int DataBank::directionY = 0;
std::vector<Vector2> DataBank::rocks;
std::vector<Vector2> DataBank::snakes;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	PlaySnake::MyForm form;
	Application::Run(% form);
}
//
// Показывает настройки
//
System::Void PlaySnake::MyForm::btn_Settings_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox_Settings->Visible = true;
}
//
// Убирает настройки
//
System::Void PlaySnake::MyForm::btn_Accept_Click(System::Object^ sender, System::EventArgs^ e)
{
	groupBox_Settings->Visible = false;
}
//
// Закрывает Форму Меню
//
System::Void PlaySnake::MyForm::btn_close_Click(System::Object^ sender, System::EventArgs^ e)
{
	MyForm::Close();
}
//
// Иницилизирует форму
//
PlaySnake::MyForm::MyForm(void)
{
	
	InitializeComponent();

	/*if (DataBank::loadGame == false) btn_Continue->Visible = false;
	else btn_Continue->Visible = true;*/

}
//
// Загружает последнюю игру
//
void PlaySnake::MyForm::LoadGame()
{
	DataBank::rocks.clear();

	DataBank::loadGame = true;

	std::ifstream file("saved_game.txt");

	// Считываем данные игры из файла
	std::string line;
	while (getline(file, line))
	{
		if (line.find("Смерт: ") == 0)
		{
			if (stoi(line.substr(6, 9)) == 1) DataBank::die = true;
			else DataBank::die = false;
		}
		else if (line.find("Счет: ") == 0)
		{
			DataBank::score = stoi(line.substr(6,9));
		}
		else if (line.find("Лучший счет: ") == 0)
		{
			DataBank::total_score = stoi(line.substr(13,16));
		}
		else if (line.find("Размеры арены: ") == 0)
		{
			DataBank::areaS = stoi(line.substr(15,18));
		}
		else if (line.find("Цвет: ") == 0)
		{
			if (stoi(line.substr(6,7)) == 1) DataBank::PlayGame = true;
			else DataBank::PlayGame = false;
		}
		else if (line.find("Телепорт: ") == 0)
		{
			if (stoi(line.substr(10,11)) == 1) DataBank::teleport = true;
			else DataBank::teleport = false;
		}
		else if (line.find("Игра Сохранена: ") == 0)
		{
			if (stoi(line.substr(16, 17)) == 1) DataBank::loadGame = true;
			else DataBank::loadGame = false;
		}
		else if (line.find("Змея х: ") == 0)
		{
			DataBank::cordX_snake = stoi(line.substr(8, 12));
		}
		else if (line.find("Змея у: ") == 0)
		{
			DataBank::cordY_snake = stoi(line.substr(8, 12));
		}
		else if (line.find("Фрукт х: ") == 0)
		{
			DataBank::cordX_fruit = stoi(line.substr(9, 14));
		}
		else if (line.find("Фрукт у: ") == 0)
		{
			DataBank::cordY_fruit = stoi(line.substr(9, 14));
		}
		else if (line.find("Направление х: ") == 0)
		{
			DataBank::directionX = stoi(line.substr(15, 17));
		}
		else if (line.find("Направление у: ") == 0)
		{
			DataBank::directionY = stoi(line.substr(15, 17));
		}
		else if (line.find("Камень: ") == 0)
		{
			DataBank::rocks.emplace_back(stoi(line.substr(8, 11)), stoi(line.substr(11, 14)));
		}
		else if (line.find("Змейка: ") == 0)
		{
			DataBank::snakes.emplace_back(stoi(line.substr(8, 11)), stoi(line.substr(11, 14)));
		}


	}

	// Закрываем файл
	file.close();
}
//
// Принимает все предыдущик настройки и запускает Форму со Змейкой
//
System::Void PlaySnake::MyForm::btn_Continue_Click(System::Object^ sender, System::EventArgs^ e)
{
	LoadGame();

	MyForm1^ snakeGame = gcnew MyForm1();
	//snakeGame->form = this;

	snakeGame->Height = DataBank::areaS;
	snakeGame->Width = DataBank::areaS;
	snakeGame->groupBox_Pause->Height = DataBank::areaS;
	snakeGame->groupBox_Pause->Width = DataBank::areaS;

	if (DataBank::areaS == 400)
	{
		snakeGame->btn_ExitAndSave->Width = 200;
		snakeGame->btn_ExitAndSave->Height = 100;

		snakeGame->btn_cont->Width = 200;
		snakeGame->btn_cont->Height = 100;

		snakeGame->label1->Width = 200;
		snakeGame->label1->Height = 100;

		snakeGame->textBox1->Location = Point(250, 100);

		snakeGame->label_score->Height = 25;
		snakeGame->label_score->Width = 50;
	}

	snakeGame->Show();
	MyForm::Visible = false;
}
//
// Принимает все настройки и запускает Форму со Змейкой
//
System::Void PlaySnake::MyForm::btn_Start_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (radioButton_400->Checked == true) DataBank::areaS = 400;
	
	if (radioButton2->Checked == true) DataBank::PlayGame = false;

	if (teleport_no->Checked == true) DataBank::teleport = false;

	MyForm1^ snakeGame = gcnew MyForm1();
	// Присваиваем  
	//snakeGame->form = this;

	snakeGame->Height = DataBank::areaS;
	snakeGame->Width = DataBank::areaS;
	snakeGame->groupBox_Pause->Height = DataBank::areaS;
	snakeGame->groupBox_Pause->Width = DataBank::areaS;

	if (DataBank::areaS == 400)
	{
		snakeGame->btn_ExitAndSave->Width = 200;
		snakeGame->btn_ExitAndSave->Height = 100;

		snakeGame->btn_cont->Width = 200;
		snakeGame->btn_cont->Height = 100;

		snakeGame->label1->Width = 200;
		snakeGame->label1->Height = 100;

		snakeGame->textBox1->Location = Point(250, 100);

		snakeGame->label_score->Height = 25;
		snakeGame->label_score->Width = 50;
	}


	snakeGame->Show();
	MyForm::Visible = false;


}
//
//
//

