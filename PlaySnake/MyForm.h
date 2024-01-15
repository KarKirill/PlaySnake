#pragma once
#include "MyForm1.h"
#include <fstream>
#include <string>

namespace PlaySnake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void);

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Start;
	private: System::Windows::Forms::Button^ btn_Continue;
	private: System::Windows::Forms::Button^ btn_Settings;
	private: System::Windows::Forms::GroupBox^ groupBox_Settings;
	private: System::Windows::Forms::GroupBox^ groupBox_Area;
	private: System::Windows::Forms::GroupBox^ groupBox_AreaColor;




	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton_800;
	private: System::Windows::Forms::RadioButton^ radioButton_400;
	private: System::Windows::Forms::Button^ btn_Accept;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ teleport_no;

	private: System::Windows::Forms::RadioButton^ teleport_yes;
	private: System::Windows::Forms::Button^ btn_close;


	protected:

	protected:



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btn_Start = (gcnew System::Windows::Forms::Button());
			this->btn_Continue = (gcnew System::Windows::Forms::Button());
			this->btn_Settings = (gcnew System::Windows::Forms::Button());
			this->groupBox_Settings = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->teleport_no = (gcnew System::Windows::Forms::RadioButton());
			this->teleport_yes = (gcnew System::Windows::Forms::RadioButton());
			this->btn_Accept = (gcnew System::Windows::Forms::Button());
			this->groupBox_AreaColor = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox_Area = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_800 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_400 = (gcnew System::Windows::Forms::RadioButton());
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->groupBox_Settings->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox_AreaColor->SuspendLayout();
			this->groupBox_Area->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_Start
			// 
			this->btn_Start->BackColor = System::Drawing::Color::YellowGreen;
			this->btn_Start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Start->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->btn_Start->FlatAppearance->BorderSize = 0;
			this->btn_Start->FlatAppearance->MouseDownBackColor = System::Drawing::Color::GreenYellow;
			this->btn_Start->FlatAppearance->MouseOverBackColor = System::Drawing::Color::GreenYellow;
			this->btn_Start->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Start->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_Start->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btn_Start->Location = System::Drawing::Point(350, 50);
			this->btn_Start->Margin = System::Windows::Forms::Padding(4);
			this->btn_Start->Name = L"btn_Start";
			this->btn_Start->Size = System::Drawing::Size(500, 200);
			this->btn_Start->TabIndex = 0;
			this->btn_Start->Text = L"Начать Игру";
			this->btn_Start->UseVisualStyleBackColor = false;
			this->btn_Start->Click += gcnew System::EventHandler(this, &MyForm::btn_Start_Click);
			// 
			// btn_Continue
			// 
			this->btn_Continue->BackColor = System::Drawing::Color::YellowGreen;
			this->btn_Continue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Continue->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->btn_Continue->FlatAppearance->BorderSize = 0;
			this->btn_Continue->FlatAppearance->MouseDownBackColor = System::Drawing::Color::GreenYellow;
			this->btn_Continue->FlatAppearance->MouseOverBackColor = System::Drawing::Color::GreenYellow;
			this->btn_Continue->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Continue->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_Continue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btn_Continue->Location = System::Drawing::Point(350, 275);
			this->btn_Continue->Margin = System::Windows::Forms::Padding(4);
			this->btn_Continue->Name = L"btn_Continue";
			this->btn_Continue->Size = System::Drawing::Size(500, 200);
			this->btn_Continue->TabIndex = 1;
			this->btn_Continue->Text = L"Продолжить";
			this->btn_Continue->UseVisualStyleBackColor = false;
			this->btn_Continue->Click += gcnew System::EventHandler(this, &MyForm::btn_Continue_Click);
			// 
			// btn_Settings
			// 
			this->btn_Settings->BackColor = System::Drawing::Color::YellowGreen;
			this->btn_Settings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Settings->FlatAppearance->BorderColor = System::Drawing::Color::YellowGreen;
			this->btn_Settings->FlatAppearance->BorderSize = 0;
			this->btn_Settings->FlatAppearance->MouseDownBackColor = System::Drawing::Color::GreenYellow;
			this->btn_Settings->FlatAppearance->MouseOverBackColor = System::Drawing::Color::GreenYellow;
			this->btn_Settings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Settings->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_Settings->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btn_Settings->Location = System::Drawing::Point(350, 500);
			this->btn_Settings->Margin = System::Windows::Forms::Padding(4);
			this->btn_Settings->Name = L"btn_Settings";
			this->btn_Settings->Size = System::Drawing::Size(500, 200);
			this->btn_Settings->TabIndex = 2;
			this->btn_Settings->Text = L"Настройки";
			this->btn_Settings->UseVisualStyleBackColor = false;
			this->btn_Settings->Click += gcnew System::EventHandler(this, &MyForm::btn_Settings_Click);
			// 
			// groupBox_Settings
			// 
			this->groupBox_Settings->BackColor = System::Drawing::Color::YellowGreen;
			this->groupBox_Settings->Controls->Add(this->groupBox1);
			this->groupBox_Settings->Controls->Add(this->btn_Accept);
			this->groupBox_Settings->Controls->Add(this->groupBox_AreaColor);
			this->groupBox_Settings->Controls->Add(this->groupBox_Area);
			this->groupBox_Settings->Cursor = System::Windows::Forms::Cursors::Default;
			this->groupBox_Settings->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox_Settings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox_Settings->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox_Settings->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->groupBox_Settings->Location = System::Drawing::Point(0, 0);
			this->groupBox_Settings->Margin = System::Windows::Forms::Padding(4);
			this->groupBox_Settings->Name = L"groupBox_Settings";
			this->groupBox_Settings->Padding = System::Windows::Forms::Padding(4);
			this->groupBox_Settings->Size = System::Drawing::Size(1178, 744);
			this->groupBox_Settings->TabIndex = 3;
			this->groupBox_Settings->TabStop = false;
			this->groupBox_Settings->Text = L"Настройки";
			this->groupBox_Settings->Visible = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->teleport_no);
			this->groupBox1->Controls->Add(this->teleport_yes);
			this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->groupBox1->Location = System::Drawing::Point(767, 80);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->groupBox1->Size = System::Drawing::Size(399, 151);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Телепортация";
			// 
			// teleport_no
			// 
			this->teleport_no->Appearance = System::Windows::Forms::Appearance::Button;
			this->teleport_no->BackColor = System::Drawing::Color::Transparent;
			this->teleport_no->Cursor = System::Windows::Forms::Cursors::Hand;
			this->teleport_no->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->teleport_no->FlatAppearance->BorderSize = 3;
			this->teleport_no->FlatAppearance->CheckedBackColor = System::Drawing::Color::Crimson;
			this->teleport_no->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Crimson;
			this->teleport_no->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Crimson;
			this->teleport_no->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->teleport_no->Location = System::Drawing::Point(200, 64);
			this->teleport_no->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->teleport_no->Name = L"teleport_no";
			this->teleport_no->Size = System::Drawing::Size(199, 87);
			this->teleport_no->TabIndex = 1;
			this->teleport_no->TabStop = true;
			this->teleport_no->Text = L"Выкл";
			this->teleport_no->UseVisualStyleBackColor = false;
			// 
			// teleport_yes
			// 
			this->teleport_yes->Appearance = System::Windows::Forms::Appearance::Button;
			this->teleport_yes->BackColor = System::Drawing::Color::Transparent;
			this->teleport_yes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->teleport_yes->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->teleport_yes->FlatAppearance->BorderSize = 3;
			this->teleport_yes->FlatAppearance->CheckedBackColor = System::Drawing::Color::Green;
			this->teleport_yes->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Green;
			this->teleport_yes->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Green;
			this->teleport_yes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->teleport_yes->Location = System::Drawing::Point(0, 64);
			this->teleport_yes->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->teleport_yes->Name = L"teleport_yes";
			this->teleport_yes->Size = System::Drawing::Size(194, 87);
			this->teleport_yes->TabIndex = 0;
			this->teleport_yes->TabStop = true;
			this->teleport_yes->Text = L"Вкл";
			this->teleport_yes->UseVisualStyleBackColor = false;
			// 
			// btn_Accept
			// 
			this->btn_Accept->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->btn_Accept->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Accept->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->btn_Accept->FlatAppearance->BorderSize = 0;
			this->btn_Accept->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Accept->ForeColor = System::Drawing::Color::White;
			this->btn_Accept->Location = System::Drawing::Point(4, 584);
			this->btn_Accept->Margin = System::Windows::Forms::Padding(4);
			this->btn_Accept->Name = L"btn_Accept";
			this->btn_Accept->Size = System::Drawing::Size(1170, 156);
			this->btn_Accept->TabIndex = 3;
			this->btn_Accept->Text = L"Применить";
			this->btn_Accept->UseVisualStyleBackColor = false;
			this->btn_Accept->Click += gcnew System::EventHandler(this, &MyForm::btn_Accept_Click);
			// 
			// groupBox_AreaColor
			// 
			this->groupBox_AreaColor->Controls->Add(this->radioButton2);
			this->groupBox_AreaColor->Controls->Add(this->radioButton1);
			this->groupBox_AreaColor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->groupBox_AreaColor->Location = System::Drawing::Point(13, 258);
			this->groupBox_AreaColor->Margin = System::Windows::Forms::Padding(4);
			this->groupBox_AreaColor->Name = L"groupBox_AreaColor";
			this->groupBox_AreaColor->Padding = System::Windows::Forms::Padding(4);
			this->groupBox_AreaColor->Size = System::Drawing::Size(453, 272);
			this->groupBox_AreaColor->TabIndex = 2;
			this->groupBox_AreaColor->TabStop = false;
			this->groupBox_AreaColor->Text = L"Цветовая Палитра";
			// 
			// radioButton2
			// 
			this->radioButton2->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->radioButton2->FlatAppearance->BorderSize = 3;
			this->radioButton2->FlatAppearance->CheckedBackColor = System::Drawing::Color::Green;
			this->radioButton2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton2->Location = System::Drawing::Point(2, 173);
			this->radioButton2->Margin = System::Windows::Forms::Padding(4);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(451, 99);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Синий и Красный";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->radioButton1->FlatAppearance->BorderSize = 3;
			this->radioButton1->FlatAppearance->CheckedBackColor = System::Drawing::Color::Green;
			this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton1->Location = System::Drawing::Point(0, 64);
			this->radioButton1->Margin = System::Windows::Forms::Padding(4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(453, 101);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Красный и Зеленый";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// groupBox_Area
			// 
			this->groupBox_Area->Controls->Add(this->radioButton_800);
			this->groupBox_Area->Controls->Add(this->radioButton_400);
			this->groupBox_Area->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox_Area->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->groupBox_Area->Location = System::Drawing::Point(13, 80);
			this->groupBox_Area->Margin = System::Windows::Forms::Padding(4);
			this->groupBox_Area->Name = L"groupBox_Area";
			this->groupBox_Area->Padding = System::Windows::Forms::Padding(4);
			this->groupBox_Area->Size = System::Drawing::Size(453, 151);
			this->groupBox_Area->TabIndex = 1;
			this->groupBox_Area->TabStop = false;
			this->groupBox_Area->Text = L"Поле";
			// 
			// radioButton_800
			// 
			this->radioButton_800->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton_800->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton_800->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->radioButton_800->FlatAppearance->BorderSize = 3;
			this->radioButton_800->FlatAppearance->CheckedBackColor = System::Drawing::Color::Green;
			this->radioButton_800->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton_800->Location = System::Drawing::Point(226, 55);
			this->radioButton_800->Margin = System::Windows::Forms::Padding(4);
			this->radioButton_800->Name = L"radioButton_800";
			this->radioButton_800->Size = System::Drawing::Size(227, 96);
			this->radioButton_800->TabIndex = 1;
			this->radioButton_800->TabStop = true;
			this->radioButton_800->Text = L"800x800";
			this->radioButton_800->UseVisualStyleBackColor = true;
			// 
			// radioButton_400
			// 
			this->radioButton_400->Appearance = System::Windows::Forms::Appearance::Button;
			this->radioButton_400->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton_400->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->radioButton_400->FlatAppearance->BorderSize = 3;
			this->radioButton_400->FlatAppearance->CheckedBackColor = System::Drawing::Color::Green;
			this->radioButton_400->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->radioButton_400->Location = System::Drawing::Point(0, 55);
			this->radioButton_400->Margin = System::Windows::Forms::Padding(4);
			this->radioButton_400->Name = L"radioButton_400";
			this->radioButton_400->Size = System::Drawing::Size(218, 96);
			this->radioButton_400->TabIndex = 0;
			this->radioButton_400->TabStop = true;
			this->radioButton_400->Text = L"400x400";
			this->radioButton_400->UseVisualStyleBackColor = true;
			// 
			// btn_close
			// 
			this->btn_close->BackColor = System::Drawing::Color::Brown;
			this->btn_close->FlatAppearance->BorderSize = 0;
			this->btn_close->FlatAppearance->MouseDownBackColor = System::Drawing::Color::IndianRed;
			this->btn_close->FlatAppearance->MouseOverBackColor = System::Drawing::Color::IndianRed;
			this->btn_close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_close->Location = System::Drawing::Point(1034, 12);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(132, 86);
			this->btn_close->TabIndex = 0;
			this->btn_close->Text = L"X";
			this->btn_close->UseVisualStyleBackColor = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &MyForm::btn_close_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(51)));
			this->ClientSize = System::Drawing::Size(1178, 744);
			this->Controls->Add(this->groupBox_Settings);
			this->Controls->Add(this->btn_Settings);
			this->Controls->Add(this->btn_Continue);
			this->Controls->Add(this->btn_Start);
			this->Controls->Add(this->btn_close);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Игра в Змейку";
			this->groupBox_Settings->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox_AreaColor->ResumeLayout(false);
			this->groupBox_Area->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	public:  void LoadGame();

	//Создает поле игры и запускает ее
	public: System::Void btn_Start_Click(System::Object^ sender, System::EventArgs^ e);
	//Открывает настройки
	private: System::Void btn_Settings_Click(System::Object^ sender, System::EventArgs^ e); 
	//Применяет настройки
	private: System::Void btn_Accept_Click(System::Object^ sender, System::EventArgs^ e);
	//Закрывает Форму Меню
	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_Continue_Click(System::Object^ sender, System::EventArgs^ e);
};
}
