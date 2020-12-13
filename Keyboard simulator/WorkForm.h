#pragma once

namespace Keyboardsimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для WorkForm
	/// </summary>
	public ref class WorkForm : public System::Windows::Forms::Form
	{
	public:
		WorkForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~WorkForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ назадToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::TextBox^ textBoxOutput;
	private: System::Windows::Forms::TextBox^ textBoxInput;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ buttonStart;
	private: System::Windows::Forms::Button^ buttonNext;
	private: System::Windows::Forms::Button^ buttonComplete;



	private: System::Windows::Forms::Label^ labelTimer;
	private: System::Windows::Forms::Timer^ timer;
	private: System::ComponentModel::IContainer^ components;

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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->назадToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->textBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->textBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonStart = (gcnew System::Windows::Forms::Button());
			this->buttonNext = (gcnew System::Windows::Forms::Button());
			this->buttonComplete = (gcnew System::Windows::Forms::Button());
			this->labelTimer = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->назадToolStripMenuItem,
					this->оПрограммеToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(654, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// назадToolStripMenuItem
			// 
			this->назадToolStripMenuItem->Name = L"назадToolStripMenuItem";
			this->назадToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->назадToolStripMenuItem->Text = L"Назад";
			this->назадToolStripMenuItem->Click += gcnew System::EventHandler(this, &WorkForm::назадToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->оПрограммеToolStripMenuItem->Text = L"О программе";
			this->оПрограммеToolStripMenuItem->Click += gcnew System::EventHandler(this, &WorkForm::оПрограммеToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->выходToolStripMenuItem->Text = L"Выход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &WorkForm::выходToolStripMenuItem_Click);
			// 
			// textBoxOutput
			// 
			this->textBoxOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxOutput->Location = System::Drawing::Point(12, 47);
			this->textBoxOutput->Multiline = true;
			this->textBoxOutput->Name = L"textBoxOutput";
			this->textBoxOutput->ReadOnly = true;
			this->textBoxOutput->ShortcutsEnabled = false;
			this->textBoxOutput->Size = System::Drawing::Size(306, 206);
			this->textBoxOutput->TabIndex = 1;
			// 
			// textBoxInput
			// 
			this->textBoxInput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxInput->Location = System::Drawing::Point(333, 47);
			this->textBoxInput->Multiline = true;
			this->textBoxInput->Name = L"textBoxInput";
			this->textBoxInput->Size = System::Drawing::Size(306, 206);
			this->textBoxInput->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(61, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Вывод текста под запись:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(389, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(199, 18);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Область для ввода текста:";
			// 
			// buttonStart
			// 
			this->buttonStart->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStart->Location = System::Drawing::Point(160, 274);
			this->buttonStart->Name = L"buttonStart";
			this->buttonStart->Size = System::Drawing::Size(78, 32);
			this->buttonStart->TabIndex = 5;
			this->buttonStart->Text = L"Начать";
			this->buttonStart->UseVisualStyleBackColor = true;
			this->buttonStart->Click += gcnew System::EventHandler(this, &WorkForm::buttonStart_Click);
			// 
			// buttonNext
			// 
			this->buttonNext->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonNext->Location = System::Drawing::Point(244, 274);
			this->buttonNext->Name = L"buttonNext";
			this->buttonNext->Size = System::Drawing::Size(117, 32);
			this->buttonNext->TabIndex = 6;
			this->buttonNext->Text = L"Продолжить";
			this->buttonNext->UseVisualStyleBackColor = true;
			this->buttonNext->Click += gcnew System::EventHandler(this, &WorkForm::buttonNext_Click);
			// 
			// buttonComplete
			// 
			this->buttonComplete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonComplete->Location = System::Drawing::Point(367, 274);
			this->buttonComplete->Name = L"buttonComplete";
			this->buttonComplete->Size = System::Drawing::Size(117, 32);
			this->buttonComplete->TabIndex = 7;
			this->buttonComplete->Text = L"Завершить";
			this->buttonComplete->UseVisualStyleBackColor = true;
			this->buttonComplete->Click += gcnew System::EventHandler(this, &WorkForm::buttonComplete_Click);
			// 
			// labelTimer
			// 
			this->labelTimer->AutoSize = true;
			this->labelTimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTimer->Location = System::Drawing::Point(330, 256);
			this->labelTimer->Name = L"labelTimer";
			this->labelTimer->Size = System::Drawing::Size(86, 15);
			this->labelTimer->TabIndex = 8;
			this->labelTimer->Text = L"Время ввода:";
			// 
			// timer
			// 
			this->timer->Interval = 1000;
			this->timer->Tick += gcnew System::EventHandler(this, &WorkForm::Update);
			// 
			// WorkForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 314);
			this->Controls->Add(this->labelTimer);
			this->Controls->Add(this->buttonComplete);
			this->Controls->Add(this->buttonNext);
			this->Controls->Add(this->buttonStart);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBoxInput);
			this->Controls->Add(this->textBoxOutput);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(670, 353);
			this->MinimumSize = System::Drawing::Size(670, 353);
			this->Name = L"WorkForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Клавиатурный тренажер ";
			this->Load += gcnew System::EventHandler(this, &WorkForm::WorkForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	//Открытые поля
	public: int mode;
	public: String^ name;

	//Закрытые поля
	private: bool complete;//флаг - был ли завершен тест
	private: bool start;//флаг - начался ли тест
	private: List<float> times;//список с временем каждой попытки
	private: int time;//прошедшее время
	private: int correct_answers;//правильные ответы
	private: int in_total;//всего тестов
	private: List<String^> words;//список слов
	private: String^ line_words;

	//Методы
	private: System::Void назадToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void оПрограммеToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonStart_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonNext_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonComplete_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void WorkForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: void Update(System::Object^ sender, System::EventArgs^ e);
	private: void SaveResult();
	private: void LoadData();
	private: void ShowWords();
	private: void ResetParam();
	private: void Check();
};
}
