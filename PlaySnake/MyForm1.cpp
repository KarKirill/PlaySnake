#include "MyForm1.h"
#include "DataBank.h"

Vector2 direction;
Vector2 posFruit;
Vector2 posRock;
Vector2 gameArea;

PlaySnake::MyForm1::MyForm1(void)
{
	InitializeComponent();

	gameArea.X = DataBank::areaS;
	gameArea.Y = DataBank::areaS;
	label_score->SendToBack();

	firstLaunch = true;
	NewGame();
}

void PlaySnake::MyForm1::GenPositionFruit()
{
	//
	// При загрузке игры
	if (DataBank::loadGame == true)
	{
		fruit->Location = Point(DataBank::cordX_fruit, DataBank::cordY_fruit);

		this->Controls->Add(fruit);

		DataBank::loadGame = false;
	}
	else
	{
		Random^ rand = gcnew Random();
		posFruit.X = rand->Next(0, gameArea.X);
		posFruit.Y = rand->Next(0, gameArea.Y);


		for (int i = 0; i < DataBank::snakes.size(); i++)
		{
			if ((posFruit.X == snake[i]->Location.X && posFruit.Y == snake[i]->Location.Y) ||
				(posRock.X == posFruit.X && posRock.Y == posFruit.Y))
			{
				GenPositionFruit();
				return;
			}
		}

		int tempX = posFruit.X % step;
		posFruit.X -= tempX;

		int tempY = posFruit.Y % step;
		posFruit.Y -= tempY;
		DataBank::cordX_fruit = posFruit.X;
		DataBank::cordY_fruit = posFruit.Y;
		fruit->Location = Point(posFruit.X, posFruit.Y);

		this->Controls->Add(fruit);
	}
}

void PlaySnake::MyForm1::GenPositionRock()
{
	Random^ randd = gcnew Random();
	posRock.X = randd->Next(step, gameArea.X-step);
	posRock.Y = randd->Next(step, gameArea.Y - step);

	for (int i = 0; i < DataBank::snakes.size(); i++)
	{
		if ((posRock.X == snake[i]->Location.X && posRock.Y == snake[i]->Location.Y) ||
			(posRock.X == posFruit.X && posRock.Y == posFruit.Y))
		{
			GenPositionRock();
			return;
		}
	}

	int tempXR = posRock.X % step;
	posRock.X -= tempXR;

	int tempYR = posRock.Y % step;
	posRock.Y -= tempYR;

	rock[DataBank::rocks.size()]->Location = Point(posRock.X, posRock.Y);

	if (rock[DataBank::rocks.size()]->Location == fruit->Location) { GenPositionFruit(); return; }

	this->Controls->Add(rock[DataBank::rocks.size()]);

	DataBank::rocks.emplace_back(posRock.X, posRock.Y);
}

void PlaySnake::MyForm1::Eating()
{
	if (snake[0]->Location.X == posFruit.X && snake[0]->Location.Y == posFruit.Y || snake[0]->Location.X == DataBank::cordX_fruit && snake[0]->Location.Y == DataBank::cordY_fruit)
	{
		//PlaySound("C:\\Users\\USER\\Desktop\\pickup_apple.wav");

		if (total_score > score) label_score->Text = "Счет: " + ++score + "\nЛучший счет : " + total_score;
		else if (total_score == score) label_score->Text = "Счет: " + ++score + "\nЛучший счет: " + ++total_score;

		snake[DataBank::snakes.size()] = gcnew PictureBox();
		snake[DataBank::snakes.size()]->Location = Point(snake[DataBank::snakes.size() - 1]->Location.X + direction.X * step, snake[DataBank::snakes.size() - 1]->Location.Y + direction.Y * step);
		snake[DataBank::snakes.size()]->Width = step;
		snake[DataBank::snakes.size()]->Height = step;

		if (score >= total_score) 
			snake[DataBank::snakes.size()]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_body_gold.png");
		else if (DataBank::PlayGame == true) 
			snake[DataBank::snakes.size()]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_body_static.png");
		else 
			snake[DataBank::snakes.size()]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_body_static_2.png");

		this->Controls->Add(snake[DataBank::snakes.size()]);
		DataBank::snakes.emplace_back(snake[DataBank::snakes.size() - 1]->Location.X + direction.X * step, snake[DataBank::snakes.size() - 1]->Location.Y + direction.Y * step);

		GenPositionFruit();

		rock[DataBank::rocks.size()] = gcnew PictureBox();
		if (DataBank::PlayGame == true)  rock[DataBank::rocks.size()]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\rock.png");
		else rock[DataBank::rocks.size()]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\rock2.png");
		rock[DataBank::rocks.size()]->Width = step;
		rock[DataBank::rocks.size()]->Height = step;

		GenPositionRock();

	}
}

void PlaySnake::MyForm1::Movement()
{
	for (int i = DataBank::snakes.size() - 1; i >= 1; i--)
	{
		snake[i]->Location = snake[i - 1]->Location;
	}
	snake[0]->Location = Point(snake[0]->Location.X + step * direction.X, snake[0]->Location.Y + step * direction.Y);
}

void PlaySnake::MyForm1::EatYourSelf()
{
	for (int i = 1; i < DataBank::snakes.size() - 1; i++)
	{
		if (snake[0]->Location == snake[i]->Location)
		{
			label_score->Text = "Съел Себя!";
			GameOver();
		}
	}
}

void PlaySnake::MyForm1::GameOver()
{
	play = true;
	die = true;
	snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_dead.png");
}

void PlaySnake::MyForm1::NewGame()
{
	if (!firstLaunch)
	{
		this->Controls->Remove(fruit);

		for (int i = 0; i < DataBank::rocks.size(); i++)
		{
			this->Controls->Remove(rock[i]);
		}

		for (int i = 0; i < DataBank::snakes.size() + 1; i++)
		{
			this->Controls->Remove(snake[i]);
		}

		DataBank::snakes.clear();
		DataBank::rocks.clear();
		DataBank::score = 0;
		
		score = 0;
		label_score->SendToBack();
	}
	else
		firstLaunch = false;

	//
	// Выбор цветовой темы
	if (DataBank::PlayGame == true)
	{
		this->BackColor = Color::FromArgb(51, 102, 51);
		this->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\place.png");
	}
	else 
	{
		this->BackColor = Color::FromArgb(34, 32, 52);
		this->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\place2.png");
	}
	//
	// Если Игра загружена, иначе
	if (DataBank::loadGame == true)
	{
		snake = gcnew array<PictureBox^>(400);

		for (int i = 0; i < DataBank::snakes.size(); i++)
		{
			snake[i] = gcnew PictureBox();
			if (DataBank::PlayGame == true)
				snake[i]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_body_static.png");
			else
				snake[i]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_body_static_2.png");
			snake[i]->Width = step;
			snake[i]->Height = step;
			snake[i]->Location = Point(DataBank::snakes[i].X, DataBank::snakes[i].Y);
			this->Controls->Add(snake[i]);
		}

		if (DataBank::PlayGame == true)
			snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_down.png");
		else
			snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_2_down.png");

		///

		fruit = gcnew PictureBox();
		if (DataBank::PlayGame == true) fruit->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\apple.png");
		else fruit->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\apple2.png");
		fruit->Location = Point(DataBank::cordX_fruit, DataBank::cordY_fruit);
		fruit->Width = step;
		fruit->Height = step;
		GenPositionFruit();

		///

		rock = gcnew array<PictureBox^>(400);

		for (int i = 0; i < DataBank::rocks.size(); i++)
		{
			rock[i] = gcnew PictureBox();
			if (DataBank::PlayGame == true)  rock[i]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\rock.png");
			else rock[i]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\rock2.png");
			rock[i]->Width = step;
			rock[i]->Height = step;
			rock[i]->Location = Point(DataBank::rocks[i].X, DataBank::rocks[i].Y);
			this->Controls->Add(rock[i]);
		}

		timer->Interval = updateInterval;
		timer->Start();

		direction.X = DataBank::directionX;
		direction.Y = DataBank::directionY;

		play = true;
		die = DataBank::die;


		total_score = DataBank::total_score;
		score = DataBank::score;

		label_score->Text = "Счет: " + score + "\nЛучший счет: " + total_score;
		label_score->SendToBack();

	}
	else
	{
		
		snake = gcnew array<PictureBox^>(400);
		snake[0] = gcnew PictureBox();

		if (DataBank::PlayGame == true)
		{
			snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_down.png");
		}
		else snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_2_down.png");


		Random^ random = gcnew Random();
		int XX = random->Next(step, gameArea.X);
		int YY = random->Next(step, gameArea.Y);

		int tempXX = XX % step;
		XX -= tempXX;
		int tempYY = YY % step;
		YY -= tempYY;

		snake[0]->Location = Point(XX, YY);
		snake[0]->Width = step;
		snake[0]->Height = step;

		score = 0;
		this->Controls->Add(snake[0]);
		DataBank::snakes.emplace_back(XX,YY);

		fruit = gcnew PictureBox();
		if (DataBank::PlayGame == true) fruit->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\apple.png");
		else fruit->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\apple2.png");
		fruit->Width = step;
		fruit->Height = step;
		GenPositionFruit();

		Random^ random_rock = gcnew Random();
		int XXR = random_rock->Next(XX, gameArea.X);
		int YYR = random_rock->Next(YY, gameArea.Y);

		int tempXXR = XXR % step;
		XXR -= tempXXR;
		int tempYYR = YYR % step;
		YYR -= tempYYR;

		rock = gcnew array<PictureBox^>(400);
		rock[0] = gcnew PictureBox();
		if (DataBank::PlayGame == true)  rock[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\rock.png");
		else rock[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\rock2.png");
		rock[0]->Width = step;
		rock[0]->Height = step;
		rock[0]->Location = Point(XXR, YYR);
		this->Controls->Add(rock[0]);
		DataBank::rocks.emplace_back(XXR, YYR);

		timer->Interval = updateInterval;
		timer->Start();

		direction.X = 0;
		direction.Y = 0;

		play = true;
		die = false;


		label_score->Text = "Счет: 0" + "\nЛучший счет: " + total_score;
		label_score->SendToBack();
	}

}

void PlaySnake::MyForm1::CheckBorder()
{
	if (DataBank::teleport == true) {
		if (snake[0]->Location.X >= gameArea.X)
		{
			snake[0]->Location = Point(0, snake[0]->Location.Y + step * direction.Y);
		}
		if (snake[0]->Location.X < 0)
		{
			snake[0]->Location = Point(gameArea.X, snake[0]->Location.Y + step * direction.Y);
		}
		if (snake[0]->Location.Y >= gameArea.X)
		{
			snake[0]->Location = Point(snake[0]->Location.X + step * direction.X, 0);
		}
		if (snake[0]->Location.Y < 0)
		{
			snake[0]->Location = Point(snake[0]->Location.X + step * direction.X, gameArea.X);
		}
	}
	else if (DataBank::teleport == false) {
		if (snake[0]->Location.X >= gameArea.X)
		{
			label_score->Text = "Удар об Стену!";
			GameOver();
		}
		if (snake[0]->Location.X < 0)
		{
			label_score->Text = "Удар об Стену!";
			GameOver();
		}
		if (snake[0]->Location.Y >= gameArea.X)
		{
			label_score->Text = "Удар об Стену!";
			GameOver();
		}
		if (snake[0]->Location.Y < 0)
		{
			label_score->Text = "Удар об Стену!";
			GameOver();
		}
	}
}

void PlaySnake::MyForm1::CheckRock()
{
	for (int i = 0; i < DataBank::rocks.size(); i++)
	{
		if (rock[i]->Location == snake[0]->Location) { label_score->Text = "Удар об Камень!"; GameOver(); }
	}
}

void PlaySnake::MyForm1::PlaySound(String^ filename)
{
	SoundPlayer^ soundPlayer = gcnew SoundPlayer();
	soundPlayer->SoundLocation = filename;
	soundPlayer->Load();
	soundPlayer->Play();
}

void PlaySnake::MyForm1::SaveGame()
{


	DataBank::loadGame = true;
	// Открываем файл для записи
	std::ofstream file("saved_game.txt");

	// Записываем данные игры в файл
	file << "Смерт: " << DataBank::die << std::endl;
	file << "Счет: " << score << std::endl;
	file << "Лучший счет: " << total_score << std::endl;
	file << "Размеры арены: " << DataBank::areaS << std::endl;
	file << "Цвет: " << DataBank::PlayGame << std::endl;
	file << "Телепорт: " << DataBank::teleport << std::endl;
	file << "Игра Сохранена: " << DataBank::loadGame << std::endl;
	file << "Змея х: " << snake[0]->Location.X << std::endl;
	file << "Змея у: " << snake[0]->Location.Y << std::endl;
	file << "Фрукт х: " << fruit->Location.X << std::endl;
	file << "Фрукт у: " << fruit->Location.Y << std::endl;
	file << "Направление х: " << direction.X << std::endl;
	file << "Направление у: " << direction.Y << std::endl;

	for (int i = 0; i < DataBank::rocks.size(); i++)
	{
		int x = rock[i]->Location.X;
		int y = rock[i]->Location.Y;

		file << "Камень: " << x << ' ' << y << std::endl;

	}

	for (int i = 0; i < DataBank::snakes.size(); i++)
	{
		int x = snake[i]->Location.X;
		int y = snake[i]->Location.Y;

		file << "Змейка: " << x << ' ' << y << std::endl;

	}

	// Закрываем файл
	file.close();
	
}

void PlaySnake::MyForm1::MyForm_Update(System::Object^ sender, System::EventArgs^ e) 
{
	if (!die && play)
	{
		Movement();
		Eating();
		EatYourSelf();
		CheckBorder();
		CheckRock();

		label_score->SendToBack();
	}
	else if (die && play) {
		timer->Stop();
		DataBank::die = true;
		MessageBox::Show("Вы Проиграли!" + "\n" + label_score->Text + "\nЧтобы продолжить, дважды нажмите Пробел", "Внимание!");
	}
	else if (!play && !die) {
		timer->Stop();
		DataBank::die = false;
	}

}

System::Void PlaySnake::MyForm1::MyForm1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyCode.ToString() == "Right" || e->KeyCode.ToString() == "D")
	{
		if (direction.X != -1)
		{
			direction.X = 1;
			direction.Y = 0;
			if (DataBank::PlayGame == true) snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_right.png");
			else snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_2_right.png");
		}
		return;
	}
	if (e->KeyCode.ToString() == "Left" || e->KeyCode.ToString() == "A") {
		if (direction.X != 1)
		{
			direction.X = -1;
			direction.Y = 0;
			if (DataBank::PlayGame == true) snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_left.png");
			else snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_2_left.png");
		}
		return;
	}
	if (e->KeyCode.ToString() == "Up" || e->KeyCode.ToString() == "W") {
		if (direction.Y != 1)
		{
			direction.X = 0;
			direction.Y = -1;
			if (DataBank::PlayGame == true) snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_up.png");
			else snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_2_up.png");
		}
		return;
	}
	if (e->KeyCode.ToString() == "Down" || e->KeyCode.ToString() == "S") {
		if (direction.Y != -1)
		{
			direction.X = 0;
			direction.Y = 1;
			if (DataBank::PlayGame == true) snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_down.png");
			else snake[0]->BackgroundImage = Image::FromFile("C:\\Users\\USER\\source\\repos\\PlaySnake\\PlaySnake\\resources\\snake_head_2_down.png");
		}
		return;
	}
	if (e->KeyCode.ToString() == "Space") {
		NewGame();
		return;
	}
	if (e->KeyCode.ToString() == "Escape")
	{
		if (play)
		{
			play = false;

			label_score->Visible = false;
			groupBox_Pause->Visible = true;
			groupBox_Pause->Enabled = true;
			textBox1->Enabled = true;
			btn_cont->Enabled = true;
		}
		else
		{
			play = true;
			timer->Start();

			label_score->Visible = true;
			groupBox_Pause->Visible = false;
			groupBox_Pause->Enabled = false;
			textBox1->Enabled = false;
			btn_cont->Enabled = false;
		}
		return;
	}
}

System::Void PlaySnake::MyForm1::btn_cont_Click(System::Object^ sender, System::EventArgs^ e)
{

	if (textBox1->Text == "1")
	{
		timer->Interval = 500;
	}
	if (textBox1->Text == "2")
	{
		timer->Interval = 250;
	}
	if (textBox1->Text == "3")
	{
		timer->Interval = 200;
	}
	if (textBox1->Text == "4")
	{
		timer->Interval = 100;
	}
	if (textBox1->Text == "5")
	{
		timer->Interval = 50;
	}

	play = true;
	timer->Start();

	label_score->Visible = true;
	groupBox_Pause->Visible = false;
	groupBox_Pause->Enabled = false;
	textBox1->Enabled = false;
	btn_cont->Enabled = false;

}

System::Void PlaySnake::MyForm1::btn_ExitAndSave_Click(System::Object^ sender, System::EventArgs^ e)
{
	SaveGame();
	MyForm1::Close();
	Application::Restart();
}

