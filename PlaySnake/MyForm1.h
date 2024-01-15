#pragma once
#include <fstream>

namespace PlaySnake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void);
		//System::Windows::Forms::Form^ form;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::GroupBox^ groupBox_Pause;
	public: System::Windows::Forms::Button^ btn_cont;

	public: System::Windows::Forms::Button^ btn_ExitAndSave;

	public: System::Windows::Forms::TextBox^ textBox1;
	public: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer;
	public: System::Windows::Forms::Label^ label_score;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->groupBox_Pause = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_cont = (gcnew System::Windows::Forms::Button());
			this->btn_ExitAndSave = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_score = (gcnew System::Windows::Forms::Label());
			this->groupBox_Pause->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox_Pause
			// 
			this->groupBox_Pause->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->groupBox_Pause->Controls->Add(this->textBox1);
			this->groupBox_Pause->Controls->Add(this->label1);
			this->groupBox_Pause->Controls->Add(this->btn_cont);
			this->groupBox_Pause->Controls->Add(this->btn_ExitAndSave);
			this->groupBox_Pause->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_Pause->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox_Pause->ForeColor = System::Drawing::Color::White;
			this->groupBox_Pause->Location = System::Drawing::Point(0, 0);
			this->groupBox_Pause->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox_Pause->Name = L"groupBox_Pause";
			this->groupBox_Pause->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->groupBox_Pause->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->groupBox_Pause->Size = System::Drawing::Size(1200, 1231);
			this->groupBox_Pause->TabIndex = 0;
			this->groupBox_Pause->TabStop = false;
			this->groupBox_Pause->Text = L"Пауза";
			this->groupBox_Pause->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(586, 609);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(148, 63);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"4";
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label1->Location = System::Drawing::Point(4, 533);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1192, 231);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Скорость Змейки\r\n(от 1-5)";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// btn_cont
			// 
			this->btn_cont->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btn_cont->ForeColor = System::Drawing::Color::Black;
			this->btn_cont->Location = System::Drawing::Point(4, 764);
			this->btn_cont->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_cont->Name = L"btn_cont";
			this->btn_cont->Size = System::Drawing::Size(1192, 231);
			this->btn_cont->TabIndex = 1;
			this->btn_cont->Text = L"Продолжить";
			this->btn_cont->UseVisualStyleBackColor = true;
			this->btn_cont->Click += gcnew System::EventHandler(this, &MyForm1::btn_cont_Click);
			// 
			// btn_ExitAndSave
			// 
			this->btn_ExitAndSave->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btn_ExitAndSave->ForeColor = System::Drawing::Color::Black;
			this->btn_ExitAndSave->Location = System::Drawing::Point(4, 995);
			this->btn_ExitAndSave->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_ExitAndSave->Name = L"btn_ExitAndSave";
			this->btn_ExitAndSave->Size = System::Drawing::Size(1192, 231);
			this->btn_ExitAndSave->TabIndex = 0;
			this->btn_ExitAndSave->Text = L"Выйти и Сохранить";
			this->btn_ExitAndSave->UseVisualStyleBackColor = true;
			this->btn_ExitAndSave->Click += gcnew System::EventHandler(this, &MyForm1::btn_ExitAndSave_Click);
			// 
			// timer
			// 
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm1::MyForm_Update);
			// 
			// label_score
			// 
			this->label_score->AutoSize = true;
			this->label_score->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_score->ForeColor = System::Drawing::Color::White;
			this->label_score->Location = System::Drawing::Point(0, -1);
			this->label_score->Name = L"label_score";
			this->label_score->Size = System::Drawing::Size(307, 74);
			this->label_score->TabIndex = 4;
			this->label_score->Text = L"Счет: 0\r\nЛучший результат: 0";
			this->label_score->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1200, 1231);
			this->Controls->Add(this->groupBox_Pause);
			this->Controls->Add(this->label_score);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyDown);
			this->groupBox_Pause->ResumeLayout(false);
			this->groupBox_Pause->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//
	//Данные игры
	//
	private: PictureBox^ fruit;				
	private: array<PictureBox^>^ rock;		
	private: array<PictureBox^>^ snake;		
	private: bool play;						
	private: bool die;						
	private: bool firstLaunch;				
	private: int step = 20;					
	private: float updateInterval = 100;	
	private: int score = 0;					
	private: int total_score = 0;			
	//
	//Действия игры
	//
	private: void GenPositionFruit();	//
	private: void GenPositionRock();	//
	private: void Eating();				//
	private: void Movement();			//
	private: void EatYourSelf();		//
	private: void GameOver();			//
	private: void NewGame();			//
	private: void CheckBorder();		//
	private: void CheckRock();			//
	private: void PlaySound(String^ filename);//
	private: void SaveGame();
	//
	//Клава
	//
	private: System::Void MyForm1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
	//
	//Обновление
	//
	private: void MyForm_Update(System::Object^ sender, System::EventArgs^ e);
	//
	//Сохраняет игру и закрывает Форму со змейкой и возвращает Меню
	//
	private: System::Void btn_ExitAndSave_Click(System::Object^ sender, System::EventArgs^ e);
	//
	//Продолжает игру с измененной скоростью
	//
	private: System::Void btn_cont_Click(System::Object^ sender, System::EventArgs^ e);
};
}
